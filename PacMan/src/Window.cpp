#include "../include/Window.h"
#include <iostream>

#include <SDL.h>

    // et dans Windows, on va appeler genre Manager->initArea()
    // puis Manager->updateArea() etc...
    // dans Windows on va juste appeler des 'évènements', sans utiliser de "vrais" données 

    // gameManager_ = new gameManager_{}; // Ancienne manière d'init gameManager_

Window::Window()
: gameManager_(std::make_unique<GameManager>())
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
        case 0:
            gameManager_->characters[0]->turnRight(gameManager_->getCount());
            break;
        case 1:
            gameManager_->characters[0]->turnDown(gameManager_->getCount());
            break;
        case 2:
            gameManager_->characters[0]->turnLeft(gameManager_->getCount());
            break;
        case 3:
            gameManager_->characters[0]->turnUp(gameManager_->getCount());
            break;
        case -1:
            gameManager_->characters[0]->standStill();
            break;
    }

    int character_position;
    if(character_position = gameManager_->collisionWithGhost() > 0)
    {
        // Donner à chaque Ghost une zone où laquelle respawn
        gameManager_->characters[character_position]->position_.x = 250;
        gameManager_->characters[character_position]->position_.y = 34;
    }

    int pellet_number = gameManager_->checkForPellet(gameManager_->characters[0]->position_.x, gameManager_->characters[0]->position_.y);
    if(pellet_number == 0)
        gameManager_->characters[0]->teleportRight();
    if(pellet_number == 18)
        gameManager_->characters[0]->teleportLeft();
    if(gameManager_->checkForIntersection(gameManager_->characters[0]->position_.x, gameManager_->characters[0]->position_.y, last_pressed_key_) == 1)
        intersection_detected_ = true;
    else if(gameManager_->checkForIntersection(gameManager_->characters[0]->position_.x, gameManager_->characters[0]->position_.y, last_pressed_key_) == 2)
        direction_tmp_ = -1;
    
    gameManager_->updateInterface();

    return false;
}
