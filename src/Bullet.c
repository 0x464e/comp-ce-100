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
	if (bullet->coords.y <= 7 && bullet->coords.y >= 0) {
		SetPixel(bullet->coords.x,bullet->coords.y,255,255,255);
		run(bullet->coords.x);
		open_line(bullet->coords.x);
	}
	else {
		SetPixel(bullet->coords.x,bullet->coords.y,0,0,0);
	}
	bullet->ticker++;
	bullet->new_bullet_ticker++;
	if (bullet->ticker > 5) {
		bullet->coords.y += bullet->direction;
		bullet->ticker = 0;
	}
	if (bullet->new_bullet_ticker > 60) {
		bullet->coords.x = alien->coords.x;
		bullet->coords.y = alien->coords.y + 1;
		bullet->ticker = 0;
		bullet->new_bullet_ticker = 0;
	}
}

