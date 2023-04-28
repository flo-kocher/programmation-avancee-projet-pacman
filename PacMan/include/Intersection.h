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
        Intersection(SDL_Rect init_initial, int init_x, int init_y, SDL_Rect init_passed, bool init_has_pellet, bool path_right_available, bool path_down_available, bool path_left_available, bool path_up_available);
        ~Intersection();

        inline bool canGoRight()
        {
            return path_right;
        };
        inline bool canGoDown()
        {
            return path_down;
        };
        inline bool canGoLeft()
        {
            return path_left;
        };
        inline bool canGoUp()
        {
            return path_up;
        };

};

#endif