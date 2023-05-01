// #include <SDL.h>

#include "include/Window.h"

#include <iostream>

int main(int argc, char **argv)
{
    std::unique_ptr<Window> window = std::make_unique<Window>();

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
            window->setDirectionLeft();
        }
        if (keys[SDL_SCANCODE_RIGHT])
        {
            window->setDirectionRight();
        }
        if (keys[SDL_SCANCODE_UP])
        {
            window->setDirectionUp();
        }
        if (keys[SDL_SCANCODE_DOWN])
        {
            window->setDirectionDown();
        }

        // AFFICHAGE
        window->update();
    }
    SDL_Quit(); // ON SORT
    return 0;
}
