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
enum Direction { RIGHT, DOWN, LEFT, UP };

// Coordinates Sprite Pacman
const std::map<std::string, SDL_Rect*> PACMAN_IMAGES = {
    {"RIGHT", new SDL_Rect{19, 89, 16, 16}},
    {"RIGHT2", new SDL_Rect{34, 89, 14, 16 }},
    {"LEFT", new SDL_Rect{46, 89, 16, 16 }},
    {"LEFT2", new SDL_Rect{61, 89, 14, 16 }},
    {"UP", new SDL_Rect{75, 89, 16, 16 }},
    {"UP2", new SDL_Rect{92, 89, 16, 16 }},    
    {"DOWN", new SDL_Rect{109, 89, 16, 16 }},
    {"DOWN2", new SDL_Rect{126, 93, 16, 16 }},
};

// Coordinates Sprite Red Ghost
const std::map<std::string, SDL_Rect*> RED_GHOST_IMAGES = {
    {"RIGHT", new SDL_Rect{3, 123, 16, 16 }},
    {"RIGHT2", new SDL_Rect{20, 123, 16, 16 }},
    {"LEFT", new SDL_Rect{37, 123, 16, 16 }},
    {"LEFT2", new SDL_Rect{54, 123, 16, 16 }},
    {"UP", new SDL_Rect{71, 123, 16, 16 }},
    {"UP2", new SDL_Rect{88, 123, 16, 16 }},    
    {"DOWN", new SDL_Rect{105, 123, 16, 16 }},
    {"DOWN2", new SDL_Rect{122, 123, 16, 16 }},
};

// Coordinates Sprite Pink Ghost
const std::map<std::string, SDL_Rect*> PINK_GHOST_IMAGES = {
    {"RIGHT", new SDL_Rect{3, 141, 16, 16 }},
    {"RIGHT2", new SDL_Rect{20, 141, 16, 16 }},
    {"LEFT", new SDL_Rect{37, 141, 16, 16 }},
    {"LEFT2", new SDL_Rect{54, 141, 16, 16 }},
    {"UP", new SDL_Rect{71, 141, 16, 16 }},
    {"UP2", new SDL_Rect{88, 141, 16, 16 }},    
    {"DOWN", new SDL_Rect{105, 141, 16, 16 }},
    {"DOWN2", new SDL_Rect{122, 141, 16, 16 }},
};

// Coordinates Sprite Blue Ghost
const std::map<std::string, SDL_Rect*> BLUE_GHOST_IMAGES = {
    {"RIGHT", new SDL_Rect{3, 159, 16, 16 }},
    {"RIGHT2", new SDL_Rect{20, 159, 16, 16 }},
    {"LEFT", new SDL_Rect{37, 159, 16, 16 }},
    {"LEFT2", new SDL_Rect{54, 159, 16, 16 }},
    {"UP", new SDL_Rect{71, 159, 16, 16 }},
    {"UP2", new SDL_Rect{88, 159, 16, 16 }},    
    {"DOWN", new SDL_Rect{105, 159, 16, 16 }},
    {"DOWN2", new SDL_Rect{122, 159, 16, 16 }},
};

// Coordinates Sprite Yellow Ghost
const std::map<std::string, SDL_Rect*> YELLOW_GHOST_IMAGES = {
    {"RIGHT", new SDL_Rect{3, 177, 16, 16 }},
    {"RIGHT2", new SDL_Rect{20, 177, 16, 16 }},
    {"LEFT", new SDL_Rect{37, 177, 16, 16 }},
    {"LEFT2", new SDL_Rect{54, 177, 16, 16 }},
    {"UP", new SDL_Rect{71, 177, 16, 16 }},
    {"UP2", new SDL_Rect{88, 177, 16, 16 }},    
    {"DOWN", new SDL_Rect{105, 177, 16, 16 }},
    {"DOWN2", new SDL_Rect{122, 177, 16, 16 }},
};

// Coordinates Sprite Feared Ghost
const std::map<std::string, SDL_Rect*> FEARED_GHOST_IMAGES = {
    {"BLUE", new SDL_Rect{3, 195, 16, 16 }},
    {"BLUE2", new SDL_Rect{20, 195, 16, 16 }},
    {"WHITE", new SDL_Rect{37, 195, 16, 16 }},
    {"WHITE2", new SDL_Rect{54, 195, 16, 16 }},
};

// Coordinates Sprite Eaten Ghost
const std::map<std::string, SDL_Rect*> EATEN_GHOST_IMAGES = {
    {"RIGHT", new SDL_Rect{71, 195, 16, 16 }},
    {"LEFT", new SDL_Rect{88, 195, 16, 16 }},
    {"UP", new SDL_Rect{105, 195, 16, 16 }},
    {"DOWN", new SDL_Rect{122, 195, 16, 16 }},
};

#endif