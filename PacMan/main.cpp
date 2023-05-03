// #include <SDL.h>

// #include "include/GameInterface.h"
// #include "include/KeyboardManager.h"
#include "include/GameManager.h"

// #include <iostream>

int main(int argc, char **argv)
{
    std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
    // try run game
    /*


    RAJOUTER UN TRY CATCH ICI OU ALORS DANS LE RUN_GAME ET ENSUITE C'EST BON
    
    
    */

    gameManager->runGame();

    // catch :

    return 0;
}
