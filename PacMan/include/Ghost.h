#ifndef __GHOST_H__
#define __GHOST_H__

#include <SDL.h>
#include "Character.h"
#include "Constante.h"
#include <iostream>
#include <memory>

class Ghost : public Character
{
    private:
        std::pair<int, int> target; //x et y cible

    public:
        Ghost();
        Ghost(CharacterName name, SDL_Rect position, std::shared_ptr<SDL_Rect> image);
       // Ghost(CharacterName name, SDL_Rect position, std::shared_ptr<SDL_Rect> image, std::pair<int, int> target);
        ~Ghost();
    
};

#endif