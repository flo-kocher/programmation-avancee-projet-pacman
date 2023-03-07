#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SDL.h>
#include "Character.h"
#include "Zone.h"
#include "Pellet.h"
#include "BigPellet.h"
#include "Intersection.h"
#include <map>

class GameManager
{
    private:
        std::map<std::string, Zone*> zones;
        std::map<std::string, Pellet*> pellets;
        std::map<std::string, BigPellet*> big_pellets;
        std::map<std::string, Intersection*> intersections;

    public:
        GameManager();
        ~GameManager();

        void checkForZone(int x, int y);
        void checkForPellet(int x, int y);
        void checkForIntersection(int x, int y);
    
};

#endif