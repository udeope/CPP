//============================================================================
// Name        : p016.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//
//
//	Un primer intento de generación del juego MIRAGE usando estructuras en memoria dinámica
//	sobre interfaz: NCURSES
//
//	Para instalar NCURSES en Ubuntu hay que ejecutar los siguientes comandos en terminal
//	Para poder compilar y linkar también hay que añadir la libreria estática de NCURSES
//
//	sudo apt-get install libncurses5-dev
//	sudo apt-get install libncursesw5-dev
//============================================================================

#include <iostream>			// para el uso de io streams
#include <unistd.h>			// para el uso de la función sleep()
#include <ncurses.h>		// para el uso de las funciones de NCURSES
#include <stdlib.h>			// para el uso de numeros aleatorios
#include <time.h>
using namespace std;

#define FILAS 4				// número de filas del tablero
#define COLUMNAS 20			// número de columnas del tablero
#define SLEEP 1				// tiempo que duerme el programa entre ciclo y ciclo
#define VIDA_JUGADOR 100	// vida inicial de los jugadores
#define PRESUPUESTO	1000	// presupuesto por defecto de cada jugador al inicio

#define TABLE_HSPACE 6		// espaciado horizontal del tablero (en espacios)
#define TABLE_VSPACE 4		// espaciado vertical del tablero (en espacios)

#define FILA_MENU_CREACION 34	// fila de la pantalla donde mostraremos el menú de creación de la ficha
#define FILA_MENU_CTRL 27	// fila de la pantalla donde mostraremos el menú de control del juego

#define RANGO_POR_DEFECTO 2	// rango de ataque

// valores máximos y mínimos definidos para los atributos de la ficha
#define MIN_ATAQUE 1
#define MAX_ATAQUE 5
#define MIN_DEFENSA 1
#define MAX_DEFENSA 5
#define MIN_VELOCIDAD 1
#define MAX_VELOCIDAD 3
#define MIN_VIDA 1
#define MAX_VIDA 9
#define MIN_RANGO 1
#define MAX_RANGO 3

#define AUTO_PAUSE false				// para "debugar" el modo automático




// tipo enumerado para establecer los dos jugadores
typedef enum Jugador { JUGADOR_A = 0 , JUGADOR_B = 1} Jugador ;

// tipo estructura que define nuestra ficha
typedef struct Ficha
{
	unsigned short 	vida_ ;
	unsigned short 	ataque_ ;
	unsigned short 	defensa_ ;
	unsigned short 	velocidad_ ;
	unsigned short	rango_ ;
	Jugador 		jugador_ ;						// dueño de la ficha
	bool 			movida_ ;
} Ficha ;

// tipo estructura que guarda los marcadores del juego
typedef struct Marcador
{
	unsigned short vida_a_ ;				// vida actual del jugador A
	unsigned short vida_b_ ;				// del B
	unsigned short tics_ ;					// ciclos de juego
	unsigned short presup_a_ ;				// presupuesto A
	unsigned short presup_b_ ;				// del B
} Marcador ;


// declaración de las funciones
Ficha* creaFicha(const unsigned short& v, const unsigned short& a, const unsigned short& d, const unsigned short& ve, const Jugador& j) ;
void destruyeFicha(Ficha*) ;
void initTablero() ;
void initMarcador() ;
void initNcurses() ;
void endNcurses() ;
void destruyeTablero() ;
void recalculaTablero() ;
void printTable() ;
void printMenu() ;
void creaFichaNueva() ;
void creaFichaAleatoria(const Jugador&) ;
void printMarcador() ;
void avanzaTic() ;
void ataqueJugador(const Jugador &j, const unsigned short& ataque) ;
void resuelveColision(const unsigned short& fila) ;
void recalculaFila(const unsigned short& fila) ;
void ataque(const unsigned short& fila) ;
void setFicha(const unsigned short& fila, const unsigned short& columna, Ficha* f) ;

// variables globales
Ficha* tablero[FILAS][COLUMNAS] ;			// tablero: array 2D de punteros a ficha
Marcador marcador ;							// marcador del juego

