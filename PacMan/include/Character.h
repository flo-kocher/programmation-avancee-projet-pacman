#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <SDL.h>
#include <iostream>
#include <memory>
#include "Constante.h"

class Character
{
    private:
        CharacterName name_;

    protected:
        inline void SetCharacterName(CharacterName name)
        {
            name_ = name;
        }

    public:
        SDL_Rect* character_image_;
        SDL_Rect position_;

        Character();
        ~Character();
        
        void teleportRight();
        void teleportLeft();
        void turnRight(int count);
        void turnDown(int count);
        void turnLeft(int count);
        void turnUp(int count);
        void standStill();
        
        std::map<std::string, SDL_Rect*> getImagesMap();

        inline CharacterName GetCharacterName()
        {
            return name_;
        }
};

#endif