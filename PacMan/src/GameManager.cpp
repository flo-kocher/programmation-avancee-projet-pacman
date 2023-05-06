#include "../include/GameManager.h"
#include "../include/KeyboardManager.h"
#include "../include/Constante.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"

#include <iostream>
#include <chrono>
#include <SDL.h>

int GameManager::feared_timer_ = 0;

GameManager::GameManager()
: score_(0)
, feared_timer_running_(false)
, current_ghost_mode_(SCATTER)
, current_game_step_(SCATTER1)
, pacman_alive_(true)
, consecutive_ghost_eaten_(0)
, direction_tmp_ (RIGHT)
, intersection_detected_ (false)
, mode_start_timer_(std::chrono::steady_clock::now())
, gameInterface_(std::make_unique<GameInterface>())
{
    std::cout<<"GameInterface constructor\n";
}


GameManager::~GameManager()
{
    pellets.clear();
    big_pellets.clear();
    intersections.clear();
    intersections_big.clear();
}

void GameManager::initCharacters()
{
    initCharacter(PACMAN, {322, 642, 32, 32}, PACMAN_IMAGES.find("LEFT")->second, LEFT);
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
    //std::cout<<this->getScore()<<std::endl;
    incrementCount();
    if(feared_timer_running_)
    {
        decrementFearedTimer();
        if(feared_timer_ == 0)
            setGhostsNormal(getCount());           
    }
    
    checkGameStep();

    if(isGameOver())
        return true;

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

    checkIfInCorridor();
    checkForPellet(pacman_->position_.x, pacman_->position_.y);
    checkForTeleportation<std::shared_ptr<Pacman>>(pacman_);
    for(int i = 0; i < ghosts_.size(); ++i)
    {
        if(feared_timer_running_ && !ghosts_[i]->getIsEaten()){
            ghosts_[i]->frightened(count_);
        }
        else if(ghosts_[i]->getIsEaten()){
            ghosts_[i]->eaten(count_);
        }
        else{
            switch (current_ghost_mode_)
            {
                case CHASE :
                    ghosts_[i]->chase(pacman_, count_, ghosts_[0]);
                    break;
                case SCATTER :
                    ghosts_[i]->scatter(count_);
                    break;
            }
        }

        checkForTeleportation<std::shared_ptr<Ghost>>(ghosts_[i]);

        if(collisionWithGhost(ghosts_[i]))
        {
            actionWithGhost(ghosts_[i]);
        }
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
    if(this->getScore() == 9999 || !pacmanAlive())
    {
        std::cout<<"Score : "<<getScore()<<std::endl;
        return true;
    }
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

void GameManager::checkIfInCorridor()
{
    for(auto ghost_it = ghosts_.begin(); ghost_it != ghosts_.end(); ++ghost_it)
    {
        Ghost* ghost = ghost_it->get();
        if(ghost->position_.y == 418 && (ghost->position_.x <= 161 || ghost->position_.x >= 515))
        {
            if(!ghost->isInCorridor())
            {
                ghost->setIsInCorridor(true);
                if(!ghost->getIsFeared())
                    ghost->lowerSpeed();
            }
        }
        else
        {
            if(ghost->isInCorridor())
            {
                ghost->setIsInCorridor(false);
                if(!ghost->getIsFeared())
                    ghost->increaseSpeed();
            }
        }
    }
}

bool GameManager::collisionWithGhost(std::shared_ptr<Ghost> ghost)
{
    int pos_diff_x = abs(pacman_->position_.x - ghost->position_.x);
    int pos_diff_y = abs(pacman_->position_.y - ghost->position_.y);
    if(0 <= pos_diff_x && pos_diff_x <= HITBOX && 0 <= pos_diff_y  && pos_diff_y <= HITBOX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GameManager::setGhostsFeared(int count)
{
    if(!feared_timer_running_)
    {
        for(int i = 0; i < ghosts_.size(); ++i)
        {
            if(!ghosts_[i]->isInCorridor())
                ghosts_[i]->lowerSpeed();
            ghosts_[i]->setIsFeared(true);
            setGhostOppositeDirection(ghosts_[i]);
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
        if(!ghosts_[i]->isInCorridor())
            ghosts_[i]->increaseSpeed();
        ghosts_[i]->setIsFeared(false);
    }
    setConsecutiveEatenGhosts(0);
}

void GameManager::checkGameStep()
{
    switch (current_game_step_)
    {
        case SCATTER1 :
            switchGhostsTrackingMode(7, CHASE, CHASE1);
            break;
        case CHASE1 :
            switchGhostsTrackingMode(20, SCATTER, SCATTER2);
            break;
        case SCATTER2 :
            switchGhostsTrackingMode(7, CHASE, CHASE2);
            break;
        case CHASE2 :
            switchGhostsTrackingMode(20, SCATTER, SCATTER3);
            break;
        case SCATTER3 :
            switchGhostsTrackingMode(5, CHASE, CHASE3);
            break;
        case CHASE3 :
            switchGhostsTrackingMode(20, SCATTER, SCATTER4);
            break;
        case SCATTER4 :
            switchGhostsTrackingMode(5, CHASE, CHASE4);
            break;
        case CHASE4 :
            break;
    }
}

void GameManager::switchGhostsTrackingMode(double timer, GhostMode new_ghost_mode, GameStep next_game_step)
{
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = now - mode_start_timer_ ;
    if(elapsed_seconds.count() > timer)
    {
        mode_start_timer_ = now;
        current_ghost_mode_ = new_ghost_mode;
        current_game_step_ = next_game_step;
        for(int i = 0; i < ghosts_.size(); ++i)
        {
            setGhostOppositeDirection(ghosts_[i]);
        }
    }
}

void GameManager::setGhostOppositeDirection(std::shared_ptr<Ghost> ghost)
{
    Direction current_ghost_direction_ = ghost->getDirection();
    if(!ghost->getIsEaten() && !ghost->getIsFeared())
    {
        ghost->setPossibleDirection(
            current_ghost_direction_ == LEFT ? true : false, 
            current_ghost_direction_ == UP ? true : false, 
            current_ghost_direction_ == RIGHT ? true : false, 
            current_ghost_direction_ == DOWN ? true : false
        );
        ghost->setDirection(
            current_ghost_direction_ == RIGHT ? LEFT : 
            current_ghost_direction_ == LEFT ? RIGHT : 
            current_ghost_direction_ == UP ? DOWN : 
            UP
        );
    }
}

void GameManager::actionWithGhost(std::shared_ptr<Ghost> ghost)
{
    if(ghost->getIsFeared())
    {
        incrementConsecutiveEatenGhosts();
        ghost->setIsEaten();
        if(!ghost->isInCorridor())
            ghost->increaseSpeed();
        ghost->setEatenStartTimer(std::chrono::steady_clock::now());
        AddToScore(200*getConsecutiveEatenGhosts());
    }
    else if(ghost->getIsEaten())
    {
        
    }
    else
        pacmanDied();
}
