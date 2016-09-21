/* 
 * File:   Input.h
 * Author: roman.stetsyshin
 *
 * Created on August 29, 2016, 2:02 PM
 */

#ifndef INPUT_H
#define	INPUT_H

#include <unordered_map>

#include <SDL.h>

#include "helpers.h"

class Input {
public:
    static Input* instance();
    static bool init();
    static void destroy();
    
    bool process(SDL_Event e);
    
    bool isPressed(int player, int control);
    
private:
    Input();
    ~Input();
    
    
    void bindDefaults(); // temp???
    
    
    void processKey(SDL_Keycode key, bool pressed);
    void processJoyAxis(SDL_JoystickID joy, Uint8 axis, int value);
    void processJoyButton(SDL_JoystickID joy, Uint8 button, bool pressed);
    
    
    bool _playerMaps[CONTROL_MAX_PLAYERS][Controls::CT_Total];
    SDL_Keycode _keyBinds[CONTROL_MAX_PLAYERS][Controls::CT_Total];
    SDL_JoystickID _joyBinds[CONTROL_MAX_PLAYERS];
       
    static Input* _instance;
    
    
    
};

#endif	/* INPUT_H */

