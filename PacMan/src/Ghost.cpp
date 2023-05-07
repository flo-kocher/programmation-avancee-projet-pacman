#include "../include/Ghost.h"
#include "../include/Intersection.h"
#include "../include/GameManager.h"
#include "../include/Pacman.h"
#include <cmath>
#include <array>
#include <random>

Ghost::Ghost()
{}

Ghost::Ghost(CharacterName name, SDL_Rect start_position, SDL_Rect* image, Direction direction)
: is_feared_(false)
, is_eaten_(false)
, is_in_corridor_(false)
{
    setCharacterName(name);
    position_ = start_position;
    character_image_ = image;
    direction_ = direction;
    switch(getCharacterName()){
        case(RED_GHOST) :
            setPossibleDirection(false, false, true, false);
            setIsInSpawn(false);
            break;
        case(PINK_GHOST) :
            setPossibleDirection(false, false, false, true);
             setIsInSpawn(true);
           break;
        case(BLUE_GHOST) :
            setPossibleDirection(true, false, false, false);
            setIsInSpawn(true);
            break;
        case(YELLOW_GHOST) :
            setPossibleDirection(false, false, true, false);
            setIsInSpawn(true);
            break;
        default: break;
    }
}

Ghost::~Ghost()
{
}

void Ghost::chase(std::shared_ptr<Pacman> pacman, int count, std::shared_ptr<Ghost> red_ghost)
{
    int target_x = 0;
    int target_y = 0;
    int zone_2_tiles_front_pacman_x;
    int zone_2_tiles_front_pacman_y;
    double vector_vertical_red_ghost_to_2_tiles_front_target;
    double vector_horizontal_red_ghost_to_2_tiles_front_target;
    double vector_between_clyde_and_pacman;

    Direction pacman_direction = pacman->getDirection();
    switch(getCharacterName()){
        case(RED_GHOST) :
            setTarget(pacman->position_.x, pacman->position_.y); //Blinky cible la position exacte de Pacman 
            calculateVectorsToTarget(target, position_);
            break;
        case(PINK_GHOST) :
            target_x = pacman->position_.x + (pacman_direction == RIGHT ? 96 : (pacman_direction == LEFT || pacman_direction == UP) ? -96 : 0);
            target_y = pacman->position_.y + (pacman_direction == DOWN ? 96 : pacman_direction == UP  ? -96 : 0);
            setTarget(target_x, target_y); //Pinky cible 3 cases devant Pacman (si celui va vers le haut, 3 cases vers la gauche en plus)
            calculateVectorsToTarget(target, position_);
            break;
        case(BLUE_GHOST) :
            zone_2_tiles_front_pacman_x = pacman->position_.x + (pacman_direction == RIGHT ? 64 : (pacman_direction == LEFT || pacman_direction == UP) ? -64 : 0);
            zone_2_tiles_front_pacman_y = pacman->position_.y + (pacman_direction == DOWN ? 64 : pacman_direction == UP  ? -64 : 0);
            
            vector_horizontal_red_ghost_to_2_tiles_front_target = zone_2_tiles_front_pacman_x - red_ghost->position_.x;
            vector_vertical_red_ghost_to_2_tiles_front_target = zone_2_tiles_front_pacman_y - red_ghost->position_.y;

            target_x = zone_2_tiles_front_pacman_x + (int)vector_horizontal_red_ghost_to_2_tiles_front_target;
            target_y = zone_2_tiles_front_pacman_y + (int)vector_vertical_red_ghost_to_2_tiles_front_target;

            setTarget(target_x, target_y); //Inky cible la position exacte de Pacman   
            calculateVectorsToTarget(target, position_);
            break;
        case(YELLOW_GHOST) :
            vector_between_clyde_and_pacman = std::round(sqrt(pow(abs(pacman->position_.x - position_.x), 2) + pow(abs(pacman->position_.y - position_.y), 2)));

            if(vector_between_clyde_and_pacman < 256) //256 = longueur d'un vecteur correspondant à 8 cases autour de Pacman
            {
                setTarget(34, 768); //A l'intérieur du cercle de 8 cases autour de Pacman, Clyde cible le même point que dans le mode scatter dans le coin bas-gauche de la map
            }
            else{
                setTarget(pacman->position_.x, pacman->position_.y); //Hors du cercle de 8 cases autour de Pacman, Clyde cible sa position exacte
            }
            calculateVectorsToTarget(target, position_);
            break;
        default: break;
    }

    classicalMovementAlgorithm(count);
}
        