int main()
{
	int avances = 1 ;						// variable que indica los avances que vamos a hacer sin parar. Por defecto 1.
	int avanceActual = 1 ;					// variable que guarda los avances que llevamos realizados. Inicialmente estamos en el primero.
	bool salir = false ;					// variable que indica cuado salir del juego.
	bool automatico = false ;				// variable que indica que el juego entra en modo automático
	int autoCiclos = 5 ;
	int autoCiclosContador = 0 ;

	srand(time(NULL)) ;

	initMarcador() ;						// inicializamos los datos del marcador
	initTablero() ;							// inicializamos el contenido de las celdas de la matriz (del tablero)
	initNcurses() ;							// iniciamos el modo NCURSES

// 	Ficha* f1 = creaFicha(2,5,5,1, JUGADOR_A) ;
//	Ficha* f2 = creaFicha(8,3,3,2, JUGADOR_B) ;
//	Ficha* f3 = creaFicha(4,4,2,1, JUGADOR_B) ;
//	Ficha* f4 = creaFicha(6,1,3,2, JUGADOR_B) ;
//	Ficha* f5 = creaFicha(6,1,2,2, JUGADOR_B) ;
//	Ficha* f6 = creaFicha(7,3,1,2, JUGADOR_A) ;
//	Ficha* f7 = creaFicha(3,3,3,1, JUGADOR_A) ;
//
//	tablero[2][0] = f1 ;
//	tablero[1][1] = f2 ;
//	tablero[2][6] = f3 ;
//	tablero[2][7] = f4 ;
//	tablero[1][13] = f5 ;
//	tablero[0][16] = f6 ;
//	tablero[3][18] = f7 ;


	while(!salir)
	{
		avanzaTic() ;						// contamos un tic más (un ciclo de juego)

		printTable() ;						// imprimimos el tablero en pantalla
		printMarcador() ;					// imprimimos el marcador en pantalla
		printMenu() ;						// imprimimos el menu de juego en pantalla

		if(automatico)
		{
			if(AUTO_PAUSE)
			{
				getch() ;
			}
			// generamos fichas de forma aleatoria para jugador A y B
			if(autoCiclosContador == 0)
			{
				creaFichaAleatoria(JUGADOR_A) ;
				creaFichaAleatoria(JUGADOR_B) ;
				autoCiclosContador = autoCiclos ;
			}
			autoCiclosContador-- ;
		}

		refresh() ;

		sleep(SLEEP) ;						// dormimos la ejecución SLEEP segundos




		if(avanceActual == avances && !automatico)			// en caso que queramos avanzar varios ciclos sin parar no entraremos en el if
		{
			avances = 1 ;					// restablecemos el número de ciclos sin interrupción a 1.
			avanceActual = 1 ;				// restablecemos el ciclos actual a 1.


			int n = getch() ;				// esperamos entrada por teclado (NCURSES)

			switch(n)
			{
				case 'a' :
				case 'A' : automatico = true ; break ;
				case 'c' :
				case 'C' : creaFichaNueva() ; break ;			// 'C' -> vamos al menú de creacion de ficha nueva
				case 'q' :
				case 'Q' : salir = true ; break ;				// 'Q' -> salimos del juego
				default:										// en caso contrario vamos a detectar si se ha pulsado un número de 1 a 9
				{
					if(n > '0' && n <= '9')
					{
						avances = n - '0' ;						// guardamos en avances el número de ciclos que queremos realizar sin interrupciones
					}
				}
			}
		}
		else								// en caso que estemos en un ciclo que no requiere interrupción....
		{
			avanceActual++ ;				// ... únicamente incrementamos el ciclo actual
		}


		recalculaTablero() ;				// recalculamos el tablero de juego para un ciclo

		refresh() ;							// refrescamos pantalla (NCURSES)



	}

	destruyeTablero() ;						// una vez finalizado el juego destruimos el tablero junto con todas las fichas

	endNcurses() ;							// terminamos el modo NCURSES

	return 0;
}

// ----------------------------------------------------------------------------------------
// avanzaTic
// avanza un tic en el marcador
// ----------------------------------------------------------------------------------------
void avanzaTic()
{
	marcador.tics_++ ;
}

// ----------------------------------------------------------------------------------------
// initNcurses
// inicializa el modo ncurses
// ----------------------------------------------------------------------------------------
void initNcurses()
{
	initscr() ;					// inicialización de pantalla

	if (has_colors())			// si soporta colores
	{
		start_color();			// inicia los colores
	}
}

// ----------------------------------------------------------------------------------------
// endNcurses
// finaliza el modo ncurses
// ----------------------------------------------------------------------------------------
void endNcurses()
{
	endwin() ;			// finaliza el modo ncurses
}


// ----------------------------------------------------------------------------------------
// initMarcador
// inicializa el marcador del juego
// ----------------------------------------------------------------------------------------
void initMarcador()
{
	marcador.tics_ = 0 ;				// ciclos a cero
	marcador.vida_a_ = VIDA_JUGADOR ;	// vidas al máximo
	marcador.vida_b_ = VIDA_JUGADOR ;
	marcador.presup_a_ = PRESUPUESTO ;
	marcador.presup_b_= PRESUPUESTO ;
}

