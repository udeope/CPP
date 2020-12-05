//============================================================================
// Name        : p0ex2.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define CUADRADO 20
#define NUM_MINAS CUADRADO*CUADRADO/10

#define TABLE_VSPACE 2
#define TABLE_HSPACE 4

#define COLOR_CELDA_VACIA_VISIBLE 1
#define COLOR_CELDA_MINA_VISIBLE 2
#define COLOR_CELDA_OCULTA 3
#define COLOR_CELDA_NUM_VISIBLE 4
#define COLOR_CELDA_OCULTA_MARCADA 5
#define COLOR_CELDA_OCULTA_MARCADA_FALLO 6

typedef enum Estado { OCULTO = 0 , VISIBLE = 1, MARCADO = 2 } Estado ;

typedef struct Casilla
{
	bool mina_ ;
	unsigned char minasVecinas_ ;
	Estado estado_ ;
	bool marcada_ ;
} Casilla ;

void creaTablero() ;
void borraTablero() ;
void destruyeTablero() ;
void printTablero(bool) ;
void printTablero2(bool) ;
unsigned char minasVecinas(unsigned char, unsigned char) ;
bool visualiza(unsigned char, unsigned char) ;
void chequeaTablero(unsigned char&, unsigned char&) ;

void initNcurses() ;
void endNcurses() ;

Casilla* tablero[CUADRADO][CUADRADO] ;

int main()
{
	srand(time(NULL)) ;

	initNcurses() ;

	creaTablero() ;

	printTablero(true) ;

	bool fin = false ;
	bool ganado = false ;

	int fila, columna ;
	int c ;
	MEVENT event ;

	while(!fin)
	{
		c = getch() ;

		switch(c)
		{
			case KEY_MOUSE :
			{
				if(getmouse(&event) == OK)
				{
					columna = event.x / TABLE_HSPACE ;
					fila = event.y / TABLE_VSPACE ;

					// s'ha de recalcular x & y en funció de la taula

					if(event.bstate & BUTTON1_CLICKED) // mostrar
					{
						fin = visualiza(fila, columna) ;
					}
					else if(event.bstate & BUTTON3_CLICKED) // marcar / desmarcar
					{
						if(tablero[fila][columna]->marcada_) tablero[fila][columna]->marcada_ = false ;
						else tablero[fila][columna]->marcada_ = true ;
					}
				}
			} break ;
		}

		printTablero(true) ;

		unsigned char ocultos = 0 ;
		unsigned char marcados = 0 ;
		chequeaTablero(ocultos, marcados) ;

		if(ocultos == marcados && marcados == NUM_MINAS)
		{
			ganado = true ;
			fin = true ;
		}
		mvprintw(TABLE_VSPACE*CUADRADO+5,1,"                                       ") ;
		mvprintw(TABLE_VSPACE*CUADRADO+5,1,"Marcadas: %d        Restantes: %d",(int)marcados,(int)(NUM_MINAS-marcados)) ;
	}

	if(ganado)
	{
		mvprintw(TABLE_VSPACE*CUADRADO+7,1,"                                       ") ;
		mvprintw(TABLE_VSPACE*CUADRADO+7,1," ENHORABUENA, HAS GANADO!") ;
	}
	else
	{
		mvprintw(TABLE_VSPACE*CUADRADO+7,1,"                                       ") ;
		mvprintw(TABLE_VSPACE*CUADRADO+7,1," BOOOOM! PERDISTE!") ;
	}


	printTablero(false) ;

	getch() ;


	destruyeTablero() ;

	endNcurses() ;

	return 0;
}


// ----------------------------------------------------------------------------------------
// initNcurses
// inicializa el modo ncurses
// ----------------------------------------------------------------------------------------
void initNcurses()
{
	mmask_t old ;
	initscr() ;					// inicialización de pantalla

	if (has_colors())			// si soporta colores
	{
		start_color();			// inicia los colores
	}

	clear() ;
	noecho() ;
	cbreak() ;
	keypad (stdscr, TRUE) ;
	mousemask (ALL_MOUSE_EVENTS | BUTTON1_CLICKED | BUTTON2_CLICKED | BUTTON3_CLICKED | REPORT_MOUSE_POSITION, &old);

	// keypad(win, true) ;

	init_pair(COLOR_CELDA_VACIA_VISIBLE,COLOR_WHITE,COLOR_BLACK) ;			// CELDA VACIA
	init_pair(COLOR_CELDA_MINA_VISIBLE,COLOR_BLACK,COLOR_YELLOW) ;			// MINA
	init_pair(COLOR_CELDA_OCULTA,COLOR_CYAN,COLOR_BLACK) ;					// OCULTA
	init_pair(COLOR_CELDA_NUM_VISIBLE,COLOR_BLUE,COLOR_BLACK) ;				// NUMERO
	init_pair(COLOR_CELDA_OCULTA_MARCADA,COLOR_YELLOW,COLOR_BLACK) ;		// MARCADA
	init_pair(COLOR_CELDA_OCULTA_MARCADA_FALLO,COLOR_YELLOW,COLOR_RED) ;		// MARCADA_FALLO
}

