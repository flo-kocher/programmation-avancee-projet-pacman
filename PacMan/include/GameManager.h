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
        int score_;

        bool intersection_detected_;
        int direction_tmp_;
        std::unique_ptr<GameInterface> gameInterface_ = nullptr;

    public:
        std::shared_ptr<Pacman> pacman_;
        std::array<std::shared_ptr<Ghost>, 4> ghosts_;

        GameManager();
        ~GameManager();

        void initCharacters();
        void initCharacter(CharacterName name, SDL_Rect position, SDL_Rect* image, Direction direction);
        void runGame();
        bool updateGame();
        bool isGameOver();

        int collisionWithGhost();

        template <typename T>
        void checkForTeleportation(T character);
        void checkForPellet(int x, int y);
        template <typename T>
        void checkForPelletTemplate(int x, int y, T map);
        int checkForIntersection();
        template <typename T>
        int checkForIntersectionTemplate(T map);

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

        inline static void IncrementCount()
        {
            count_ = (count_ + 1) % (250);
        };
};

#endif