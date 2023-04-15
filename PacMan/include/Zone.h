#ifndef __ZONE_H__
#define __ZONE_H__

#include <SDL.h>
#include <iostream>

class Zone
{
    private:
        // la zone de base
        SDL_Rect initial;
        // positions de cette zone
        // int x;
        // int y;

    public:
        Zone(SDL_Rect init_initial, int init_x, int init_y);
        ~Zone();
        int x; // tmp ici !
        int y; // tmp ici !

};

#endif