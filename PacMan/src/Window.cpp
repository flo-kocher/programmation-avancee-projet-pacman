#include "../include/Window.h"
#include <iostream>

#include <SDL.h>

Window::Window()
{
    ghost = new Character{};
    direction_tmp = 0;
    intersection_detected = false;
    last_pressed_key = 0;
    // et dans Windows, on va appeler genre Manager->initArea()
    // puis Manager->updateArea() etc...
    // dans Windows on va juste appeler des 'évènements', sans utiliser de "vrais" données 
    gameManager = new GameManager{};
}

Window::~Window()
{

}

void Window::update()
{
    if(intersection_detected)
    {
        direction_tmp = last_pressed_key;
        intersection_detected = false;
    }
    else
        intersection_detected = false;

    switch(direction_tmp)
    {
        case 0:
                ghost->turnRight();
            break;
        case 1:
        {
                ghost->turnDown();
                // // // // fonctionnel
                // // // SDL_SetColorKey(plancheSprites, false, 0);
                // // // SDL_Rect init = {376, 10, 10, 10}; // où on trouve le rectagle noir
                // // // SDL_Rect cp = {64, 32, 32, 32};
                // // // SDL_BlitScaled(plancheSprites, &init, win_surf, &cp);
            break;
        }
        case 2:
                ghost->turnLeft();
            break;
        case 3:
                ghost->turnUp();
            break;
    }

    gameManager->checkForZone(ghost->ghost.x, ghost->ghost.y);
    gameManager->checkForPellet(ghost->ghost.x, ghost->ghost.y);
    gameManager->checkForIntersection(ghost->ghost.x, ghost->ghost.y);

    // ghost.x et ghost.y : position en temps réel du ghost
    if(ghost->ghost.x == 34 && ghost->ghost.y == 34)
        intersection_detected = true;
    if(ghost->ghost.x == 162 && ghost->ghost.y == 34)
        intersection_detected = true;
    if(ghost->ghost.x == 162 && ghost->ghost.y == 162)
        intersection_detected = true;
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        intersection_detected = true;
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        intersection_detected = true;
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        intersection_detected = true;
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        intersection_detected = true;
    if(ghost->ghost.x == 34 && ghost->ghost.y == 162)
        intersection_detected = true;
    
    gameManager->updateInterface(ghost->getGhost(), ghost->getGhostIn());
}
