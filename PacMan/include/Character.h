#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <SDL.h>
#include <iostream>
class Character
{
    private:
        SDL_Rect ghost = {34, 34, 32, 32}; // ici scale x2
        SDL_Rect ghost_r = {3, 123, 16, 16};
        SDL_Rect ghost_l = {37, 123, 16, 16};
        SDL_Rect ghost_d = {105, 123, 16, 16};
        SDL_Rect ghost_u = {71, 123, 16, 16};
    
    public:
        SDL_Rect *ghost_in;

    Character();
    Character(int coord_x, int coord_y, bool has_pellet);
    ~Character();
    
    void turn_right();
    void turn_down();
    void turn_left();
    void turn_up();

    inline SDL_Rect* getGhost()
    {
        return &ghost;
    };

    inline SDL_Rect getGhostIn()
    {
        // SDL_Rect ghost_in2 = *ghost_in;
        return *ghost_in;
    };
};

#endif