// ----------------------------------------------------------------------------------------
// endNcurses
// finaliza el modo ncurses
// ----------------------------------------------------------------------------------------
void endNcurses()
{
	endwin() ;			// finaliza el modo ncurses
}


void creaTablero()
{
	for(unsigned char i = 0 ; i < CUADRADO ; i++)
	{
		for(unsigned char j = 0 ; j < CUADRADO ; j++)
		{
			tablero[i][j] = (Casilla*) new Casilla ;
			tablero[i][j]->estado_ = OCULTO ;
			tablero[i][j]->mina_ = false ;
			tablero[i][j]->marcada_ = false ;
			tablero[i][j]->minasVecinas_ = 0 ;
		}
	}

	int numMinas = NUM_MINAS ;

	while(numMinas != 0)
	{
		int i = rand() % CUADRADO ;
		int j = rand() % CUADRADO ;

		if(!tablero[i][j]->mina_)
		{
			tablero[i][j]->mina_ = true ;
			numMinas-- ;
		}
	}


	for(unsigned char i = 0 ; i < CUADRADO ; i++)
	{
		for(unsigned char j = 0 ; j < CUADRADO ; j++)
		{
			if(!tablero[i][j]->mina_)
			{
				tablero[i][j]->minasVecinas_ = minasVecinas(i,j) ;
			}
		}
	}


}




unsigned char minasVecinas(unsigned char x, unsigned char y)
{
	unsigned char vecinas = 0 ;

	unsigned char xini = 0 ;
	unsigned char xfin = 0 ;
	unsigned char yini = 0 ;
	unsigned char yfin = 0 ;

	if(x > 0) xini = x - 1 ;
	else xini = 0 ;

	if(x < (CUADRADO-1)) xfin = x + 2 ;
	else xfin = CUADRADO ;

	if(y > 0) yini = y - 1 ;
	else yini = 0 ;

	if(y < (CUADRADO-1)) yfin = y + 2 ;
	else yfin = CUADRADO ;


	for(unsigned char i = xini ; i < xfin ; i++)
	{
		for(unsigned char j = yini ; j < yfin ; j++)
		{
			if(tablero[i][j]->mina_) vecinas++ ;
		}
	}


	return vecinas ;
}


