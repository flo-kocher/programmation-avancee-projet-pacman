#include "../include/Intersection.h"

template <>
Intersection<Pellet>::Intersection(int init_x, int init_y, bool init_has_pellet, bool init_path_right, bool init_path_down, bool init_path_left, bool init_path_up)
: Pellet(init_x, init_y, init_has_pellet)
, path_right_(init_path_right)
, path_down_(init_path_down)
, path_left_(init_path_left)
, path_up_(init_path_up)
{}

template <>
Intersection<BigPellet>::Intersection(int init_x, int init_y, bool init_has_pellet, bool init_path_right, bool init_path_down, bool init_path_left, bool init_path_up)
: BigPellet(init_x, init_y, init_has_pellet)
, path_right_(init_path_right)
, path_down_(init_path_down)
, path_left_(init_path_left)
, path_up_(init_path_up)
{}

template <>
Intersection<Pellet>::~Intersection()
{}

template <>
Intersection<BigPellet>::~Intersection()
{}
