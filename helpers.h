/* 
 * File:   helpers.h
 * Author: roman.stetsyshin
 *
 * Created on August 30, 2016, 3:56 PM
 */

#ifndef HELPERS_H
#define	HELPERS_H

typedef enum
{
    DIG_UP = 0,
    DIG_RIGHT = 1,
    DIG_DOWN = 2,
    DIG_LEFT = 3,
    DIG_NONE = 5
} Direction;

typedef enum 
{
    CT_UNKNOWN = -1,
    CT_LEFT = 0,
    CT_RIGHT = 1,
    CT_UP = 2,
    CT_DOWN = 3,
    CT_FIRE = 4,
    CT_BACK = 5,
    CT_Total = 6        
} Controls;

#define CONTROL_MAX_PLAYERS 4

#define JOYSTICK_DEAD_ZONE 8000

#define DIGGER_SPEED 17094.0f

#endif	/* HELPERS_H */

