/* 
 * File:   GameScene.cpp
 * Author: roman.stetsyshin
 * 
 * Created on August 31, 2016, 11:32 AM
 */

#include "GameScene.h"
#include "helpers.h"
#include "ResourceManager.h"
#include "Input.h"

Digger::Digger(int x, int y)
{
    dir = Direction::DIG_NONE;
    desiredDir = Direction::DIG_NONE;
    
    hitBox.x = x;
    hitBox.y = y;
    hitBox.w = 4;
    hitBox.h = 4;
}

void Digger::debug()
{
    printf("DIR %d DDIR %d X %d Y %d\n",dir,desiredDir, hitBox.x, hitBox.y);
}

void GameScene::initLevel(int level)
{
    _gameField.initFromLevel(level);
  
    _players.push_back(Digger(30,54));
    _digTick = 0.0f;
}


void GameScene::enter()
{   
    initLevel(0);
}

#define SPEED 0.1f

void GameScene::update(float dt)
{
    
      
    _digTick += dt;
    if(_digTick > SPEED)
    {
        _digTick -= SPEED;
        for(int i = 0; i < _players.size(); ++i)
        {
            _players[i].desiredDir = Direction::DIG_NONE;
            if(Input::instance()->isPressed(i, Controls::CT_LEFT))
            {
                _players[i].desiredDir = Direction::DIG_LEFT;
            }
            if(Input::instance()->isPressed(i, Controls::CT_RIGHT))
            {
                _players[i].desiredDir = Direction::DIG_RIGHT;
            }
            if(Input::instance()->isPressed(i, Controls::CT_UP))
            {
                _players[i].desiredDir = Direction::DIG_UP;
            }
            if(Input::instance()->isPressed(i, Controls::CT_DOWN))
            {
                _players[i].desiredDir = Direction::DIG_DOWN;
            }

            if(_players[i].desiredDir != Direction::DIG_NONE)
            {
                if(_players[i].dir == Direction::DIG_NONE)
                {
                    _players[i].dir = _players[i].desiredDir;
                }
                else
                {
                    if(_players[i].desiredDir == Direction::DIG_LEFT || _players[i].desiredDir == Direction::DIG_RIGHT)
                    {
                        if(_players[i].dir == Direction::DIG_LEFT || _players[i].dir == Direction::DIG_RIGHT)
                        {
                            _players[i].dir = _players[i].desiredDir;
                        }
                        else if ((_players[i].hitBox.y % 6) == 0)
                        {
                            _players[i].dir = _players[i].desiredDir;
                        }
                    }
                    if(_players[i].desiredDir == Direction::DIG_UP || _players[i].desiredDir == Direction::DIG_DOWN)
                    {
                        if(_players[i].dir == Direction::DIG_UP || _players[i].dir == Direction::DIG_DOWN)
                        {
                            _players[i].dir = _players[i].desiredDir;
                        }
                        else if((_players[i].hitBox.x % 5) == 0)
                        {
                             _players[i].dir = _players[i].desiredDir;
                        }
                    }
                }
                int y = _players[i].hitBox.y / 6;
                int x = _players[i].hitBox.x / 5;
                    
                
                if(_players[i].dir == Direction::DIG_LEFT && _players[i].hitBox.x > 0)
                {
                    _players[i].hitBox.x -= 1;
                    for(int j=0; j < 4; ++j)
                    {
                        _gameField.setBit(Direction::DIG_LEFT, 
                            _gameField.getWidth() - (_players[i].hitBox.x + j), 
                            y, 
                            true);
                    }
                }
                if(_players[i].dir == Direction::DIG_RIGHT && _players[i].hitBox.x < (_gameField.getWidthInBlocks() - 1) * 5)
                {
                    _players[i].hitBox.x += 1;
                    for(int j=0; j < 4; ++j)
                    {
                       _gameField.setBit(Direction::DIG_RIGHT, 
                           _players[i].hitBox.x + _players[i].hitBox.w - j, 
                           y, 
                           true);
                    }
                }
                if(_players[i].dir == Direction::DIG_UP && _players[i].hitBox.y > 0)
                {
                    _players[i].hitBox.y -= 1;
                    for(int j=0; j < 4; ++j)
                    {                    
                        _gameField.setBit(Direction::DIG_UP, 
                            x, 
                            _gameField.getHeight() - (_players[i].hitBox.y + j), 
                            true);
                    }

                }
                if(_players[i].dir == Direction::DIG_DOWN && _players[i].hitBox.y < (_gameField.getHeightInBlocks() - 1) * 6)
                {
                    _players[i].hitBox.y += 1;
                    for(int j=0; j < 4; ++j)
                    {                    
                        _gameField.setBit(Direction::DIG_DOWN, 
                            x, 
                            _players[i].hitBox.y + _players[i].hitBox.h - j,
                            true);
                    }
                }
                _players[i].debug();
            }
        
        }
        
        
        
    }
}

