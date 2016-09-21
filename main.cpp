#include<iostream>
#include <SDL.h>

#include "Application.h"


int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    
    Application* app = new Application();
    if(!app->init(win))
    {
        printf(SDL_GetError());
    }
    app->start();
    delete app;
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
