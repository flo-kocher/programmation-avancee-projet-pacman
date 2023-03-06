#include "../include/GameManager.h"
#include <iostream>

#include <SDL.h>

    // // intersections
    // SDL_Rect intersection00 = {206, 9, 12, 12};
    // SDL_Rect intersection01 = {214, 9, 12, 12};
    // SDL_Rect intersection02 = {222, 9, 12, 12};
    // SDL_Rect intersection03 = {230, 9, 12, 12};
    // SDL_Rect intersection04 = {238, 9, 12, 12};
    // SDL_Rect intersection05 = {254, 9, 12, 12};
    // SDL_Rect intersection06 = {262, 9, 12, 12};
    // SDL_Rect intersection07 = {270, 9, 12, 12};

    // SDL_Rect intersection10 = {206, 17, 12, 12};
    // SDL_Rect intersection14 = {238, 17, 12, 12};
    // SDL_Rect intersection17 = {270, 17, 12, 12};

    // SDL_Rect intersection20 = {206, 25, 12, 12};
    // SDL_Rect intersection24 = {238, 25, 12, 12};
    // SDL_Rect intersection27 = {270, 25, 12, 12};

    // SDL_Rect intersection30 = {206, 33, 12, 12};
    // SDL_Rect intersection34 = {238, 33, 12, 12};
    // SDL_Rect intersection37 = {270, 33, 12, 12};

    // SDL_Rect intersection40 = {206, 41, 12, 12};
    // SDL_Rect intersection41 = {214, 41, 12, 12};
    // SDL_Rect intersection42 = {222, 41, 12, 12};
    // SDL_Rect intersection43 = {230, 41, 12, 12};
    // SDL_Rect intersection44 = {238, 41, 12, 12};
    // SDL_Rect intersection45 = {254, 41, 12, 12};
    // SDL_Rect intersection46 = {262, 41, 12, 12};
    // SDL_Rect intersection47 = {270, 41, 12, 12};

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

    zones.insert({"Zone 1", new Zone{{206, 9, 12, 12}, "Zone 1"}});
    zones.insert({"Zone 2", new Zone{{206, 9, 12, 12}, "Zone 2"}});
    zones.insert({"Zone 3", new Zone{{206, 9, 12, 12}, "Zone 3"}});
    zones.insert({"Zone 4", new Zone{{206, 9, 12, 12}, "Zone 4"}});
    zones.insert({"Zone 5", new Zone{{206, 9, 12, 12}, "Zone 5"}});

    pellets.insert({"Pellet 1", new Pellet{{206, 9, 12, 12}, "Pellet 1", {200, 9, 12, 12}}});
    pellets.insert({"Pellet 2", new Pellet{{206, 9, 12, 12}, "Pellet 2", {200, 9, 12, 12}}});
    pellets.insert({"Pellet 3", new Pellet{{206, 9, 12, 12}, "Pellet 3", {200, 9, 12, 12}}});
    pellets.insert({"Pellet 4", new Pellet{{206, 9, 12, 12}, "Pellet 4", {200, 9, 12, 12}}});

    // big_pellets.insert({"BiPellet 1", new BigPellet{{206, 9, 12, 12}, "BigPellet 1", {200, 9, 12, 12}}});

    intersections.insert({"Intersection 1", new Intersection{{206, 9, 12, 12}, "Intersection 1", {1, 1, 1, 11}, true, true, true, true}});
    intersections.insert({"Intersection 2", new Intersection{{214, 9, 12, 12}, "Intersection 2", {1, 1, 1, 11}, true, true, true, true}});
    intersections.insert({"Intersection 3", new Intersection{{222, 9, 12, 12}, "Intersection 3", {1, 1, 1, 11}, true, true, true, true}});
    intersections.insert({"Intersection 4", new Intersection{{230, 9, 12, 12}, "Intersection 4", {1, 1, 1, 11}, true, true, true, true}});
}


GameManager::~GameManager()
{

}

