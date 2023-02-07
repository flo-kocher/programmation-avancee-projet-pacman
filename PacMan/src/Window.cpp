#include "../include/Window.h"
#include <iostream>

Window::Window()
{
    pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);
    plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
    count = 0;
    SDL_Rect src_bg = {200, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    SDL_Rect bg = {4, 4, 672, 864};       // ici scale x4
}

Window::Window(SDL_Window *pWindow, SDL_Surface *win_surf, SDL_Surface *plancheSprites, int count)
{
    pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);
    plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
    count = 0;
    SDL_Rect src_bg = {200, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    SDL_Rect bg = {4, 4, 672, 864};       // ici scale x4

}

Window::~Window()
{

}

void Window::update()
{
    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_bg, win_surf, &bg);
}

SDL_Window* Window::get_pWindow()
{
    return pWindow;
}

SDL_Surface* Window::get_win_surf()
{
    return win_surf;
}

SDL_Surface* Window::get_plancheSprites()
{
    return plancheSprites;
}

int Window::get_count()
{
    return count;
}

SDL_Rect Window::get_src_bg()
{
    return src_bg;
}

SDL_Rect Window::get_bg()
{
    return bg;
}