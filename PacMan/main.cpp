#include "include/GameManager.h"

int main(int argc, char **argv)
{
    // Initialization of the GameManager
    std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
    // Run the PacMan game
    gameManager->runGame();

    return 0;
}
