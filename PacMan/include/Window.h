#include <SDL.h>

class Window
{
    protected:
    SDL_Window *pWindow = nullptr;
    SDL_Surface *win_surf = nullptr;
    SDL_Surface *plancheSprites = nullptr;
    int count;
    SDL_Rect src_bg;
    SDL_Rect bg;

    protected:
    Window();
    Window(SDL_Window *pWindow, SDL_Surface *win_surf, SDL_Surface *plancheSprites, int count);
    ~Window();

    // update();
    
};