#include "../include/GameManager.h"
#include <iostream>

#include <SDL.h>

#ifdef __unix__
    #define OS_Windows 0
    #define SPRITE_PATH "./pacman_sprites.bmp"
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows 1
    #define SPRITE_PATH "../pacman_sprites.bmp"
#endif

GameManager::GameManager()
: count(0)
, src_bg({200, 3, 168, 216})
, bg({4, 4, 672, 864})
, score(0)
{
    // on fait une variable coordonnées{X, X, X, X}, qu'on va augmenter en faisant des x+=4 etc...
    // et pour a la version updaté, quand on passe sur la case, on a juste à prendre
    // la même valeur mais avec un y+= 100 par exemple (on a juste un décalage sur une coord sur le Sprite)

    // ------------>>>>>>>>>>>
    // en fait on a même pas besoin de données la valeur, il peut la calculer lui
    // même en prenant la valeur de la case de base !!!!!

    std::cout<<"Window constructor\n";
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        // exit il faut peut être faire autrement
        exit(0);
    }
    if((pWindow = SDL_CreateWindow("PacManGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN)) == NULL)
        std::cerr<<"Echec de la création de la fenêtre "<<SDL_GetError()<<std::endl;
    if((win_surf = SDL_GetWindowSurface(pWindow)) == NULL)
        std::cerr<<"Echec de la récupération de la surface de la fenêtre "<<SDL_GetError()<<std::endl;
    if((plancheSprites = SDL_LoadBMP(SPRITE_PATH)) == NULL)
        std::cerr<<"Echec du chargement du bmp "<<SDL_GetError()<<std::endl;

    initPellets(&pellets, &big_pellets);
    initIntersections(&intersections, &intersections_big);
}


GameManager::~GameManager()
{

}

bool GameManager::isGameOver()
{
    if(score == 2100)
        return true;
    return false;
}

template <typename T>
int GameManager::checkForPelletTemplate(int x, int y, T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(it->second->x == x && it->second->y == y)
        {
            // std::cout<<it->first<<std::endl;
            it->second->setGotThrew(false);
            if(it->second->hasPellet())
            {
                score += it->second->addPoints();
                it->second->setHasPellet();
            }
            if(it->first == "Pellet 12_left")
                {std::cout<<it->second->x<<std::endl;std::cout<<it->second->y<<std::endl;return 0;}
            if(it->first == "Pellet 12_right")
                {std::cout<<it->second->x<<std::endl;std::cout<<it->second->y<<std::endl;return 18;}
        }
    }
    return -1;
}

int GameManager::checkForPellet(int x, int y)
{
    checkForPelletTemplate(x, y, big_pellets);
    return checkForPelletTemplate(x, y, pellets);
}

template <typename T>
int GameManager::checkForIntersectionTemplate(int x, int y, int last_pressed_key, T map)
{
    bool isIntersection = false;
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(it->second->x == x && it->second->y == y)
        {
            // std::cout<<it->first<<std::endl;
            it->second->setGotThrew(false);
            if(it->second->hasPellet())
            {
                score += it->second->addPoints();
                it->second->setHasPellet();
            }
            if(last_pressed_key == 0 && it->second->canGoRight() || last_pressed_key == 1 && it->second->canGoDown()
            || last_pressed_key == 2 && it->second->canGoLeft() || last_pressed_key == 3 && it->second->canGoUp())
                return 1;
            else
                return 2;
        }
    }
    return 0;
}

int GameManager::checkForIntersection(int x, int y, int last_pressed_key)
{
    return checkForIntersectionTemplate(x, y, last_pressed_key, intersections) + checkForIntersectionTemplate(x, y, last_pressed_key, intersections_big);
}

template <typename T>
void GameManager::updatePellets(T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(!it->second->getGotThrew())
        {
            SDL_Rect init = {376, 10, 10, 10};
            setColorAndBlitScaled(false, &init, it->second->getRectangle());
        }
    }
}

template <typename T>
void GameManager::updateIntersections(T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(!it->second->getGotThrew())
        {
            SDL_Rect init = {376, 10, 10, 10};
            setColorAndBlitScaled(false, &init, it->second->getRectangle());
        }
    }
}

void GameManager::updateInterface(SDL_Rect* ghost_rect, SDL_Rect ghost_rect_in)
{
    setColorAndBlitScaled(false, &src_bg, &bg);
    std::cout<<score<<std::endl;

    SDL_Rect black_rect = {376, 10, 10, 10}; // Position d'un rectangle noir

    count = (count + 1) % (250);
    if(0 <= count && count <= 125)
    {
        setColorAndBlitScaled(false, &black_rect, intersections_big.at("BigIntersection 19_00")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, intersections_big.at("BigIntersection 19_18")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, big_pellets.at("BigPellet 02_00")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, big_pellets.at("BigPellet 02_18")->getRectangle());
    }

    updatePellets(pellets);
    updatePellets(big_pellets);
    updateIntersections(intersections);
    updateIntersections(intersections_big);

    SDL_Rect ghost_in2 = ghost_rect_in;
    // if ((count / 8) % 2)
        // ghost_in2.x += 20;
    setColorAndBlitScaled(true, &ghost_in2, ghost_rect);

    SDL_UpdateWindowSurface(pWindow);

    // LIMITE A 60 FPS
    SDL_Delay(4); // SDL_Delay(16); de base
    // utiliser SDL_GetTicks64() pour plus de precisions

}
