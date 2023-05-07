#ifndef __GHOST_H__
#define __GHOST_H__

#include <SDL.h>
#include "Character.h"
#include "Pacman.h"
#include "Constante.h"
#include <iostream>
#include <memory>
#include <chrono>

class Ghost : public Character
{
    private:
        struct Target {
            int x;
            int y;
        } target_; //Current target of the ghost
        double vector_up_to_target_; //Vector between the target and the tile above the ghost
        double vector_down_to_target_; //Vector between the target and the tile below the ghost
        double vector_left_to_target_; //Vector between the target and the tile to the left of the ghost
        double vector_right_to_target_; //Vector between the target and the tile to the right of the ghost
        bool is_feared_; //Determine if the ghost is in feared state
        bool is_eaten_; //Determine if the ghost is in eaten state
        bool is_in_corridor_; //Determine if the ghost is in the corridor
        bool is_in_spawn_; //Determine if the ghost is in the spawn
        std::chrono::steady_clock::time_point eaten_start_timer_; //Time point to know since when a ghost is in eaten state

    public:
        /**
         * @brief Construct a new Ghost object
         * 
         */
        Ghost();
        Ghost(CharacterName name, SDL_Rect position, SDL_Rect* image, Direction direction);
        ~Ghost();

        /**
         * @brief Moves to a specific target for each ghost to chase pacman
         * 
         * @param pacman Pacman pointer
         * @param count counter used to determine which image the character will take
         * @param red_ghost Red_ghost pointer (the blue ghost movement are based on the red ghost position)
         */
        void chase(std::shared_ptr<Pacman> pacman, int count, std::shared_ptr<Ghost> red_ghost);
        /**
         * @brief Moves to a corner of the map 
         * 
         * @param count counter used to determine which image the character will take
         */
        void scatter(int count);
        /**
         * @brief Moves randomly 
         * 
         * @param count counter used to determine which image the character will take
         */
        void feared(int count);
        /**
         * @brief Moves to the ghost spawner
         * 
         * @param count counter used to determine which image the character will take
         */
        void eaten(int count);
        /**
         * @brief Calculates the 4 vector of distance to the target
         * 
         * @param target current target
         * @param position current position
         */
        void calculateVectorsToTarget(Target target, SDL_Rect position);
        /**
         * @brief Determine the movement of the ghost 
         * 
         * @param count counter used to determine which image the character will take
         */
        void classicalMovementAlgorithm(int count);
        /**
         * @brief Check if the ghost needs specific image and call the GameManager goRight method
         * 
         * @param count counter used to determine which image the character will take
         */
        void goRight(int count);
        /**
         * @brief Check if the ghost needs specific image and call the GameManager goLeft method
         * 
         * @param count counter used to determine which image the character will take
         */
        void goLeft(int count);
        /**
         * @brief Check if the ghost needs specific image and call the GameManager goUp method
         * 
         * @param count counter used to determine which image the character will take
         */
        void goUp(int count);
        /**
         * @brief Check if the ghost needs specific image and call the GameManager goDown method
         * 
         * @param count counter used to determine which image the character will take
         */
        void goDown(int count);
        /**
         * @brief Set the feared image of the ghost
         * 
         * @param count counter used to determine which image the character will take
         */
        void setFearedImage(int count);
        /**
         * @brief Set the eaten image of the ghost
         * 
         * @param count counter used to determine which image the character will take
         */
        void setEatenImage(std::string direction);

        //Getter
        inline Target getTarget() {
            return target_;
        };

        inline bool getIsFeared()
        {
            return is_feared_;
        };

        inline bool getIsEaten()
        {
            return is_eaten_;
        };

        inline bool getIsInCorridor()
        {
            return is_in_corridor_;
        };

        inline bool getIsInSpawn()
        {
            return is_in_spawn_;
        };

        inline std::chrono::steady_clock::time_point getEatenStartTimer()
        {
            return eaten_start_timer_;
        };

        //Setter
        inline void setTarget(int coord_x, int coord_y) {
            target_.x = coord_x;
            target_.y = coord_y;
        };

        inline void setIsFeared(bool value)
        {
            is_feared_= value;
        };

        inline void setIsEaten()
        {
            is_feared_ = false;
            is_eaten_ = true;
        };

        inline void setIsInCorridor(bool value)
        {
            is_in_corridor_ = value;
        };

        inline void setIsInSpawn(bool value)
        {
            is_in_spawn_ = value;
        };

        inline void setEatenStartTimer(std::chrono::steady_clock::time_point eaten_start_timer)
        {
            eaten_start_timer_ = eaten_start_timer;
        };    
};

#endif