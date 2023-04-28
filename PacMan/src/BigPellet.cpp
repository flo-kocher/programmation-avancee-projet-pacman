#include "../include/BigPellet.h"

BigPellet::BigPellet(SDL_Rect init_initial, int init_x, int init_y, SDL_Rect init_passed, bool init_has_pellet)
: Pellet(init_initial, init_x, init_y, init_passed, init_has_pellet)
{
    points_earned = 50;
}

BigPellet::~BigPellet()
{

}