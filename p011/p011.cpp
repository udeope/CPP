//============================================================================
// Name        : p011.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Programa 4-En-Raya para mostrar el uso de arrays de dos dimensiones
//============================================================================

#include <iostream>
using namespace std;

// definicion de Macros
#define FILAS 6					// Filas de la matriz
#define COLUMNAS 10				// Columnas de la matriz
#define NUM_GANADOR 4			// Número de fichas para ganar
#define FICHA_A '*'				// Ficha del jugador A
#define FICHA_B 'o'				// Ficha del jugador B


// Declaración de funciones
void clear() ;
void printTablero1(char tablero[][COLUMNAS]) ;
void printTablero2(char tablero[][COLUMNAS]) ;
void initTablero(char tablero[][COLUMNAS]) ;
bool insertaFicha(char tablero[][COLUMNAS], int col, char ficha, int& fila) ;
bool hayGanador(char tablero[][COLUMNAS], char jugador, int col, int fila) ;

// Función principal
int main()
{
	// declaración del array de 2 dimensiones que funcionará como tablero.
	char tablero[FILAS][COLUMNAS] ;

	// inicialización del tablero
	initTablero(tablero) ;

	// impresión por pantalla del tablero
	printTablero2(tablero) ;

	// bucle infinito para generar los turnos de cada jugador
	while(true)
	{
		int col = 0 ;
		int fila = 0 ;
		bool bOk = false ;

		do
		{
			cout << "Jugador A - columna? " ;
			cin >> col ;

			bOk = insertaFicha(tablero, col, FICHA_A, fila) ;
			printTablero2(tablero) ;

			if(!bOk) cout << "ERROR: Vuelve a tirar" << endl ;

		} while(!bOk) ;

		if(hayGanador(tablero,FICHA_A, col, fila))
		{
			cout << "Ganador jugador A!!!!!" << endl ;
			break ;
		}

		// termioNa el turno de a

		col = 0 ;
		fila = 0 ;
		bOk = false ;
		do
		{
			cout << "Jugador B - columna? " ;
			cin >> col ;

			bOk = insertaFicha(tablero, col, FICHA_B, fila) ;

			printTablero2(tablero) ;

			if(!bOk) cout << "ERROR: Vuelve a tirar" << endl ;

		} while(!bOk) ;

		if(hayGanador(tablero,FICHA_B, col, fila))
		{
			cout << "Ganador jugador B!!!!!" << endl ;
			break ;
		}
	}



	return 0;
}


// ---------------------------------------------------------------
// initTablero
// Función que recibe el tablero por referencia y lo inicializa a
//  espacios en blanco
// ---------------------------------------------------------------
void initTablero(char tablero[][COLUMNAS])
{
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			tablero[i][j] = ' ' ;
		}
	}
}

// ---------------------------------------------------------------
// printTablero2
// Función que imprime el tablero en formato sencillo
// ---------------------------------------------------------------
void printTablero2(char tablero[][COLUMNAS])
{
	clear() ;
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			cout << "|" << tablero[i][j] ;
		}
		cout << "|" << endl ;
	}
	cout << "---------------------" << endl ;
}


// ---------------------------------------------------------------
// printTablero1
// Función que imprime el tablero en formato más elaborado
// ---------------------------------------------------------------
void printTablero1(char tablero[][COLUMNAS])
{
	clear() ;
	for(int j = 0 ; j < COLUMNAS ; j++)
	{
		cout << "  " << j << " " ;
	}
	cout << endl ;

	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			cout << "|" << tablero[i][j] << tablero[i][j] << tablero[i][j] ;
		}
		cout << "|" << endl ;
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			cout << "|" << tablero[i][j] << tablero[i][j] << tablero[i][j] ;
		}
		cout << "|" << endl ;
		cout << "-----------------------------------------" << endl ;

	}
}

