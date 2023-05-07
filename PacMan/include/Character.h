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
        CharacterName name_; //Name of the character

    protected:
        Direction direction_; //Current direction of the character
        bool can_go_right_; //Determine if character can go right
        bool can_go_down_; //Determine if character can go down
        bool can_go_left_; //Determine if character can go left
        bool can_go_up_; //Determine if character can go up
 
        int speed_; //Current speed of the character
        
        //Setter
        inline void setCharacterName(CharacterName name)
        {
            name_ = name;
        };

    public:
        // The bitmap rectangles
        SDL_Rect* character_image_;
        SDL_Rect position_;

        /**
         * @brief Construct a new Character object
         * 
         */
        Character();
        ~Character();
        
        /**
         * @brief Teleport the character to the right corridor
         * 
         */
        void teleportRight();

        /**
         * @brief Teleport the character to the left corridor
         * 
         */
        void teleportLeft();

        /**
         * @brief Make the character move to the right
         * 
         * @param count counter used to determine which image the character will take
         */
        void goRight(int count);

        /**
         * @brief Make the character move to the down
         * 
         * @param count counter used to determine which image the character will take
         */
        void goDown(int count);

        /**
         * @brief Make the character move to the left
         * 
         * @param count counter used to determine which image the character will take
         */
        void goLeft(int count);

        /**
         * @brief Make the character move to the up
         * 
         * @param count counter used to determine which image the character will take
         */
        void goUp(int count);

        /**
         * @brief Make the character stand still
         * 
         */
        void standStill();

        /**
         * @brief Set the image of the character
         * 
         * @param count counter used to determine which image the character will take
         * @param direction direction to determine which image the character will take
         */
        void setImage(int count, std::string direction);

        /**
         * @brief Get the map of all the character base images
         * 
         */     
        std::map<std::string, SDL_Rect*> getImagesMap();

        //Getter
        inline CharacterName getCharacterName()
        {
            return name_;
        };

        inline Direction getDirection()
        {
            return direction_;
        };

        inline std::array<bool, 4> getPossibleDirection() {
            return std::array<bool,4>{ {can_go_right_, can_go_down_, can_go_left_, can_go_up_} };
        };

        //Setter
        inline void setDirection(Direction direction)
        {
            direction_ = direction;
        };

        inline void setPossibleDirection(bool can_go_right, bool can_go_down, bool can_go_left, bool can_go_up) {
            can_go_right_ = can_go_right;
            can_go_down_ = can_go_down;
            can_go_left_ = can_go_left;
            can_go_up_ = can_go_up;
        };

        // Mode de vitesse Lent
        inline void lowerSpeed()
        {
            speed_ = 1;
        };

        // Mode de vitesse Normal
        inline void increaseSpeed()
        {
            speed_ = 2;
        };

        inline void setSpeed(int speed)
        {
            speed_ = speed;
        };
};

#endif