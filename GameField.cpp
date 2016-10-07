/* 
 * File:   GameField.cpp
 * Author: roman.stetsyshin
 * 
 * Created on October 6, 2016, 1:26 PM
 */

#include <vector>

#include "GameField.h"
#include "helpers.h"


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

GameField::GameField() {
}

GameField::~GameField() {
}

void GameField::setH(int x, int y)
{
    for(int i = x*5; i < (x+1) * 5; ++i )
    {
        _states[Direction::DIG_RIGHT][y][i] = 1;
        _states[Direction::DIG_LEFT][y][_width-i-1] = 1;
    }
}
void GameField::setV(int x, int y)
{
    for(int i = y*6; i < (y+1) * 6; ++i )
    {
        _states[Direction::DIG_DOWN][x][i] = 1;
        _states[Direction::DIG_UP][x][_height-i-1] = 1;
    }
}


void GameField::initFromLevel(int level)
{
    int w = 15; 
    int h = 10;
    _width = w * 5;
    _height = h * 6;
    
    _states[Direction::DIG_UP].resize(w);
    _states[Direction::DIG_RIGHT].resize(h);
    _states[Direction::DIG_DOWN].resize(w);
    _states[Direction::DIG_LEFT].resize(h);
    
    
    for(int i = 0; i < h; ++i)
    {
        _states[Direction::DIG_RIGHT][i].resize(_width, 0);
        _states[Direction::DIG_LEFT][i].resize(_width, 0);
    }
    for(int i = 0; i < w; ++i)
    {
        _states[Direction::DIG_UP][i].resize(_height, 0);
        _states[Direction::DIG_DOWN][i].resize(_height, 0);
    }
    
     
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 15; ++j)
        {
            switch(leveldat[level][i][j])
            {
                case 'H':
                    setH(j,i);
                break;
                case 'V':
                    setV(j,i);
                break;
                case 'S':
                   setH(j,i);
                    setV(j,i);
                break;
            }
        }
    }
    
}

void GameField::setBit(int direction, int x, int y, bool value)
{
    int a = (direction == Direction::DIG_LEFT || direction == Direction::DIG_RIGHT) ? y : x;
    int b = a == x ? y : x;
    _states[direction][a][b] = value;
}

bool GameField::getBit(int direction, int x, int y)
{
    int a = (direction == Direction::DIG_LEFT || direction == Direction::DIG_RIGHT) ? y : x;
    int b = a == x ? y : x;
    return _states[direction][a][b];
}

int GameField::getHeight()
{
    return _height;
}

int GameField::getWidth()
{
    return _width;
}

int GameField::getHeightInBlocks()
{
    return _height / 6;
}

int GameField::getWidthInBlocks()
{
    return _width / 5;
}

const std::vector<bool>& GameField::getStream(int direction, int v)
{
    return _states[direction][v];
}