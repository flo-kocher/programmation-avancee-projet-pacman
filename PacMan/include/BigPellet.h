#ifndef __BIGPELLET_H__
#define __BIGPELLET_H__

#include "Pellet.h"

class BigPellet: public Pellet
{
    public:
        BigPellet(SDL_Rect init_initial, int init_x, int init_y, SDL_Rect init_passed, bool init_has_pellet);
        ~BigPellet();

};

#endif