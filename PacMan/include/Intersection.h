#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Pellet.h"
#include "BigPellet.h"

template <class T>
class Intersection: public T
{
    private:
        bool path_right_;
        bool path_down_;
        bool path_left_;
        bool path_up_;

    public:
        Intersection(int init_x, int init_y, bool init_has_pellet, bool init_path_right, bool init_path_down, bool init_path_left, bool init_path_up);
        ~Intersection();

        inline bool canGoRight()
        {
            return path_right_;
        };
        inline bool canGoDown()
        {
            return path_down_;
        };
        inline bool canGoLeft()
        {
            return path_left_;
        };
        inline bool canGoUp()
        {
            return path_up_;
        };

};

#endif