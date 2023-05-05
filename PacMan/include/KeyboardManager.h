#ifndef __KEYBOARD_MANAGER_H__
#define __KEYBOARD_MANAGER_H__

#include <SDL.h>

class KeyboardManager
{
    public:
        KeyboardManager();
        ~KeyboardManager();

        int waitForEvent();

};

#endif