// ---------------------------------------------------------------
// insertaFicha
// Función que inserta ficha en la matriz del tablero
//	- tablero: array de dos dimensiones
//	- col: columna en que se ha insertado la ficha
//  - fila: fila en la que se insertará la ficha (referencia modificable)
// ---------------------------------------------------------------
bool insertaFicha(char tablero[][COLUMNAS], int col, char ficha, int &fila)
{
	bool bOk = false ;

	if(col < COLUMNAS)
	{
		for(int i = 0 ; i < FILAS ; i++)
		{
			// si no encontramos un espacio, significa que hay ficha
			if(tablero[i][col] != ' ')
			{
				// si i > 0 significa que la columna no está llena
				if(i > 0)
				{
					// guardamos la fila en la que se va a insertar la ficha
					fila = i - 1 ;
					// se inserta la ficha en el tablero
					tablero[fila][col] = ficha ;
					bOk = true ;
				}
				else
				{
					// i == 0 significa que la columna está llena
					bOk = false ;
				}

				// salimos del for
				break ;
			}

			// en caso de llegar al final de la columna (última fila)
			// significa que no hay ninguna ficha y la podemos insertar
			if(i == FILAS-1)
			{
				fila = i ;
				tablero[fila][col] = ficha ;
				bOk = true ;
				break ;
			}
		}
	}

	return bOk ;
}



// ---------------------------------------------------------------
// hayGanador
// Función que comprueba si hay ganador en el tablero actual
//	- tablero: array de dos dimensiones
//	- jugador: jugador '*' o 'o'
//	- col: columna en que se ha insertado la ficha
//  - fila: fila en la que se ha insertado la ficha
//
// Solo tendremos que comprobar la horizontal, vertical y diagonales
//	sobre la celda en la que se ha realizado la inserción
// 1. contamos en horizontal sobre la fila
// 2. contamos en vertical sobre la coluna
// 3. contamos en las dos diagonales sobre fila x columna
// ---------------------------------------------------------------
bool hayGanador(char tablero[][COLUMNAS], char jugador, int col, int fila)
{
	bool res = false ;

	int numA = 0 ;

	// contamos verticalmente toda la columna
	for(int i = 0 ; i < FILAS ; i++)
	{
		if(tablero[i][col] == jugador) numA++ ;
		else numA = 0 ;

		if(numA == NUM_GANADOR) return true ;
	}


	numA = 0 ;

	// HORIZONTAL
	for(int j = 0 ; j < COLUMNAS ; j++)
	{
		if(tablero[fila][j] == jugador) numA++ ;
		else numA = 0 ;

		if(numA == NUM_GANADOR) return true ;
	}


	// DIAGONAL CRECIENTE
	numA = 0 ;
	int fi = fila ;
	int co = col ;
	while(fi < FILAS && co < COLUMNAS && tablero[fi][co] == jugador)
	{
		fi++ ;
		co++ ;
		numA++ ;
	}

	fi = fila ;
	co = col ;
	while(fi >= 0 && co >= 0 && tablero[fi][co] == jugador)
	{
		fi-- ;
		co-- ;
		numA++ ;
	}
	// hemos contado dos veces la última ficha por tanto:
	numA-- ;

	if(numA == NUM_GANADOR) return true ;


	// DIAGONAL DECRECIENTE
	numA = 0 ;
	fi = fila ;
	co = col ;
	while(fi < FILAS && co >= 0 && tablero[fi][co] == jugador)
	{
		fi++ ;
		co-- ;
		numA++ ;
	}

	fi = fila ;
	co = col ;
	while(fi >= 0 && co < COLUMNAS && tablero[fi][co] == jugador)
	{
		fi-- ;
		co++ ;
		numA++ ;
	}
	// hemos contado dos veces la última ficha por tanto:
	numA-- ;

	// Final de las diagonales

	if(numA == NUM_GANADOR) return true ;

	return res ;
}

// ---------------------------------------------------------------
// clear
// Función que entra 100 saltos de línea para limpiar terminal
// ---------------------------------------------------------------
void clear()
{
	for(int i = 0 ; i < 100 ; i++) cout << endl ;
}

