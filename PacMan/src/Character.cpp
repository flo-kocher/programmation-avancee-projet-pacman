#include "../include/Character.h"

Character::Character()
{
    ghost_in = nullptr;
}

Character::~Character()
{

}

void Character::turn_right()
{
    ghost_in = &(ghost_r);
    ghost.x++;
}

void Character::turn_down()
{
    ghost_in = &(ghost_d);
    ghost.y++;
}

void Character::turn_left()
{
    ghost_in = &(ghost_l);
    ghost.x--;
}

void Character::turn_up()
{
    ghost_in = &(ghost_u);
    ghost.y--;
}
