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
        int lifes_; //Number of lifes pacman currently has

    public:
        /**
         * @brief Construct a new Ghost object
         * 
         */
        Pacman();
        Pacman(CharacterName name, SDL_Rect position, SDL_Rect* image, Direction direction);
        ~Pacman();

        /**
         * @brief Makes Pacman lose a life
         * 
         */
        inline void loseLife()
        {
            lifes_--;
        }

        //Getter
        inline int getLifes()
        {
            return lifes_;
        }

        //Setter
        inline void setLifes(int remaining_lifes)
        {
            lifes_ = remaining_lifes;
        }


};

#endif