#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SDL.h>
#include "Character.h"
#include "MapInitialization.h"
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
        SDL_Rect src_bg_;
        SDL_Rect bg_;
        int score_;

    public:
    SDL_Window *pWindow_ = nullptr;
        SDL_Surface *win_surf_ = nullptr;
        SDL_Surface *plancheSprites_ = nullptr;
       
        std::array<std::shared_ptr<Character>, 5> characters;

        GameManager();
        ~GameManager();

        int checkForPellet(int x, int y);
        template <typename T>
        int checkForPelletTemplate(int x, int y, T map);
        int checkForIntersection(int x, int y, int last_pressed_key);
        template <typename T>
        int checkForIntersectionTemplate(int x, int y, int last_pressed_key, T map);

        void updateInterface();
        template <typename T>
        void updatePellets(T map);
        template <typename T>
        void updateIntersections(T map);
        void updateCharacters(std::array<std::shared_ptr<Character>, 5> map);
        void initCharacters();
        void initCharacter(CharacterName name, SDL_Rect position, SDL_Rect* image);
        bool isGameOver();
        int collisionWithGhost();

        inline void setColorAndBlitScaled(const bool transparence, const SDL_Rect* src_rect, SDL_Rect* dst_rect)
        {
            // if true then transparent color
            // int SDL_BlitScaled(SDL_Surface*    src,
            //                const SDL_Rect* srcrect,
            //                SDL_Surface*    dst,
            //                SDL_Rect*       dstrect)
            SDL_SetColorKey(plancheSprites_, transparence, 0);
            SDL_BlitScaled(plancheSprites_, src_rect, win_surf_, dst_rect);
        }

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

};

#endif