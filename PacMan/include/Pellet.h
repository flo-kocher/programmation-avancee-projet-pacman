#ifndef __PELLET_H__
#define __PELLET_H__

#include "Zone.h"

class Pellet: public Zone
{
    private:
        bool got_threw_;
        bool has_pellet_;
    
    protected:
        int points_earned_;

    public:
        Pellet(int init_x, int init_y, bool init_has_pellet);
        ~Pellet();

        inline bool getGotThrough()
        {
            return got_threw_;
        };

        inline void setGotThrew(bool res)
        {
            got_threw_ = res;
        };

        inline bool hasPellet()
        {
            return has_pellet_;
        };

        inline void setHasPellet()
        {
            has_pellet_ = false;
        };

        inline int addPoints()
        {
            return points_earned_;
        };
    
};

#endif