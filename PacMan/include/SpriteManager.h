#ifndef __SPRITE_MANAGER_H__
#define __SPRITE_MANAGER_H__

#include <SDL.h>
#include "Character.h"

class SpriteManager
{
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

    public:
    SpriteManager();
    ~SpriteManager();
    
};

#endif