#include "../include/GameInterface.h"
#include "../include/Character.h"
#include <iostream>
#include <array>
#include <SDL.h>

GameInterface::GameInterface()
: src_bg_({200, 3, 168, 216})
, bg_({4, 4, 672, 864})
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    if((pWindow_ = SDL_CreateWindow("PacManGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN)) == NULL)
    {
        std::cerr<<"Echec de la création de la fenêtre "<<SDL_GetError()<<std::endl;
        exit(EXIT_FAILURE);
    }

    if((win_surf_ = SDL_GetWindowSurface(pWindow_)) == NULL)
    {
        std::cerr<<"Echec de la récupération de la surface de la fenêtre "<<SDL_GetError()<<std::endl;
        exit(EXIT_FAILURE);
    }

    if((plancheSprites_ = SDL_LoadBMP(SPRITES_PATH)) == NULL)
    {
        std::cerr<<"Echec du chargement du bmp "<<SDL_GetError()<<std::endl;
        exit(EXIT_FAILURE);
    }
}

GameInterface::~GameInterface()
{

}

template <typename T>
void GameInterface::updateCharacters(T array)
{
    for (auto it = array.begin(); it != array.end(); ++it) {
        SDL_Rect* image = it->get()->character_image_;
        SDL_Rect position = it->get()->position_;
        setColorAndBlitScaled(true, image, &position);
    }
}

template <typename T>
void GameInterface::updatePellets(T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(!it->second->getGotThrough())
        {
            SDL_Rect init = {376, 10, 10, 10};
            setColorAndBlitScaled(false, &init, it->second->getRectangle());
        }
    }
}

template <typename T>
void GameInterface::updateIntersections(T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(!it->second->getGotThrough())
        {
            SDL_Rect init = {376, 10, 10, 10};
            setColorAndBlitScaled(false, &init, it->second->getRectangle());
        }
    }
}

void GameInterface::updateGameInterface(int timer, std::shared_ptr<Pacman> pacman,
                            std::array<std::shared_ptr<Ghost>, 4> ghosts,
                            std::map<std::string, std::shared_ptr<Pellet>> pellets,
                            std::map<std::string, std::shared_ptr<BigPellet>> big_pellets,
                            std::map<std::string, std::shared_ptr<Intersection<Pellet>>> intersections,
                            std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> intersections_big)
{
    setColorAndBlitScaled(false, &src_bg_, &bg_);

    SDL_Rect black_rect = {376, 10, 10, 10}; // Position d'un rectangle noir

    if(0 <= timer && timer <= 125)
    {
        setColorAndBlitScaled(false, &black_rect, intersections_big.at("BigIntersection 19_00")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, intersections_big.at("BigIntersection 19_18")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, big_pellets.at("BigPellet 02_00")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, big_pellets.at("BigPellet 02_18")->getRectangle());
    }

    std::array<std::shared_ptr<Pacman>, 1> pacman_as_array = {pacman};
    updatePellets(pellets);
    updatePellets(big_pellets);
    updateIntersections(intersections);
    updateIntersections(intersections_big);
    updateCharacters(pacman_as_array);
    updateCharacters(ghosts);

    SDL_UpdateWindowSurface(pWindow_);

    // LIMITE A 60 FPS
    SDL_Delay(5); // SDL_Delay(16); de base
    // utiliser SDL_GetTicks64() pour plus de precisions
}
