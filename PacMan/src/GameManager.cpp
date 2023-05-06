#include "../include/GameManager.h"
#include "../include/KeyboardManager.h"
#include "../include/Constante.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"

#include <iostream>

#include <SDL.h>

int GameManager::count_ = 0;
int GameManager::feared_timer_ = 0;

GameManager::GameManager()
: score_(0)
, feared_timer_running_(false)
, direction_tmp_ (RIGHT)
, intersection_detected_ (false)
, gameInterface_(std::make_unique<GameInterface>())
{
    std::cout<<"GameInterface constructor\n";
}


GameManager::~GameManager()
{

}

void GameManager::initCharacters()
{
    initCharacter(PACMAN, {34, 34, 32, 32}, PACMAN_IMAGES.find("RIGHT")->second, RIGHT);
    initCharacter(RED_GHOST, {322, 322, 32, 32}, RED_GHOST_IMAGES.find("LEFT")->second, LEFT);
    initCharacter(PINK_GHOST, {322, 418, 32, 32}, PINK_GHOST_IMAGES.find("DOWN")->second, UP);
    initCharacter(BLUE_GHOST, {290, 418, 32, 32}, BLUE_GHOST_IMAGES.find("UP")->second, RIGHT);
    initCharacter(YELLOW_GHOST, {354, 418, 32, 32}, YELLOW_GHOST_IMAGES.find("UP")->second, LEFT);
}

void GameManager::initCharacter(CharacterName name, SDL_Rect start_position, SDL_Rect* image, Direction direction){
    if(name == PACMAN){
        pacman_ = std::make_unique<Pacman>(name, start_position, image, direction);
    }
    else{
        ghosts_[name - 1] = std::make_shared<Ghost>(name, start_position, image, direction);
    }
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
                // std::cout << "setDirection(LEFT)\n";
                pacman_->setDirection(LEFT);
                break;
            case RIGHT:
                // std::cout << "setDirection(RIGHT)\n";
                pacman_->setDirection(RIGHT);
                break;
            case UP:
                // std::cout << "setDirection(UP)\n";
                pacman_->setDirection(UP);
                break;
            case DOWN:
                // std::cout << "setDirection(DOWN)\n";
                pacman_->setDirection(DOWN);
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
    incrementCount();
    if(feared_timer_running_)
    {
        if(feared_timer_ == 0)
            setGhostsNormal(getCount());
        decrementFearedTimer();
    }

    if(isGameOver())
    {
        std::cout<<"FINITO"<<std::endl;
        return true;
    }

    Direction pacman_direction = pacman_->getDirection();
    if((intersection_detected_ && pacman_direction != direction_tmp_) || (pacman_direction == RIGHT && direction_tmp_ == LEFT) || (pacman_direction == LEFT && direction_tmp_ == RIGHT) || (pacman_direction == DOWN && direction_tmp_ == UP) || (pacman_direction == UP && direction_tmp_ == DOWN))
    {
        direction_tmp_ = pacman_direction;
        intersection_detected_ = false;
    }
    else
        intersection_detected_ = false;

    switch(direction_tmp_)
    {
        case RIGHT:
            pacman_->goRight(getCount());
            break;
        case DOWN:
            pacman_->goDown(getCount());
            break;
        case LEFT:
            pacman_->goLeft(getCount());
            break;
        case UP:
            pacman_->goUp(getCount());
            break;
        case -1:
            pacman_->standStill();
            break;
    }

    for(auto ghost_it = ghosts_.begin(); ghost_it != ghosts_.end(); ++ghost_it)
    {
        Ghost* ghost = ghost_it->get();
        //ghost->chase(pacman_, count_);
        ghost->scatter(count_);
    }

    // int character_position = collisionWithGhost();
    // if(character_position != -1)
    // {
    //     // Donner à chaque Ghost une zone où laquelle respawn
    //     ghosts_[character_position]->position_.x = 250;
    //     ghosts_[character_position]->position_.y = 34;
    // }

    checkForPellet(pacman_->position_.x, pacman_->position_.y);
    checkForTeleportation<std::shared_ptr<Pacman>>(pacman_);
    for(int i = 0; i < 4; ++i)
    {
        checkForTeleportation<std::shared_ptr<Ghost>>(ghosts_[i]);
    }
    
    int intersection_check = checkForIntersection();
    if(intersection_check == 1)
        intersection_detected_ = true;
    else if(intersection_check == 2)
        direction_tmp_ = -1;

    // gère tout l'affichage dans le GameInterface en fonction des events qui sont catch juste au dessus (impossible de faire des appels en plusieurs fonctions)
    gameInterface_->updateGameInterface(getCount(), pacman_, ghosts_, pellets, big_pellets, intersections, intersections_big);

    return false;

}

