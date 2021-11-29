/*
 * alien->c
 *
 *  Created on: 15.11.2021
 *      Author: rinne8
 */

#include "Pixel.h"
#include "alien.h"



void DrawAlien(Alien* alien) {
	SetPixel(alien->coords.x,alien->coords.y,255,0,255);
	run(alien->coords.x);
	open_line(alien->coords.x);
	alien->ticker++;
	if (alien->ticker > 10) {
		alien->coords.x += alien->direction;
		if (alien->coords.x == 7) {
			alien->direction = -1;
		}
		else if (alien->coords.x == 0) {
			alien->direction = 1;
		}
		alien->ticker = 0;
	}
}
