#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SDL.h>
#include "Character.h"
#include "Zone.h"
#include "Pellet.h"
#include "BigPellet.h"
#include <map>

// struct playArea {
//         std::map<std::string, Zone*> zones;
//         std::map<std::string, Pellet*> pellets;
//         std::map<std::string, BigPellet*> big_pellets;
// };

class GameManager
{
    public:
        GameManager();
        ~GameManager();
    
};

#endif