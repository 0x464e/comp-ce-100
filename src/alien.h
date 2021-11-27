/*
 * alien.h
 *
 *  Created on: 15.11.2021
 *      Author: rinne8
 */

#ifndef SRC_ALIEN_H_
#define SRC_ALIEN_H_
#include "utils.h"
#include "Bullet.h"

struct Alien {
	int health;
	struct Coords coords;
	int direction;
	int ticker;
	int bullet_counter;
};

void DrawAlien(Bullet* alienbullet);


#endif /* SRC_ALIEN_H_ */
