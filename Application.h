/* 
 * File:   Application.h
 * Author: roman.stetsyshin
 *
 * Created on August 29, 2016, 12:22 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
#include <chrono>

#include <SDL.h>
#include "Scene.h"

class Application {
public:
    Application();
    virtual ~Application();
    
    bool init(SDL_Window* window);
        
    void start();
    void cleanUp();
    
private:
    SDL_Renderer* _renderer;
    std::chrono::high_resolution_clock _clock;
    std::chrono::high_resolution_clock::time_point _lastTime;
    unsigned int _dt;
    void update();
    
    Scene* _currentScene;

};

#endif	/* APPLICATION_H */

