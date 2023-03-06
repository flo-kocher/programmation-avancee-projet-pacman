#include "../include/Pellet.h"

Pellet::Pellet(SDL_Rect init_initial, std::string init_name, SDL_Rect init_passed): Zone(init_initial, init_name)
{
    passed = init_passed;
    has_pellet = true;
}

Pellet::~Pellet()
{

}