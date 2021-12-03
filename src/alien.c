#include "Pixel.h"
#include "alien.h"


void DrawAlien(Alien* alien) {
	alien->ticker++;
	if (alien->ticker > 10) {
		SetPixel(alien->coords.x,alien->coords.y,0,0,0);
		alien->coords.x += alien->direction;
		SetPixel(alien->coords.x,alien->coords.y,50,0,50);
		if (alien->coords.x == 7) {
			alien->direction = LEFT;
		}
		else if (alien->coords.x == 0) {
			alien->direction = RIGHT;
		}

		alien->ticker = 0;
	}
}
