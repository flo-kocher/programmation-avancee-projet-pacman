#ifndef __BIGPELLET_H__
#define __BIGPELLET_H__

#include "Pellet.h"

class BigPellet: public Pellet
{
    public:
        BigPellet(int init_x, int init_y, bool init_has_pellet);
        ~BigPellet();

};

#endif