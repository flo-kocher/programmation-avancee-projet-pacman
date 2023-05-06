#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <SDL.h>
#include <iostream>
#include <memory>
#include <array>
#include "Constante.h"

class Character
{
    private:
        CharacterName name_;
       

    protected:
        Direction direction_;
        bool can_go_right_;
        bool can_go_down_;
        bool can_go_left_;
        bool can_go_up_;
        
        inline void setCharacterName(CharacterName name)
        {
            name_ = name;
        };

    public:
        SDL_Rect* character_image_;
        SDL_Rect position_;

        Character();
        ~Character();
        
        void teleportRight();
        void teleportLeft();
        void goRight(int count);
        void goDown(int count);
        void goLeft(int count);
        void goUp(int count);
        void standStill();
        void setImage(int count, std::string direction);

        std::map<std::string, SDL_Rect*> getImagesMap();

        inline CharacterName getCharacterName()
        {
            return name_;
        };

        inline Direction getDirection()
        {
            return direction_;
        };

        inline void setDirection(Direction direction)
        {
            direction_ = direction;
        };

        inline std::array<bool, 4> getPossibleDirection() {
            return std::array<bool,4>{ {can_go_right_, can_go_down_, can_go_left_, can_go_up_} };
        };

        inline void setPossibleDirection(bool can_go_right, bool can_go_down, bool can_go_left, bool can_go_up) {
            can_go_right_ = can_go_right;
            can_go_down_ = can_go_down;
            can_go_left_ = can_go_left;
            can_go_up_ = can_go_up;
        };
};

#endif