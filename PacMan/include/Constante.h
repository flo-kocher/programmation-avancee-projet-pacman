#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__

#include <SDL.h>
#include <map>
#include <iostream>
#include <vector>

#ifdef __unix__
    #define SPRITES_PATH "./pacman_sprites.bmp"
#elif defined(_WIN32) || defined(WIN32)
    #define SPRITES_PATH "../pacman_sprites.bmp"
#endif

enum CharacterName { PACMAN, RED_GHOST, PINK_GHOST, BLUE_GHOST, YELLOW_GHOST };

// Coordonnées Sprite Pacman
const std::map<std::string, std::shared_ptr<SDL_Rect>> PACMAN_IMAGES = {
    {"RIGHT", std::make_shared<SDL_Rect>(SDL_Rect{19, 89, 16, 16})},
    {"RIGHT2", std::make_shared<SDL_Rect>(SDL_Rect{34, 89, 14, 16})},
    {"LEFT", std::make_shared<SDL_Rect>(SDL_Rect{46, 89, 16, 16})},
    {"LEFT2", std::make_shared<SDL_Rect>(SDL_Rect{61, 89, 14, 16})},
    {"UP", std::make_shared<SDL_Rect>(SDL_Rect{75, 89, 16, 16})},
    {"UP2", std::make_shared<SDL_Rect>(SDL_Rect{92, 89, 16, 16})},    
    {"DOWN", std::make_shared<SDL_Rect>(SDL_Rect{109, 89, 16, 16})},
    {"DOWN2", std::make_shared<SDL_Rect>(SDL_Rect{126, 93, 16, 16})},
};

 const SDL_Rect PACMAN_R = {19, 89, 16, 16};
// const SDL_Rect PACMAN_R2 = ;
// const SDL_Rect PACMAN_L = ;
// const SDL_Rect PACMAN_L2 = ;
// const SDL_Rect PACMAN_U = ;
// const SDL_Rect PACMAN_U2 = ;
// const SDL_Rect PACMAN_D = };
// const SDL_Rect PACMAN_D2 = ;

// Coordonnées Sprite Fantôme rouge
const std::map<std::string, std::shared_ptr<SDL_Rect>> RED_GHOST_IMAGES = {
    {"RIGHT", std::make_shared<SDL_Rect>(SDL_Rect{3, 123, 16, 16})},
    {"RIGHT2", std::make_shared<SDL_Rect>(SDL_Rect{20, 123, 16, 16})},
    {"LEFT", std::make_shared<SDL_Rect>(SDL_Rect{37, 123, 16, 16})},
    {"LEFT2", std::make_shared<SDL_Rect>(SDL_Rect{54, 123, 16, 16})},
    {"UP", std::make_shared<SDL_Rect>(SDL_Rect{71, 123, 16, 16})},
    {"UP2", std::make_shared<SDL_Rect>(SDL_Rect{88, 123, 16, 16})},    
    {"DOWN", std::make_shared<SDL_Rect>(SDL_Rect{105, 123, 16, 16})},
    {"DOWN2", std::make_shared<SDL_Rect>(SDL_Rect{122, 123, 16, 16})},
};
// const SDL_Rect GHOST_RED_R = {3, 123, 16, 16};
// const SDL_Rect GHOST_RED_R2 = {20, 123, 16, 16};
// const SDL_Rect GHOST_RED_L = {37, 123, 16, 16};
// const SDL_Rect GHOST_RED_L2 = {54, 123, 16, 16};
// const SDL_Rect GHOST_RED_U = {71, 123, 16, 16};
// const SDL_Rect GHOST_RED_U2 = {88, 123, 16, 16};
// const SDL_Rect GHOST_RED_D = {105, 123, 16, 16};
// const SDL_Rect GHOST_RED_D2 = {122, 123, 16, 16};

// Coordonnées Sprite Fantôme rose
const std::map<std::string, std::shared_ptr<SDL_Rect>> PINK_GHOST_IMAGES = {
    {"RIGHT", std::make_shared<SDL_Rect>(SDL_Rect{3, 141, 16, 16})},
    {"RIGHT2", std::make_shared<SDL_Rect>(SDL_Rect{20, 141, 16, 16})},
    {"LEFT", std::make_shared<SDL_Rect>(SDL_Rect{37, 141, 16, 16})},
    {"LEFT2", std::make_shared<SDL_Rect>(SDL_Rect{54, 141, 16, 16})},
    {"UP", std::make_shared<SDL_Rect>(SDL_Rect{71, 141, 16, 16})},
    {"UP2", std::make_shared<SDL_Rect>(SDL_Rect{88, 141, 16, 16})},    
    {"DOWN", std::make_shared<SDL_Rect>(SDL_Rect{105, 141, 16, 16})},
    {"DOWN2", std::make_shared<SDL_Rect>(SDL_Rect{122, 141, 16, 16})},
};
// const SDL_Rect GHOST_PINK_R = {3, 141, 16, 16};
// const SDL_Rect GHOST_PINK_R2 = {20, 141, 14, 16};
// const SDL_Rect GHOST_PINK_L = {37, 141, 16, 16};
// const SDL_Rect GHOST_PINK_L2 = {54, 141, 14, 16};
// const SDL_Rect GHOST_PINK_U = {71, 141, 16, 16};
// const SDL_Rect GHOST_PINK_U2 = {88, 141, 16, 16};
// const SDL_Rect GHOST_PINK_D = {105, 141, 16, 16};
// const SDL_Rect GHOST_PINK_D2 = {122, 141, 16, 16};

