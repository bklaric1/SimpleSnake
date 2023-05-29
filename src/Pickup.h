/*
 * Pickup.h
 *
 *  Created on: 21.12.2022
 *      Author: Mario
 */

#ifndef PICKUP_H_
#define PICKUP_H_

#include "Position.h"

struct Pickup
{
	Position pos;
};

typedef struct Pickup Pickup;

Pickup* pickup_erstellen();

void pickUp_zeichne(Pickup* pickUp_ptr, int farbe);

#endif /* PICKUP_H_ */
