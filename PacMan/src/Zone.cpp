#include "../include/Zone.h"

/**
 * @brief Construct a new Zone:: Zone object
 * The width and length of the zone is always 32
 * 
 * @param init_x 
 * @param init_y 
 */
Zone::Zone(int init_x, int init_y)
: x_(init_x)
, y_(init_y)
, rect_({init_x, init_y, 32, 32})
{}

Zone::~Zone()
{}