#ifndef __ZONE_H__
#define __ZONE_H__

#include <SDL.h>

/**
 * @brief The Zone class represent à zone where the PacMan and the ghosts can travel,
 * the walls don't count as zones
 * 
 */
class Zone
{
    private:
        // The rectangle representing the zone
        SDL_Rect rect_;
        // The positions of the zones in the bitmap
        int x_;
        int y_;

    public:
        /**
         * @brief Construct a new Zone object
         * 
         * @param init_x x position
         * @param init_y y position
         */
        Zone(int init_x, int init_y);
        ~Zone();

        // Getters
        inline SDL_Rect* getRectangle()
        {
            return &rect_;
        };

        inline int getX()
        {
            return x_;
        };

        inline int getY()
        {
            return y_;
        };

        // Setters
        inline void setX(int x)
        {
            x_ = x;
        };

        inline void setY(int y)
        {
            y_ = y;
        };

};

#endif