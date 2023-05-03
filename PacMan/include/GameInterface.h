#ifndef __GAME_INTERFACE_H__
#define __GAME_INTERFACE_H__

#include <SDL.h>
#include "Pacman.h"
#include "Ghost.h"
#include "Pellet.h"
#include "Intersection.h"
#include "Character.h"
#include <memory>

class GameInterface
{
    private:
        SDL_Rect src_bg_;
        SDL_Rect bg_;

    public:
        SDL_Window *pWindow_ = nullptr;
        SDL_Surface *win_surf_ = nullptr;
        SDL_Surface *plancheSprites_ = nullptr;

        GameInterface();
        ~GameInterface();

        void updateCharacters(std::array<std::shared_ptr<Character>, 5> array);
        template <typename T>
        void updatePellets(T map);
        template <typename T>
        void updateIntersections(T map);
        void updateGameInterface(int timer, std::array<std::shared_ptr<Character>, 5> array,
                                    std::map<std::string, std::shared_ptr<Pellet>> pellets,
                                    std::map<std::string, std::shared_ptr<BigPellet>> big_pellets,
                                    std::map<std::string, std::shared_ptr<Intersection<Pellet>>> intersections,
                                    std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> intersections_big);


        inline void setColorAndBlitScaled(const bool transparence, const SDL_Rect* src_rect, SDL_Rect* dst_rect)
        {
            // if true then transparent color
            // int SDL_BlitScaled(SDL_Surface*    src,
            //                const SDL_Rect* srcrect,
            //                SDL_Surface*    dst,
            //                SDL_Rect*       dstrect)
            SDL_SetColorKey(plancheSprites_, transparence, 0);
            SDL_BlitScaled(plancheSprites_, src_rect, win_surf_, dst_rect);
        };

    
};

#endif