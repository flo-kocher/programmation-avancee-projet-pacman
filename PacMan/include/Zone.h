#ifndef __ZONE_H__
#define __ZONE_H__

#include <SDL.h>
#include <iostream>

class Zone
{
    private:
        // la zone de base
        SDL_Rect rect_;
        int x_;
        int y_;

    public:

        Zone(int init_x, int init_y);
        ~Zone();

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