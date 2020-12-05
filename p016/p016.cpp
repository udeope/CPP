//============================================================================
// Name        : p016.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Versión sencilla de MIRAGE para una sola ficha introducida
//				por teclado. La ficha se crea en el HEAP y se hace avanzar
//				por el tablero hasta que sale de este. En ese momento se
//				elimina la ficha del HEAP (y del tablero).
//				El programa se ejecuta de forma ininterrumida pero podría mejorarse
//				fácilmente añadiendo una varible que determine cuando hemos eliminado
//				la ficha del tablero y parar el bucle infinito en ese momento.
//============================================================================

#include <iostream>				// para el uso de io streams
#include <unistd.h>				// nos permite usar sleep()
using namespace std;

#define FILAS 4					// filas del tablero
#define COLUMNAS 20				// columnas del tablero
#define SLEEP 1					// tiempo que duerme el programa entre ciclo y ciclo


// definición de la estructura Ficha con sus 4 atributos
typedef struct Ficha
{
	unsigned short vida_ ;
	unsigned short ataque_ ;
	unsigned short defensa_ ;
	unsigned short velocidad_ ;
} Ficha ;

// declaración de las funciones utilitzadas en el proyecto
Ficha* creaFicha(const unsigned short& v, const unsigned short& a, const unsigned short& d, const unsigned short& ve) ;
void destruyeFicha(Ficha*) ;
void printFicha(Ficha*) ;
void initTablero() ;
void printTablero() ;
void clear() ;
void recalculaTablero() ;

// variables globales
// en este proyecto solo tenemos la variable global que representa nuestro tablero de juego.
// Las variables globales son accesibles desde cualquier función sin tener que pasar por parámetro esa variable.
// Debemos manatener como variables globales únicamente aquellas variables que realmente sean necesarias.
Ficha* tablero[FILAS][COLUMNAS] ;			// tablero: array 2D de punteros a ficha


int main()
{
	Ficha *F1 = nullptr ;					// varible que es un apuntador a ficha, guardará la dirección de la zona de memoria donde reside la Ficha dentro del HEAP
	unsigned int vida = 0 ;					// variable vida
	unsigned int ataque = 0 ;				// viariable ataque
	unsigned int defensa = 0 ;				// variable para almacenar la defensa
	unsigned int velocidad = 0 ;			// velocidad
	unsigned int fila = 0 ;					// variable que indica donde queremos colocar la ficha

	// inicializamos el tablero de juego
	initTablero() ;

	// pedimos los valores necesarios para crear una ficha
	cout << "Entra valores para ficha -" << endl ;
	cout << "Vida: " ;
	cin >> vida ;
	cout << "Ataque: " ;
	cin >> ataque ;
	cout << "Defensa: " ;
	cin >> defensa ;
	cout << "Velocidad: " ;
	cin >> velocidad ;
	cout << "Fila del tablero: [0 a 3]" ;
	cin >> fila ;

	// llamamos a la función que nos creará la ficha dados los atributos de la ficha que hemos pedido al usuario
	// el resultado de la creación de la ficha es un apuntador (F1) que guarda la dirección de memoria donde está esta ficha
	F1 = creaFicha(vida, ataque, defensa, velocidad) ;

	// insertamos la ficha en la posición ZERO dentro de la fila seleccionada por el usuario
	tablero[fila][0] = F1 ;

	// bucle infinito
	while(true)
	{
		// borramos pantalla
		clear() ;

		// imprimimos tablero
		printTablero() ;

		// recalculamos la posición de la ficha
		recalculaTablero() ;

		// dormimos el programa durante 1 segundo antes de continuar
		sleep(SLEEP) ;
	}

	return 0;
}

// ----------------------------------------------------------------------------------------
// creaFicha
// Función que crea una ficha nueva en el HEAP (memoria dinámica)
//	recibe los atributos que tiene la ficha y después de crearla los introduce en la ficha
// ----------------------------------------------------------------------------------------
Ficha* creaFicha(const unsigned short& v, const unsigned short& a, const unsigned short& d, const unsigned short& ve)
{
	cout << "*** Creando ficha ..." << endl ;

	// declaramos el puntor donde guardaremos la posición de memoria donde se creará la ficha
	Ficha* f = nullptr ;

	// creamos la ficha con la función new. Como resultado el sistema nos devuelve la posición de memoria
	f = (Ficha*) new Ficha ;

	// si el puntero es diferente de NULL (vacío)
	if(f != nullptr)
	{
		// guardamos todos los atributos pasados como parámetros en la estructura de ficha
		f->ataque_ = a ;
		f->vida_ = v ;
		f->defensa_ = d ;
		f->velocidad_ = ve ;
		cout << "*** Ficha creada OK!" << endl ;
	}
	// si el puntero es nulo, entonces ha habido un error
	else
	{
		cout << "*** Error creando ficha!" << endl ;
	}


	// como resultado de esta función devolvemos un puntero que apunta a la ficha en el HEAP (o nulo si algo ha ido mal)
	return f ;
}