void printTablero(bool oculto)
{
	for(int i = 0 ; i < CUADRADO+1 ; i++)
	{
		for(int j = 0 ; j < CUADRADO ; j++)
		{
			if(i == 0 && j == 0)
			{
				move((TABLE_VSPACE*i),(TABLE_HSPACE*j)); addch(ACS_ULCORNER);
			}
			else if(i == CUADRADO && j == 0)
			{
				move((TABLE_VSPACE*i),(TABLE_HSPACE*j)); addch(ACS_LLCORNER);
			}
			else if(j == 0)
			{
				move((TABLE_VSPACE*i),(TABLE_HSPACE*j)); addch(ACS_LTEE);
			}
			else if(i == 0)
			{
				move((TABLE_VSPACE*i),(TABLE_HSPACE*j)); addch(ACS_TTEE);
			}
			else if(i == CUADRADO)
			{
				move((TABLE_VSPACE*i),(TABLE_HSPACE*j)); addch(ACS_BTEE);
			}
			else
			{
				move((TABLE_VSPACE*i),(TABLE_HSPACE*j)); addch(ACS_PLUS);
			}

			// ponemos las lineas horizontales de la tabla
			for(int n = 1 ; n < (TABLE_HSPACE+1) ; n++)
			{
				move((TABLE_VSPACE*i),    (TABLE_HSPACE*j)+n); addch(ACS_HLINE) ;
			}

			if(i < CUADRADO)
			{
				attr_t colorPair = 0 ;

				// ponemos las lineas verticales y los espacios en blanco
				for(int n = 1 ; n < (TABLE_VSPACE+1) ; n++)
				{
					move((TABLE_VSPACE*i)+n,    (TABLE_HSPACE*j)); addch(ACS_VLINE) ;
					for(int m = 1 ; m < TABLE_HSPACE ; m++)
					{
						mvprintw((TABLE_VSPACE*i)+n,    (TABLE_HSPACE*j)+m," ") ;
					}

					char val = ' ' ;

					if(oculto)
					{
						if(tablero[i][j]->estado_ != OCULTO)
						{
							if(tablero[i][j]->marcada_)
							{
								colorPair = COLOR_PAIR(COLOR_CELDA_OCULTA_MARCADA) | A_BOLD | A_BLINK; // cout << " O " ;
								val = 'O' ;
							}
							else if(tablero[i][j]->mina_)
							{
								colorPair = COLOR_PAIR(COLOR_CELDA_MINA_VISIBLE) ; // cout << " * " ;
								val = '*' ;
							}
							else if(tablero[i][j]->minasVecinas_ > 0)
							{
								colorPair = COLOR_PAIR(COLOR_CELDA_NUM_VISIBLE) ; // cout << " " << (int) tablero[i][j]->minasVecinas_ << " " ;
								val = '0' + tablero[i][j]->minasVecinas_ ;
							}
							else
							{
								colorPair = COLOR_PAIR(COLOR_CELDA_VACIA_VISIBLE) ; // cout << "   " ;
								val = ' ' ;
							}
						}
						else
						{
							if(tablero[i][j]->marcada_)
							{
								colorPair = COLOR_PAIR(COLOR_CELDA_OCULTA_MARCADA) | A_BOLD | A_BLINK; // cout << " O " ;
								val = 'O' ;
							}
							else
							{
								colorPair = COLOR_PAIR(COLOR_CELDA_OCULTA) ; // cout << "###" ;
								val = '#' ;
							}
						}
					}
					else
					{
						if(tablero[i][j]->marcada_ && tablero[i][j]->mina_)
						{
							colorPair = COLOR_PAIR(COLOR_CELDA_OCULTA_MARCADA) | A_BOLD ; // cout << " O " ;
							val = 'O' ;
						}
						if(tablero[i][j]->marcada_ && !tablero[i][j]->mina_)
						{
							colorPair = COLOR_PAIR(COLOR_CELDA_OCULTA_MARCADA_FALLO) | A_BOLD | A_BLINK; // cout << " O " ;
							val = 'O' ;
						}
						else if(tablero[i][j]->mina_)
						{
							colorPair = COLOR_PAIR(COLOR_CELDA_MINA_VISIBLE) ; // cout << " * " ;
							val = '*' ;
						}
						else if(tablero[i][j]->minasVecinas_ > 0)
						{
							colorPair = COLOR_PAIR(COLOR_CELDA_NUM_VISIBLE) ; // cout << " " << (int) tablero[i][j]->minasVecinas_ << " " ;
							val = '0' + tablero[i][j]->minasVecinas_ ;
						}
						else
						{
							colorPair = COLOR_PAIR(COLOR_CELDA_VACIA_VISIBLE) ; // cout << "   " ;
							val = ' ' ;
						}
					}


					attron(colorPair) ;
					mvprintw((TABLE_VSPACE*i)+1,  (TABLE_HSPACE*j)+2,"%c",val) ;
					attroff(colorPair) ;
				}
			}
		}

		if(i == 0)
		{
			move((TABLE_VSPACE*i),    (TABLE_HSPACE*CUADRADO)); addch(ACS_URCORNER) ;
			for(int n = 1 ; n < TABLE_VSPACE ; n++)
			{
				move((TABLE_VSPACE*i)+n,  (TABLE_HSPACE*CUADRADO)); addch(ACS_VLINE);
			}
		}
		else if(i == CUADRADO)
		{
			move((TABLE_VSPACE*i),    (TABLE_HSPACE*CUADRADO)); addch(ACS_LRCORNER) ;
		}
		else
		{
			move((TABLE_VSPACE*i),    (TABLE_HSPACE*CUADRADO)); addch(ACS_RTEE) ;
			for(int n = 1 ; n < TABLE_VSPACE ; n++)
			{
				move((TABLE_VSPACE*i)+n,  (TABLE_HSPACE*CUADRADO)); addch(ACS_VLINE);
			}

		}
	}

}


