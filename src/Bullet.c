/*
 * Bullet.c
 *
 *  Created on: Nov 27, 2021
 *      Author: tsuribori
 */
#include "Bullet.h"
#include "Pixel.h"
#include "alien.h"

void DrawBullet(Bullet* bullet) {
	bullet->ticker++;
	if (bullet->ticker > 1) {
		if (bullet->coords.y <= 5) {
			SetPixel(bullet->coords.x,bullet->coords.y,0,0,0);
		}
		bullet->coords.y += bullet->direction;
		if (bullet->coords.y <= 7 && bullet->coords.y >= 0) {
			SetPixel(bullet->coords.x,bullet->coords.y,0,50,0);
		}
		bullet->ticker = 0;
	}
}

