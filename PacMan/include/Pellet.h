#ifndef __PELLET_H__
#define __PELLET_H__

#include "Zone.h"

class Pellet: public Zone
{
    private:
        SDL_Rect passed;
        bool got_threw;
        bool has_pellet;

    public:
        Pellet(SDL_Rect init_initial, std::string init_name, int init_x, int init_y, SDL_Rect init_passed);
        ~Pellet();

        inline SDL_Rect* getPassed()
        {
            return &passed;
        };

        inline bool getGotThrew()
        {
            return got_threw;
        };

        inline void setGotThrew(bool res)
        {
            got_threw = res;
        };
    
};

#endif