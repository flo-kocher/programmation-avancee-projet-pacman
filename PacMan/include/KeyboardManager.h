#ifndef __KEYBOARD_MANAGER_H__
#define __KEYBOARD_MANAGER_H__

#include <SDL.h>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

class KeyboardManager
{
    public:
        KeyboardManager();
        ~KeyboardManager();

        int waitForEvent();

};

#endif