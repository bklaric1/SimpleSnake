/*
 * Element.c
 *
 *  Created on: 12.12.2022
 *      Author: Benjamin Klaric
 */
#include "Element.h"
Element* element_erzeugen()
{
	Element* element = (Element*) malloc(sizeof(Element));
	element->nachfolger_ptr = NULL;
	element->pos.x = 0;
	element->pos.y = 0;
	return element;
}
/* Prüfe, ob e1 mit einem seiner Nachfolger übereinstimmt */
char element_folge_pruefen (Element* pruef_ptr, Element* e_ptr)
{

	char Ergebnis = 0;

	while(e_ptr != NULL)
	{
		if((pruef_ptr->pos.x == e_ptr->pos.x) && (pruef_ptr->pos.y == e_ptr->pos.y))
		{
			Ergebnis = 1;
			break;
		}
		e_ptr = e_ptr->nachfolger_ptr;
	}
	return Ergebnis;
}
