#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SDL.h>
#include "Character.h"
#include "MapInitialization.h"
#include "GameInterface.h"
#include "Intersection.h"
#include "Pacman.h"
#include "Ghost.h"
#include <map>
#include <array>
#include <chrono>


#define HITBOX 16


/**
 * @brief GameManager class used to handle all the events that occure in the game
 * 
 */
class GameManager
{
    private:
        // Maps of all the objects
        std::map<std::string, std::shared_ptr<Pellet>> pellets;
        std::map<std::string, std::shared_ptr<BigPellet>> big_pellets;
        std::map<std::string, std::shared_ptr<Intersection<Pellet>>> intersections;
        std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> intersections_big;

        // Infinite timer used to change the animation of the characters
        int count_;
        // Holds the score of the player
        int score_;
        // Holds the number of consecutive ghosts eaten
        int consecutive_ghost_eaten_;
        // Number of pellets eaten by PacMan
        int pellet_counter_;
        // If PacMan is on an Intersection object
        bool intersection_detected_;
        // The current direction of the PacMan
        int direction_tmp_;
        // If the feared mode is running
        bool feared_timer_running_;
        // All the ghost modes
        enum GhostMode { CHASE, SCATTER } current_ghost_mode_;
        // All the game steps
        enum GameStep { SCATTER1, CHASE1, SCATTER2, CHASE2, SCATTER3, CHASE3, SCATTER4, CHASE4 } current_game_step_;
        // Chronometer of the different modes
        std::chrono::steady_clock::time_point mode_start_timer_;
        // The GameInterface
        std::unique_ptr<GameInterface> gameInterface_ = nullptr;

    public:
        // Feared timer
        static int feared_timer_;
        // PacMan object
        std::shared_ptr<Pacman> pacman_;
        // The 4 ghost objects
        std::array<std::shared_ptr<Ghost>, 4> ghosts_;

        /**
         * @brief Construct a new Game Manager object
         * 
         */
        GameManager();
        ~GameManager();

        /**
         * @brief Initialize all the characters
         * 
         */
        void initCharacters();
        /**
         * @brief Initialize a Character
         * 
         * @param name Name of the Character
         * @param position Position of the Character
         * @param image Starting image of the Character
         * @param direction Starting direction of the Character
         */
        void initCharacter(CharacterName name, SDL_Rect position, SDL_Rect* image, Direction direction);
        /**
         * @brief Starting function to run the game and inialize all the necessary objects and maps
         * 
         */
        int runGame();
        /**
         * @brief In real-time function that catches all the events happening
         * 
         * @return true if the game is over
         * @return false else
         */
        int updateGame();
        /**
         * @brief Events that would lead to the game beeing over
         * 
         * @return true if the game is over
         * @return false else
         */
        bool isGameOver();
        /**
         * @brief If PacMan collides with a Ghost
         * 
         * @param ghost a ghost in the ghosts_ array
         * @return true if he coliided with the PacMan
         * @return false else
         */
        bool collisionWithGhost(std::shared_ptr<Ghost> ghost);
        /**
         * @brief Action happening when a ghost is collided depending on his current mode
         * 
         * @param ghost a ghost in the ghosts_ array
         */
        int actionWithGhost(std::shared_ptr<Ghost> ghost);
        /**
         * @brief Teleports the Character if he is the left corridor or right corridor of the stage
         * 
         * @tparam T 
         * @param character array of character to check
         */
        template <typename T>
        void checkForTeleportation(T character);
        /**
         * @brief Check if PacMan is on a pellet
         * 
         * @param x x position of PacMan
         * @param y y position of PacMan
         */
        void checkForPellet(int x, int y);
        /**
         * @brief Function template used for any map of pellets
         * 
         * @tparam T 
         * @param x x position
         * @param y y position
         * @param map map to check
         */
        template <typename T>
        void checkForPelletTemplate(int x, int y, T map);
        /**
         * @brief Check if PacMan is on an intersection
         * 
         * @return int 
         */
        int checkForIntersection();
        /**
         * @brief Function template used for any map of intersections
         * 
         * @tparam T 
         * @param map 
         * @return int 
         */
        template <typename T>
        int checkForIntersectionTemplate(T map);
        /**
         * @brief Check if a ghost is inside the corridor (because slowed if in feared mode)
         * 
         */
        void checkIfInCorridor();
        void checkIfInSpawn(std::shared_ptr<Ghost> ghost);
        /**
         * @brief Set the ghosts to feared mode
         * 
         * @param count Current count timer for cool animation
         */
        void setGhostsFeared(int count);
        /**
         * @brief Set the ghosts back to normal mode
         * 
         * @param count Current count timer for cool animation
         */
        void setGhostsNormal(int count);
        /**
         * @brief 
         * 
         */
        void checkGameStep();
        /**
         * @brief 
         * 
         * @param timer 
         * @param new_ghost_mode 
         * @param next_game_step 
         */
        void switchGhostsTrackingMode(double timer, GhostMode new_ghost_mode, GameStep next_game_step);
        /**
         * @brief Set the Ghost Opposite Direction object
         * 
         * @param ghost 
         */
        void setGhostOppositeDirection(std::shared_ptr<Ghost> ghost);
        void respawn(int remaining_life);

        // Getters
        inline const int getCount()
        {
            return count_;
        };

        inline const int getScore()
        {
            return score_;
        };

        inline bool allPelletsEaten()
        {
            return (pellet_counter_ == 194);
        };

        inline int getConsecutiveEatenGhosts()
        {
            return consecutive_ghost_eaten_;
        };

        inline GhostMode getCurrentGhostMode()
        {
            return current_ghost_mode_;
        };

        // Setters
        inline void incrementCount()
        {
            count_++;
        };

        inline void decrementFearedTimer()
        {
            feared_timer_--;
        };

        inline void incrementConsecutiveEatenGhosts()
        {
            consecutive_ghost_eaten_++;
        };

        inline void incrementPelletCounter()
        {
            pellet_counter_++;
        };

        // Activates the timer of the feared mode for the ghosts
        inline void activateFearedTimer()
        {
            feared_timer_running_ = true;
            feared_timer_ = 500;
        };

        // Resets if a second BigPellet is eaten
        inline void resetFearedTimer()
        {
            feared_timer_ = 500;
        };

        inline void deactivateFearedTimer()
        {
            feared_timer_running_ = false;
        };

        inline void setConsecutiveEatenGhosts(int value)
        {
            consecutive_ghost_eaten_ = value;
        };

        inline void setCurrentGhostMode(GhostMode mode)
        {
            current_ghost_mode_ = mode;
        };

        inline const void AddToScore(int to_add)
        {
            score_ += to_add;
        };
};

#endif