void Ghost::scatter(int count)
{
    switch(getCharacterName()){
        case(RED_GHOST) :
            setTarget(546, 0);
            calculateVectorsToTarget(target, position_);
            break;
        case(PINK_GHOST) :
            setTarget(64, 0);
            calculateVectorsToTarget(target, position_);
            break;
        case(BLUE_GHOST) :
            setTarget(608, 768);
            calculateVectorsToTarget(target, position_);
            break;
        case(YELLOW_GHOST) :
            setTarget(34, 768);
            calculateVectorsToTarget(target, position_);
            break;
        default: break;
    }

    classicalMovementAlgorithm(count);
}

void Ghost::frightened(int count)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 3);
    bool can_move_to_random_direction = false;

    while (!can_move_to_random_direction){
        int random_direction = distrib(gen);
        if(can_go_up_ && random_direction == UP)
        {
            can_move_to_random_direction = true;
            setDirection(UP);
            goUp(count);
            setPossibleDirection(false, false, false, true);
        }
        else if(can_go_left_ && random_direction == LEFT){
            can_move_to_random_direction = true;
            setDirection(LEFT);
            goLeft(count);
            setPossibleDirection(false, false, true, false);
        }
        else if(can_go_down_ && random_direction == DOWN){
            can_move_to_random_direction = true;
            setDirection(DOWN);
            goDown(count);
            setPossibleDirection(false, true, false, false);
        }
        else if(can_go_right_ && random_direction == RIGHT){
            can_move_to_random_direction = true;
            setDirection(RIGHT);
            goRight(count);
            setPossibleDirection(true, false, false, false);
        }
    }
}
        
void Ghost::eaten(int count)
{
    setTarget(322, 322);
    calculateVectorsToTarget(target, position_);
    if(position_.x == 322 && position_.y == 322)
    {
        setDirection(DOWN);
        goDown(count);
        setPossibleDirection(false, true, false, false);
    }
    else if(position_.x == 322 && position_.y == 418)
    {
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = now - eaten_start_timer_;
        if (elapsed_seconds.count() < 10)
        {
            setPossibleDirection(direction_ != LEFT ? true : false, false, direction_ != RIGHT ? true : false, false);
            classicalMovementAlgorithm(count);
        }
        else
        {
            is_eaten_ = false;
            setDirection(UP);
            goUp(count);
            setPossibleDirection(false, false, false, true);
        }
    }
    else if(position_.x == 290 && position_.y == 418)
    {
        setPossibleDirection(true, false, false, false);
        classicalMovementAlgorithm(count);
    }
    else if(position_.x == 354 && position_.y == 418)
    {
        setPossibleDirection(false, false, true, false);
        classicalMovementAlgorithm(count);
    }
    else
    {
        classicalMovementAlgorithm(count);
    }
}

