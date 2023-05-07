#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Pellet.h"
#include "BigPellet.h"

/**
 * @brief 
 * 
 * @tparam T An Intersection can derive from a Pellet or a BigPellet
 */
template <class T>
class Intersection: public T
{
    private:
        // Paths possible on the Intersection
        bool path_right_;
        bool path_down_;
        bool path_left_;
        bool path_up_;

    public:

        /**
         * @brief Construct a new Intersection object
         * 
         * @param init_x 
         * @param init_y 
         * @param init_has_pellet if the Intersection has a pellet on it
         * @param init_path_right true if a path is possible on the right else false
         * @param init_path_down true if a path is possible under else false
         * @param init_path_left true if a path is possible on the left else false
         * @param init_path_up true if a path is possible up else false
         */
        Intersection(int init_x, int init_y, bool init_has_pellet, bool init_path_right, bool init_path_down, bool init_path_left, bool init_path_up);
        ~Intersection();

        // Getters
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