// ----------------------------------------------------------------------------------------
// destruyeFicha
// Función que destruye una ficha liberando la memoria dinámica reservada (HEAP)
// ----------------------------------------------------------------------------------------
void destruyeFicha(Ficha* f)
{
	cout << "*** Eliminando ficha ..." << endl ;

	// si el puntero pasado para liberar la memoria es distinto de NULO
	if(f != nullptr)
	{
		// liberamos la memoria del HEAP
		delete f ;
		f = nullptr ;
		cout << "*** Ficha eliminada OK!" << endl ;
	}
	else
	{
		cout << "*** Error eliminando ficha!" << endl ;
	}
}


// ----------------------------------------------------------------------------------------
// printFicha
// Función que imprime una ficha por pantalla
// ----------------------------------------------------------------------------------------
void printFicha(Ficha* f)
{
	cout << "*** Imprimiendo ficha ..." << endl ;
	cout << "+++++++++++++++++++++++++++++++++++++++++++"  << endl ;
	if(f != nullptr)
	{
		cout << "   Vida: " << f->vida_ << endl ;
		cout << "   Ataque: " << f->ataque_ << endl ;
		cout << "   Defensa: " << f->defensa_ << endl ;
		cout << "   Velocidad: " << f->velocidad_ << endl ;
	}
	else
	{
		cout << "Ficha inválida!" << endl ;
	}
	cout << "+++++++++++++++++++++++++++++++++++++++++++"  << endl ;
}



// ----------------------------------------------------------------------------------------
// initTablero
// Función que inicializa el tablero poninendo el contenido de todas las celdas a NULL
// 	Es decir: todos los punteros que hay en las celdas quedan apuntando a "NADA"
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
// printTablero
// Función que imprime de forma sencilla un tablero por pantalla.
// Si la celda tiene un puntero nulo imprimieros la celda con un espacio en blanco
// Si la celda tuene un puntero distinto de nulo significa que hay una ficha y imprimieros un asterisco '*'
// ----------------------------------------------------------------------------------------
void printTablero()
{
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			if(tablero[i][j] != nullptr) cout << "|*" ;
			else cout << "| " ;
		}

		cout << "|" << endl ;
	}
}

// ----------------------------------------------------------------------------------------
// clear
// Función que para limpiar la pantalla imprime 100 saltos de línea
// ----------------------------------------------------------------------------------------
void clear()
{
	for(int i = 0 ; i < 100 ; i++) cout << endl ;
}


// ----------------------------------------------------------------------------------------
// recalculaTablero
// Función que recalcula la posición de las fichas del tablero.
// Para cada celda del tablero:
// 	1. Comprueba si hay una ficha
//  2. Si hay ficha obtiene su velocidad y recalcula su posición aumentando la según su velocidad
//	3. También aumentamos el índice 'j' para no volver a encontrarnos la misma ficha
//	4. Si la nueva posición de la ficha supera los límites del tablero la ficha se destruye
// NOTA:
// Este algoritmo sólo tiene sentido para avanzar fichas de un único jugador A en un tablero
// Donde no hay más que una ficha en una fila.
// No habrá cálculo de bloqueos, colisiones, etc

// ----------------------------------------------------------------------------------------
void recalculaTablero()
{
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			// si la celda [i][j] tiene una ficha
			if(tablero[i][j] != nullptr)
			{
				// la nueva posición de la ficha será la posición actual (j) + la velocidad de la ficha
				unsigned int siguiente = j + tablero[i][j]->velocidad_ ;

				// si la posición está dentro de los límites del tablero
				if(siguiente < COLUMNAS)
				{
					// copiamos el apuntador de la celda destino del apuntador de la celda origen
					tablero[i][siguiente] = tablero[i][j] ;
					// ponemos a nulo el apuntador de la celda origen
					tablero[i][j] = nullptr ;
					// aumentamos el índice (j) para no encontrarnos de nuevo la ficha que acabamos de mover
					j = siguiente + 1 ;
				}
				// si la posición nueva está fuera del tablero
				else
				{
					// hemos llegado a final de tablero y destruimos la ficha pasando el apuntador a la dirección
					// donde se encuentra la ficha en el HEAP para poderla liberar
					destruyeFicha(tablero[i][j]) ;
					// ponemos la celda de origen a NULO para indicar que ya no hay ficha
					tablero[i][j] = nullptr ;
				}
			}
		}
	}
}








