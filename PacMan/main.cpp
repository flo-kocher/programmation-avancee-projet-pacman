// #include <SDL.h>

#include "include/Window.h"
#include "include/KeyboardManager.h"

#include <iostream>

int main(int argc, char **argv)
{
    std::unique_ptr<Window> window = std::make_unique<Window>();
    std::unique_ptr<KeyboardManager> kb_manager = std::make_unique<KeyboardManager>();
    int keyboard_event;

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

        keyboard_event = kb_manager->waitForEvent();
        switch (keyboard_event)
        {
        case -1:
            quit = true;
            break;
        case 0:
            window->setDirectionLeft();
            break;
        case 1:
            window->setDirectionRight();
            break;
        case 2:
            window->setDirectionUp();
            break;
        case 3:
            window->setDirectionDown();
            break;
        default:
            // Do nothing
            break;
        }

        // AFFICHAGE
        if(window->update())
            quit = true;
    }
    SDL_Quit(); // ON SORT
    return 0;
}
