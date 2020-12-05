//============================================================================
// Name        : p017.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// includes
#include <ncurses.h>			// para usar las funciones de NCURSES
#include <unistd.h>				// para usar la función sleep
#include <stdlib.h>				// para los números aleatorios
#include <time.h>				// para la función time()
#include <iostream>				// para entrada y salida de streams
using namespace std;

#define COLORES_FRANK 1			// definieremos un par de colores con el número 1
#define COLORES_RICARDO 2		// ... y un segundo par de colores con el 2

// función que imprime un rectángulo en pantalla
void printRectangulo(int fila, int columna, int base, int altura, int color) ;


int main()
{
	// inicialización de números aleatorios
	srand(time(NULL)) ;

	// iniciamos el modo NCURSES
	initscr() ;

	// si el sistema soporta colores...
	if(has_colors())
	{
		// activamos los colores
		start_color() ;
	}

	// definimos dos pares de colores
	init_pair(COLORES_FRANK, COLOR_WHITE, COLOR_BLUE) ;						// el par 1
	init_pair(COLORES_RICARDO, COLOR_YELLOW, COLOR_GREEN) ;					// el par 2

	attron(COLOR_PAIR(COLORES_FRANK)) ;		// activamos el par 1
	mvprintw(20,50,"HELLO WORLD!") ;		// imprime HELLO WORD! en la posición 20,50 de la pantalla
	attroff(COLOR_PAIR(COLORES_FRANK)) ;	// desactivamos el par 1

	// mueve el cursor a la posición 21,50
	move(21,50) ;
	attron(COLOR_PAIR(COLORES_RICARDO)) ;	// activamos el par 2

	for(int i = 0 ; i < 12; i++)			// imprimimos 12 caracteres de tipo diamante
		addch(ACS_DIAMOND) ;

	attroff(COLOR_PAIR(COLORES_RICARDO)) ;	// desactivamos el par 2

	// esperamos una tecla para continuar
	getch() ;

	// borramos la pantalla
	erase() ;



	// obtenemos el número de filas y columnas de nuestro terminal actual
	int maxx = 0 ;
	int maxy = 0 ;
	getmaxyx(stdscr,maxy,maxx) ;

	// durante 100 iteraciones...
	for(int x = 0 ; x < 100 ; x++)
	{
		// calculamos de forma aleatoria los datos del rectángulo a imprimir
		int fila = rand() % 50 ;
		int columna = rand() % 200 ;
		int base = 2 + rand() % (maxx - columna - 1) ;
		int altura = 2 + rand() % (maxy - fila - 1) ;
		int color = 1 + rand() % 2 ;

		// llamamos a la función que imprime el rectángulo dados los valores calculados
		printRectangulo(fila, columna, base, altura, color) ;

		// con el refresh mostramos datos en pantalla
		refresh() ;

		// dormimos 1 segundo
		sleep(1) ;

	}

	// fin de modo NCURSES
	endwin() ;

	return 0;
}


// -----------------------------------------------------------------------------------------------------------
// printRectangulo
// Función que dadas unas coordenadas (fila, columna) imprime un rectángulo en NCURSES con una base, altura y
//	par de colores especificados en los parámatros de la función
void printRectangulo(int fila, int columna, int base, int altura, int colorpair)
{
	// activamos el par de colores
	attron(COLOR_PAIR(colorpair)) ;

	// imprimimos el rectángulo
	for(int i = 0 ; i < altura ; i++)
	{
		if(i == 0)							// fila inicial
		{
			move(fila,columna) ; addch(ACS_ULCORNER) ;
			for(int j = 0 ; j < base ; j++)
			{
				addch(ACS_HLINE) ;
			}
			addch(ACS_URCORNER) ;
		}
		else if(i == altura -1)				// fila final
		{
			move(fila+i,columna) ; addch(ACS_LLCORNER) ;
			for(int j = 0 ; j < base ; j++)
			{
				addch(ACS_HLINE) ;
			}
			addch(ACS_LRCORNER) ;
		}
		else								// resto de filas
		{
			move(fila+i,columna) ; addch(ACS_VLINE) ;
			move(fila+i,columna+base+1) ; addch(ACS_VLINE) ;
		}
	}

	// desactivamos el par de colores actual
	attroff(COLOR_PAIR(colorpair)) ;

}
