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

char leveldat[8][10][15]=
{
  {
    {'S',' ',' ',' ','B',' ',' ',' ',' ',' ','H','H','H','H','S'},
    {'V',' ',' ','C','C',' ',' ','C',' ',' ','V',' ','B',' ',' '},
    {'V','B',' ','C','C',' ',' ','C',' ',' ','V',' ',' ',' ',' '},
    {'V',' ',' ','C','C','B',' ','C','B',' ','V',' ','C','C','C'},
    {'V',' ',' ','C','C',' ',' ','C',' ',' ','V',' ','C','C','C'},
    {'H','H',' ','C','C',' ',' ','C',' ',' ','V',' ','C','C','C'},
    {' ','V',' ',' ',' ',' ','B',' ','B',' ','V',' ',' ',' ',' '},
    {' ','H','H','H','H',' ',' ',' ',' ',' ','V',' ',' ',' ',' '},
    {'C',' ',' ',' ','V',' ',' ',' ',' ',' ','V',' ',' ',' ','C'},
    {'C','C',' ',' ','H','H','H','H','H','H','H',' ',' ','C','C'}
  },
  {
    {'S','H','H','H','H','H',' ',' ','B',' ','B',' ',' ','H','S'},
    {' ','C','C',' ',' ','V',' ',' ',' ',' ',' ',' ',' ','V',' '},
    {' ','C','C',' ',' ','V',' ','C','C','C','C','C',' ','V',' '},
    {'B','C','C','B',' ','V',' ','C','C','C','C','C',' ','V',' '},
    {'C','C','C','C',' ','V',' ',' ',' ',' ',' ',' ',' ','V',' '},
    {'C','C','C','C',' ','V',' ','B',' ',' ','H','H','H','H',' '},
    {' ','C','C',' ',' ','V',' ','C','C',' ','V',' ',' ',' ',' '},
    {' ','B','B',' ',' ','V','C','C','C','C','V',' ','C','C',' '},
    {'C',' ',' ',' ',' ','V',' ','C','C',' ','V',' ','C','C',' '},
    {'C','C',' ',' ',' ','H','H','H','H','H','H',' ',' ',' ',' '}
  },
  {
    {'S','H','H','H','H','B',' ','B',' ','B','H','H','H','H','S'},
    {'C','C',' ',' ','V',' ','C',' ','C',' ','V',' ','B','B',' '},
    {'C',' ',' ',' ','V',' ','C',' ','C',' ','V',' ','C','C',' '},
    {' ','B','B',' ','V',' ','C',' ','C',' ','V','C','C','C','C'},
    {'C','C','C','C','V',' ','C',' ','C',' ','V','C','C','C','C'},
    {'C','C','C','C','H','H','H','H','H','H','H',' ','C','C',' '},
    {' ','C','C',' ',' ','C',' ','V',' ','C',' ',' ','C','C',' '},
    {' ','C','C',' ',' ','C',' ','V',' ','C',' ',' ',' ',' ',' '},
    {'C',' ',' ',' ',' ','C',' ','V',' ','C',' ',' ',' ',' ','C'},
    {'C','C',' ',' ',' ','C',' ','H',' ','C',' ',' ',' ','C','C'}
  },
  {
    {'S','H','B','C','C','C','C','B','C','C','C','C','B','H','S'},
    {'C','V',' ',' ','C','C','C','C','C','C','C',' ',' ','V','C'},
    {'C','H','H','H',' ','C','C','C','C','C',' ','H','H','H','C'},
    {'C',' ',' ','V',' ',' ','C','C','C',' ',' ','V',' ',' ','C'},
    {' ',' ',' ','H','H','H',' ','C',' ','H','H','H',' ',' ',' '},
    {' ',' ','B',' ',' ','V',' ','B',' ','V',' ',' ','B',' ',' '},
    {' ',' ','C',' ',' ','V','C','C','C','V',' ',' ','C',' ',' '},
    {' ','C','C','C',' ','H','H','H','H','H',' ','C','C','C',' '},
    {'C','C','C','C','C',' ','C','V','C',' ','C','C','C','C','C'},
    {'C','C','C','C','C',' ','C','H','C',' ','C','C','C','C','C'}
  },
  {
    {'S','H','H','H','H','H','H','H','H','H','H','H','H','H','S'},
    {'V','B','C','C','C','C','B','V','C','C','C','C','C','C','V'},
    {'V','C','C','C','C','C','C','V',' ','C','C','B','C',' ','V'},
    {'V',' ','C','C','C','C',' ','V','C','C','B','C','C','C','V'},
    {'V','C','C','C','C','C','C','V',' ','C','C','C','C',' ','V'},
    {'V',' ','C','C','C','C',' ','V','B','C','C','C','C','C','V'},
    {'V','C','C','B','C','C','C','V',' ','C','C','C','C',' ','V'},
    {'V',' ','C','C','B','C',' ','V','C','C','C','C','C','C','V'},
    {'V','C','C','C','C','C','C','V','C','C','C','C','C','C','V'},
    {'H','H','H','H','H','H','H','H','H','H','H','H','H','H','H'}
  },
  {
    {'S','H','H','H','H','H','H','H','H','H','H','H','H','H','S'},
    {'V','C','B','C','C','V',' ','V',' ','V','C','C','B','C','V'},
    {'V','C','C','C',' ','V','B','V','B','V',' ','C','C','C','V'},
    {'V','C','C','C','H','H',' ','V',' ','H','H','C','C','C','V'},
    {'V','C','C',' ','V',' ','C','V','C',' ','V',' ','C','C','V'},
    {'V','C','C','H','H',' ','C','V','C',' ','H','H','C','C','V'},
    {'V','C',' ','V',' ','C','C','V','C','C',' ','V',' ','C','V'},
    {'V','C','H','H','B','C','C','V','C','C','B','H','H','C','V'},
    {'V','C','V','C','C','C','C','V','C','C','C','C','V','C','V'},
    {'H','H','H','H','H','H','H','H','H','H','H','H','H','H','H'}
  },
  {
    {'S','H','C','C','C','C','C','V','C','C','C','C','C','H','S'},
    {' ','V','C','B','C','B','C','V','C','B','C','B','C','V',' '},
    {'B','V','C','C','C','C','C','V','C','C','C','C','C','V','B'},
    {'C','H','H','C','C','C','C','V','C','C','C','C','H','H','C'},
    {'C','C','V',' ','C','C','C','V','C','C','C',' ','V','C','C'},
    {'C','C','H','H','H','C','C','V','C','C','H','H','H','C','C'},
    {'C','C','C','C','V',' ','C','V','C',' ','V','C','C','C','C'},
    {'C','C','C','C','H','H',' ','V',' ','H','H','C','C','C','C'},
    {'C','C','C','C','C','V',' ','V',' ','V','C','C','C','C','C'},
    {'C','C','C','C','C','H','H','H','H','H','C','C','C','C','C'}
  },
  {
    {'H','H','H','H','H','H','H','H','H','H','H','H','H','H','S'},
    {'V',' ','C','C','B','C','C','C','C','C','B','C','C',' ','V'},
    {'H','H','H','C','C','C','C','B','C','C','C','C','H','H','H'},
    {'V','B','V',' ','C','C','C','C','C','C','C',' ','V','B','V'},
    {'V','C','H','H','H','C','C','C','C','C','H','H','H','C','V'},
    {'V','C','C','B','V',' ','C','C','C',' ','V','B','C','C','V'},
    {'V','C','C','C','H','H','H','C','H','H','H','C','C','C','V'},
    {'V','C','C','C','C',' ','V',' ','V',' ','C','C','C','C','V'},
    {'V','C','C','C','C','C','V',' ','V','C','C','C','C','C','V'},
    {'H','H','H','H','H','H','H','H','H','H','H','H','H','H','H'}
  }
};