// ----------------------------------------------------------------------------------------
// creaFichaNueva
// Función que crea una ficha nueva en el HEAP (memoria dinámica) y la introduce en el tablero
//		en la posición deseada por el jugador
// ----------------------------------------------------------------------------------------
void creaFichaNueva()
{
	Ficha *F1 = nullptr ;				// puntero que nos servirá para guardar la dirección de memoria donde se crea la ficha
	unsigned int vida = 0 ;
	unsigned int ataque = 0 ;
	unsigned int defensa = 0 ;
	unsigned int velocidad = 0 ;
	unsigned int fila = 0 ;
	unsigned int jugador = 0 ;
	unsigned int coste = 0 ;
	Jugador j = JUGADOR_A ;
	bool bOk = false ;
	char confirmacion = 'n' ;

	while(!bOk)
	{

		int iniQ = FILA_MENU_CREACION ;		// Fila inicial donde mostraremos el menú de creación de la ficha

		// imprimimos y leemos dos datos para crear la ficha
		mvprintw(iniQ,1,"Vida: ") ; refresh() ;
		scanf("%d", &vida) ;
		mvprintw(iniQ+1,1,"Ataque: ") ;  refresh() ;
		scanf("%d", &ataque) ;
		mvprintw(iniQ+2,1,"Defensa: ") ;  refresh() ;
		scanf("%d", &defensa) ;
		mvprintw(iniQ+3,1,"Velocidad: ") ;  refresh() ;
		scanf("%d", &velocidad) ;
		mvprintw(iniQ+4,1,"Jugador: ") ;  refresh() ;
		scanf("%d", &jugador) ;
		mvprintw(iniQ+5,1,"Fila: ") ;  refresh() ;
		scanf("%d", &fila) ;
		coste = vida + ataque + defensa + velocidad ;
		mvprintw(iniQ+6,1,"Coste ficha: %d", coste) ;  refresh() ;
		mvprintw(iniQ+7,1,"Confirmas? [S/N]: ") ;  refresh() ;
		confirmacion = getch() ;

		if(confirmacion == 's' || confirmacion == 'S') bOk = true ;


		// borramos de pantalla el menú de creación de ficha (sobreimprimiendo carateres en blanco
		mvprintw(iniQ,1,  "                    ") ;
		mvprintw(iniQ+1,1,"                    ") ;
		mvprintw(iniQ+2,1,"                    ") ;
		mvprintw(iniQ+3,1,"                    ") ;
		mvprintw(iniQ+4,1,"                    ") ;
		mvprintw(iniQ+5,1,"                    ") ;
		mvprintw(iniQ+6,1,"                    ") ;
	}

	// seleccionamos el jugador elegido
	if(jugador == 0)
	{
		j = JUGADOR_A ;
		marcador.presup_a_ -= coste ;
	}
	else
	{
		j = JUGADOR_B ;
		marcador.presup_b_ -= coste ;
	}

	// llamamos a la función que crea físicamente la ficha
	F1 = creaFicha(vida, ataque, defensa, velocidad, j) ;

	// dependiendo si es un jugador o otro la ficha se insertará en un lado u otro del tablero
	if(F1->jugador_ == JUGADOR_A) tablero[fila][0] = F1 ;
	else tablero[fila][COLUMNAS-1] = F1 ;
}


// ----------------------------------------------------------------------------------------
// creaFichaAletoria
// Función que crea una ficha nueva con valores aleatorios para el jugador seleccionado
//	y después de crearla introduce la ficha en el tablero
// ----------------------------------------------------------------------------------------
void creaFichaAleatoria(const Jugador& jugador)
{
	unsigned short ataque = MIN_ATAQUE + (rand() % (MAX_ATAQUE-MIN_ATAQUE)) ;
	unsigned short defensa = MIN_DEFENSA + (rand() % (MAX_DEFENSA - MIN_DEFENSA)) ;
	unsigned short velocidad = MIN_VELOCIDAD + (rand() % (MAX_VELOCIDAD - MIN_VELOCIDAD));
	unsigned short vida = MIN_VIDA +(rand() % (MAX_VIDA - MIN_VIDA));
	unsigned short fila = rand() % FILAS ;

	//unsigned short rango = RANGO_POR_DEFECTO ;

	Ficha *ficha = creaFicha(vida, ataque, defensa, velocidad, jugador) ;

	// dependiendo si es un jugador o otro la ficha se insertará en un lado u otro del tablero
	if(jugador == JUGADOR_A) tablero[fila][0] = ficha ;
	else tablero[fila][COLUMNAS-1] = ficha ;
}



