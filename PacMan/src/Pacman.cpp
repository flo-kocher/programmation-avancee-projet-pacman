#include "../include/Pacman.h"
#include "../include/Constante.h"

Pacman::Pacman()
: life_(3)
{   
    setCharacterName(PACMAN);
    position_ = {34, 34, 32, 32};
    character_image_ = PACMAN_IMAGES.find("RIGHT")->second;
    direction_ = RIGHT;
}

Pacman::Pacman(CharacterName name, SDL_Rect start_position, SDL_Rect* image, Direction direction)
: life_(3)
{
    setCharacterName(name);
    position_ = start_position;
    character_image_ = image;
    direction_ = direction;   
}

Pacman::~Pacman()
{}