const char masks[7] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20};
const char turningPoints[4] = {0,4,0,5};
 
cell::cell()
{
    state[Direction::DIG_LEFT] = 0;
    state[Direction::DIG_RIGHT] = 0;
    state[Direction::DIG_UP] = 0;
    state[Direction::DIG_DOWN] = 0;
}

void cell::H()
{
    state[Direction::DIG_LEFT] = 31;
    state[Direction::DIG_RIGHT] = 31;
}

void cell::V()
{
    state[Direction::DIG_UP] = 63;
    state[Direction::DIG_DOWN] = 63;
    
}

void cell::S()
{
    H();
    V();
}

Digger::Digger(int x, int y)
{
    dir = Direction::DIG_NONE;
    desiredDir = Direction::DIG_NONE;
    
    hitBox.x = x;
    hitBox.y = y;
    hitBox.w = 5;
    hitBox.h = 6;
}

void GameScene::initLevel(int level)
{
    _levelData.resize(10);
    for(int i = 0; i < 10; ++i)
    {
        _levelData[i].resize(15);
        for(int j = 0; j < 15; ++j)
        {
            cell c;
            switch(leveldat[level][i][j])
            {
                case 'H':
                    c.H();
                    if(i < 9 && leveldat[level][i+1][j] == 'V')
                    {
                        c.state[Direction::DIG_DOWN] |= 32;
                    }
                    if(i > 0 && leveldat[level][i-1][j] == 'V')
                    {
                        c.state[Direction::DIG_UP] |= 32;
                    }
                break;
                case 'V':
                    c.V();
                break;
                case 'S':
                    c.S();
                break;
            }
            _levelData[i][j] = c;
        }
    }
    _levelSize.w = 15;
    _levelSize.h = 10;
  
    _players.push_back(Digger(30,54));
    _digTick = 0.0f;
}


