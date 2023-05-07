#ifndef __KEYBOARD_MANAGER_H__
#define __KEYBOARD_MANAGER_H__

#include <SDL.h>

/**
 * @brief Gets the keyboard inputs and uses them in the GameManager
 * 
 */
class KeyboardManager
{
    public:
        KeyboardManager();
        ~KeyboardManager();

        /**
         * @brief Catches a keyboard input
         * 
         * @return int the input caught
         */
        int waitForEvent();

};

#endif