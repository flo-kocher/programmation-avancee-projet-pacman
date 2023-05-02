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

bool Window::update()
{
    if(gameManager->isGameOver())
    {
        std::cout<<"FINITO"<<std::endl;
        return true;
    }

    if(intersection_detected || last_pressed_key == 0 && direction_tmp == 2 || last_pressed_key == 2 && direction_tmp == 0 || last_pressed_key == 1 && direction_tmp == 3 || last_pressed_key == 3 && direction_tmp == 1)
    {
        direction_tmp = last_pressed_key;
        intersection_detected = false;
    }
    else
        intersection_detected = false;

    switch(direction_tmp)
    {
        case RIGHT:
            ghost->turnRight(gameManager->getCount());
            break;
        case DOWN:
            ghost->turnDown(gameManager->getCount());
            break;
        case LEFT:
            ghost->turnLeft(gameManager->getCount());
            break;
        case UP:
            ghost->turnUp(gameManager->getCount());
            break;
        case -1:
            ghost->standStill();
            break;
    }

    // ghost.x et ghost.y : position en temps réel du ghost
    int pellet_number = gameManager->checkForPellet(ghost->ghost.x, ghost->ghost.y);
    if(pellet_number == 0)
        ghost->teleportRight();
    if(pellet_number == 18)
        ghost->teleportLeft();
    if(gameManager->checkForIntersection(ghost->ghost.x, ghost->ghost.y, last_pressed_key) == 1)
        intersection_detected = true;
    else if(gameManager->checkForIntersection(ghost->ghost.x, ghost->ghost.y, last_pressed_key) == 2)
        direction_tmp = -1;
    
    gameManager->updateInterface(ghost->getGhost(), ghost->getGhostIn());

    return false;
}
