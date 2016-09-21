/* 
 * File:   ResourceManager.h
 * Author: roman.stetsyshin
 *
 * Created on August 30, 2016, 3:54 PM
 */

#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#include <SDL.h>


#include "helpers.h"

class ResourceManager {
public:
    static bool init();
    static void destroy();
    static ResourceManager* instance();
    
    
    SDL_Texture* getBlob(Direction dir, char mask, SDL_Renderer* render); 
    SDL_Texture* getDigger(int player, Direction dir, int frame, SDL_Renderer* render); 
    
private:
    
    static ResourceManager* _instance;
    
    ResourceManager();
    ~ResourceManager();
    
    SDL_Texture* _blobs[4][0xFF];
    SDL_Texture* _diggers[CONTROL_MAX_PLAYERS][4][3];
    
    SDL_Texture* buildBlob(Direction dir, char mask, SDL_Renderer* render);
    
};

#endif	/* RESOURCEMANAGER_H */

