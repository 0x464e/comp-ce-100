#include "Bullet.h"
#include "Pixel.h"
#include "alien.h"

void DrawBullet(Bullet* bullet) {
	if (bullet->coords.y <= 5 && bullet->coords.y >= 0) {
		SetPixel(bullet->coords.x,bullet->coords.y,0,0,0);
	}
	bullet->coords.y--;
	if (bullet->coords.y <= 7 && bullet->coords.y >= 0) {
		SetPixel(bullet->coords.x,bullet->coords.y,0,50,0);
	}
}

