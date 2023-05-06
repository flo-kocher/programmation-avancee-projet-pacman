#include "../include/Character.h"
#include "../include/Constante.h"

Character::Character()
: speed_(2)
{}

Character::~Character()
{}

void Character::teleportRight()
{
    position_.x = 642;
    position_.y = 418;
}

void Character::teleportLeft()
{
    position_.x = 2;
    position_.y = 418;
}

void Character::goRight(int count)
{
    std::map<std::string, SDL_Rect*> character_images = getImagesMap();
    if (!((count / 8) % 2))
        character_image_ = character_images.find("RIGHT")->second;
    else
        character_image_ = character_images.find("RIGHT2")->second;
    position_.x += speed_;
}

void Character::goDown(int count)
{
    std::map<std::string, SDL_Rect*> character_images = getImagesMap();
    if (!((count / 8) % 2))
        character_image_ = character_images.find("DOWN")->second;
    else
        character_image_ = character_images.find("DOWN2")->second;
    position_.y += speed_;
}

void Character::goLeft(int count)
{
    std::map<std::string, SDL_Rect*> character_images = getImagesMap();
    if (!((count / 8) % 2))
        character_image_ = character_images.find("LEFT")->second;
    else
        character_image_ = character_images.find("LEFT2")->second;
    position_.x -= speed_;
}

void Character::goUp(int count)
{
    std::map<std::string, SDL_Rect*> character_images = getImagesMap();
    if (!((count / 8) % 2))
        character_image_ = character_images.find("UP")->second;
    else
        character_image_ = character_images.find("UP2")->second;
    position_.y -= speed_;
}

void Character::standStill()
{
    
}

std::map<std::string, SDL_Rect*> Character::getImagesMap()
{
    std::map<std::string, SDL_Rect*> map;

    switch(name_){
        case(PACMAN) :
            map = PACMAN_IMAGES; break;
        case(RED_GHOST) :
            map = RED_GHOST_IMAGES; break;
        case(PINK_GHOST) :
            map = PINK_GHOST_IMAGES; break;
        case(BLUE_GHOST) :
            map = BLUE_GHOST_IMAGES; break;
        case(YELLOW_GHOST) :
            map = YELLOW_GHOST_IMAGES; break;
        default: break;
    }

    return map;
}