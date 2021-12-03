#ifndef SRC_ALIEN_H_
#define SRC_ALIEN_H_
#include "utils.h"

typedef struct Alien {
	int health;
	struct Coords coords;
	int direction;
	int ticker;
} Alien;



void DrawAlien(Alien* alien);


#endif /* SRC_ALIEN_H_ */