void Ghost::classicalMovementAlgorithm(int count){
    double min_vector;

    min_vector = std::min(std::min(std::min(vector_up_to_target_, vector_left_to_target_), vector_down_to_target_), vector_right_to_target_);
    if(can_go_up_ && 
        (min_vector == vector_up_to_target_ || 
        (!can_go_left_ && !can_go_down_ && !can_go_right_) ||
        (!can_go_down_ && !can_go_right_ && vector_up_to_target_ < vector_left_to_target_) ||
        (!can_go_down_ && !can_go_left_ && vector_up_to_target_ < vector_right_to_target_) ||
        (!can_go_left_ && !can_go_right_ && vector_up_to_target_ < vector_down_to_target_) ||
        (!can_go_down_ && vector_up_to_target_ < vector_right_to_target_ && vector_up_to_target_ < vector_left_to_target_) ||
        (!can_go_left_ && vector_up_to_target_ < vector_down_to_target_ && vector_up_to_target_ < vector_right_to_target_) ||
        (!can_go_right_ && vector_up_to_target_ < vector_down_to_target_ && vector_up_to_target_ < vector_left_to_target_)))
    {
        setDirection(UP);
        goUp(count);
        setPossibleDirection(false, false, false, true);
    }
    else{
        min_vector = std::min(std::min(vector_left_to_target_, vector_down_to_target_), vector_right_to_target_);

        if(can_go_left_ && 
            (min_vector == vector_left_to_target_ || 
            (!can_go_down_ && !can_go_right_) || 
            (!can_go_down_ && vector_left_to_target_ < vector_right_to_target_) ||
            (!can_go_right_ && vector_left_to_target_ < vector_down_to_target_)))
        {
            setDirection(LEFT);
            goLeft(count);
            setPossibleDirection(false, false, true, false);
        }
        else{
            min_vector = std::min(vector_down_to_target_, vector_right_to_target_);

            if(can_go_down_ && (min_vector == vector_down_to_target_ || !can_go_right_))
            {
                setDirection(DOWN);
                goDown(count);
                setPossibleDirection(false, true, false, false);
            }
            else if(can_go_right_)
            {
                setDirection(RIGHT);
                goRight(count);
                setPossibleDirection(true, false, false, false);
            }
            else{
                std::cout << "Aucune direction disponible pour le fantôme " << getCharacterName() << "\n";
            }
        }
    }
}

void Ghost::calculateVectorsToTarget(Target target, SDL_Rect position){
    vector_up_to_target_ = std::round(sqrt(pow(abs(target.x - position_.x), 2) + pow(abs(target.y - (position_.y - 32)), 2)));
    vector_down_to_target_ = std::round(sqrt(pow(abs(target.x - position_.x), 2) + pow(abs(target.y - (position_.y + 32)), 2)));
    vector_left_to_target_ = std::round(sqrt(pow(abs(target.x - (position_.x - 32)), 2) + pow(abs(target.y - position_.y), 2)));
    vector_right_to_target_ = std::round(sqrt(pow(abs(target.x - (position_.x + 32)), 2) + pow(abs(target.y - position_.y), 2)));
}

void Ghost::goRight(int count)
{
    Character::goRight(count);
    if(is_eaten_)
        setEatenImage("RIGHT");
    if(is_feared_)
        setFearedImage(count);
}

void Ghost::goLeft(int count)
{
    Character::goLeft(count);
    if(is_eaten_)
        setEatenImage("LEFT");
    if(is_feared_)
        setFearedImage(count);
}

void Ghost::goUp(int count)
{
    Character::goUp(count);
    if(is_eaten_)
        setEatenImage("UP");
    if(is_feared_)
        setFearedImage(count);
}

void Ghost::goDown(int count)
{
    Character::goDown(count);
    if(is_eaten_)
        setEatenImage("DOWN");
    if(is_feared_)
        setFearedImage(count);
}

void Ghost::setFearedImage(int count)
{
    int timer = GameManager::feared_timer_;
    if(timer < 200)
    {
        if (!((count / 16) % 2))
            if (!((count / 8) % 2))
                character_image_ = FEARED_GHOST_IMAGES.find("WHITE")->second;
            else
                character_image_ = FEARED_GHOST_IMAGES.find("WHITE2")->second;
        else
            if (!((count / 8) % 2))
                character_image_ = FEARED_GHOST_IMAGES.find("BLUE")->second;
            else
                character_image_ = FEARED_GHOST_IMAGES.find("BLUE2")->second;
    }
    else
    {
        if (!((count / 8) % 2))
            character_image_ = FEARED_GHOST_IMAGES.find("BLUE")->second;
        else
            character_image_ = FEARED_GHOST_IMAGES.find("BLUE2")->second;
    }
}

void Ghost::setEatenImage(std::string direction)
{
    character_image_ = EATEN_GHOST_IMAGES.find(direction)->second;
}