// ----------------------------------------------------------------------------------------
// creaFicha
// Función que crea una ficha nueva en el HEAP (memoria dinámica)
//	recibe los atributos que tiene la ficha y después de crearla los introduce en la ficha
// ----------------------------------------------------------------------------------------
Ficha* creaFicha(const unsigned short& v, const unsigned short& a, const unsigned short& d, const unsigned short& ve, const Jugador& j)
{
	// cout << "*** Creando ficha ..." << endl ;

	Ficha* f = nullptr ;

	// llamada a la función 'new' para crear en el HEAP un espacio de memoria reservado para la ficha
	f = (Ficha*) new Ficha ;

	// si se ha podido crear correctamente...
	if(f != nullptr)
	{
		// guardamos los datos passados en la función en los atributos que corresponden
		f->ataque_ = a ;
		f->vida_ = v ;
		f->defensa_ = d ;
		f->velocidad_ = ve ;
		f->jugador_ = j ;
		f->movida_ = false ;
		f->rango_ = RANGO_POR_DEFECTO ;
	}

	// devolvemos el puntero a la ficha recién creada (o nullptr si no se ha podido crear)
	return f ;
}

// ----------------------------------------------------------------------------------------
// destruyeFicha
// Función que destruye una ficha liberando la memoria dinámica reservada (HEAP)
// ----------------------------------------------------------------------------------------
void destruyeFicha(Ficha* f)
{
	if(f != nullptr)	// si el puntero es distinto de NULL
	{
		// liberamos el espacio de memoria apuntado por el puntero f
		delete f ;
	}
}



// ----------------------------------------------------------------------------------------
// initTablero
// Función inicializa el tablero con punteros a NULL (nullptr)
// ----------------------------------------------------------------------------------------
void initTablero()
{
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			tablero[i][j] = nullptr ;
		}
	}
}

// ----------------------------------------------------------------------------------------
// destruyeTablero
// Función que recorre TODO el tablero en busca de fichas. Si las encuentra, las destruye.
// ----------------------------------------------------------------------------------------
void destruyeTablero()
{
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			if(tablero[i][j] != nullptr)		// si el contenido es distinto de NULL
			{
				destruyeFicha(tablero[i][j]) ;	// destruye el contenido
				tablero[i][j] = nullptr ;		// pone la celda a NULL
			}
		}
	}
}

// ----------------------------------------------------------------------------------------
// recalculaTablero
// Función que recorre TODO el tablero en busca de fichas para recalcular su nueva posición
//	basándose en su atributo velocidad.
// Si la ficha sale del tablero realizará el ataque contra el jugador contrario y la ficha
//	será destruida.
// ----------------------------------------------------------------------------------------
void recalculaTablero()
{
	// 1. Ponemos TODAS las fichas del tablero a NO Movidas para no olvidarnos de ninguna
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			if(tablero[i][j] != nullptr) tablero[i][j]->movida_ = false ;
		}
	}


	for(int i = 0 ; i < FILAS ; i++)
	{
		// 2. Resolvemos colisiones
		//    Situaciones en que dos fichas adversarias no pueden moverse de forma normal ya que no disponen de espacio suficiente entre ambas
		//		En estos casos hay que determinar como se reparten el espacio interior (si lo hay). En caso de que haya espacio las fichas
		//		se mueven consecuentemente a un cálculo proporcional a su velocidad.
		resuelveColision(i) ;

		// 3. recalculamos la fila
		// 	Se realiza el cálculo de movimiento normal del resto de fichas que quedan en el tablero y que no estaban en situación de colisión.
		//	aquí incluimos tanto fichas totalemente libres como fichas bloqueantes (fichas del mismo jugador con velocidades distintas y que
		//	no permiten a una de ellas evolucionar a la velocidad marcada).
		recalculaFila(i) ;

		// 4. calculamos ataques
		// Una vez calculados todos los moviemientos se realizan los ataques. Aquellas fichas que tengan en su rango de acción una ficha
		//	adversaria podrán atacarla según las normas de ataque.
		ataque(i) ;


	}
}

