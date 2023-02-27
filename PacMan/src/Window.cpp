#include "../include/Window.h"
#include <iostream>

#include <SDL.h>

Window::Window()
{
    std::cout<<"Window constructor\n";
    if((pWindow = SDL_CreateWindow("PacManGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN)) == NULL)
        std::cerr<<"Echec de la création de la fenêtre "<<SDL_GetError()<<std::endl;
    if((win_surf = SDL_GetWindowSurface(pWindow)) == NULL)
        std::cerr<<"Echec de la récupération de la surface de la fenêtre "<<SDL_GetError()<<std::endl;
    if((plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp")) == NULL)
        std::cerr<<"Echec du chargement du bmp "<<SDL_GetError()<<std::endl;
    count = 0;
    src_bg = {200, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    bg = {4, 4, 672, 864};       // ici scale x4
    ghost = new Character{};
    direction_tmp = 0;
    intersection_detected = false;
    last_pressed_key = 0;
}

Window::Window(SDL_Window *new_pWindow, SDL_Surface *new_win_surf, SDL_Surface *new_plancheSprites, int new_count)
{
    std::cout<<"Window constructor\n";
    if((pWindow = new_pWindow) == NULL)
        std::cerr<<"Echec de la création de la fenêtre "<<SDL_GetError()<<std::endl;
    if((win_surf = new_win_surf) == NULL)
        std::cerr<<"Echec de la récupération de la surface de la fenêtre "<<SDL_GetError()<<std::endl;
    if((plancheSprites = new_plancheSprites) == NULL)
        std::cerr<<"Echec du chargement du bmp "<<SDL_GetError()<<std::endl;
    count = new_count;
    src_bg = {200, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    bg = {4, 4, 672, 864};       // ici scale x4
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
    
    // ghost->turn_right();

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
                ghost->turn_right();
            break;
        case 1:
                ghost->turn_down();
            break;
        case 2:
                ghost->turn_left();
            break;
        case 3:
                ghost->turn_up();
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


    //couelur transparente
    SDL_SetColorKey(plancheSprites, true, 0);
    // copie du sprite zoomé
    // SDL_Rect ghost_in2 = *ghost_in;
    SDL_Rect ghost_in2 = ghost->getGhostIn();
    SDL_BlitScaled(plancheSprites, &ghost_in2, win_surf, ghost->getGhost());

    SDL_UpdateWindowSurface(pWindow);
    SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
}

SDL_Window* Window::get_pWindow()
{
    return pWindow;
}

SDL_Surface* Window::get_win_surf()
{
    return win_surf;
}

SDL_Surface* Window::get_plancheSprites()
{
    return plancheSprites;
}

int Window::get_count()
{
    return count;
}

SDL_Rect Window::get_src_bg()
{
    return src_bg;
}

SDL_Rect Window::get_bg()
{
    return bg;
}

void Window::set_direction_right()
{
    last_pressed_key = 0;
}

void Window::set_direction_down()
{
    last_pressed_key = 1;
}

void Window::set_direction_left()
{
    last_pressed_key = 2;
}

void Window::set_direction_up()
{
    last_pressed_key = 3;
}
