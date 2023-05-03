#include "../include/GameManager.h"
#include "../include/KeyboardManager.h"
#include "../include/Constante.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"
// #include "../include/Character.h"

#include <iostream>

#include <SDL.h>

GameManager::GameManager()
: count_(0)
, score_(0)
, direction_tmp_ (0)
, intersection_detected_ (false)
, last_pressed_key_(0)
, gameInterface_(std::make_unique<GameInterface>())
{
    std::cout<<"GameInterface constructor\n";
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
    // setColorAndBlitScaled(true, character->character_image_, &character->position_);
}

void GameManager::runGame()
{
    std::cout<<"runGame"<<std::endl;
    initPellets(&pellets, &big_pellets);
    initIntersections(&intersections, &intersections_big);
    initCharacters();

    std::unique_ptr<KeyboardManager> kb_manager = std::make_unique<KeyboardManager>();

    int keyboard_event;

    // BOUCLE PRINCIPALE
    bool quit = false;
    while (!quit)
    {
        // Créer une fonction eventHandler pour tout ça

        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        keyboard_event = kb_manager->waitForEvent();

        switch (keyboard_event)
        {
        case -1:
            quit = true;
            break;
        case LEFT:
            setDirectionLeft();
            break;
        case RIGHT:
            setDirectionRight();
            break;
        case UP:
            setDirectionUp();
            break;
        case DOWN:
            setDirectionDown();
            break;
        default:
            // Do nothing
            break;
        }

        // AFFICHAGE
        // if(window->update())
            // quit = true;
        if(updateGame())
            quit = true;
    }
    SDL_Quit(); // ON SORT

}

bool GameManager::updateGame()
{
    std::cout<<this->getScore()<<std::endl;
    IncrementCount();

    if(isGameOver())
    {
        std::cout<<"FINITO"<<std::endl;
        return true;
    }

    if(intersection_detected_ || last_pressed_key_ == 0 && direction_tmp_ == 2 || last_pressed_key_ == 2 && direction_tmp_ == 0 || last_pressed_key_ == 1 && direction_tmp_ == 3 || last_pressed_key_ == 3 && direction_tmp_ == 1)
    {
        direction_tmp_ = last_pressed_key_;
        intersection_detected_ = false;
    }
    else
        intersection_detected_ = false;

    switch(direction_tmp_)
    {
        case 0:
            characters[0]->turnRight(getCount());
            break;
        case 1:
            characters[0]->turnDown(getCount());
            break;
        case 2:
            characters[0]->turnLeft(getCount());
            break;
        case 3:
            characters[0]->turnUp(getCount());
            break;
        case -1:
            characters[0]->standStill();
            break;
    }

    int character_position;
    if(character_position = collisionWithGhost() > 0)
    {
        // Donner à chaque Ghost une zone où laquelle respawn
        characters[character_position]->position_.x = 250;
        characters[character_position]->position_.y = 34;
    }

    int pellet_number = checkForPellet(characters[0]->position_.x, characters[0]->position_.y);
    if(pellet_number == 0)
        characters[0]->teleportRight();
    if(pellet_number == 18)
        characters[0]->teleportLeft();
    if(checkForIntersection(characters[0]->position_.x, characters[0]->position_.y, last_pressed_key_) == 1)
        intersection_detected_ = true;
    else if(checkForIntersection(characters[0]->position_.x, characters[0]->position_.y, last_pressed_key_) == 2)
        direction_tmp_ = -1;

    // gère tout l'affichage dans le GameInterface en fonction des events qui sont catch juste au dessus (impossible de faire des appels en plusieurs fonctions)
    gameInterface_->updateGameInterface(getCount(), characters, pellets, big_pellets, intersections, intersections_big);

    return false;

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
