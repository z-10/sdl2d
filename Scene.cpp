/* 
 * File:   Scene.cpp
 * Author: roman.stetsyshin
 * 
 * Created on August 29, 2016, 5:25 PM
 */

#include "Scene.h"
#include "Input.h"

Scene::Scene() {
}

Scene::~Scene() {
}

void Scene::update(float dt)
{
    printf("Time passed : %f\n", dt);
    
    if(Input::instance()->isPressed(0,0))
    {
        printf("GO LEFT!\n");
    }

}

void Scene::render(SDL_Renderer* renderer)
{

}

void Scene::enter()
{

}

void Scene::leave()
{

}
