#include <SDL.h>

#include "../include/KeyboardManager.h"

KeyboardManager::KeyboardManager()
{}

KeyboardManager::~KeyboardManager()
{

}

int KeyboardManager::waitForEvent()
{
    // Gestion du clavier
    int nbk;
    const Uint8 *keys = SDL_GetKeyboardState(&nbk);
    if (keys[SDL_SCANCODE_ESCAPE])
        return -1;
    if (keys[SDL_SCANCODE_LEFT])
    {
        return LEFT;
    }
    if (keys[SDL_SCANCODE_RIGHT])
    {
        return RIGHT;
    }
    if (keys[SDL_SCANCODE_UP])
    {
        return UP;
    }
    if (keys[SDL_SCANCODE_DOWN])
    {
        return DOWN;
    }

    return 10;
}
