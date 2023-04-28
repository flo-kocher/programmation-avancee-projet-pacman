#include "../include/Pellet.h"

Pellet::Pellet(SDL_Rect init_initial, int init_x, int init_y, SDL_Rect init_passed, bool init_has_pellet)
: Zone(init_initial, init_x, init_y)
, passed(init_passed)
, has_pellet(init_has_pellet)
, got_threw(true)
, points_earned(10)
{}

Pellet::~Pellet()
{

}