#include "../include/Intersection.h"

Intersection::Intersection(SDL_Rect init_initial, int init_x, int init_y, SDL_Rect init_passed, bool init_has_pellet, bool init_path_right, bool init_path_down, bool init_path_left, bool init_path_up)
: Pellet(init_initial, init_x, init_y, init_passed, init_has_pellet)
, path_right(init_path_right)
, path_down(init_path_down)
, path_left(init_path_left)
, path_up(init_path_up)
{}

Intersection::~Intersection()
{

}