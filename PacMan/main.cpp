#include <SDL.h>
#include "include/GameManager.h"
#include <iostream>

int main(int argc, char **argv)
{
    try{
        int quit_event = 1;
        while(quit_event == 1)
        {
            std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
            quit_event = gameManager->runGame();
            gameManager = nullptr;
            SDL_Quit(); // On quitte l'instance de jeu actuelle
        }
    }
    catch(...)
    {
        std::cout << "An error has occured during the program" << std::endl;
    }

    return 0;
}