// ----------------------------------------------------------------------------------------
// printTable
// Función que imprime con NCURSES el tablero y su contenido
// ----------------------------------------------------------------------------------------
void printTable()
{
	for(int i = 0 ; i < FILAS+1 ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			if(i == 0 && j == 0)
			{
				move((TABLE_VSPACE*i),(TABLE_HSPACE*j)); addch(ACS_ULCORNER);
			}
			else if(i == FILAS && j == 0)
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
			else if(i == FILAS)
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

			if(i < FILAS)
			{


				// ponemos las lineas verticales y los espacios en blanco
				for(int n = 1 ; n < (TABLE_VSPACE+1) ; n++)
				{
					move((TABLE_VSPACE*i)+n,    (TABLE_HSPACE*j)); addch(ACS_VLINE) ;
					for(int m = 1 ; m < TABLE_HSPACE ; m++)
					{
						mvprintw((TABLE_VSPACE*i)+n,    (TABLE_HSPACE*j)+m," ") ;
					}
				}


				if(tablero[i][j] != nullptr)
				{
					if(tablero[i][j]->jugador_ == JUGADOR_A)
					{
						init_pair(1,COLOR_YELLOW,COLOR_BLUE);
						attron(COLOR_PAIR(1));
					}
					else
					{
						init_pair(2,COLOR_BLUE,COLOR_YELLOW);
						attron(COLOR_PAIR(2));
					}

					// ponemos los espacios en blanco
					for(int n = 1 ; n < (TABLE_VSPACE+1) ; n++)
					{
						for(int m = 1 ; m < TABLE_HSPACE ; m++)
						{
							mvprintw((TABLE_VSPACE*i)+n,    (TABLE_HSPACE*j)+m," ") ;
						}
					}

					// ATAQUE
					mvprintw((TABLE_VSPACE*i)+1,  (TABLE_HSPACE*j)+1,"%d",tablero[i][j]->ataque_) ;

					// DEFENSA
					if(tablero[i][j]->defensa_ < 10)
						mvprintw((TABLE_VSPACE*i)+1,  (TABLE_HSPACE*j)+TABLE_HSPACE-1,"%d",tablero[i][j]->defensa_) ;
					else
						mvprintw((TABLE_VSPACE*i)+1,  (TABLE_HSPACE*j)+TABLE_HSPACE-2,"%d",tablero[i][j]->defensa_) ;

					// VIDA
					int v = TABLE_VSPACE / 2 ;
					int h = TABLE_HSPACE / 2 ;
					mvprintw((TABLE_VSPACE*i)+v,  (TABLE_HSPACE*j)+h,"%d", tablero[i][j]->vida_) ;

					// VELOCIDAD
					mvprintw((TABLE_VSPACE*i)+(TABLE_VSPACE-1),  (TABLE_HSPACE*j)+TABLE_HSPACE-1,"%d",tablero[i][j]->velocidad_) ;

					// MOVIDA
					// if(tablero[i][j]->velocidad_)
					//	mvprintw((TABLE_VSPACE*i)+1,  (TABLE_HSPACE*j)+TABLE_HSPACE-1,"M") ;


					if(tablero[i][j]->jugador_ == JUGADOR_A) attroff(COLOR_PAIR(1));
					else attroff(COLOR_PAIR(2)) ;
				}
			}
		}

		if(i == 0)
		{
			move((TABLE_VSPACE*i),    (TABLE_HSPACE*COLUMNAS)); addch(ACS_URCORNER) ;
			for(int n = 1 ; n < TABLE_VSPACE ; n++)
			{
				move((TABLE_VSPACE*i)+n,  (TABLE_HSPACE*COLUMNAS)); addch(ACS_VLINE);
			}
		}
		else if(i == FILAS)
		{
			move((TABLE_VSPACE*i),    (TABLE_HSPACE*COLUMNAS)); addch(ACS_LRCORNER) ;
		}
		else
		{
			move((TABLE_VSPACE*i),    (TABLE_HSPACE*COLUMNAS)); addch(ACS_RTEE) ;
			for(int n = 1 ; n < TABLE_VSPACE ; n++)
			{
				move((TABLE_VSPACE*i)+n,  (TABLE_HSPACE*COLUMNAS)); addch(ACS_VLINE);
			}

		}
	}

}

// ----------------------------------------------------------------------------------------
// printMenu
// Función que imprime con NCURSES el menú de control del juego
// ----------------------------------------------------------------------------------------
void printMenu()
{
	mvprintw(FILA_MENU_CTRL,10,"[1-9] - Continua de 1 a 9 veces ") ;
	mvprintw(FILA_MENU_CTRL+1,10,"[C] - Crea una ficha nueva ") ;
	mvprintw(FILA_MENU_CTRL+2,10,"[Q] - Finaliza") ;
	mvprintw(FILA_MENU_CTRL+3,10,"[A] - Entra en modo automático") ;
	mvprintw(FILA_MENU_CTRL+4,10," --- opción: ") ;
}

