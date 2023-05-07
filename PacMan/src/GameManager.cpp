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
, pellet_counter_(0)
, consecutive_ghost_eaten_(0)
, direction_tmp_ (RIGHT)
, intersection_detected_ (false)
, mode_start_timer_(std::chrono::steady_clock::now())
, gameInterface_(std::make_unique<GameInterface>())
{}

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
    // Initialize all the game objects and the KeyboardManager
    initPellets(&pellets, &big_pellets);
    initIntersections(&intersections, &intersections_big);
    initCharacters();
    std::unique_ptr<KeyboardManager> kb_manager = std::make_unique<KeyboardManager>();

    int keyboard_event;

    bool quit = false;
    while (!quit)
    {
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

        // Change the direction of the PacMan depending on the key pressed by the player
        switch (keyboard_event)
        {
            case -1:
                quit = true;
                break;
            case LEFT:
                pacman_->setDirection(LEFT);
                break;
            case RIGHT:
                pacman_->setDirection(RIGHT);
                break;
            case UP:
                pacman_->setDirection(UP);
                break;
            case DOWN:
                pacman_->setDirection(DOWN);
                break;
            default:
                // Do nothing
                break;
        }
        // updateGame is constently running
        if(updateGame())
            quit = true;
    }
    SDL_Quit(); // ON SORT

}

bool GameManager::updateGame()
{
    std::cout<<"Current score : "<<this->getScore()<<std::endl;

    incrementCount();

    // Setting back the ghosts to normal mode when the feared_timer is finished
    if(feared_timer_running_)
    {
        decrementFearedTimer();
        if(feared_timer_ == 0)
            setGhostsNormal(getCount());           
    }
    
    checkGameStep();

    // Check if one of the condition for the game to end is valid
    if(isGameOver())
        return true;

    // Get the current direction of the PacMan
    Direction pacman_direction = pacman_->getDirection();
    // Allow a change of direction only if it is to turn around or if PacMan reaches an Intersection
    if((intersection_detected_ && pacman_direction != direction_tmp_)
     || (pacman_direction == RIGHT && direction_tmp_ == LEFT) 
     || (pacman_direction == LEFT && direction_tmp_ == RIGHT) 
     || (pacman_direction == DOWN && direction_tmp_ == UP) 
     || (pacman_direction == UP && direction_tmp_ == DOWN))
    {
        direction_tmp_ = pacman_direction;
        intersection_detected_ = false;
    }
    else
        intersection_detected_ = false;

    // Change animation depending on the current direction
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

    // Only if ghosts is in corridor
    checkIfInCorridor();
    // Check if on a Pellet
    checkForPellet(pacman_->position_.x, pacman_->position_.y);
    // Check if in the right or left side of the corridor to teleport the PacMan
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
    
    // If on an Intersection, allow direction
    int intersection_check = checkForIntersection();
    if(intersection_check == 1)
        intersection_detected_ = true;
    else if(intersection_check == 2)
        direction_tmp_ = -1;

    // All the updates regarding the Window are made in the GameInterface
    gameInterface_->updateGameInterface(getCount(), pacman_, ghosts_, pellets, big_pellets, intersections, intersections_big);

    return false;
}

bool GameManager::isGameOver()
{
    // GameOver if the PacMan dies from a Ghost or if all the pellets were eaten
    if(!pacmanAlive() || allPelletsEaten())
    {
        std::cout<<"Final score : "<<getScore()<<std::endl;
        return true;
    }
    return false;
}

template <typename T>
void GameManager::checkForTeleportation(T character)
{
    // When a character hits one of those specific pellets, they are teleported
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
                incrementPelletCounter();
                // Add the correct points to the score
                this->AddToScore(it->second->addPoints());
                it->second->setHasPellet();
                // If a BigPellet is eaten, all the ghosts are set to feared mode
                if(it->second->hasAdditionalBehavior())
                    this->setGhostsFeared(count_);
            }
            break;
        }
    }
}

