// #include <SDL.h>

#include "include/Window.h"

#include <iostream>

SDL_Window *pWindow = nullptr;
SDL_Surface *win_surf = nullptr;
SDL_Surface *plancheSprites = nullptr;

// la planche servant de background
SDL_Rect src_bg = {200, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
SDL_Rect bg = {4, 4, 672, 864};       // ici scale x4

SDL_Rect ghost_r = {3, 123, 16, 16};
SDL_Rect ghost_l = {37, 123, 16, 16};
SDL_Rect ghost_d = {105, 123, 16, 16};
SDL_Rect ghost_u = {71, 123, 16, 16};
SDL_Rect ghost = {34, 34, 32, 32}; // ici scale x2

// intersections
SDL_Rect intersection00 = {206, 9, 12, 12};
SDL_Rect intersection01 = {214, 9, 12, 12};
SDL_Rect intersection02 = {222, 9, 12, 12};
SDL_Rect intersection03 = {230, 9, 12, 12};
SDL_Rect intersection04 = {238, 9, 12, 12};
SDL_Rect intersection05 = {254, 9, 12, 12};
SDL_Rect intersection06 = {262, 9, 12, 12};
SDL_Rect intersection07 = {270, 9, 12, 12};

SDL_Rect intersection10 = {206, 17, 12, 12};
SDL_Rect intersection14 = {238, 17, 12, 12};
SDL_Rect intersection17 = {270, 17, 12, 12};

SDL_Rect intersection20 = {206, 25, 12, 12};
SDL_Rect intersection24 = {238, 25, 12, 12};
SDL_Rect intersection27 = {270, 25, 12, 12};

SDL_Rect intersection30 = {206, 33, 12, 12};
SDL_Rect intersection34 = {238, 33, 12, 12};
SDL_Rect intersection37 = {270, 33, 12, 12};

SDL_Rect intersection40 = {206, 41, 12, 12};
SDL_Rect intersection41 = {214, 41, 12, 12};
SDL_Rect intersection42 = {222, 41, 12, 12};
SDL_Rect intersection43 = {230, 41, 12, 12};
SDL_Rect intersection44 = {238, 41, 12, 12};
SDL_Rect intersection45 = {254, 41, 12, 12};
SDL_Rect intersection46 = {262, 41, 12, 12};
SDL_Rect intersection47 = {270, 41, 12, 12};

int count;

int last_pressed_key = 0;
int current_direction = last_pressed_key;

bool intersection_detected = false;

// fonction qui met à jour la surface de la fenetre "win_surf"
void draw()
{
    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_bg, win_surf, &bg);

    // petit truc pour faire tourner le fantome
    SDL_Rect *ghost_in = nullptr;
    // switch (count / 128)
    // {
    // case 0:
    //     ghost_in = &(ghost_r);
    //     ghost.x++;
    //     break;
    // case 1:
    //     ghost_in = &(ghost_d);
    //     ghost.y++;
    //     break;
    // case 2:
    //     ghost_in = &(ghost_l);
    //     ghost.x--;
    //     break;
    // case 3:
    //     ghost_in = &(ghost_u);
    //     ghost.y--;
    //     break;
    // }
    if(intersection_detected)
    {
        current_direction = last_pressed_key;
        intersection_detected = false;
    }
    else
        intersection_detected = false;
    switch(current_direction)
    {
        case 0:
                ghost_in = &(ghost_r);
                ghost.x++;
            break;
        case 1:
                ghost_in = &(ghost_d);
                ghost.y++;
            break;
        case 2:
                ghost_in = &(ghost_l);
                ghost.x--;
            break;
        case 3:
                ghost_in = &(ghost_u);
                ghost.y--;
            break;
    }

    if(ghost.x == 34 && ghost.y == 34)
        {puts("intersection 00");
        intersection_detected = true;}
    if(ghost.x == 162 && ghost.y == 34)
    {
        puts("intersection 04");
        intersection_detected = true;
    }
    if(ghost.x == 162 && ghost.y == 162)
        {puts("intersection 44");
        intersection_detected = true;}
    if(ghost.x == 34 && ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    if(ghost.x == 34 && ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    if(ghost.x == 34 && ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    if(ghost.x == 34 && ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    if(ghost.x == 34 && ghost.y == 162)
        {puts("intersection 40");
        intersection_detected = true;}
    

    // std::cout<<"x : "<<ghost.x<<" y : "<<ghost.y<<"\n";
    count = (count + 1) % (512);

    // ici on change entre les 2 sprites sources pour une jolie animation.
    SDL_Rect ghost_in2 = *ghost_in;
    if ((count / 4) % 2)
        ghost_in2.x += 17;

    // couleur transparente
    SDL_SetColorKey(plancheSprites, true, 0);
    // copie du sprite zoomé
    SDL_BlitScaled(plancheSprites, &ghost_in2, win_surf, &ghost);
}

int main(int argc, char **argv)
{
    // à inclure dans la classs Window
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        return 1;
    }

    Window* window = new Window{};

    // BOUCLE PRINCIPALE
    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        // Gestion du clavier
        int nbk;
        const Uint8 *keys = SDL_GetKeyboardState(&nbk);
        if (keys[SDL_SCANCODE_ESCAPE])
            quit = true;
        if (keys[SDL_SCANCODE_LEFT])
        {
            last_pressed_key = 2;
            puts("LEFT");
        }
        if (keys[SDL_SCANCODE_RIGHT])
        {
            last_pressed_key = 0;
            puts("RIGHT");
        }
        if (keys[SDL_SCANCODE_UP])
        {
            last_pressed_key = 3;
            puts("UP");
        }
        if (keys[SDL_SCANCODE_DOWN])
        {
            last_pressed_key = 1;
            puts("DOWN");
        }

        // AFFICHAGE
        // draw();
        window->update();

        // SDL_UpdateWindowSurface(pWindow);
        // SDL_UpdateWindowSurface(window->get_pWindow());     

        // LIMITE A 60 FPS
        // SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
    }
    SDL_Quit(); // ON SORT
    return 0;
}
