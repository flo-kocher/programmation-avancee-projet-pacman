#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Pellet.h"

class Intersection: public Pellet
{
    private:
        bool path_right;
        bool path_down;
        bool path_left;
        bool path_up;

    public:
        Intersection(SDL_Rect init_initial, std::string init_name, SDL_Rect init_passed, bool path_right_available, bool path_down_available, bool path_left_available, bool path_up_available);
        ~Intersection();

};

#endif