#include "../include/Pellet.h"

Pellet::Pellet(int init_x, int init_y, bool init_has_pellet)
: Zone(init_x, init_y)
, has_pellet(init_has_pellet)
, got_threw(true)
, points_earned(10)
{}

Pellet::~Pellet()
{

}