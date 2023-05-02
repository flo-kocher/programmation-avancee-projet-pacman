#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <SDL.h>
#include <iostream>
#include <memory>

class Character
{
    private:
        SDL_Rect ghost_r = {19, 88, 16, 16};
        SDL_Rect ghost_r2 = {34, 88, 14, 16};
        SDL_Rect ghost_l = {45, 88, 16, 16};
        SDL_Rect ghost_l2 = {61, 88, 15, 16};
        SDL_Rect ghost_d = {108, 88, 16, 16};
        SDL_Rect ghost_d2 = {125, 91, 16, 16};
        SDL_Rect ghost_u = {74, 88, 16, 16};
        SDL_Rect ghost_u2 = {90, 88, 17, 16};

        // Fantôme rouge
        // SDL_Rect ghost_r = {3, 123, 16, 16};
        // SDL_Rect ghost_l = {37, 123, 16, 16};
        // SDL_Rect ghost_d = {105, 123, 16, 16};
        // SDL_Rect ghost_u = {71, 123, 16, 16};
    
    public:
        // std::unique_ptr<SDL_Rect> ghost_in;
        SDL_Rect *ghost_in;
        SDL_Rect ghost = {34, 34, 32, 32}; // ici scale x2

        void teleportRight();
        void teleportLeft();

    Character();
    Character(int coord_x, int coord_y, bool has_pellet);
    ~Character();
    
    void turnRight(int count)
    {
        ghost_in = &(ghost_r);
        if ((count / 8) % 2)
            ghost_in = &(ghost_r2);
        ghost.x++;
    };
    void turnDown(int count)
    {
        ghost_in = &(ghost_d);
        if ((count / 8) % 2)
            ghost_in = &(ghost_d2);
        ghost.y++;
    };
    void turnLeft(int count)
    {
        ghost_in = &(ghost_l);
        if ((count / 8) % 2)
            ghost_in = &(ghost_l2);
        ghost.x--;
    };
    void turnUp(int count)
    {
        ghost_in = &(ghost_u);
        if ((count / 8) % 2)
            ghost_in = &(ghost_u2);
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