#include "../include/Ghost.h"
#include "../include/Intersection.h"
#include "../include/GameManager.h"
#include "../include/Pacman.h"
#include <cmath>
#include <array>

Ghost::Ghost()
{}

Ghost::Ghost(CharacterName name, SDL_Rect start_position, SDL_Rect* image, Direction direction)
{
    setCharacterName(name);
    position_ = start_position;
    character_image_ = image;
    direction_ = direction;
    switch(getCharacterName()){
        case(RED_GHOST) :
            can_go_right_ = false;
            can_go_down_ = false;
            can_go_left_ = true;
            can_go_up_ = false;
            break;
        case(PINK_GHOST) :
            can_go_right_ = false;
            can_go_down_ = false;
            can_go_left_ = false;
            can_go_up_ = true;
            break;
        case(BLUE_GHOST) :
            can_go_right_ = true;
            can_go_down_ = false;
            can_go_left_ = false;
            can_go_up_ = false;
            break;
        case(YELLOW_GHOST) :
            can_go_right_ = false;
            can_go_down_ = false;
            can_go_left_ = true;
            can_go_up_ = false;
            break;
        default: break;
    }
}

Ghost::~Ghost()
{

}

void Ghost::chase(std::shared_ptr<Pacman> pacman, int count)
{
    double min_vector;
    int target_x = 0;
    int target_y = 0;
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
            setTarget(pacman->position_.x, pacman->position_.y); //Inky cible la position exacte de Pacman   
            calculateVectorsToTarget(target, position_);
            break;
        case(YELLOW_GHOST) :
            setTarget(pacman->position_.x, pacman->position_.y); //Clyde cible la position exacte de Pacman   
            calculateVectorsToTarget(target, position_);
            break;
        default: break;
    }

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
        
void Ghost::scatter(int count)
{
    double min_vector;

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

void Ghost::frightened(int count)
{
    double min_vector;

    switch(getCharacterName()){
        case(RED_GHOST) :
            //setTarget(position_pacman.x, position_pacman.y); //Blinky cible la position exacte de Pacman 
            //calculateVectorsToTarget(target, position_);
            break;
        case(PINK_GHOST) :
            //setTarget(position_pacman.x, position_pacman.y); //Pinky cible la position exacte de Pacman 
            //calculateVectorsToTarget(target, position_);
            break;
        case(BLUE_GHOST) :
            //setTarget(position_pacman.x, position_pacman.y); //Inky cible la position exacte de Pacman   
            //calculateVectorsToTarget(target, position_);
            break;
        case(YELLOW_GHOST) :
            //setTarget(position_pacman.x, position_pacman.y); //Clyde cible la position exacte de Pacman   
            //calculateVectorsToTarget(target, position_);
            break;
        default: break;
    }

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
        
void Ghost::eaten(int count)
{
    double min_vector;

    switch(getCharacterName()){
        case(RED_GHOST) :
            //setTarget(position_pacman.x, position_pacman.y); //Blinky cible la position exacte de Pacman 
            //calculateVectorsToTarget(target, position_);
            break;
        case(PINK_GHOST) :
            //setTarget(position_pacman.x, position_pacman.y); //Pinky cible la position exacte de Pacman 
            //calculateVectorsToTarget(target, position_);
            break;
        case(BLUE_GHOST) :
            //setTarget(position_pacman.x, position_pacman.y); //Inky cible la position exacte de Pacman   
            //calculateVectorsToTarget(target, position_);
            break;
        case(YELLOW_GHOST) :
            //setTarget(position_pacman.x, position_pacman.y); //Clyde cible la position exacte de Pacman   
            //calculateVectorsToTarget(target, position_);
            break;
        default: break;
    }

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
    vector_up_to_target_ = pow(abs(target.x - position_.x), 2) + pow(abs(target.y - (position_.y - 32)), 2);
    vector_down_to_target_ = pow(abs(target.x - position_.x), 2) + pow(abs(target.y - (position_.y + 32)), 2);
    vector_left_to_target_ = pow(abs(target.x - (position_.x - 32)), 2) + pow(abs(target.y - position_.y), 2);
    vector_right_to_target_ = pow(abs(target.x - (position_.x + 32)), 2) + pow(abs(target.y - position_.y), 2);
}
