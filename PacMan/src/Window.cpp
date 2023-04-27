#include "../include/Window.h"
#include <iostream>

#include <SDL.h>

    // et dans Windows, on va appeler genre Manager->initArea()
    // puis Manager->updateArea() etc...
    // dans Windows on va juste appeler des 'évènements', sans utiliser de "vrais" données 

    // gameManager = new GameManager{}; // Ancienne manière d'init gameManager

Window::Window()
: gameManager(std::make_unique<GameManager>())
, ghost (std::make_unique<Character>())
, direction_tmp (0)
, intersection_detected (false)
, last_pressed_key(0)
{}

Window::~Window()
{

}

void Window::update()
{
    if(intersection_detected)
    {
        direction_tmp = last_pressed_key;
        intersection_detected = false;
    }
    else
        intersection_detected = false;

    switch(direction_tmp)
    {
        case 0:
            ghost->turnRight();
            break;
        case 1:
            ghost->turnDown();
            break;
        case 2:
            ghost->turnLeft();
            break;
        case 3:
            ghost->turnUp();
            break;
        case -1:
            ghost->standStill();
            break;
    }

    // ghost.x et ghost.y : position en temps réel du ghost
    gameManager->checkForZone(ghost->ghost.x, ghost->ghost.y);
    gameManager->checkForPellet(ghost->ghost.x, ghost->ghost.y);
    if(gameManager->checkForIntersection(ghost->ghost.x, ghost->ghost.y, last_pressed_key) == 1)
        intersection_detected = true;
    else if(gameManager->checkForIntersection(ghost->ghost.x, ghost->ghost.y, last_pressed_key) == 2)
        direction_tmp = -1;
    
    gameManager->updateInterface(ghost->getGhost(), ghost->getGhostIn());
}
