/* 
 * File:   GameField.h
 * Author: roman.stetsyshin
 *
 * Created on October 6, 2016, 1:26 PM
 */

#ifndef GAMEFIELD_H
#define	GAMEFIELD_H

#include <vector>

class GameField {
public:
    GameField();
    ~GameField();
    
    int getWidth();
    int getHeight();
    
    int getWidthInBlocks();
    int getHeightInBlocks();
    
    void setBit(int direction, int x, int y , bool value);
    bool getBit(int direction, int x, int y);
    
    const std::vector<bool>& getStream(int direction, int v);
    
    void initFromLevel(int level);
    
private:
    std::vector<std::vector<bool> > _states[4];
    int _width;
    int _height;
    
    void setH(int x,int y);
    void setV(int x, int y);
    
    
};

#endif	/* GAMEFIELD_H */

