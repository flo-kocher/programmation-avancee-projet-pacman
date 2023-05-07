#ifndef __GAME_INTERFACE_H__
#define __GAME_INTERFACE_H__

#include <SDL.h>
#include <map>
#include <array>
#include "../include/Pellet.h"
#include "../include/BigPellet.h"
#include "../include/Intersection.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"

// FPS DELAY of the window
// lower it to increase the speed of the game
#define DELAY 4

/**
 * @brief Declared in the GameManager, it is used to handle the SDL Interface and to update for example the Pellets
 * when they are eaten by PacMan
 * 
 */
class GameInterface
{
    private:
        // The bitmap rectangle
        SDL_Rect src_bg_;
        SDL_Rect bg_;

    public:
        SDL_Window *pWindow_ = nullptr;
        SDL_Surface *win_surf_ = nullptr;
        SDL_Surface *plancheSprites_ = nullptr;

        /**
         * @brief Construct a new Game Interface object
         * 
         */
        GameInterface();
        ~GameInterface();

        /**
         * @brief Updates the characters images ahead of the background
         * 
         * @tparam T 
         * @param array an array of characters of type PacMan, Ghost
         */
        template <typename T>
        void updateCharacters(T array);

        /**
         * @brief Updates the background of the bitmap to show that a pellet was eaten by PacMan
         * 
         * @tparam T 
         * @param map a map of Pellets, BigPellets, Intersections or BigIntersections
         */
        template <typename T>
        void updateZones(T map);

        /**
         * @brief Handles all the interface updates that happen during the game (all in real-time)
         * Examples :
         * - blinks of the BigPellets
         * - update the background when a Pellet is eaten
         * - update the characters image
         * 
         * @param timer the current timer in the game
         * @param pacman the pacman
         * @param ghosts all the ghosts
         * @param pellets all the pellets
         * @param big_pellets all the big_pellets
         * @param intersections all the intersections
         * @param intersections_big all the big_intersections
         */
        void updateGameInterface(int timer, std::shared_ptr<Pacman> pacman,
                                    std::array<std::shared_ptr<Ghost>, 4> ghosts,
                                    std::map<std::string, std::shared_ptr<Pellet>> pellets,
                                    std::map<std::string, std::shared_ptr<BigPellet>> big_pellets,
                                    std::map<std::string, std::shared_ptr<Intersection<Pellet>>> intersections,
                                    std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> intersections_big);

        /**
         * @brief Set the Color And Blit Scaled object
         * the function that applies a rectangle on the background
         * 
         * @param transparence true if your want a transparent color else false
         * @param src_rect rectangle to apply
         * @param dst_rect rectangle to update
         */
        inline void setColorAndBlitScaled(const bool transparence, const SDL_Rect* src_rect, SDL_Rect* dst_rect)
        {
            // int SDL_BlitScaled(SDL_Surface*    src,
            //                const SDL_Rect* srcrect,
            //                SDL_Surface*    dst,
            //                SDL_Rect*       dstrect)
            SDL_SetColorKey(plancheSprites_, transparence, 0);
            SDL_BlitScaled(plancheSprites_, src_rect, win_surf_, dst_rect);
        }; 
};

#endif