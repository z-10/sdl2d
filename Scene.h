/* 
 * File:   Scene.h
 * Author: roman.stetsyshin
 *
 * Created on August 29, 2016, 5:25 PM
 */

#ifndef SCENE_H
#define	SCENE_H
#include <SDL.h>

class Scene {
public:
    Scene();
    virtual ~Scene();
    
    virtual void enter();
    virtual void update(float dt);
    virtual void render(SDL_Renderer* renderer);
    virtual void leave();
    
private:

};

#endif	/* SCENE_H */

