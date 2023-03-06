#include "../include/Window.h"
#include <iostream>

#include <SDL.h>

Window::Window()
{
    std::cout<<"Window constructor\n";
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        // exit il faut peut être faire autrement
        exit;
    }
    if((pWindow = SDL_CreateWindow("PacManGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN)) == NULL)
        std::cerr<<"Echec de la création de la fenêtre "<<SDL_GetError()<<std::endl;
    if((win_surf = SDL_GetWindowSurface(pWindow)) == NULL)
        std::cerr<<"Echec de la récupération de la surface de la fenêtre "<<SDL_GetError()<<std::endl;
    if((plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp")) == NULL)
        std::cerr<<"Echec du chargement du bmp "<<SDL_GetError()<<std::endl;
    // count pour l'instant non utilisé
    count = 0;
    src_bg = {200, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    bg = {4, 4, 672, 864};       // ici scale x4
    ghost = new Character{};
    direction_tmp = 0;
    intersection_detected = false;
    last_pressed_key = 0;
    // fonctionne : test = new Pellet{{206, 9, 12, 12}, "Intersection 00", {207, 9, 12, 12}, true};
    // il vaudrait mieux créer une classe qui va faire toutes ces insertions
    // et qui va aussi update les valuers ou les chercher quand il faudra
    // du coup peut être faire une classe où dedans on déclare les maps d'objets, plutot que 
    // de faire une structure en fait
    // et dans Windows, on va appeler genre Manager->initArea()
    // puis Manager->updateArea() etc...
    // dans Windows on va juste appeler des 'évènements', sans utiliser de "vrais" données 
    gameManager = new GameManager{};
}

Window::Window(SDL_Window *new_pWindow, SDL_Surface *new_win_surf, SDL_Surface *new_plancheSprites, int new_count)
{
    // constructeur non utilisé pour le moment
}

Window::~Window()
{

}

void Window::update()
{
    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_bg, win_surf, &bg);

    // tmp values
    // SDL_Rect ghost = {34, 34, 32, 32}; // ici scale x2
    // SDL_Rect ghost_in2 = {3, 123, 16, 16};
    
    if(intersection_detected)
    {
        direction_tmp = last_pressed_key;
        intersection_detected = false;
    }
    else
        intersection_detected = false;

    switch(direction_tmp)
    {
        case 0:
                ghost->turnRight();
            break;
        case 1:
                ghost->turnDown();
            break;
        case 2:
                ghost->turnLeft();
            break;
        case 3:
                ghost->turnUp();
            break;
    }

    if(ghost->ghost.x == 34 && ghost->ghost.y == 34)
        {puts("intersection 00");
        intersection_detected = true;}
    if(ghost->ghost.x == 162 && ghost->ghost.y == 34)
    {
        puts("intersection 04");
        intersection_detected = true;
    }
    if(ghost->ghost.x == 162 && ghost->ghost.y == 162)
        {puts("intersection 44");
        intersection_detected = true;}
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}

    // count = (count + 1) % (512);

    // // ici on change entre les 2 sprites sources pour une jolie animation.
    // SDL_Rect ghost_in2 = *ghost_in;
    // if ((count / 4) % 2)
    //     ghost_in2.x += 17;

    //couelur transparente
    SDL_SetColorKey(plancheSprites, true, 0);
    // copie du sprite zoomé
    // SDL_Rect ghost_in2 = *ghost_in;
    SDL_Rect ghost_in2 = ghost->getGhostIn();
    SDL_BlitScaled(plancheSprites, &ghost_in2, win_surf, ghost->getGhost());

    SDL_UpdateWindowSurface(pWindow);

    // LIMITE A 60 FPS
    SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
}
