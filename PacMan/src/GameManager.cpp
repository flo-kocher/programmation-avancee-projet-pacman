#include "../include/GameManager.h"
#include "../include/Constante.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"
// #include "../include/Character.h"

#include <iostream>

#include <SDL.h>

GameManager::GameManager()
: count_(0)
, src_bg_({200, 3, 168, 216})
, bg_({4, 4, 672, 864})
, score_(0)
{
    std::cout<<"Window constructor\n";
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        // exit il faut peut être faire autrement
        exit(0);
    }
    if((pWindow_ = SDL_CreateWindow("PacManGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN)) == NULL)
        std::cerr<<"Echec de la création de la fenêtre "<<SDL_GetError()<<std::endl;
    if((win_surf_ = SDL_GetWindowSurface(pWindow_)) == NULL)
        std::cerr<<"Echec de la récupération de la surface de la fenêtre "<<SDL_GetError()<<std::endl;
    if((plancheSprites_ = SDL_LoadBMP(SPRITES_PATH)) == NULL)
        std::cerr<<"Echec du chargement du bmp "<<SDL_GetError()<<std::endl;

    initPellets(&pellets, &big_pellets);
    initIntersections(&intersections, &intersections_big);
    initCharacters();
}


GameManager::~GameManager()
{

}

void GameManager::initCharacters()
{
    initCharacter(PACMAN, {34, 34, 32, 32}, PACMAN_IMAGES.find("RIGHT")->second);
    initCharacter(RED_GHOST, {322, 322, 32, 32}, RED_GHOST_IMAGES.find("LEFT")->second);
    initCharacter(PINK_GHOST, {322, 402, 32, 32}, PINK_GHOST_IMAGES.find("DOWN")->second);
    initCharacter(BLUE_GHOST, {288, 402, 32, 32}, BLUE_GHOST_IMAGES.find("UP")->second);
    initCharacter(YELLOW_GHOST, {358, 402, 32, 32}, YELLOW_GHOST_IMAGES.find("UP")->second);
}

void GameManager::initCharacter(CharacterName name, SDL_Rect start_position, SDL_Rect* image){
    std::shared_ptr<Character> character;
    if(name == PACMAN){
        character = std::make_shared<Pacman>(name, start_position, image);
    }
    else{
        character = std::make_shared<Ghost>(name, start_position, image);
    }
    characters[name] = character;
    setColorAndBlitScaled(true, character->character_image_, &character->position_);
}

bool GameManager::isGameOver()
{
    if(this->getScore() == 2100)
        return true;
    return false;
}

template <typename T>
int GameManager::checkForPelletTemplate(int x, int y, T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(it->second->getX() == x && it->second->getY() == y)
        {
            // std::cout<<it->first<<std::endl;
            it->second->setGotThrew(false);
            if(it->second->hasPellet())
            {
                this->AddToScore(it->second->addPoints());
                it->second->setHasPellet();
            }
            if(it->first == "Pellet 12_left")
                {std::cout<<it->second->getX()<<std::endl;std::cout<<it->second->getY()<<std::endl;return 0;}
            if(it->first == "Pellet 12_right")
                {std::cout<<it->second->getX()<<std::endl;std::cout<<it->second->getY()<<std::endl;return 18;}
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
        if(it->second->getX() == x && it->second->getY() == y)
        {
            // std::cout<<it->first<<std::endl;
            it->second->setGotThrew(false);
            if(it->second->hasPellet())
            {
                this->AddToScore(it->second->addPoints());
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
        if(!it->second->getGotThrough())
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
        if(!it->second->getGotThrough())
        {
            SDL_Rect init = {376, 10, 10, 10};
            setColorAndBlitScaled(false, &init, it->second->getRectangle());
        }
    }
}

void GameManager::updateCharacters(std::array<std::shared_ptr<Character>, 5> array)
{
    for (auto it = array.begin(); it != array.end(); ++it) {
        SDL_Rect* image = it->get()->character_image_;
        SDL_Rect position = it->get()->position_;
        setColorAndBlitScaled(true, image, &position);
    }
}

void GameManager::updateInterface()
{
    setColorAndBlitScaled(false, &src_bg_, &bg_);
    std::cout<<this->getScore()<<std::endl;

    SDL_Rect black_rect = {376, 10, 10, 10}; // Position d'un rectangle noir

    this->IncrementCount();
    if(0 <= this->getCount() && this->getCount() <= 125)
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
    updateCharacters(characters);

    SDL_UpdateWindowSurface(pWindow_);

    // LIMITE A 60 FPS
    SDL_Delay(10); // SDL_Delay(16); de base
    // utiliser SDL_GetTicks64() pour plus de precisions

}

int GameManager::collisionWithGhost()
{
    for (int i = 1; i < 5; i++) {
        int pos_diff_x = abs(characters[0]->position_.x-characters[i]->position_.x);
        int pos_diff_y = abs(characters[0]->position_.y-characters[i]->position_.y);
        if(0 <= pos_diff_x && pos_diff_x <= HITBOX && 0 <= pos_diff_y  && pos_diff_y <= HITBOX)
        {
            return i;
        }
    }
    return -1;
}
