#include "../include/Pacman.h"

Pacman::Pacman()
: life_(3)
{   
    SetCharacterName(PACMAN);
    position_ = {34, 34, 32, 32};
    character_image_ = PACMAN_IMAGES.find("RIGHT")->second;
}

Pacman::Pacman(CharacterName name, SDL_Rect start_position, std::shared_ptr<SDL_Rect> image)
: life_(3)
{
    SetCharacterName(name);
    position_ = start_position;
    character_image_ = image;
}

Pacman::~Pacman()
{

}