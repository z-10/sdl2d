/* 
 * File:   DebugScene.cpp
 * Author: roman.stetsyshin
 * 
 * Created on August 30, 2016, 12:00 PM
 */

#include "DebugScene.h"
#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_Image.h>


DebugScene::DebugScene() {
}

DebugScene::~DebugScene() {
}

void DebugScene::enter()
{

}

void DebugScene::update(float dt)
{

}

void DebugScene::render(SDL_Renderer* renderer)
{

    SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_LEFT, 0xFF, renderer);
    SDL_Texture* tex2 = ResourceManager::instance()->getBlob(Direction::DIG_RIGHT, 0xFF, renderer);
    SDL_Texture* tex3 = ResourceManager::instance()->getBlob(Direction::DIG_UP, 0xFF, renderer);
    SDL_Texture* tex4 = ResourceManager::instance()->getBlob(Direction::DIG_DOWN, 0xFF, renderer);
    SDL_Rect r;
    r.x = 100;
    r.y = 100;
    r.w = 56;
    r.h = 48;
    
    SDL_RenderCopy(renderer, tex1, NULL, &r);
    SDL_RenderCopy(renderer, tex2, NULL, &r);    
    SDL_RenderCopy(renderer, tex3, NULL, &r);
    SDL_RenderCopy(renderer, tex4, NULL, &r);

}