// ----------------------------------------------------------------------------------------
// printMarcador
// Función que imprime con NCURSES el marcador del juego
// ----------------------------------------------------------------------------------------
void printMarcador()
{
	int fila = FILAS * TABLE_VSPACE + 1 ;
	int col = COLUMNAS * TABLE_HSPACE + 1 ;


	init_pair(3,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(3));

	mvprintw(fila,col/2.0,"          ") ;
	mvprintw(fila,1,"              ") ;
	mvprintw(fila,col-10,"                 ") ;
	mvprintw(fila+1,1,"                  ") ;
	mvprintw(fila+1,col-10,"                     ") ;

	mvprintw(fila,col/2.0,"Tics: %d",marcador.tics_) ;
	mvprintw(fila,1,"Vida A: %d",marcador.vida_a_) ;
	mvprintw(fila,col-10,"Vida B: %d",marcador.vida_b_) ;
	mvprintw(fila+1,1,"Pres A: %d",marcador.presup_a_) ;
	mvprintw(fila+1,col-10,"Pres B: %d",marcador.presup_b_) ;

	attroff(COLOR_PAIR(3)) ;

}

// ----------------------------------------------------------------------------------------
// ataqueJugador
// Función que realiza un ataque contra un jugador. Dado el jugadore atacado y la cantidad
//	del ataque.
// ----------------------------------------------------------------------------------------
void ataqueJugador(const Jugador& j, const unsigned short& ataque)
{
	if(j == JUGADOR_A) marcador.vida_a_ -= ataque ;
	else marcador.vida_b_ -= ataque ;
}


// ----------------------------------------------------------------------------------------
// resuelveColision
// Función que realiza un ataque contra un jugador. Dado el jugadore atacado y la cantidad
//	del ataque.
// ----------------------------------------------------------------------------------------
void resuelveColision(const unsigned short& fila)
{
	short colA = -1 ;
	short colB = -1 ;

	// 1. buscamos la primera ficha A desde la derecha
	for(int j = COLUMNAS-1 ; j >= 0; j--)
	{
		if(tablero[fila][j] != nullptr)
		{
			if(tablero[fila][j]->jugador_ == JUGADOR_A)
			{
				colA = j ;
				break ;
			}
		}
	}

	// 2. buscamos la primera ficha B desde la izquierda
	for(int j = 0 ; j < COLUMNAS; j++)
	{
		if(tablero[fila][j] != nullptr)
		{
			if(tablero[fila][j]->jugador_ == JUGADOR_B)
			{
				colB = j ;
				break ;
			}
		}
	}

	// en caso de que no haya A o no haya B implica que no hay colisión
	// posible colisión
	if(colA >= 0 && colB >= 0)
	{
		int posA = colA + tablero[fila][colA]->velocidad_ ;
		int posB = colB - tablero[fila][colB]->velocidad_ ;

		if(posA >= posB)	// COLISIÓN!!!
		{
//			mvprintw(30,100,"COLISIÓ") ;
			// de momento dejaremos las fichas donde están y las marcaremos como movidas!
			tablero[fila][colA]->movida_ = true ;
			tablero[fila][colB]->movida_ = true ;


			// Vamos a comprobar que esta colisión se resuelve por ataques.
			// En caso que los ataques generen un bloqueo indefinido eliminaremos la vida de ambas fichas de 1 en 1
			if(tablero[fila][colA]->ataque_ <= tablero[fila][colB]->defensa_ &&	tablero[fila][colB]->ataque_ <= tablero[fila][colA]->defensa_)
			{
				mvprintw(35,100,"Reduccion de vida: %d,%d - %d,%d", fila, colA, fila, colB) ;
				tablero[fila][colA]->vida_ -- ;
				tablero[fila][colB]->vida_ -- ;
			}


			// espacio libre que hay entre las dos fichas en colisión
			int espacio = colB - colA - 1 ;
			mvprintw(31,100,"Espai.: %d", espacio) ;

			if(espacio > 0)
			{

				// espacio libre que necesitaríamos para que ambas fichas pudieran moverse sin colisionar
				int espacioEsperado = tablero[fila][colA]->velocidad_ + tablero[fila][colB]->velocidad_ ;
				mvprintw(32,100,"Espai esperat.: %d", espacioEsperado) ;

				int divA = (espacio*tablero[fila][colA]->velocidad_) / espacioEsperado ; // espacios reales que avanzará la ficha A
				int divB = (espacio*tablero[fila][colB]->velocidad_) / espacioEsperado ; // espacios reales que avanzará la ficha B
				int modA = (espacio*tablero[fila][colA]->velocidad_) % espacioEsperado ; // cuanto le falta a A por avanzar
				int modB = (espacio*tablero[fila][colB]->velocidad_) % espacioEsperado ; // cuanto le falta a B por avanzar
				mvprintw(33,100,"Espai asignado a A: %d", divA) ;
				mvprintw(34,100,"Espai asignado a B: %d", divB) ;
				mvprintw(35,100,"Espacio pendiente para A: %d", modA) ;
				mvprintw(36,100,"Espacio pendiente para B: %d", modB) ;



				if(modA > modB)
				{
					mvprintw(37,100,"Espai guanyat per: A") ;
					divA++ ;
				}
				else if(modB > modA)
				{
					mvprintw(37,100,"Espai guanyat per: B") ;
					divB++ ;
				}
				else if(modA != 0 && modB != 0)
				{
					// asignación aleatoria de la celda
					if(rand() % 2 == 0)
					{
						mvprintw(37,100,"Empat: Espai guanyat per: A") ;
						divA++;
					}
					else
					{
						mvprintw(37,100,"Empat: Espai guanyat per: B") ;
						divB++ ;
					}
				}

				// en divA y divB tenemos el número de celdas que avanzará cada jugador
				mvprintw(38,100,"Nueva posición para ficha A: %d",colA+divA ) ;
				mvprintw(39,100,"Nueva posición para ficha B: %d",colB-divB ) ;
				if(divA != 0)
				{
					tablero[fila][colA+divA] = tablero[fila][colA] ;
					tablero[fila][colA] = nullptr ;
				}
				if(divB != 0)
				{
					tablero[fila][colB-divB] = tablero[fila][colB] ;
					tablero[fila][colB] = nullptr ;
				}


			}
		}
	}


}




