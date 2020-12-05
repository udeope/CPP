//============================================================================
// Name        : p010.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto destinado a trabajar con arrays de dos dimensiones
//============================================================================

// definición de macros
#define NUM_FILAS 4				// número de filas
#define NUM_COLUMNAS 7			// número de columnas
#define MAX_VAL 9				// valor máximo para la generación aleatoria de valores

// includes
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

// declaración de las funciones para calcular las sumas de filas y columnas
// ATENCIÓN: fijaros como se pasan los arrays de más de una dimensión como parámetros y que SIEMPRE los arrays se pasan por referencia
int sumaFilas(int fila, int mat[][NUM_COLUMNAS], int size) ;
int sumaColumnas(int columna, int mat[][NUM_COLUMNAS], int size) ;


int main()
{
	// inicializamos la semilla de valores aleatorios con el "tiempo".
	srand(time(NULL)) ;

	// declaración del array de dos dimensiones
	int matriz[NUM_FILAS][NUM_COLUMNAS] ;

	// inicalización del array de dos dimensiones con valores aleatorios:
	// en este caso recorremos filas y columnas con dos sentencias FOR
	for(int i = 0 ; i < NUM_FILAS ; i++)
	{
		for(int j = 0 ; j < NUM_COLUMNAS ; j++)
		{
			matriz[i][j] = rand() % (MAX_VAL + 1) ;
		}
	}

	// recorremos el array y lo imprimimos por pantalla
	for(int i = 0 ; i < NUM_FILAS ; i++)
	{
		for(int j = 0 ; j < NUM_COLUMNAS ; j++)
		{
			cout << matriz[i][j] << " " ;
		}

		cout << endl ;
	}

	cout << "______________________________" << endl << endl ;


	int fila = 12 ;
	int columna = 4 ;

	// llamada a la función que suma una fila de un array bidimensional.
	// Guardamos el resultado de la suma en la variable sumaF
	// Si la fila excede las dimensiones del array devolverá el valor -1
	int sumaF = sumaFilas(fila, matriz, NUM_FILAS) ;

	// llamada a la función que suma una columna de un array bidimensional
	// Guardamos el resultado de la suma en la variable sumaC
	// Si la fila excede las dimensiones del array devolverá el valor -1
	int sumaC = sumaColumnas(columna, matriz, NUM_FILAS) ;

	// si el valor és válido (mayor o igual que cero)
	if(sumaF >= 0) 	cout << "la fila " << fila << " suma: " << sumaFilas(fila, matriz, NUM_FILAS) << endl;
	// de lo contrario ( -1) ...
	else cout << "la fila " << fila << " no existe!" << endl ;

	// si el valor és válido (mayor o igual que cero)
	if(sumaC >= 0) 	cout << "la columna " << columna << " suma: " << sumaColumnas(columna, matriz, NUM_FILAS) << endl;
	// de lo contrario ( -1) ...
	else cout << "la columna " << columna << " no existe!" << endl ;

	return 0;
}


// ----------------------------------------------------------------------------------------
// sumaFilas
// Descripción: dado un array bidimensional retorna la suma de todos los elementos de la fila seleccionada
// - fila: fila a sumar
// - mat: array bidimensional
// - size: tamaño de la primera dimensión
// Retorno: retorna la suma de los elementos de la fila o -1 si la fila está fuera de dimensiones.
int sumaFilas(int fila, int mat[][NUM_COLUMNAS], int size)
{
	int suma = 0 ;

	if(fila >= NUM_FILAS) suma = -1 ;
	else
	{
		for(int j = 0 ; j < NUM_COLUMNAS; j++)
		{
			suma = suma + mat[fila][j] ;
		}
	}

	return suma ;
}

// ----------------------------------------------------------------------------------------
// sumaColumnas
// Descripción: donat un array bidimensional retorna la suma de tots els elements de la fila seleccionada
// - fila: fila a sumar
// - mat: array bidimensional
// - size: tamaño de la primera dimensión
// Retorno: retorna la suma de los elementos de la fila o -1 si la fila está fuera de dimensiones.
int sumaColumnas(int columna, int mat[][NUM_COLUMNAS], int size)
{
	int suma = 0 ;

	if(columna >= NUM_COLUMNAS) suma = -1 ;
	else
	{
		for(int i = 0 ; i < NUM_FILAS; i++)
		{
			suma = suma + mat[i][columna] ;
		}
	}

	return suma ;
}
