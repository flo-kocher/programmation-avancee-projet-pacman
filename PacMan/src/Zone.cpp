#include "../include/Zone.h"

Zone::Zone()
{

}

Zone::Zone(int coord_x, int coord_y, bool has_pellet)
{
    x = coord_x;
    y = coord_y;
    pellet = has_pellet;
}

Zone::~Zone()
{

}