void recalculaFila(const unsigned short& fila)
{
	// 1. PARA JUGADORES A
	//	busco las fichas de derecha a izquierda y recalculo su posición
	//	si tienen conflicto con otra que bloquea la ponemos antes de esa

	for(int j = (COLUMNAS -1) ; j >= 0 ; j--)
	{
		if(tablero[fila][j] != nullptr)
		{
			// Si encontramos un ficha del jugador A y no ha sido movida aún
			if(tablero[fila][j]->jugador_ == JUGADOR_A && tablero[fila][j]->movida_ == false)
			{
				unsigned int siguiente = j + tablero[fila][j]->velocidad_ ;	// calculamos cual sería su siguiente posición (incremento hacia la derecha)


				unsigned int final = (siguiente >= COLUMNAS) ? (COLUMNAS-1) : siguiente ;

				// debemos comprobar si no hay ninguna ficha bloqueante
				for(unsigned short i = (j+1) ; i <= final ; i++)
				{
					if(tablero[fila][i] != nullptr) // atención BLOQUEO
					{
						siguiente = i - 1 ;
						break ;
					}
				}

				if(final == COLUMNAS-1 && siguiente >= COLUMNAS)
				{
					siguiente = COLUMNAS ;
				}


				// si ese incremento sigue estando dentro del tablero...
				if(siguiente < COLUMNAS)
				{
					if(siguiente != (unsigned int)j)
					{
						// realizo un cambio en la posición de la ficha
						tablero[fila][siguiente] = tablero[fila][j] ;				// la nueva posición pasa a apuntar a la ficha
						tablero[fila][siguiente]->movida_ = true ;					// la marcamos como movida para saber que ya se ha cambiado de lugar
						tablero[fila][j] = nullptr ;								// la posición antigua pasa a apuntar a nullptr
						j = siguiente + 1 ;											// el índice j salta a la siguiente posición para no volver a encontrarse con la misma ficha
					}
					else
					{
						tablero[fila][siguiente]->movida_ = true ;					// aunque la ficha no se ha podido mover pq está bloqueada, la consideramos como revisada!
					}
				}
				else	// si el incremento se sale del tablero (hemos llegado al final)
				{
					// realizamos un ataque al jugador B con el valor del atributo ataque de la ficha
					ataqueJugador(JUGADOR_B, tablero[fila][j]->ataque_) ;

					// destruimos la ficha
					destruyeFicha(tablero[fila][j]) ;

					// vaciamos la celda del tablero
					tablero[fila][j] = nullptr ;
				}
			}
		}
	}

	// 2. PARA JUGADORES B
	// idem pero de izquierda a derecha


	for(int j = 0 ; j < COLUMNAS ; j++)
	{
		if(tablero[fila][j] != nullptr)
		{
			if(tablero[fila][j]->jugador_ == JUGADOR_B && tablero[fila][j]->movida_ == false) // si la ficha es del jugador B y no ha sido movida aún
			{
				int siguiente = j - tablero[fila][j]->velocidad_ ;				// calculamos cual sería la siguiente posición (decremento hacia la izquierda)

				int final = (siguiente < 0) ? 0 : siguiente ;

				// debemos comprobar si no hay ninguna ficha bloqueante
				for(int i = (j-1) ; i >= final ; i--)
				{
					if(tablero[fila][i] != nullptr) // atención BLOQUEO
					{
						siguiente = i + 1 ;
						break ;
					}
				}

				if(final == 0 && siguiente < 0)
				{
					siguiente = -1 ;
				}

				// si ese incremento sigue estando en el tablero...
				if(siguiente >= 0)
				{
					if(siguiente != j)
					{
						// realizamos un cambio de posición de la ficha
						tablero[fila][siguiente] = tablero[fila][j] ;
						tablero[fila][siguiente]->movida_ = true ;					// la marcamos como movida para saber que ya se ha cambiado de lugar
						tablero[fila][j] = nullptr ;
					}
					else
					{
						tablero[fila][siguiente]->movida_ = true ;					// aunque la ficha no se ha podido mover pq está bloqueada la marcamos como movida!
					}
				}
				else	// si el decremento se sale del tablero por la izquierda (hemos llegado al final)
				{
					// realizamos un ataque al jugador B con el valor del atributo ataque de la ficha
					ataqueJugador(JUGADOR_A, tablero[fila][j]->ataque_) ;

					// destruimos la ficha
					destruyeFicha(tablero[fila][j]) ;

					// vaciamos la celda del tablero
					tablero[fila][j] = nullptr ;
				}
			}
		}
	}
}