void GameManager::checkForPellet(int x, int y)
{
    // Call is done on both big_pellets and pellets maps
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
                incrementPelletCounter();
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
                if((it->first == "Intersection 09_08" || it->first == "Intersection 09_10" 
                    || it->first == "Intersection 19_08" || it->first == "Intersection 19_10")
                    && (!ghost->getIsEaten() && !ghost->getIsFeared()))
                {
                    ghost->setPossibleDirection(
                        it->second->canGoRight() && ghost_direction != LEFT,
                        it->second->canGoDown() && ghost_direction != UP, 
                        it->second->canGoLeft() && ghost_direction != RIGHT, 
                        false
                    );
                }
                else
                {
                    ghost->setPossibleDirection(
                        it->second->canGoRight() && ghost_direction != LEFT,
                        it->second->canGoDown() && ghost_direction != UP, 
                        it->second->canGoLeft() && ghost_direction != RIGHT, 
                        it->second->canGoUp() && ghost_direction != DOWN
                    );
                }
            }   
        }
    }
    return res;
}

int GameManager::checkForIntersection()
{
    // Check done on both intersections and intersections_big maps
    return checkForIntersectionTemplate(intersections) + checkForIntersectionTemplate(intersections_big);
}

void GameManager::checkIfInCorridor()
{
    for(auto ghost_it = ghosts_.begin(); ghost_it != ghosts_.end(); ++ghost_it)
    {
        Ghost* ghost = ghost_it->get();
        if(ghost->position_.y == 418 && (ghost->position_.x <= 161 || ghost->position_.x >= 515))
        {
            // If a ghost enters the corridor
            if(!ghost->isInCorridor())
            {
                ghost->setIsInCorridor(true);
                // And it is in normal mode, his speed is lowered
                if(!ghost->getIsFeared())
                    ghost->lowerSpeed();
            }
        }
        else
        {
            if(ghost->isInCorridor())
            {
                ghost->setIsInCorridor(false);
                // Set the speed back to normal when exits the corridor
                if(!ghost->getIsFeared())
                    ghost->increaseSpeed();
            }
        }
    }
}

bool GameManager::collisionWithGhost(std::shared_ptr<Ghost> ghost)
{
    // If the PacMan is around the hitbox of a ghost, this method returns true
    int pos_diff_x = abs((pacman_->position_.x + ((32 - HITBOX) / 2)) - (ghost->position_.x +  ((32 - HITBOX) / 2)));
    int pos_diff_y = abs((pacman_->position_.y + ((32 - HITBOX) / 2)) - (ghost->position_.y +  ((32 - HITBOX) / 2)));
    if((pos_diff_x <= HITBOX) && (pos_diff_y <= HITBOX))
        return true;
    else
        return false;
}

void GameManager::setGhostsFeared(int count)
{
    if(!feared_timer_running_)
    {
        for(int i = 0; i < ghosts_.size(); ++i)
        {
            if(!ghosts_[i]->isInCorridor())
                ghosts_[i]->lowerSpeed();
            // Ghosts pass in feared mode
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
    // If PacMan enters in collision with a ghost in feared mode
    if(ghost->getIsFeared())
    {
        // To influence on the number of points earned when a ghost is eaten consecutively
        incrementConsecutiveEatenGhosts();
        // Ghost is in eaten mode
        ghost->setIsEaten();
        if(!ghost->isInCorridor())
            ghost->increaseSpeed();
        // Start a clock for the time the ghost stays in eaten mode
        ghost->setEatenStartTimer(std::chrono::steady_clock::now());
        // Add points to the score
        AddToScore(200*getConsecutiveEatenGhosts());
    }
    // No specific action when PacMan passes through an eaten ghost 
    else if(ghost->getIsEaten())
    {
        
    }
    // If PacMan hits a normal mode ghost, he dies
    else
        pacmanDied();
}
