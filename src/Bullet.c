/*
 * Bullet.c
 *
 *  Created on: Nov 27, 2021
 *      Author: tsuribori
 */
#include "Bullet.h"
#include "Pixel.h"

void DrawBullet(Bullet* bullet) {
	SetPixel(bullet->coords.x,bullet->coords.y,20,20,20);
	run(bullet->coords.x);
	open_line(bullet->coords.x);
	bullet->ticker++;
	if (bullet->ticker > 5) {
		if (bullet->coords.y == 7 || bullet->coords.y == 0) {
			bullet = NULL;
		}
		else {
			bullet->coords.y += bullet->direction;
			bullet->ticker = 0;
		}
	}
}

