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
        std::shared_ptr<SDL_Rect> character_image_;
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
        
        std::map<std::string, std::shared_ptr<SDL_Rect>> getImagesMap();

        // inline SDL_Rect* getPosition()
        // {
        //     return &position_;
        // };

        // inline void setPosition(SDL_Rect pos)
        // {
        //     position_ = pos;
        // };

        // inline std::shared_ptr<SDL_Rect> getCharacterImage()
        // {
        //     return character_image_;
        // };
        
        // inline void setCharacterImage(std::shared_ptr<SDL_Rect> image)
        // {
        //     character_image_ = image;
        // };

        inline CharacterName GetCharacterName()
        {
            return name_;
        }
};

#endif