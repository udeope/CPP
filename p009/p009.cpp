//============================================================================
// Name        : p009.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto destinado a trabajar con arrays
//============================================================================

// definición de macros
#define NUM_ELEMENTOS 100
#define MAX_VALOR 100

// includes
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

// declaración de las funciones para manipular arrays
// ATENCIÓN: un array en C/C++ se passa como parámetrer SIEMPRE por referencia y debemos indicar el tamaño
//	del array para poder determinar sus dimensiones
void init(int l[], int size) ;
void print(int l[], int size) ;
int max(int l[], int size) ;
int min(int l[], int size) ;


int main()
{
	// inicializamos la semilla de valores aleatorios con el "tiempo".
	srand(time(NULL)) ;

	// declaración del array de dos dimensiones
	int lista[NUM_ELEMENTOS] ;

	// llamada a la función que inicializa el array
	init(lista, NUM_ELEMENTOS) ;

	// llamada a la función que imprime el array por pantalla
	print(lista, NUM_ELEMENTOS) ;

	// llamada a la función que busca la posición del valor más alto del array
	int maxId = max(lista, NUM_ELEMENTOS) ;

	// llamada a la función que busca la posición del valor más bajo del array
	int minId = min(lista, NUM_ELEMENTOS) ;

	// imprimimos los resultados por pantalla
	cout << "El valor máximo está en la posición [" << maxId << "] y tiene un valor de [" << lista[maxId] << "]" << endl ;
	cout << "El valor mínimo está en la posición [" << minId << "] y tiene un valor de [" << lista[minId] << "]" << endl ;

	return 0;
}





// ----------------------------------------------------------------------------------------
// max
// Descripción: dado un array busca el valor más grande i devuelve su posición dentro del array
// - l: array de enteros pasado por referencia
// - size: tamaño del array
// Retorno: devuelve la posición dentro del array del valor más grande encontrado.
int max(int l[], int size)
{
	int maxIdx = 0 ;
	int maxVal = 0 ;
	for(int i = 0 ; i < size ; i++)
	{
		if(maxVal < l[i])
		{
			maxIdx = i ;
			maxVal = l[i] ;
		}
	}

	return maxIdx ;
}

// ----------------------------------------------------------------------------------------
// min
// Descripción: dado un array busca el valor más pequeño i devuelve su posición dentro del array
// - l: array de enteros pasado por referencia
// - size: tamaño del array
// Retorno: devuelve la posición dentro del array del valor más pequeño encontrado.
int min(int l[], int size)
{
	int minIdx = 0 ;
	int minVal = MAX_VALOR + 1 ;
	for(int i = 0 ; i < size ; i++)
	{
		if(minVal > l[i])
		{
			minIdx = i ;
			minVal = l[i] ;
		}
	}

	return minIdx ;
}



// ----------------------------------------------------------------------------------------
// print
// Descripción: dado un array imprime por pantalla la posición y el valor de todos los elementos del array
// - l: array de enteros pasado por referencia
// - size: tamaño del array
// Retorno: no retorna nada
void print(int l[], int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		cout << i << " - " << l[i] << endl ;
	}
}


// ----------------------------------------------------------------------------------------
// init
// Descripción: dado un array inicializa sus valores con números aleatorios entre 0 i MAX_VALOR
// - l: array de enteros pasado por referencia
// - size: tamaño del array
// Retorno: no retorna nada
void init(int l[], int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		l[i] = rand() % (MAX_VALOR + 1) ;
	}
}