void GameScene::enter()
{
    _renderWindow.x = 0;
    _renderWindow.y = 0;
    _renderWindow.w = 640;
    _renderWindow.h = 400;
    
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
                        if(_players[i].dir == Direction::DIG_LEFT || _players[i].dir == Direction::DIG_RIGHT || (_players[i].hitBox.y % 6) == 0)
                        {
                            _players[i].dir = _players[i].desiredDir;
                        }
                    }
                    if(_players[i].desiredDir == Direction::DIG_UP || _players[i].desiredDir == Direction::DIG_DOWN)
                    {
                        if(_players[i].dir == Direction::DIG_UP || _players[i].dir == Direction::DIG_DOWN || (_players[i].hitBox.x % 5) == 0)
                        {
                            _players[i].dir = _players[i].desiredDir;
                        }
                    }
                }
                printf("DIR : %d DESIRED %d X %d Y %d XR %d YR %d\n", _players[i].dir, _players[i].desiredDir, _players[i].hitBox.x , _players[i].hitBox.y , _players[i].hitBox.x % 5, _players[i].hitBox.y % 6);
                if(_players[i].dir == Direction::DIG_LEFT && _players[i].hitBox.x > 0)
                {
                    _players[i].hitBox.x -= 1;
                    int x = _players[i].hitBox.x / 5;
                    int y = _players[i].hitBox.y / 6;
                    int index = 5 - (_players[i].hitBox.x % 5) + 1;
                    _levelData[y][x].state[Direction::DIG_LEFT] |= masks[index]; 
                }
                if(_players[i].dir == Direction::DIG_RIGHT && _players[i].hitBox.x < (_levelSize.w - 1) * 5)
                {
                    _players[i].hitBox.x += 1;
                    int x = (_players[i].hitBox.x + 5) / 5;
                    int y = _players[i].hitBox.y / 6;
                    int index = _players[i].hitBox.x % 5 + 1;
                    _levelData[y][x].state[Direction::DIG_RIGHT] |= masks[index]; 
                }
                if(_players[i].dir == Direction::DIG_UP && _players[i].hitBox.y > 0)
                {
                    _players[i].hitBox.y -= 1;
                    int x = _players[i].hitBox.x / 5;
                    int y = _players[i].hitBox.y / 6;
                    int index = 6 - (_players[i].hitBox.x % 6);
                    _levelData[y][x].state[Direction::DIG_UP] |= masks[index]; 
                }
                if(_players[i].dir == Direction::DIG_DOWN && _players[i].hitBox.y < (_levelSize.h - 1) * 6)
                {
                    _players[i].hitBox.y += 1;
                }
            }
        
        }
        
        
        
    }
}

void GameScene::renderLeft(SDL_Renderer* renderer)
{
    SDL_Rect r;
    r.w = 56;
    r.h = 48;
    for(int y = 0; y < _levelSize.h; ++y)
    {
        for(int x = _levelSize.w - 1; x > -1; x--)
        {
            SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_LEFT, _levelData[y][x].state[Direction::DIG_LEFT], renderer);
            r.x = 24 + x * 40 - 8;
            r.y = 36 + y * 36 - 6;
            SDL_RenderCopy(renderer, tex1, NULL, &r);
        }
    }
}

void GameScene::renderRight(SDL_Renderer* renderer)
{
    SDL_Rect r;
    r.w = 56;
    r.h = 48;
    for(int y = 0; y < _levelSize.h; ++y)
    {
        for(int x = 0; x < _levelSize.w; x++)
        {
            SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_RIGHT, _levelData[y][x].state[Direction::DIG_RIGHT], renderer);
            r.x = 24 + x * 40 - 8;
            r.y = 36 + y * 36 - 6;
            SDL_RenderCopy(renderer, tex1, NULL, &r);
        }
    }
}

void GameScene::renderDown(SDL_Renderer* renderer)
{
    SDL_Rect r;
    r.w = 56;
    r.h = 48;
    for(int y = 0; y < _levelSize.h; ++y)
    {
        for(int x = 0; x < _levelSize.w; x++)
        {
            SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_DOWN, _levelData[y][x].state[Direction::DIG_DOWN], renderer);
            r.x = 24 + x * 40 - 8;
            r.y = 36 + y * 36 - 6;
            SDL_RenderCopy(renderer, tex1, NULL, &r);
        }
    }
}

void GameScene::renderUp(SDL_Renderer* renderer)
{
    SDL_Rect r;
    r.w = 56;
    r.h = 48;
    for(int y = _levelSize.h - 1; y > -1; y--)
    {
        for(int x = 0; x < _levelSize.w; x++)
        {
            SDL_Texture* tex1 = ResourceManager::instance()->getBlob(Direction::DIG_UP, _levelData[y][x].state[Direction::DIG_UP], renderer);
            r.x = 24 + x * 40 - 8;
            r.y = 36 + y * 36 - 6;
            SDL_RenderCopy(renderer, tex1, NULL, &r);
        }
    }
}

void GameScene::renderDigger(SDL_Renderer* renderer)
{
   SDL_Texture* tex1 = ResourceManager::instance()->getDigger(0, Direction::DIG_UP, 0, renderer);
   SDL_Rect r;
   for(int i = 0; i < _players.size(); ++i)
   {  
        r.x = _players[i].hitBox.x * 8 + 24 + 4;
        r.y = _players[i].hitBox.y * 6 + 36 + 3;
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

