#include "../include/Zone.h"

Zone::Zone(SDL_Rect init_initial, std::string init_name, int init_x, int init_y)
{
    initial = init_initial;
    name = init_name;
    x = init_x;
    y = init_y;
}

Zone::~Zone()
{

}