// Coordonnées Sprite Fantôme bleu
const std::map<std::string, std::shared_ptr<SDL_Rect>> BLUE_GHOST_IMAGES = {
    {"RIGHT", std::make_shared<SDL_Rect>(SDL_Rect{3, 159, 16, 16})},
    {"RIGHT2", std::make_shared<SDL_Rect>(SDL_Rect{20, 159, 16, 16})},
    {"LEFT", std::make_shared<SDL_Rect>(SDL_Rect{37, 159, 16, 16})},
    {"LEFT2", std::make_shared<SDL_Rect>(SDL_Rect{54, 159, 16, 16})},
    {"UP", std::make_shared<SDL_Rect>(SDL_Rect{71, 159, 16, 16})},
    {"UP2", std::make_shared<SDL_Rect>(SDL_Rect{88, 159, 16, 16})},    
    {"DOWN", std::make_shared<SDL_Rect>(SDL_Rect{105, 159, 16, 16})},
    {"DOWN2", std::make_shared<SDL_Rect>(SDL_Rect{122, 159, 16, 16})},
};
// const SDL_Rect GHOST_BLUE_R = {3, 159, 16, 16};
// const SDL_Rect GHOST_BLUE_R2 = {20, 159, 14, 16};
// const SDL_Rect GHOST_BLUE_L = {37, 159, 16, 16};
// const SDL_Rect GHOST_BLUE_L2 = {54, 159, 14, 16};
// const SDL_Rect GHOST_BLUE_U = {71, 159, 16, 16};
// const SDL_Rect GHOST_BLUE_U2 = {88, 159, 16, 16};
// const SDL_Rect GHOST_BLUE_D = {105, 159, 16, 16};
// const SDL_Rect GHOST_BLUE_D2 = {122, 159, 16, 16};

// Coordonnées Sprite Fantôme jaune
const std::map<std::string, std::shared_ptr<SDL_Rect>> YELLOW_GHOST_IMAGES = {
    {"RIGHT", std::make_shared<SDL_Rect>(SDL_Rect{3, 177, 16, 16})},
    {"RIGHT2", std::make_shared<SDL_Rect>(SDL_Rect{20, 177, 16, 16})},
    {"LEFT", std::make_shared<SDL_Rect>(SDL_Rect{37, 177, 16, 16})},
    {"LEFT2", std::make_shared<SDL_Rect>(SDL_Rect{54, 177, 16, 16})},
    {"UP", std::make_shared<SDL_Rect>(SDL_Rect{71, 177, 16, 16})},
    {"UP2", std::make_shared<SDL_Rect>(SDL_Rect{88, 177, 16, 16})},    
    {"DOWN", std::make_shared<SDL_Rect>(SDL_Rect{105, 177, 16, 16})},
    {"DOWN2", std::make_shared<SDL_Rect>(SDL_Rect{122, 177, 16, 16})},
};
// const SDL_Rect GHOST_YELLOW_R = {3, 177, 16, 16};
// const SDL_Rect GHOST_YELLOW_R2 = {20, 177, 14, 16};
// const SDL_Rect GHOST_YELLOW_L = {37, 177, 16, 16};
// const SDL_Rect GHOST_YELLOW_L2 = {54, 177, 14, 16};
// const SDL_Rect GHOST_YELLOW_U = {71, 177, 16, 16};
// const SDL_Rect GHOST_YELLOW_U2 = {88, 177, 16, 16};
// const SDL_Rect GHOST_YELLOW_D = {105, 177, 16, 16};
// const SDL_Rect GHOST_YELLOW_D2 = {122, 177, 16, 16};

// Coordonnées Sprite Fantôme appeuré
const std::map<std::string, std::shared_ptr<SDL_Rect>> FEARED_GHOST_IMAGES = {
    {"BLUE", std::make_shared<SDL_Rect>(SDL_Rect{3, 195, 16, 16})},
    {"BLUE2", std::make_shared<SDL_Rect>(SDL_Rect{20, 195, 16, 16})},
    {"WHITE", std::make_shared<SDL_Rect>(SDL_Rect{37, 195, 16, 16})},
    {"WHITE2", std::make_shared<SDL_Rect>(SDL_Rect{54, 195, 16, 16})},
};
// const SDL_Rect GHOST_FEARED_BLUE = {3, 195, 16, 16};
// const SDL_Rect GHOST_FEARED_BLUE2 = {20, 195, 16, 16};
// const SDL_Rect GHOST_FEARED_WHITE = {37, 195, 16, 16};
// const SDL_Rect GHOST_FEARED_WHITE2 = {54, 195, 16, 16};

// Coordonnées Sprite Fantôme mangé
const std::map<std::string, std::shared_ptr<SDL_Rect>> EATEN_GHOST_IMAGES = {
    {"RIGHT", std::make_shared<SDL_Rect>(SDL_Rect{71, 195, 16, 16})},
    {"LEFT", std::make_shared<SDL_Rect>(SDL_Rect{88, 195, 16, 16})},
    {"UP", std::make_shared<SDL_Rect>(SDL_Rect{105, 195, 16, 16})},
    {"DOWN", std::make_shared<SDL_Rect>(SDL_Rect{122, 195, 16, 16})},
};
// const SDL_Rect GHOST_EATEN_R = {71, 195, 16, 16};
// const SDL_Rect GHOST_EATEN_L = {88, 195, 16, 16};
// const SDL_Rect GHOST_EATEN_U = {105, 195, 16, 16};
// const SDL_Rect GHOST_EATEN_D = {122, 195, 16, 16};

#endif