bool GameManager::isGameOver()
{
    if(this->getScore() == 2100)
        return true;
    return false;
}

template <typename T>
void GameManager::checkForTeleportation(T character)
{
    if(pellets.find("Pellet 12_left")->second->getX() == character->position_.x && pellets.find("Pellet 12_left")->second->getY() == character->position_.y)
    {
        character->teleportRight();
    }
    else if(pellets.find("Pellet 12_right")->second->getX() == character->position_.x && pellets.find("Pellet 12_right")->second->getY() == character->position_.y)
    {
        character->teleportLeft();
    }
}

template <typename T>
void GameManager::checkForPelletTemplate(int x, int y, T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(it->second->getX() == x && it->second->getY() == y)
        {
            // std::cout<<it->first<<std::endl;
            it->second->setGotThrough(false);
            if(it->second->hasPellet())
            {
                this->AddToScore(it->second->addPoints());
                it->second->setHasPellet();
                if(it->second->hasAdditionalBehavior())
                    this->setGhostsFeared(count_);
            }
            break;
        }
    }
}

void GameManager::checkForPellet(int x, int y)
{
    checkForPelletTemplate(x, y, big_pellets);
    checkForPelletTemplate(x, y, pellets);
}

template <typename T>
int GameManager::checkForIntersectionTemplate(T map)
{
    int res = 0;
    Direction pacman_direction = pacman_->getDirection();
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(it->second->getX() == pacman_->position_.x && it->second->getY() == pacman_->position_.y){
            pacman_->setPossibleDirection(
                it->second->canGoRight(),
                it->second->canGoDown(),
                it->second->canGoLeft(),
                it->second->canGoUp()
            );
            // std::cout<<it->first<<std::endl;
            it->second->setGotThrough(false);
            if(it->second->hasPellet())
            {
                this->AddToScore(it->second->addPoints());
                it->second->setHasPellet();
                if(it->second->hasAdditionalBehavior())
                    this->setGhostsFeared(count_);
            }
        
            if(pacman_direction == RIGHT && it->second->canGoRight() || pacman_direction == DOWN && it->second->canGoDown()
            || pacman_direction == LEFT && it->second->canGoLeft() || pacman_direction == UP && it->second->canGoUp())
                res = 1;
            else
                res = 2;
        }

        for(auto ghost_it = ghosts_.begin(); ghost_it != ghosts_.end(); ++ghost_it){
            Ghost* ghost = ghost_it->get();

            if(it->second->getX() == ghost->position_.x && it->second->getY() == ghost->position_.y)
            {
                Direction ghost_direction = ghost->getDirection();
                ghost->setPossibleDirection(
                    it->second->canGoRight() && ghost_direction != LEFT,
                    it->second->canGoDown() && ghost_direction != UP, 
                    it->second->canGoLeft() && ghost_direction != RIGHT, 
                    it->second->canGoUp() && ghost_direction != DOWN
                );
            }   
        }
    }
    return res;
}

int GameManager::checkForIntersection()
{
    return checkForIntersectionTemplate(intersections) + checkForIntersectionTemplate(intersections_big);
}


int GameManager::collisionWithGhost()
{
    for (int i = 0; i < 4; i++) {
        int pos_diff_x = abs(pacman_->position_.x - ghosts_[i]->position_.x);
        int pos_diff_y = abs(pacman_->position_.y - ghosts_[i]->position_.y);
        if(0 <= pos_diff_x && pos_diff_x <= HITBOX && 0 <= pos_diff_y  && pos_diff_y <= HITBOX)
        {
            return i;
        }
    }
    return -1;
}

void GameManager::setGhostsFeared(int count)
{
    if(!feared_timer_running_)
    {
        for(int i = 0; i < ghosts_.size(); ++i)
        {
            ghosts_[i]->lowerSpeed();
            ghosts_[i]->setIsFeared(true);
        }
        activateFearedTimer();
    }
    else
        resetFearedTimer();
}

void GameManager::setGhostsNormal(int count)
{
    deactivateFearedTimer();
    for(int i = 0; i < ghosts_.size(); ++i)
    {
        ghosts_[i]->increaseSpeed();
        ghosts_[i]->setIsFeared(false);
    }
}
