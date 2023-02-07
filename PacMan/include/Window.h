#include <SDL.h>

class Window
{
    private:
    SDL_Window *pWindow = nullptr;
    SDL_Surface *win_surf = nullptr;
    SDL_Surface *plancheSprites = nullptr;
    int count;
    SDL_Rect src_bg;
    SDL_Rect bg;

    public:
    Window();
    Window(SDL_Window *pWindow, SDL_Surface *win_surf, SDL_Surface *plancheSprites, int count);
    ~Window();

    void update();

    SDL_Window* get_pWindow();
    SDL_Surface* get_win_surf();
    SDL_Surface* get_plancheSprites();
    int get_count();
    SDL_Rect get_src_bg();
    SDL_Rect get_bg();

    // protected:
    

    // Getters
    

    
};