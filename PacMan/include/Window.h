#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL.h>
#include "Character.h"
#include "GameManager.h"

class Window
{
    private:
        SDL_Window *pWindow = nullptr;
        SDL_Surface *win_surf = nullptr;
        SDL_Surface *plancheSprites = nullptr;
        int count;
        SDL_Rect src_bg;
        SDL_Rect bg;
        Character* ghost;
        int direction_tmp;
        bool intersection_detected;
        int last_pressed_key;
        // init le GameManager ici
        GameManager* gameManager;
    
    public:
        Window();
        Window(SDL_Window *pWindow, SDL_Surface *win_surf, SDL_Surface *plancheSprites, int count);
        ~Window();

        void update();

        inline const SDL_Window* getPWindow()
        {
            return pWindow;
        };
        inline const SDL_Surface* getWinSurf()
        {
            return win_surf;
        };
        inline const SDL_Surface* getPlanchesSprites()
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

        inline void setDirectionRight()
        {
            last_pressed_key = 0;
        };
        inline void setDirectionDown()
        {
            last_pressed_key = 1;
        };
        inline void setDirectionLeft()
        {
            last_pressed_key = 2;
        };
        inline void setDirectionUp()
        {
            last_pressed_key = 3;
        };
    
};

#endif