void ataque(const unsigned short& fila)
{
	// 1. para todas las fichas comprobaremos si hay fichas atacables, y si las hay realizaremos el ataque
	for(int j = 0 ; j < COLUMNAS ; j++)
	{
		if(tablero[fila][j] != nullptr)
		{
			if(tablero[fila][j]->jugador_ == JUGADOR_A)
			{
				// atacaremos a celdas del jugador contrario que esten a la derecha
				int final = j + tablero[fila][j]->rango_ ;

				if(final >= COLUMNAS) final = (COLUMNAS -1) ;

				for(int k = j+1; k <= final ; k++)
				{
					if(tablero[fila][k] != nullptr)
					{
						if(tablero[fila][k]->jugador_ == JUGADOR_B)
						{
							int ataque = tablero[fila][j]->ataque_ - tablero[fila][k]->defensa_ ;
							if(ataque > 0)
							{
								int vida = 	tablero[fila][k]->vida_ ;
								vida -= ataque ;
								if(vida > 0) tablero[fila][k]->vida_ = vida ;
								else tablero[fila][k]->vida_ = 0 ;
							}
						}
					}
				}
			}
			else
			{
				// atacaremos a celdas del jugador contrario que esten a la izquierda
				int final = j-tablero[fila][j]->rango_ ;
				if(final < 0) final = 0 ;

				for(int k = j-1; k >= final ; k--)
				{
					if(tablero[fila][k] != nullptr)
					{
						if(tablero[fila][k]->jugador_ == JUGADOR_A)
						{
							int ataque = tablero[fila][j]->ataque_ - tablero[fila][k]->defensa_ ;
							if(ataque > 0)
							{
								int vida = 	tablero[fila][k]->vida_ ;
								vida -= ataque ;
								if(vida > 0) tablero[fila][k]->vida_ = vida ;
								else tablero[fila][k]->vida_ = 0 ;
							}
						}
					}
				}
			}
		}
	}

	// 2. comprobamos si hay fichas con vida = 0, en ese caso las eliminaremos del tablero
	for(int j = 0 ; j < COLUMNAS ; j++)
	{
		if(tablero[fila][j] != nullptr)
		{
			if(tablero[fila][j]->vida_ == 0)
			{
				destruyeFicha(tablero[fila][j]) ;
				tablero[fila][j] = nullptr ;
			}
		}
	}

}




