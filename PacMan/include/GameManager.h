#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SDL.h>
#include "Character.h"
#include "Zone.h"
#include "Pellet.h"
#include "BigPellet.h"
#include "Intersection.h"
#include <map>

class GameManager
{
    private:
        std::map<std::string, Zone*> zones;
        std::map<std::string, Pellet*> pellets;
        std::map<std::string, BigPellet*> big_pellets;
        std::map<std::string, Intersection*> intersections;

        SDL_Window *pWindow = nullptr;
        SDL_Surface *win_surf = nullptr;
        SDL_Surface *plancheSprites = nullptr;
        int count;
        SDL_Rect src_bg;
        SDL_Rect bg;

    public:
        GameManager();
        ~GameManager();

        void checkForZone(int x, int y);
        void checkForPellet(int x, int y);
        bool checkForIntersection(int x, int y);

        void updateInterface(SDL_Rect* ghost_rect, SDL_Rect ghost_rect_in);
        void updatePellets();
        void initPellets();
        void initIntersections();

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