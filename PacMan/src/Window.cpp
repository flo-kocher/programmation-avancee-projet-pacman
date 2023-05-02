#include "../include/Window.h"
#include <iostream>

#include <SDL.h>

    // et dans Windows, on va appeler genre Manager->initArea()
    // puis Manager->updateArea() etc...
    // dans Windows on va juste appeler des 'évènements', sans utiliser de "vrais" données 

    // gameManager_ = new gameManager_{}; // Ancienne manière d'init gameManager_

Window::Window()
: gameManager_(std::make_unique<GameManager>())
, ghost_ (std::make_unique<Character>())
, direction_tmp_ (0)
, intersection_detected_ (false)
, last_pressed_key_(0)
{}

Window::~Window()
{

}

bool Window::update()
{
    if(gameManager_->isGameOver())
    {
        std::cout<<"FINITO"<<std::endl;
        return true;
    }

    if(intersection_detected_ || last_pressed_key_ == 0 && direction_tmp_ == 2 || last_pressed_key_ == 2 && direction_tmp_ == 0 || last_pressed_key_ == 1 && direction_tmp_ == 3 || last_pressed_key_ == 3 && direction_tmp_ == 1)
    {
        direction_tmp_ = last_pressed_key_;
        intersection_detected_ = false;
    }
    else
        intersection_detected_ = false;

    switch(direction_tmp_)
    {
        case RIGHT:
            ghost_->turnRight(gameManager_->getCount());
            break;
        case DOWN:
            ghost_->turnDown(gameManager_->getCount());
            break;
        case LEFT:
            ghost_->turnLeft(gameManager_->getCount());
            break;
        case UP:
            ghost_->turnUp(gameManager_->getCount());
            break;
        case -1:
            ghost_->standStill();
            break;
    }

    // ghost_.x et ghost_.y : position en temps réel du ghost_
    int pellet_number = gameManager_->checkForPellet(ghost_->ghost.x, ghost_->ghost.y);
    if(pellet_number == 0)
        ghost_->teleportRight();
    if(pellet_number == 18)
        ghost_->teleportLeft();
    if(gameManager_->checkForIntersection(ghost_->ghost.x, ghost_->ghost.y, last_pressed_key_) == 1)
        intersection_detected_ = true;
    else if(gameManager_->checkForIntersection(ghost_->ghost.x, ghost_->ghost.y, last_pressed_key_) == 2)
        direction_tmp_ = -1;
    
    gameManager_->updateInterface(ghost_->getGhost(), ghost_->getGhostIn());

    return false;
}
