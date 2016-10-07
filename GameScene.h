/* 
 * File:   GameScene.h
 * Author: roman.stetsyshin
 *
 * Created on August 31, 2016, 11:32 AM
 */

#ifndef GAMESCENE_H
#define	GAMESCENE_H
#include "Scene.h"
#include "GameField.h"

#include <vector>

struct Digger
{
    int dir;
    int desiredDir;
    SDL_Rect hitBox;
    Digger(int x, int y);
    void debug();
};

class GameScene: public Scene {
public:
    GameScene();
    virtual ~GameScene();
    
    void enter();
    
    void update(float dt);
    void render(SDL_Renderer* renderer);
    
private:

    GameField _gameField;
    
    void initLevel(int level);
    
    void renderLeft(SDL_Renderer* renderer);
    void renderRight(SDL_Renderer* renderer);
    void renderUp(SDL_Renderer* renderer);
    void renderDown(SDL_Renderer* renderer);
    
    void renderDigger(SDL_Renderer* renderer);
    
    
    float _digTick;
    std::vector<Digger> _players;
};

#endif	/* GAMESCENE_H */

