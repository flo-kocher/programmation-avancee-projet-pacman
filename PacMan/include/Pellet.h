#ifndef __PELLET_H__
#define __PELLET_H__

#include "Zone.h"

class Pellet: public Zone
{
    private:
        SDL_Rect passed;
        bool has_pellet;

    protected:
        Pellet();
        ~Pellet();
    
};

#endif