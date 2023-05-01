#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <SDL.h>
#include <iostream>
#include <memory>

class Character
{
    private:
        SDL_Rect ghost_r = {3, 123, 16, 16};
        SDL_Rect ghost_l = {37, 123, 16, 16};
        SDL_Rect ghost_d = {105, 123, 16, 16};
        SDL_Rect ghost_u = {71, 123, 16, 16};
    
    public:
        // std::unique_ptr<SDL_Rect> ghost_in;
        SDL_Rect *ghost_in;
        SDL_Rect ghost = {34, 34, 32, 32}; // ici scale x2

    Character();
    Character(int coord_x, int coord_y, bool has_pellet);
    ~Character();
    
    void turnRight()
    {
        ghost_in = &(ghost_r);
        ghost.x++;
    };
    void turnDown()
    {
        ghost_in = &(ghost_d);
        ghost.y++;
    };
    void turnLeft()
    {
        ghost_in = &(ghost_l);
        ghost.x--;
    };
    void turnUp()
    {
        ghost_in = &(ghost_u);
        ghost.y--;
    };
    void standStill()
    {
        
    };

    inline SDL_Rect* getGhost()
    {
        return &ghost;
    };

    inline SDL_Rect getGhostIn()
    {
        return *ghost_in;
    };
};

#endif