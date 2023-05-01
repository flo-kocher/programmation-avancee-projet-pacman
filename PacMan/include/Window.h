#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL.h>
#include "Character.h"
#include "GameManager.h"
#include <memory>
// using namespace std;

class Window
{
    private:
        std::unique_ptr<Character> ghost;
        int direction_tmp;
        bool intersection_detected;
        int last_pressed_key;
        // GameManager* gameManager; // Ancienne manière de déclarer gameManager
        std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
    public:
        Window();
        ~Window();

        void update();

        inline void setDirectionRight()
        {
            last_pressed_key = 0;
        };
        inline void setDirectionDown()
        {
            last_pressed_key = 1;
        };
        inline void setDirectionLeft()
        {
            last_pressed_key = 2;
        };
        inline void setDirectionUp()
        {
            last_pressed_key = 3;
        };
    
};

#endif