#include <ncurses.h>

//Farben - Übersicht
#define FARBE_SCHWARZ           COLOR_BLACK
#define FARBE_ROT               COLOR_RED
#define FARBE_GRUEN             COLOR_GREEN
#define FARBE_GELB              COLOR_YELLOW
#define FARBE_BLAU              COLOR_BLUE
#define FARBE_MAGENTA           COLOR_MAGENTA
#define FARBE_CYAN              COLOR_CYAN
#define FARBE_WEISS             COLOR_WEISS

//Spielfeld
#define SPIELFELD_OFFSET_Y		3
#define SPIELFELD_OFFSET_X		5
#define SPIELFELD_YSIZE			30
#define SPIELFELD_XSIZE			70
#define SPIELFELD_RAND_FARBE	FARBE_MAGENTA
#define SPIELFELD_HINTERGRUND_FARBE	4

//Spieler
#define SPIELER_1_FARBE		FARBE_ROT
#define SPIELER_2_FARBE		FARBE_GRUEN

#define SPIELER_1_XPOS	SPIELFELD_OFFSET_X+3
#define SPIELER_2_XPOS	SPIELFELD_OFFSET_X+SPIELFELD_XSIZE-9 //9 statt 3 für irgendwelcher Grund
#define SPIELER_YPOS	SPIELFELD_OFFSET_Y+(SPIELFELD_YSIZE-2)/2 //-2 zusätzlich

//Steuerung
#define SPIELER_1_HOCH		'w'
#define SPIELER_1_LINKS		'a'
#define SPIELER_1_RUNTER	's'
#define SPIELER_1_RECHTS	'd'
#define SPIELER_2_HOCH		'i'
#define SPIELER_2_LINKS		'j'
#define SPIELER_2_RUNTER	'k'
#define SPIELER_2_RECHTS	'l'


//Punktestand
#define PUNKTSTAND_XPOS	 SPIELFELD_OFFSET_X + SPIELFELD_XSIZE / 2 - 8;
#define PUNKTSTAND_YPOS	 SPIELFELD_OFFSET_Y + 3;

//Bewegung
#define BEWEGUNG_HOCH	0
#define BEWEGUNG_LINKS	1
#define BEWEGUNG_RUNTER	2
#define BEWEGUNG_RECHTS	3

//Spiel
#define SPIEL_GESCHWINDIGKEIT 	100000
#define SPIEL_SCHLANGEN_LAENGE 	10

