/*
 * Ship.h
 *
 *  Created on: Nov 29, 2021
 *      Author: tsuribori
 */

#ifndef SRC_SHIP_H_
#define SRC_SHIP_H_
#include "platform.h"
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"
#include "xgpiops.h"
#include "xttcps.h"
#include "xscugic.h"
#include "xparameters.h"
#include "Pixel.h"
#include "utils.h"

typedef struct Ship {
	int position;
} Ship;

void DrawShip(uint8_t position, uint8_t r, uint8_t g, uint8_t b);
void MoveShip(uint8_t direction, Ship* ship);



#endif /* SRC_SHIP_H_ */
