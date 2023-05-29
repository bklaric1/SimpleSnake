/*
 ============================================================================
 Name        : SimpleSnake.c
 Author      : Benjamin Klaric
 Version     :
 Copyright   : Hochschule Augsburg
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// Informationen zu ncurses => https://de.wikibooks.org/wiki/Ncurses:_Grundlegendes#ncurses_und_I/O-Befehle_von_C
// Informationen zu ncurses => https://openbook.rheinwerk-verlag.de/linux_unix_programmierung/Kap13-002.htm

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "Schlange.h"
#include "Console.h"
#include "Eingabe.h"
#include "Configuration.h"
#include "Spiel.h"
#include <unistd.h>
/*test von Bodisco
int main (void)
{
	//Startet ncurses und initialisiert es
	console_init();

	Schlange* s_ptr = schlange_erzeugen();

	Element* e_ptr = element_erzeugen();
	e_ptr->pos.x = 10;
	e_ptr->pos.y = 10;

	liste_einfuegen_kopf(s_ptr->positionen_ptr, e_ptr);

	schlange_zeichne(s_ptr, SPIELER_2_FARBE);
	getchar();
	schlange_zeichne(s_ptr, SPIELFELD_HINTERGRUND_FARBE);
	schlange_bewege(s_ptr, BEWEGUNG_LINKS);
	schlange_zeichne(s_ptr, SPIELER_2_FARBE);
	getchar();
	return 0;
}
*/

int main(void) {

	//Startet ncurses und initialisiert es
	console_init();

	//srand(time(NULL));
	//Zeichne den Spielfeldrand
	spiel_zeichne_rand();

	//Erzeugt eine Struktur zum Einlesen
	Eingabe* eingabe_ptr = eingabe_erzeugen();

	//Erzeugt ein Spiel mit zwei Schlangen und initialisiert es
	Spiel* spiel_ptr = spiel_erzeugen();

	while(spiel_ptr->run == 1)
	{
		//Einlesen der Eingabe
		eingabe_einlesen(eingabe_ptr);

		//Zeichne Schlange 1
		schlange_zeichne(spiel_ptr->s1_ptr, SPIELFELD_HINTERGRUND_FARBE);
		schlange_bewege(spiel_ptr->s1_ptr, eingabe_ptr->letzte_eingabe_spieler_1);
		schlange_zeichne(spiel_ptr->s1_ptr, SPIELER_1_FARBE);

		//Zeichne Schlange 2
		schlange_zeichne(spiel_ptr->s2_ptr, SPIELFELD_HINTERGRUND_FARBE);
		schlange_bewege(spiel_ptr->s2_ptr, eingabe_ptr->letzte_eingabe_spieler_2);
		schlange_zeichne(spiel_ptr->s2_ptr, SPIELER_2_FARBE);

		//Prüfe auf Kollission => Relevant für Spielende
		spiel_pruefe_kollission(spiel_ptr);
		// Mario's code for pickups
		/*
		if(spiel_ptr->pickup_ptr == NULL)
		{
			attron(COLOR_PAIR(SPIELFELD_RAND_FARBE));
			spiel_ptr->pickup_ptr = pickup_erstellen();
			spiel_ptr->pickup_ptr->pos.x = rand()%(SPIELFELD_XSIZE - SPIELFELD_OFFSET_X) + SPIELFELD_OFFSET_X;
			spiel_ptr->pickup_ptr->pos.y = rand()%(SPIELFELD_YSIZE - SPIELFELD_OFFSET_Y) + SPIELFELD_OFFSET_Y;
			console_zeichne_punkt(spiel_ptr->pickup_ptr->pos.x, spiel_ptr->pickup_ptr->pos.y, ' ');
		}

		schlange_bearbeite_pickup(spiel_ptr->s1_ptr, spiel_ptr->pickup_ptr);
		schlange_bearbeite_pickup(spiel_ptr->s2_ptr, spiel_ptr->pickup_ptr);
		 */

		//Spielzeit erhöhen
		spiel_ptr->schritte++;

		//Pausieren des Main-Thread - Spielgeschwindigkeit
		usleep(SPIEL_GESCHWINDIGKEIT);
	}

	//Warte auf Tastendruck
	getchar();

	return EXIT_SUCCESS;
}
