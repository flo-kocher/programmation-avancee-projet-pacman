#ifndef __GHOST_H__
#define __GHOST_H__

#include <SDL.h>
#include "Character.h"
#include "Pacman.h"
#include "Constante.h"
#include <iostream>
#include <memory>

class Ghost : public Character
{
    private:
        //std::pair<int, int> target; //x et y cible
        struct Target {
            int x;
            int y;
        } target;
        double vector_up_to_target_;
        double vector_down_to_target_;
        double vector_left_to_target_;
        double vector_right_to_target_;
        bool is_feared_;
        bool is_eaten_;

    public:
        Ghost();
        Ghost(CharacterName name, SDL_Rect position, SDL_Rect* image, Direction direction);
        ~Ghost();

        void chase(std::shared_ptr<Pacman> pacman, int count);
        void scatter(int count);
        void frightened(int count);
        void eaten(int count);
        void calculateVectorsToTarget(Target target, SDL_Rect position);

        void goRight(int count);
        void goLeft(int count);
        void goUp(int count);
        void goDown(int count);
        void setFearedImage(int count);
        void setEatenImage(std::string direction);

        inline Target getTarget() {
            return target;
        };

        inline void setTarget(int coord_x, int coord_y) {
            target.x = coord_x;
            target.y = coord_y;
        };

        inline void setIsFeared(bool value)
        {
            is_feared_= value;
        };

        inline bool getIsFeared()
        {
            return is_feared_;
        };

        inline void setIsEaten()
        {
            is_feared_ = false;
            is_eaten_ = true;
        };

        inline bool getIsEaten()
        {
            return is_eaten_;
        };


};

#endif