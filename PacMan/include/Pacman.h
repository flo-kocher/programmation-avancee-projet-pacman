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
        int lifes_;

    public:
        Pacman();
        Pacman(CharacterName name, SDL_Rect position, SDL_Rect* image, Direction direction);
        ~Pacman();

        inline int getLifes()
        {
            return lifes_;
        }

        inline void setLifes(int remaining_lifes)
        {
            lifes_ = remaining_lifes;
        }

        inline void loseLife()
        {
            lifes_--;
        }
};

#endif