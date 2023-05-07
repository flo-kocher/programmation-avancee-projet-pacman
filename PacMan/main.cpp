#include "include/GameManager.h"

int main(int argc, char **argv)
{
    // Initialization of the GameManager
    std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();

    try
    {
        // Run the PacMan game
        gameManager->runGame();
    }
    catch(...)
    {
        std::cout << "An error has occured during the program" << std::endl;
    }

    return 0;
}
