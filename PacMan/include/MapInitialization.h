#ifndef __MAP_INITIALIZATION_H__
#define __MAP_INITIALIZATION_H__

#include "Pellet.h"
#include "BigPellet.h"
#include "Intersection.h"
#include <map>
#include <memory>

/**
 * @brief This file is used to separate all the mapping initialization from the GameManager
 * For a clearer visualization of the different objects, the zones_numbering.ods is there to help understanding
 * how we chose our numbering
 * 
 */

/**
 * @brief 
 * 
 * @param pellets the pellets map inside the GameManager
 * @param big_pellets the big_pellets map inside the GameManager
 */
void initPellets(std::map<std::string, std::shared_ptr<Pellet>> *pellets, std::map<std::string, std::shared_ptr<BigPellet>> *big_pellets);

/**
 * @brief 
 * 
 * @param intersections the intersections map inside the GameManager
 * @param intersections_big the intersections_big map inside the GameManager
 */
void initIntersections(std::map<std::string, std::shared_ptr<Intersection<Pellet>>> *intersections, std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> *intersections_big);

#endif