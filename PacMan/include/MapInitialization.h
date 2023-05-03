#ifndef __MAP_INITIALIZATION_H__
#define __MAP_INITIALIZATION_H__

#include "Pellet.h"
#include "BigPellet.h"
#include "Intersection.h"
#include <map>
#include <memory>

void initPellets(std::map<std::string, std::shared_ptr<Pellet>> *pellets, std::map<std::string, std::shared_ptr<BigPellet>> *big_pellets);
void initIntersections(std::map<std::string, std::shared_ptr<Intersection<Pellet>>> *intersections, std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> *intersections_big);

#endif