#include "../include/Pellet.h"

Pellet::Pellet(int init_x, int init_y, bool init_has_pellet)
: Zone(init_x, init_y)
, has_pellet_(init_has_pellet)
, got_through_(true)
, points_earned_(10)
{}

Pellet::~Pellet()
{}