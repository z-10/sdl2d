/* 
 * File:   ResourceManager.cpp
 * Author: roman.stetsyshin
 * 
 * Created on August 30, 2016, 3:54 PM
 */

#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_Image.h>

ResourceManager* ResourceManager::_instance = NULL;

bool ResourceManager::init()
{
    if(!_instance)
    {
        _instance = new ResourceManager();
    }
    return true;
}
void ResourceManager::destroy()
{
    delete _instance;
    _instance = NULL;
}
ResourceManager* ResourceManager::instance()
{
    return _instance;
}

SDL_Texture* ResourceManager::getBlob(Direction dir, char mask, SDL_Renderer* render)
{
    SDL_Texture* blob = _blobs[dir][mask];
    if(!blob)
    {
        blob = buildBlob(dir, mask, render);
        _blobs[dir][mask] = blob;
    }
    return blob;
    
}

SDL_Texture* ResourceManager::buildBlob(Direction dir, char mask, SDL_Renderer* render)
{
    SDL_Surface *surface, *blob;
    Uint32 rmask, gmask, bmask, amask;
    SDL_Rect r;

    /* SDL interprets each pixel as a 32-bit number, so our masks must depend
       on the endianness (byte order) of the machine */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif
    surface = SDL_CreateRGBSurface(0, 56, 48, 32, rmask, gmask, bmask, amask);
    
    if(dir == Direction::DIG_LEFT)
    {
        blob = IMG_Load("data/left.png");
        r.w = 16;
        r.h = 36;
        
        for(int i = 0; i < 5; ++i)
        {
            if((mask >> i) & 1)
            {
                r.x = 32 - i * 8;
                r.y = 6;
                SDL_BlitSurface(blob, NULL, surface, &r);    
            }
        }
        
    }
    if(dir == Direction::DIG_RIGHT)
    {
        blob = IMG_Load("data/right.png");
        r.w = 16;
        r.h = 36;
        
        for(int i = 0; i < 5; ++i)
        {
            if((mask >> i) & 1)
            {
                r.x = 8 + i * 8;
                r.y = 6;
                SDL_BlitSurface(blob, NULL, surface, &r);    
            }
        }
        
    }
    
    if(dir == Direction::DIG_UP)
    {
        blob = IMG_Load("data/up.png");
        r.w = 40;
        r.h = 12;
        
        for(int i = 0; i < 6; ++i)
        {
            if((mask >> i) & 1)
            {
                r.x = 4;
                r.y = 30 - i * 6;
                SDL_BlitSurface(blob, NULL, surface, &r);    
            }
        }
        
    }
    
        if(dir == Direction::DIG_DOWN)
    {
        blob = IMG_Load("data/down.png");
        r.w = 40;
        r.h = 12;
        
        for(int i = 0; i < 6; ++i)
        {
            if((mask >> i) & 1)
            {
                r.x = 4;
                r.y = 6 + i * 6;
                SDL_BlitSurface(blob, NULL, surface, &r);    
            }
        }
        
    }
    
    SDL_Texture* tex = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(blob);
    IMG_SavePNG(surface,"data/test.png");
    SDL_FreeSurface(surface);
    return tex;
}


ResourceManager::ResourceManager() 
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j= 0; j < 0xFF; ++j)
        {
            _blobs[i][j] = NULL;
        }
    }
    for(int player = 0; player < CONTROL_MAX_PLAYERS; ++player)
    {
        for(int i = 0; i < 4; ++i)
        {
            for(int j= 0; j < 3; ++j)
            {
                if(_diggers[player][i][j])
                {
                    _diggers[player][i][j] = NULL;
                }
            }
        }
    
    }    
    
}

SDL_Texture* ResourceManager::getDigger(int player, Direction dir, int frame, SDL_Renderer* render)
{
    SDL_Texture* tex = _diggers[player][dir][frame];
    if(!tex)
    {
        SDL_Surface* surface = IMG_Load("data/dig.png");
        tex = SDL_CreateTextureFromSurface(render, surface);
        SDL_FreeSurface(surface);
        _diggers[player][dir][frame] = tex;
    }
    return tex;
}

ResourceManager::~ResourceManager() 
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j= 0; j < 0xFF; ++j)
        {
            if(_blobs[i][j])
            {
                SDL_DestroyTexture(_blobs[i][j]);
                _blobs[i][j] = NULL;
            }
        }
    }
    
    for(int player = 0; player < CONTROL_MAX_PLAYERS; ++player)
    {
        for(int i = 0; i < 4; ++i)
        {
            for(int j= 0; j < 3; ++j)
            {
                if(_diggers[player][i][j])
                {
                    SDL_DestroyTexture(_diggers[player][i][j]);
                    _diggers[player][i][j] = NULL;
                }
            }
        }
    
    }

}

