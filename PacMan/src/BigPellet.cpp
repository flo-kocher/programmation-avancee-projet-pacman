#include "../include/BigPellet.h"

BigPellet::BigPellet(int init_x, int init_y, bool init_has_pellet)
: Pellet(init_x, init_y, init_has_pellet)
{
    points_earned_ = 50;
}

BigPellet::~BigPellet()
{

}