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



#define HITBOX 30

class GameManager
{
    private:
        std::map<std::string, std::shared_ptr<Pellet>> pellets;
        std::map<std::string, std::shared_ptr<BigPellet>> big_pellets;
        std::map<std::string, std::shared_ptr<Intersection<Pellet>>> intersections;
        std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> intersections_big;

        static int count_;
        static int feared_timer_;
        int score_;
        int consecutive_ghost_eaten_;
        bool pacman_alive_;

        bool intersection_detected_;
        int direction_tmp_;
        std::unique_ptr<GameInterface> gameInterface_ = nullptr;

        bool feared_timer_running_;

    public:
        std::shared_ptr<Pacman> pacman_;
        std::array<std::shared_ptr<Ghost>, 4> ghosts_;

        GameManager();
        ~GameManager();

        void initCharacters();
        void initCharacter(CharacterName name, SDL_Rect position, SDL_Rect* image, Direction direction);
        void runGame();
        bool updateGame();
        bool levelCompleted();
        bool isGameOver();
        void gameOver();

        int collisionWithGhost();
        void actionWithGhost(std::shared_ptr<Ghost> ghost);

        template <typename T>
        void checkForTeleportation(T character);
        void checkForPellet(int x, int y);
        template <typename T>
        void checkForPelletTemplate(int x, int y, T map);
        int checkForIntersection();
        template <typename T>
        int checkForIntersectionTemplate(T map);
        void setGhostsFeared(int count);
        void setGhostsNormal(int count);

        inline static const int getCount()
        {
            return count_;
        };

        inline const int getScore()
        {
            return score_;
        };

        inline const void AddToScore(int to_add)
        {
            score_ += to_add;
        };

        inline static void incrementCount()
        {
            count_ = (count_ + 1) % (250);
        };

        inline void activateFearedTimer()
        {
            feared_timer_running_ = true;
            feared_timer_ = 500;
        };

        inline void resetFearedTimer()
        {
            feared_timer_ = 500;
        };

        inline void deactivateFearedTimer()
        {
            feared_timer_running_ = false;
        };

        inline void decrementFearedTimer()
        {
            feared_timer_--;
        };

        inline void incrementConsecutiveEatenGhosts()
        {
            consecutive_ghost_eaten_++;
        };

        inline void setConsecutiveEatenGhosts(int value)
        {
            consecutive_ghost_eaten_ = value;
        };

        inline int getConsecutiveEatenGhosts()
        {
            return consecutive_ghost_eaten_;
        };

        inline void pacmanDied()
        {
            pacman_alive_ = false;
        };

        inline bool pacmanAlive()
        {
            return pacman_alive_;
        };
};

#endif