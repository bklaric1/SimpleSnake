/*
 * Schlange.c
 *
 *  Created on: 12.12.2022
 *      Author: Benjamin Klaric
 */
#include <stdlib.h>
#include "Configuration.h"
#include "Schlange.h"
#include "Console.h"
#include <ncurses.h>
#include "Spiel.h"

/*
 * Initialisiert alle Attribute
 */
void schlange_init (Schlange* schlange_ptr)
{
	Liste* liste_ptr = liste_erzeugen();
	schlange_ptr->positionen_ptr = liste_ptr;
	schlange_ptr->punkte = 0;
	schlange_ptr->wachsen = 0;
}

Schlange* schlange_erzeugen()
{
	Schlange* schlange_ptr = (Schlange*) malloc(sizeof(Schlange));
	schlange_init(schlange_ptr);
	return schlange_ptr;
}


/*
 * Funktion bewegt die Schlange in die angegebene Richtung
 * */
void schlange_bewege (Schlange* schlange_ptr, int richtung)
{
	int x, y;

	//Element* element_ptr = element_erzeugen();
	Element* element_ptr = (Element*) malloc(sizeof(Element));
	Element* ende_ptr;

	x = schlange_ptr->positionen_ptr->kopf_ptr->pos.x;
	y = schlange_ptr->positionen_ptr->kopf_ptr->pos.y;

	switch (richtung)
	{
		case BEWEGUNG_HOCH:
			y--;
			break;
		case BEWEGUNG_RECHTS:
			x++;;
			break;
		case BEWEGUNG_RUNTER:
			y++;
			break;
		case BEWEGUNG_LINKS:
			x--;
			break;
		default:
			break;
	}
	element_ptr->pos.x = x;
	element_ptr->pos.y = y;

	if(schlange_ptr->wachsen > 0)
	{
		schlange_ptr->wachsen--;
	}
	else if(schlange_ptr->wachsen <= 0)
	{
		ende_ptr = liste_entferne_ende(schlange_ptr->positionen_ptr);
			if(ende_ptr != NULL)
			{
				free(ende_ptr);
			}
	}
	liste_einfuegen_kopf(schlange_ptr->positionen_ptr, element_ptr);
}

/*
 * Zeichnet die Schlange auf der Konsole
 */
void schlange_zeichne(Schlange* schlange_ptr, int farbe)
{
	attron(COLOR_PAIR(farbe));
	int x, y;
	Element* element_ptr = schlange_ptr->positionen_ptr->kopf_ptr;

	while(element_ptr != NULL)
	{
		x = element_ptr->pos.x;
		y = element_ptr->pos.y;
		console_zeichne_punkt(x, y, ' ');
		element_ptr = element_ptr->nachfolger_ptr;
	}
}
/*
 * Die Funktion verändert die Schlange in Abhängigkeit des eingesammelten Pickups.
 * Alles ist denkbar. Beschleunigung, Wurmloch oder ähnliches.
 */
void schlange_bearbeite_pickup(Schlange* schlange_ptr, Pickup* pickup_ptr)
{
	//Mario's code for pickups
	/*
	if (schlange_ptr->positionen_ptr->kopf_ptr->pos.x == pickup_ptr->pos.x && schlange_ptr->positionen_ptr->kopf_ptr->pos.y == pickup_ptr->pos.y) {
		pickup_ptr->pos.x = rand()%(SPIELFELD_XSIZE - SPIELFELD_OFFSET_X) + SPIELFELD_OFFSET_X;
		pickup_ptr->pos.y = rand()%(SPIELFELD_YSIZE - SPIELFELD_OFFSET_Y) + SPIELFELD_OFFSET_Y;
		pickUp_zeichne(pickup_ptr, FARBE_MAGENTA);
		schlange_ptr->wachsen = 2;
	}
	*/
}

/*
 * Die Funktion sollte nach jeder Bewegung aufgerufen werden und zum Beispiel den
 * Punktestand in Abhängigkeit der Länge der Schlange oder der Spieldauer erhöhen.
 */
void schlange_aktualisiere(Schlange* schlange_ptr)
{
	//Aufgabe 3f) OPTIONAL
	//TODO
}
