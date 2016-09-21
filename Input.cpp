/* 
 * File:   Input.cpp
 * Author: roman.stetsyshin
 * 
 * Created on August 29, 2016, 2:02 PM
 */

#include "Input.h"

Input* Input::_instance = NULL;

Input* Input::instance()
{
    return _instance;
};

bool Input::init()
{
    if(!_instance)
    {
        _instance = new Input();
    }
    return true;
}

void Input::destroy()
{
    delete _instance;
    _instance = NULL;
};

void Input::bindDefaults()
{
    _keyBinds[0][Controls::CT_LEFT]  = SDLK_LEFT;
    _keyBinds[0][Controls::CT_RIGHT] = SDLK_RIGHT;
    _keyBinds[0][Controls::CT_UP]    = SDLK_UP;
    _keyBinds[0][Controls::CT_DOWN]  = SDLK_DOWN;
    _keyBinds[0][Controls::CT_FIRE]  = SDLK_F1;
    _keyBinds[0][Controls::CT_BACK]  = SDLK_ESCAPE;
    _joyBinds[0] = 0;
    
}

void Input::processKey(SDL_Keycode key, bool pressed)
{
    for(int i = 0; i < CONTROL_MAX_PLAYERS; ++i)
    {
        for(int j = 0; j < Controls::CT_Total; ++j)
        {
            if(_keyBinds[i][j] == key)
            {
                _playerMaps[i][j] = pressed;
                return;
            }
        }
    }
}

void Input::processJoyAxis(SDL_JoystickID joy, Uint8 axis, int value)
{
    for(int i = 0; i < CONTROL_MAX_PLAYERS; ++i)
    {
        if(_joyBinds[i] == joy)
        {
            if(axis == 0)
            {
                _playerMaps[i][Controls::CT_LEFT] = value < -JOYSTICK_DEAD_ZONE ? true : false;
                _playerMaps[i][Controls::CT_RIGHT] = value > JOYSTICK_DEAD_ZONE ? true : false;
            }
            if(axis == 1)
            {
                _playerMaps[i][Controls::CT_DOWN] = value < -JOYSTICK_DEAD_ZONE ? true : false;
                _playerMaps[i][Controls::CT_UP] = value > JOYSTICK_DEAD_ZONE ? true : false;
            }
            return;
        }
    }
}

void Input::processJoyButton(SDL_JoystickID joy, Uint8 button, bool pressed)
{
 for(int i = 0; i < CONTROL_MAX_PLAYERS; ++i)
    {
        if(_joyBinds[i] == joy)
        {
            if(button == 0)
            {
                _playerMaps[i][Controls::CT_FIRE] = pressed;
            }
            if(button == 1)
            {
                _playerMaps[i][Controls::CT_BACK] = pressed;
            }
            return;
        }
    }
}


bool Input::process(SDL_Event e)
{
    if (e.type == SDL_QUIT) 
    {
        return false;
    }
    if (e.type == SDL_KEYDOWN) 
    {
        processKey(e.key.keysym.sym, true);
    }
    if (e.type == SDL_KEYUP) 
    {
        processKey(e.key.keysym.sym, false);
    }
    if(e.type == SDL_CONTROLLERBUTTONDOWN)
    {
        processJoyButton(e.cbutton.which, e.cbutton.button, true);
    }
    if(e.type == SDL_CONTROLLERBUTTONUP)
    {
        processJoyButton(e.cbutton.which, e.cbutton.button, true);
    }
    if(e.type == SDL_CONTROLLERAXISMOTION)
    {
        processJoyAxis(e.caxis.which, e.caxis.axis, e.caxis.value);
    }
        
}

bool Input::isPressed(int player, int control)
{
    return _playerMaps[player][control];
}

Input::Input() {
    if(SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0)
    {
        printf("Joystick init failed.\n");
    }
    for(int i = 0; i < CONTROL_MAX_PLAYERS; ++i)
    {
        for(int j = 0; j < Controls::CT_Total; ++j)
        {
            _playerMaps[i][j] = false;
            _keyBinds[i][j] = 0;
        }
        _joyBinds[i] = -1;
    }
    
    bindDefaults();
}

Input::~Input() {
    SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
}




