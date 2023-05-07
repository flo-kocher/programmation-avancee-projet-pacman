#ifndef __PELLET_H__
#define __PELLET_H__

#include "Zone.h"

/**
 * @brief Pellet class that can or cannot possess a regular pellet
 * 
 */
class Pellet: public Zone
{
    private:
        // true when PacMan passes once through this Pellet
        bool got_through_;
        // if the Pellet possesses a regular pellet
        bool has_pellet_;
    
    protected:
        // number of points earned when PacMan eats the pellet
        int points_earned_;

    public:

        /**
         * @brief Construct a new Pellet object
         * 
         * @param init_x 
         * @param init_y 
         * @param init_has_pellet 
         */
        Pellet(int init_x, int init_y, bool init_has_pellet);
        ~Pellet();

        // Getters
        inline bool getGotThrough()
        {
            return got_through_;
        };

        inline int addPoints()
        {
            return points_earned_;
        };

        inline bool hasPellet()
        {
            return has_pellet_;
        };

        //Setters
        inline void setHasPellet()
        {
            has_pellet_ = false;
        };

        inline void setGotThrough(bool res)
        {
            got_through_ = res;
        };

        inline bool hasAdditionalBehavior()
        {
            return false;
        };
    
};

#endif