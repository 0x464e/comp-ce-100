/*
 * alien->c
 *
 *  Created on: 15.11.2021
 *      Author: rinne8
 */

#include "Pixel.h"
#include "alien.h"



void DrawAlien(Alien* alien) {
	alien->ticker++;
	if (alien->ticker > 10) {
		SetPixel(alien->coords.x,alien->coords.y,0,0,0);
		alien->coords.x += alien->direction;
		SetPixel(alien->coords.x,alien->coords.y,50,0,50);
		if (alien->coords.x == 7) {
			alien->direction = -1;
		}
		else if (alien->coords.x == 0) {
			alien->direction = 1;
		}

		alien->ticker = 0;
	}
}
