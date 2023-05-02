#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL.h>
#include "Character.h"
#include "GameManager.h"
#include <memory>

class Window
{
    private:

        std::unique_ptr<Character> ghost_;
        int direction_tmp_;
        bool intersection_detected_;
        int last_pressed_key_;
        std::unique_ptr<GameManager> gameManager_ = std::make_unique<GameManager>();

    public:

        Window();
        ~Window();

        bool update();

        inline void setDirectionRight()
        {
            last_pressed_key_ = 0;
        };

        inline void setDirectionDown()
        {
            last_pressed_key_ = 1;
        };

        inline void setDirectionLeft()
        {
            last_pressed_key_ = 2;
        };

        inline void setDirectionUp()
        {
            last_pressed_key_ = 3;
        };
    
};

#endif