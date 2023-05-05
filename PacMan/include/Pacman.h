#ifndef __PACMAN_H__
#define __PACMAN_H__

#include <SDL.h>
#include "Character.h"
#include "Constante.h"
#include <iostream>
#include <memory>

class Pacman : public Character
{
    private:
        int life_;

    public:
        Pacman();
        Pacman(CharacterName name, SDL_Rect position, SDL_Rect* image, Direction direction);
        ~Pacman();
};

#endif