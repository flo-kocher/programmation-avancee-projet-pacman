#ifndef __BIGPELLET_H__
#define __BIGPELLET_H__

#include "Pellet.h"

/**
 * @brief Class for the BigPellets
 * 
 */
class BigPellet: public Pellet
{
    public:

    /**
     * @brief Construct a new Big Pellet object
     * 
     * @param init_x 
     * @param init_y 
     * @param init_has_pellet 
     */
        BigPellet(int init_x, int init_y, bool init_has_pellet);
        ~BigPellet();

        // Getter
        inline bool hasAdditionalBehavior()
        {
            return true;
        };

};

#endif