/*
 * alien.c
 *
 *  Created on: 15.11.2021
 *      Author: rinne8
 */

#include "Pixel.h"
#include "alien.h"
#include "Bullet.h"

struct Alien alien = { 100, {0,1}, 1, 0, 0};

void DrawAlien(Bullet* alienbullet) {
	SetPixel(alien.coords.x,alien.coords.y,20,0,20);
	run(alien.coords.x);
	open_line(alien.coords.x);
	alien.ticker++;
	alien.bullet_counter++;
	if (alien.ticker > 10) {
		alien.coords.x += alien.direction;
		if (alien.coords.x == 7) {
			alien.direction = -1;
		}
		else if (alien.coords.x == 0) {
			alien.direction = 1;
		}
		alien.ticker = 0;
	}
	if (alien.bullet_counter > 30) {
		//Bullet new_bullet = {-1, 1, {alien.coords.x, alien.coords.y + 1}, 0};
		//*alienbullet = new_bullet;
	}
}
