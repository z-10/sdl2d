/* 
 * File:   DebugScene.h
 * Author: roman.stetsyshin
 *
 * Created on August 30, 2016, 12:00 PM
 */

#ifndef DEBUGSCENE_H
#define	DEBUGSCENE_H

#include "Scene.h"

class DebugScene : public Scene {
public:
    DebugScene();
    virtual ~DebugScene();
    
    void enter();
    
    void update(float dt);
    void render(SDL_Renderer* renderer);
    
private:

};

#endif	/* DEBUGSCENE_H */

