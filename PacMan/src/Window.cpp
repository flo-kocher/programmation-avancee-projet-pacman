#include "../include/Window.h"
#include <iostream>

#include <SDL.h>

    // et dans Windows, on va appeler genre Manager->initArea()
    // puis Manager->updateArea() etc...
    // dans Windows on va juste appeler des 'évènements', sans utiliser de "vrais" données 

    // gameManager = new GameManager{}; // Ancienne manière d'init gameManager

Window::Window()
: gameManager(std::make_unique<GameManager>())
// , characters ({std::make_unique<Pacman>(), std::make_shared<Ghost>(), std::make_shared<Ghost>(), std::make_shared<Ghost>(), std::make_shared<Ghost>()})
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
            gameManager->characters[0]->turnRight(gameManager->getCount());
            break;
        case 1:
            gameManager->characters[0]->turnDown(gameManager->getCount());
            break;
        case 2:
            gameManager->characters[0]->turnLeft(gameManager->getCount());
            break;
        case 3:
            gameManager->characters[0]->turnUp(gameManager->getCount());
            break;
        case -1:
            gameManager->characters[0]->standStill();
            break;
    }

    // position_.x et position_.y : position en temps réel du gameManager->characters[0]
    gameManager->checkForZone(gameManager->characters[0]->position_.x, gameManager->characters[0]->position_.y);
    int pellet_number = gameManager->checkForPellet(gameManager->characters[0]->position_.x, gameManager->characters[0]->position_.y);
    if(pellet_number == 0)
        gameManager->characters[0]->teleportRight();
    if(pellet_number == 18)
        gameManager->characters[0]->teleportLeft();
    if(gameManager->checkForIntersection(gameManager->characters[0]->position_.x, gameManager->characters[0]->position_.y, last_pressed_key) == 1)
        intersection_detected = true;
    else if(gameManager->checkForIntersection(gameManager->characters[0]->position_.x, gameManager->characters[0]->position_.y, last_pressed_key) == 2)
        direction_tmp = -1;
    
    gameManager->updateInterface();

    return false;
}
