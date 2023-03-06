#include "../include/GameManager.h"
#include <iostream>

#include <SDL.h>

GameManager::GameManager()
{
    // fonctionne : test = new Pellet{{206, 9, 12, 12}, "Intersection 00", {207, 9, 12, 12}, true};
    // il vaudrait mieux créer une classe qui va faire toutes ces insertions
    // et qui va aussi update les valuers ou les chercher quand il faudra
    // du coup peut être faire une classe où dedans on déclare les maps d'objets, plutot que 
    // de faire une structure en fait
    // et dans Windows, on va appeler genre Manager->initArea()
    // puis Manager->updateArea() etc...
    // dans Windows on va juste appeler des 'évènements', sans utiliser de "vrais" données 
    // PacManArea.zones.insert({"Zone 1", new Zone{{206, 9, 12, 12}, "Zone 1"}});
    // PacManArea.zones.insert({"Zone 2", new Zone{{207, 9, 12, 12}, "Zone 2"}});
    // PacManArea.zones.insert({"Zone 3", new Zone{{208, 9, 12, 12}, "Zone 3"}});
}


GameManager::~GameManager()
{

}

