/*
 * Ship.c
 *
 *  Created on: Nov 29, 2021
 *      Author: tsuribori
 */

#include "Ship.h"

void DrawShip(uint8_t position, uint8_t r, uint8_t g, uint8_t b)
{
	    if(position > 0)
	        SetPixel(position-1, 7, r, g, b);
	    SetPixel(position, 7, r, g, b);
	    SetPixel(position, 6, r, g, b);
	    if(position < 7)
	        SetPixel(position+1, 7, r, g, b);

}


