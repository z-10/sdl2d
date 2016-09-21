/* 
 * File:   GameScene.h
 * Author: roman.stetsyshin
 *
 * Created on August 31, 2016, 11:32 AM
 */

#ifndef GAMESCENE_H
#define	GAMESCENE_H
#include "Scene.h"

#include <vector>

struct cell
{
    char visual[4];
    char logic[2];
    cell();
    void H();
    void V();
    void S();
};

class GameScene: public Scene {
public:
    GameScene();
    virtual ~GameScene();
    
    void enter();
    
    void update(float dt);
    void render(SDL_Renderer* renderer);
    
private:

    std::vector<std::vector<cell> > _levelData;
    SDL_Rect _levelSize;
    
    SDL_Rect _renderWindow;
    int _dx, _dy;
    int _dh, _dv;
    int _offset;
    int _digDir;
    int _desiredDir;
    
    void initLevel(int level);
    
    void renderLeft(SDL_Renderer* renderer);
    void renderRight(SDL_Renderer* renderer);
    void renderUp(SDL_Renderer* renderer);
    void renderDown(SDL_Renderer* renderer);
    
    void renderDigger(SDL_Renderer* renderer);
    
    
    float _digTick;
};

#endif	/* GAMESCENE_H */

