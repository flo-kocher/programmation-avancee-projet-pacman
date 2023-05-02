#include "../include/Character.h"

Character::Character()
: ghost_in(nullptr)
{}

Character::~Character()
{

}

void Character::teleportRight()
{
    ghost.x = 610;
    ghost.y = 418;
}

void Character::teleportLeft()
{
    ghost.x = 34;
    ghost.y = 418;
}