void GameScene::renderLeft(SDL_Renderer* renderer)
{
    SDL_Rect r;
    r.w = 16;
    r.h = 36;
    SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_LEFT, renderer);
    for(int y = 0; y < _gameField.getHeightInBlocks(); ++y)
    {
        auto stream = _gameField.getStream(Direction::DIG_LEFT, y);
        for(int x = 0; x < stream.size(); ++x)
        {
            if(stream[x])
            {
                r.x = (stream.size() - x) * 8 - 8 ;
                r.y = y * 36 + 6;
                SDL_RenderCopy(renderer, tex1, NULL, &r);
            }
        }
    }
}

void GameScene::renderRight(SDL_Renderer* renderer)
{
    SDL_Rect r;
    r.w = 16;
    r.h = 36;
    SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_RIGHT, renderer);
    for(int y = 0; y < _gameField.getHeightInBlocks(); ++y)
    {
        auto stream = _gameField.getStream(Direction::DIG_RIGHT, y);
        for(int x = 0; x < stream.size(); ++x)
        {
            if(stream[x])
            {
                r.x = x * 8 + 8;
                r.y = y * 36 + 6;
                SDL_RenderCopy(renderer, tex1, NULL, &r);
            }
        }
    }
}

void GameScene::renderDown(SDL_Renderer* renderer)
{
    SDL_Rect r;
    r.h = 12;
    r.w = 48;
    SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_DOWN, renderer);
    for(int x = 0; x < _gameField.getWidthInBlocks(); ++x)
    {
        auto stream = _gameField.getStream(Direction::DIG_DOWN, x);
        for(int y = 0; y < stream.size(); ++y)
        {
            if(stream[y])
            {
                r.x = x * 40 + 4;
                r.y = y * 6 + 6;
                SDL_RenderCopy(renderer, tex1, NULL, &r);
            }
        }
    }
}

void GameScene::renderUp(SDL_Renderer* renderer)
{
    SDL_Rect r;
    r.h = 12;
    r.w = 48;
    SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_UP, renderer);
    for(int x = 0; x < _gameField.getWidthInBlocks(); ++x)
    {
        auto stream = _gameField.getStream(Direction::DIG_UP, x);
        for(int y = 0; y < stream.size(); ++y)
        {
            if(stream[y])
            {
                r.x = x * 40 + 4;
                r.y = (stream.size() - y) * 6 - 6;
                SDL_RenderCopy(renderer, tex1, NULL, &r);
            }
        }
    }
}

void GameScene::renderDigger(SDL_Renderer* renderer)
{
   SDL_Texture* tex1 = ResourceManager::instance()->getDigger(0, Direction::DIG_UP, 0, renderer);
   SDL_Rect r;
   for(int i = 0; i < _players.size(); ++i)
   {  
        r.x = _players[i].hitBox.x * 8 + 8;
        r.y = _players[i].hitBox.y * 6 + 9;
        r.w = 32;
        r.h = 30;
        SDL_RenderCopy(renderer, tex1, NULL, &r);    
   }
}

void GameScene::render(SDL_Renderer* renderer)
{
   renderLeft(renderer);    
   renderRight(renderer);
   renderUp(renderer);
   renderDown(renderer);
   renderDigger(renderer);

   
}

GameScene::GameScene() {
}

GameScene::~GameScene() {
}

