#include "../include/Zone.h"

Zone::Zone(int init_x, int init_y)
: x_(init_x)
, y_(init_y)
, rect_({init_x, init_y, 32, 32})
{}

Zone::~Zone()
{

}