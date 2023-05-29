/*
 * Pickup.c
 *
 *  Created on: 21.12.2022
 *      Author: Mario
 */

#include <ncurses.h>
#include <stdlib.h>
#include "Configuration.h"
#include "Console.h"
#include "Pickup.h"

Pickup* pickup_erstellen()
{
	Pickup* pickup = (Pickup*) malloc(sizeof(Pickup));
	pickup->pos.x = 0;
	pickup->pos.y = 0;
	return pickup;
}

void pickUp_zeichne(Pickup* pickup_ptr, int farbe)
{
	attron(COLOR_PAIR(farbe));
	console_zeichne_punkt(pickup_ptr->pos.x, pickup_ptr->pos.y, ' ');
}
