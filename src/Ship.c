/*
 * Ship.c
 *
 *  Created on: Nov 29, 2021
 *      Author: tsuribori
 */

#include "Ship.h"

void DrawShip(uint8_t position, uint8_t r, uint8_t g, uint8_t b)
{
	if(position > 0)
		SetPixel(position-1, 7, r, g, b);
	SetPixel(position, 7, r, g, b);
	SetPixel(position, 6, r, g, b);
	if(position < 7)
		SetPixel(position+1, 7, r, g, b);

}

void MoveShip(uint8_t direction, Ship* ship)
{
	if (direction == LEFT)
	{
		//if we're not jumping from the left side to the right side
		if (ship->position != 0)
		{
			//if right most pixel isnt out of the screen
			if (ship->position != 7)
				SetPixel(ship->position+1, 7, 0, 0, 0);
			SetPixel(ship->position, 6, 0, 0, 0);

			SetPixel(ship->position-1, 6, 0, 50, 0);

			//if left most pixel isnt out of the screen
			if (ship->position != 1)
				SetPixel(ship->position-2, 7, 0, 50, 0);
		}
		else
		{
			SetPixel(ship->position+1, 7, 0, 0, 0);
			SetPixel(ship->position, 6, 0, 0, 0);
			SetPixel(ship->position, 7, 0, 0, 0);

			SetPixel(7, 6, 0, 50, 0);
			SetPixel(7, 7, 0, 50, 0);
			SetPixel(6, 7, 0, 50, 0);
		}

		ship->position = ((ship->position - 1) % 8 + 8) % 8; // trick for negative modulo to work (-1 % 8 = 7)
	}
	else // RIGHT
	{
		//if we're not jumping from the right side to the left side
		if (ship->position != 7)
		{
			//if left most pixel isnt out of the screen
			if (ship->position != 0)
				SetPixel(ship->position-1, 7, 0, 0, 0);
			SetPixel(ship->position, 6, 0, 0, 0);

			SetPixel(ship->position+1, 6, 0, 50, 0);

			//if right most pixel isnt out of the screen
			if (ship->position != 6)
				SetPixel(ship->position+2, 7, 0, 50, 0);
		}
		else
		{
			SetPixel(ship->position-1, 7, 0, 0, 0);
			SetPixel(ship->position, 6, 0, 0, 0);
			SetPixel(ship->position, 7, 0, 0, 0);

			SetPixel(0, 6, 0, 50, 0);
			SetPixel(0, 7, 0, 50, 0);
			SetPixel(1, 7, 0, 50, 0);
		}
		ship->position = (ship->position + 1) % 8;
	}
}


