#include "../include/Character.h"
#include "../include/Constante.h"

Character::Character()
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
    setImage(count, "RIGHT");
    position_.x++;
}

void Character::goDown(int count)
{
    setImage(count, "DOWN");
    position_.y++;
}

void Character::goLeft(int count)
{
    setImage(count, "LEFT");
    position_.x--;
}

void Character::goUp(int count)
{
    setImage(count, "UP");
    position_.y--;
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

void Character::setImage(int count, std::string direction)
{
    std::map<std::string, SDL_Rect*> character_images = getImagesMap();
    if (!((count / 8) % 2))
        character_image_ = character_images.find(direction)->second;
    else
        character_image_ = character_images.find(direction.append("2"))->second;
}