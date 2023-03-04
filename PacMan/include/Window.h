#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL.h>
#include "Character.h"
#include "Pellet.h"

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
    // fonctionne : Pellet* test;

    // intersections
    SDL_Rect intersection00 = {206, 9, 12, 12};
    SDL_Rect intersection01 = {214, 9, 12, 12};
    SDL_Rect intersection02 = {222, 9, 12, 12};
    SDL_Rect intersection03 = {230, 9, 12, 12};
    SDL_Rect intersection04 = {238, 9, 12, 12};
    SDL_Rect intersection05 = {254, 9, 12, 12};
    SDL_Rect intersection06 = {262, 9, 12, 12};
    SDL_Rect intersection07 = {270, 9, 12, 12};

    SDL_Rect intersection10 = {206, 17, 12, 12};
    SDL_Rect intersection14 = {238, 17, 12, 12};
    SDL_Rect intersection17 = {270, 17, 12, 12};

    SDL_Rect intersection20 = {206, 25, 12, 12};
    SDL_Rect intersection24 = {238, 25, 12, 12};
    SDL_Rect intersection27 = {270, 25, 12, 12};

    SDL_Rect intersection30 = {206, 33, 12, 12};
    SDL_Rect intersection34 = {238, 33, 12, 12};
    SDL_Rect intersection37 = {270, 33, 12, 12};

    SDL_Rect intersection40 = {206, 41, 12, 12};
    SDL_Rect intersection41 = {214, 41, 12, 12};
    SDL_Rect intersection42 = {222, 41, 12, 12};
    SDL_Rect intersection43 = {230, 41, 12, 12};
    SDL_Rect intersection44 = {238, 41, 12, 12};
    SDL_Rect intersection45 = {254, 41, 12, 12};
    SDL_Rect intersection46 = {262, 41, 12, 12};
    SDL_Rect intersection47 = {270, 41, 12, 12};

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


    // inline void setCurrentCourse(std::string new_course)
        // {
            // course = new_course;
        // };
    
};

#endif