#ifndef __INTERSECTION_TEMPLATE_H__
#define __INTERSECTION_TEMPLATE_H__

#include "Pellet.h"
#include "BigPellet.h"

template <class T>
class IntersectionTemplate: public T
{
    private:
        bool path_right;
        bool path_down;
        bool path_left;
        bool path_up;

    public:
        IntersectionTemplate(SDL_Rect init_initial, int init_x, int init_y, SDL_Rect init_passed, bool init_has_pellet, bool init_path_right, bool init_path_down, bool init_path_left, bool init_path_up)
        : T(init_initial, init_x, init_y, init_passed, init_has_pellet)
        , path_right(init_path_right)
        , path_down(init_path_down)
        , path_left(init_path_left)
        , path_up(init_path_up)
        {};

        ~IntersectionTemplate()
        {
        
        };
        
        // IntersectionTemplate(SDL_Rect init_initial, int init_x, int init_y, SDL_Rect init_passed, bool init_has_pellet, bool path_right_available, bool path_down_available, bool path_left_available, bool path_up_available);
        // ~IntersectionTemplate();

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