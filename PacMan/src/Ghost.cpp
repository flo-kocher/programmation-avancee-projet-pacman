#include "../include/Ghost.h"

Ghost::Ghost()
{}

Ghost::Ghost(CharacterName name, SDL_Rect start_position, SDL_Rect* image)
{
    SetCharacterName(name);
    position_ = start_position;
    character_image_ = image;
}

// Ghost::Ghost(CharacterName name, SDL_Rect start_position, std::shared_ptr<SDL_Rect> image, std::pair<int, int> target)
// {
//         SetCharacterName(name);
    // position_ = start_position;
    // character_image_ = image;
// }

Ghost::~Ghost()
{

}