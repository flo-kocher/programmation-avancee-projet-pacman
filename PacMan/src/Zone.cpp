#include "../include/Zone.h"

Zone::Zone(SDL_Rect init_initial, std::string init_name)
{
    initial = init_initial;
    name = init_name;
}

Zone::~Zone()
{

}