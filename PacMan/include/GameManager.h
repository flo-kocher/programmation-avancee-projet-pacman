#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SDL.h>
#include "Character.h"
#include "MapInitialization.h"
#include "GameInterface.h"
#include <map>
#include <array>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

#define HITBOX 30

class GameManager
{
    private:
        std::map<std::string, std::shared_ptr<Pellet>> pellets;
        std::map<std::string, std::shared_ptr<BigPellet>> big_pellets;
        std::map<std::string, std::shared_ptr<Intersection<Pellet>>> intersections;
        std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> intersections_big;
        //std::map<std::string, std::shared_ptr<Character>> characters;

        
        int count_;
        int score_;

        bool intersection_detected_;
        int direction_tmp_;
        int last_pressed_key_;
        std::unique_ptr<GameInterface> gameInterface_ = nullptr;

    public:
        std::array<std::shared_ptr<Character>, 5> characters;

        GameManager();
        ~GameManager();

        void initCharacters();
        void initCharacter(CharacterName name, SDL_Rect position, SDL_Rect* image);
        void runGame();
        bool updateGame();
        bool isGameOver();

        int collisionWithGhost();

        int checkForPellet(int x, int y);
        template <typename T>
        int checkForPelletTemplate(int x, int y, T map);
        int checkForIntersection(int x, int y, int last_pressed_key);
        template <typename T>
        int checkForIntersectionTemplate(int x, int y, int last_pressed_key, T map);

        inline const int getCount()
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

        inline void IncrementCount()
        {
            count_ = (count_ + 1) % (250);
        };

        inline void setDirectionRight()
        {
            last_pressed_key_ = 0;
        };

        inline void setDirectionDown()
        {
            last_pressed_key_ = 1;
        };

        inline void setDirectionLeft()
        {
            last_pressed_key_ = 2;
        };

        inline void setDirectionUp()
        {
            last_pressed_key_ = 3;
        };

};

#endif