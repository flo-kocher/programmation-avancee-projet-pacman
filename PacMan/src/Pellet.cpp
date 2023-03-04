#include "../include/Pellet.h"

Pellet::Pellet(SDL_Rect init_initial, std::string init_name, SDL_Rect init_passed, bool init_has_pellet): Zone(init_initial, init_name)
{
    passed = init_passed;
    has_pellet = init_has_pellet;
}

Pellet::~Pellet()
{

}