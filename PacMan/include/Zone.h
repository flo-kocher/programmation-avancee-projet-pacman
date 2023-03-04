#ifndef __ZONE_H__
#define __ZONE_H__

#include <SDL.h>
#include <iostream>

class Zone
{
    private:
        SDL_Rect initial;
        std::string name;

    protected:
        Zone(SDL_Rect init_initial, std::string init_name);
        ~Zone();
    
};

#endif