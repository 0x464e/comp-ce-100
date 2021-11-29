/*
 * Bullet.c
 *
 *  Created on: Nov 27, 2021
 *      Author: tsuribori
 */
#include "Bullet.h"
#include "Pixel.h"
#include "alien.h"

void DrawBullet(Bullet* bullet, Alien* alien) {
	bullet->ticker++;
	bullet->new_bullet_ticker++;
	if (bullet->ticker > 5) {
		SetPixel(bullet->coords.x,bullet->coords.y,0,0,0);
		bullet->coords.y += bullet->direction;
		if (bullet->coords.y <= 7 && bullet->coords.y >= 0) {
			if (bullet->is_alien) {
				SetPixel(bullet->coords.x,bullet->coords.y,50,0,50);
			}
			else {
				SetPixel(bullet->coords.x,bullet->coords.y,0,50,0);
			}
		}
		bullet->ticker = 0;
	}
	if (bullet->new_bullet_ticker > 60) {
		if (alien) {
			SetPixel(bullet->coords.x,bullet->coords.y,0,0,0);
			bullet->coords.x = alien->coords.x;
			bullet->coords.y = alien->coords.y + 1;
			SetPixel(bullet->coords.x,bullet->coords.y,50,0,50);
		}

		bullet->ticker = 0;
		bullet->new_bullet_ticker = 0;
	}
}

