#ifndef SRC_BULLET_H_
#define SRC_BULLET_H_
#include "utils.h"
#include "alien.h"


typedef struct Bullet {
	struct Coords coords;
} Bullet;

void DrawBullet(Bullet* bullet);

#endif /* SRC_BULLET_H_ */
