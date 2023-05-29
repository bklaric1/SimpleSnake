/*
 * Liste.c
 *
 *  Created on: 12.12.2022
 *      Author: Benjamin Klaric
 */

#include "Liste.h"
Liste* liste_erzeugen()
{
	Liste* liste_ptr = (Liste*) malloc(sizeof(Liste));
	liste_ptr->kopf_ptr = NULL;
	liste_ptr->laenge = 0;
	return liste_ptr;
}

void liste_einfuegen_kopf(Liste* liste_ptr, Element* element_ptr)
{
	element_ptr->nachfolger_ptr = liste_ptr->kopf_ptr;
	liste_ptr->kopf_ptr = element_ptr;
	liste_ptr->laenge++;
}

Element* liste_entferne_ende(Liste* liste_ptr)
{
	Element* vorletzteElement_ptr = liste_ptr->kopf_ptr;
	Element* letzteElement_ptr;

	for(int i = 1; i < liste_ptr->laenge-1; i++)
	{
		vorletzteElement_ptr = vorletzteElement_ptr->nachfolger_ptr;
	}

	letzteElement_ptr = vorletzteElement_ptr->nachfolger_ptr;
	vorletzteElement_ptr->nachfolger_ptr = NULL;
	liste_ptr->laenge--;

	return letzteElement_ptr;
}
