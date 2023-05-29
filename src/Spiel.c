/*
 * Spiel.c
 *
 *  Created on: 12.12.2022
 *      Author: Benjamin Klaric
 */
#include "Configuration.h"
#include "Console.h"
#include "Spiel.h"
#include <stdlib.h>
#include <ncurses.h>

void spiel_init(Spiel* spiel_ptr)
{
	spiel_ptr->s1_ptr = schlange_erzeugen();
	spiel_ptr->s2_ptr = schlange_erzeugen();

	Element* e_ptr1 = element_erzeugen();
	Element* e_ptr2 = element_erzeugen();

	liste_einfuegen_kopf(spiel_ptr->s1_ptr->positionen_ptr, e_ptr1);
	liste_einfuegen_kopf(spiel_ptr->s2_ptr->positionen_ptr, e_ptr2);

	spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr->pos.x = SPIELER_1_XPOS;
	spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr->pos.y = SPIELER_YPOS;
	spiel_ptr->s1_ptr->wachsen = SPIEL_SCHLANGEN_LAENGE;

	spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr->pos.x = SPIELER_2_XPOS;
	spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr->pos.y = SPIELER_YPOS;
	spiel_ptr->s2_ptr->wachsen = SPIEL_SCHLANGEN_LAENGE;

	spiel_ptr->run = 1;
}

Spiel* spiel_erzeugen()
{
	Spiel* spiel_ptr = (Spiel*) malloc(sizeof(Spiel));
	spiel_init(spiel_ptr);
	return spiel_ptr;
}

void spiel_zeichne_rand()
{
	attron(COLOR_PAIR(SPIELFELD_RAND_FARBE));
	for(int x = SPIELFELD_OFFSET_X; x <= SPIELFELD_XSIZE; x++)
	{
		for(int y = SPIELFELD_OFFSET_Y; y <= SPIELFELD_YSIZE; y++)
		{
			if((x == SPIELFELD_OFFSET_X) || (y == SPIELFELD_OFFSET_Y) || (x == SPIELFELD_XSIZE) || (y == SPIELFELD_YSIZE))
			{
				console_zeichne_punkt(x, y, ' ');
			}
		}
	}

}

void spiel_pruefe_kollission(Spiel* spiel_ptr)
{
	char folge_1 = element_folge_pruefen(spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr, spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr);
	char folge_2 = element_folge_pruefen(spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr, spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr);
	char folge_3 = element_folge_pruefen(spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr, spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr);
	char folge_4 = element_folge_pruefen(spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr, spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr);
	int x_1 = spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr->pos.x;
	int y_1 = spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr->pos.y;
	int x_2 = spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr->pos.x;
	int y_2 = spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr->pos.y;

		if(folge_1 == 1)
		{
			spiel_ptr->run = 0;
		}

		if(folge_2 == 1)
		{
			spiel_ptr->run = 0;
		}

		if(folge_3 == 1)
		{
			spiel_ptr->run = 0;
		}

		if(folge_4 == 1)
		{
			spiel_ptr->run = 0;
		}

		if((x_1 == SPIELFELD_OFFSET_X + 1) || (y_1 == SPIELFELD_OFFSET_Y + 1)
				|| (x_1 == SPIELFELD_XSIZE - 1) || (y_1 == SPIELFELD_YSIZE - 1))
		{
			spiel_ptr->run = 0;
		}

		if((x_2 == SPIELFELD_OFFSET_X + 1) || (y_2 == SPIELFELD_OFFSET_Y + 1)
				|| (x_2 == SPIELFELD_XSIZE - 1) || (y_2 == SPIELFELD_YSIZE - 1))
		{
			spiel_ptr->run = 0;
		}
}

void spiel_zeichne_spielstand()
{
	//Aufgabe 4e)     OPTIONAL
	//TODO
}
