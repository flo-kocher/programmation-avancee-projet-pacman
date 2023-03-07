#include "../include/Pellet.h"

Pellet::Pellet(SDL_Rect init_initial, std::string init_name, int init_x, int init_y, SDL_Rect init_passed): Zone(init_initial, init_name, init_x, init_y)
{
    passed = init_passed;
    has_pellet = true;
}

Pellet::~Pellet()
{

}