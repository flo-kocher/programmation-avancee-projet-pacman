#include "../include/Zone.h"

Zone::Zone(int init_x, int init_y)
: x(init_x)
, y(init_y)
, rect({init_x, init_y, 32, 32})
{}

Zone::~Zone()
{

}