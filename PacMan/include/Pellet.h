#ifndef __PELLET_H__
#define __PELLET_H__

#include "Zone.h"

class Pellet: public Zone
{
    private:
        SDL_Rect passed;
        bool got_threw;
        bool has_pellet;
    
    protected:
        int points_earned;

    public:
        Pellet(int init_x, int init_y, bool init_has_pellet);
        ~Pellet();

        inline bool getGotThrough()
        {
            return got_threw;
        };

        inline void setGotThrew(bool res)
        {
            got_threw = res;
        };

        inline bool hasPellet()
        {
            return has_pellet;
        };

        inline void setHasPellet()
        {
            has_pellet = false;
        };

        inline int addPoints()
        {
            return points_earned;
        };
    
};

#endif