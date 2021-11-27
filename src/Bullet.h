/*
 * Bullet.h
 *
 *  Created on: Nov 27, 2021
 *      Author: tsuribori
 */

#ifndef SRC_BULLET_H_
#define SRC_BULLET_H_
#include "utils.h"

typedef struct Bullet {
	int direction;
	int is_alien;
	struct Coords coords;
	int ticker;
} Bullet;

void DrawBullet(Bullet* bullet);

#endif /* SRC_BULLET_H_ */