void printTablero2(bool oculto)
{
	cout << "   |" ;
	for(unsigned char i = 0 ; i < CUADRADO ; i++)
	{
		cout << setw(3) << (int) i << "|" ;
	}
	cout << endl ;

	for(unsigned char i = 0 ; i < CUADRADO + 1 ; i++)
	{
		cout << "---|" ;
	}
	cout << endl ;

	for(unsigned char i = 0 ; i < CUADRADO ; i++)
	{
		for(unsigned char j = 0 ; j < CUADRADO ; j++)
		{
			if(j == 0)
			{
				cout << setw(3) << (int) i << "|" ;
			}
			if(oculto)
			{
				if(tablero[i][j]->estado_ != OCULTO)
				{
					if(tablero[i][j]->marcada_) cout << " O " ;
					else if(tablero[i][j]->mina_) cout << " * " ;
					else if(tablero[i][j]->minasVecinas_ > 0) cout << " " << (int) tablero[i][j]->minasVecinas_ << " " ;
					else cout << "   " ;
				}
				else
				{
					if(tablero[i][j]->marcada_) cout << " O " ;
					else cout << "###" ;
				}
			}
			else
			{
				if(tablero[i][j]->marcada_) cout << " O " ;
				else if(tablero[i][j]->mina_) cout << " * " ;
				else if(tablero[i][j]->minasVecinas_ > 0) cout << " " << (int) tablero[i][j]->minasVecinas_ << " " ;
				else cout << "   " ;
			}

			cout << "|" ;
		}
		cout << endl ;
		for(unsigned char i = 0 ; i < CUADRADO + 1 ; i++)
		{
			cout << "---|" ;
		}
		cout << endl ;
	}
}

void destruyeTablero()
{
	for(unsigned char i = 0 ; i < CUADRADO ; i++)
	{
		for(unsigned char j = 0 ; j < CUADRADO ; j++)
		{
			if(tablero[i][j] != nullptr)
			{
				delete tablero[i][j] ;
				tablero[i][j] = nullptr ;
			}
		}
	}
}

void borraTablero()
{
	for(unsigned char i = 0 ; i < CUADRADO ; i++)
	{
		for(unsigned char j = 0 ; j < CUADRADO ; j++)
		{
			if(tablero[i][j] != nullptr)
			{
				tablero[i][j]->estado_ = OCULTO ;
				tablero[i][j]->mina_ = false ;
				tablero[i][j]->minasVecinas_ = 0 ;
			}
		}
	}
}


bool visualiza(unsigned char x, unsigned char y)
{
	bool res = false ;

	// printTablero(true) ;

	if(x >= 0 && y < CUADRADO && y >= 0 && y < CUADRADO)
	{
		if(tablero[x][y]->estado_ == OCULTO)
		{
			tablero[x][y]->estado_ = VISIBLE ;

			if(tablero[x][y]->mina_) res = true ;
			else
			{
				if(tablero[x][y]->minasVecinas_ > 0)
				{
					res = false ;
				}
				else
				{
					if(x > 0 && y > 0)							visualiza(x-1,y-1) ;
					if(x > 0) 									visualiza(x-1, y) ;
					if(x > 0 && y < (CUADRADO-1))				visualiza(x-1,y+1) ;

					if(x < (CUADRADO-1) && y > 0)				visualiza(x+1,y-1) ;
					if(x < (CUADRADO-1)) 						visualiza(x+1, y) ;
					if(x < (CUADRADO-1) && y < (CUADRADO-1))	visualiza(x+1,y+1) ;


					if(y > 0) 									visualiza(x, y-1) ;
					if(y < (CUADRADO-1)) 						visualiza(x, y+1) ;

				}
			}
		}
	}


	return res ;
}


void chequeaTablero(unsigned char& ocultos, unsigned char& marcados)
{
	ocultos = 0 ;
	marcados = 0 ;
	for(unsigned char i = 0 ; i < CUADRADO ; i++)
	{
		for(unsigned char j = 0 ; j < CUADRADO ; j++)
		{
			if(tablero[i][j]->estado_ == OCULTO) ocultos++ ;
			if(tablero[i][j]->marcada_) marcados++ ;
		}
	}
}
