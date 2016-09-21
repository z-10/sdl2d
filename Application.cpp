/* 
 * File:   Application.cpp
 * Author: roman.stetsyshin
 * 
 * Created on August 29, 2016, 12:22 PM
 */

#include "Application.h"
#include "Input.h"
#include "ResourceManager.h"
#include "GameScene.h"

Application::Application() 
{
    _lastTime  = _clock.now();
    _currentScene = new GameScene();
}

Application::~Application() 
{
    cleanUp();
}

bool Application::init(SDL_Window* window)
{
    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == NULL) {
        return false;
    }
    if(!Input::init())
    {
        return false;
    }
    
    if(!ResourceManager::init())
    {
        return false;
    }
    
    if(SDL_RenderSetLogicalSize(_renderer, 640, 480) < 0)
    {
        return false;
    }
    
    return true;
}

void Application::start()
{
    _currentScene->enter();
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            Input::instance()->process(e);
        }
        update();
    }    
}

void Application::update()
{
    auto ticks = _clock.now();
    auto diff = ticks - _lastTime;
    _lastTime = ticks;
    float dt = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() * 0.001f;
    
    _currentScene->update(dt);
    
    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    SDL_RenderClear(_renderer);
    _currentScene->render(_renderer);
    SDL_RenderPresent(_renderer);
}

void Application::cleanUp()
{
    Input::destroy();
    ResourceManager::destroy();
    SDL_DestroyRenderer(_renderer);

}