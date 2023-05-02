#include "../include/Character.h"

Character::Character()
: ghost_in(nullptr)
{}

Character::~Character()
{

}

void Character::teleportRight()
{
    ghost.x = 642;
    ghost.y = 418;
}

void Character::teleportLeft()
{
    ghost.x = 2;
    ghost.y = 418;
}
