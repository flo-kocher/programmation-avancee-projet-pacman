#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SDL.h>
#include "Character.h"
#include "Zone.h"
#include "Pellet.h"
#include "BigPellet.h"
#include "Intersection.h"
#include "Intersection.h"
#include <map>

class GameManager
{
    private:
        std::map<std::string, std::shared_ptr<Zone>> zones;
        std::map<std::string, std::shared_ptr<Pellet>> pellets;
        std::map<std::string, std::shared_ptr<BigPellet>> big_pellets;
        std::map<std::string, std::shared_ptr<Intersection<Pellet>>> intersections;
        std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> intersections_big;

        SDL_Window *pWindow = nullptr;
        SDL_Surface *win_surf = nullptr;
        SDL_Surface *plancheSprites = nullptr;
        int count;
        SDL_Rect src_bg;
        SDL_Rect bg;

    public:
        int score;

        GameManager();
        ~GameManager();

        void checkForZone(int x, int y);
        void checkForPellet(int x, int y);
        template <typename T>
        void checkForPelletTemplate(int x, int y, T map);
        int checkForIntersection(int x, int y, int last_pressed_key);
        template <typename T>
        int checkForIntersectionTemplate(int x, int y, int last_pressed_key, T map);

        void updateInterface(SDL_Rect* ghost_rect, SDL_Rect ghost_rect_in);
        template <typename T>
        void updatePellets(T map);
        template <typename T>
        void updateIntersections(T map);
        void initPellets();
        void initIntersections();
        bool isGameOver();

        inline void setColorAndBlitScaled(const bool transparence, const SDL_Rect* src_rect, SDL_Rect* dst_rect)
        {
            // if true then transparent color
            // int SDL_BlitScaled(SDL_Surface*    src,
            //                const SDL_Rect* srcrect,
            //                SDL_Surface*    dst,
            //                SDL_Rect*       dstrect)
            SDL_SetColorKey(plancheSprites, transparence, 0);
            SDL_BlitScaled(plancheSprites, src_rect, win_surf, dst_rect);
        }

        inline const SDL_Window* getPWindow()
        {
            return pWindow;
        };
        inline SDL_Surface* getWinSurf()
        {
            return win_surf;
        };
        inline SDL_Surface* getPlanchesSprites()
        {
            return plancheSprites;
        };
        inline const int getCount()
        {
            return count;
        };
        inline const SDL_Rect getSrcBg()
        {
            return src_bg;
        };
        inline const SDL_Rect getBg()
        {
            return bg;
        };

    
};

#endif