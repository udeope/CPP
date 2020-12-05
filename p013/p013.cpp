//============================================================================
// Name        : p013.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto para introducir el uso de las estructuras
//============================================================================


// includes
#include <iostream>				// para el uso de cin, cout
#include <string>				// para el uso del tipo string (cadena de caracteres)
#include <stdlib.h>				// para el uso de rand() y srand()
#include <time.h>				// para el uso del tiempo
using namespace std;

#define NUM_TRIANGULOS 10		// máximo número de triángulos
#define MAX_NUM 20				// valor maximo


// estructura Triangulo
typedef struct Triangulo
{
	char id ;					// 1 byte para identificar el triángulo
	float base ;				// 1 float para la base
	float altura ;				// 1 float para la altura
	float area ;				// 1 float para guardar el resultado del cálculo del área
} Triangulo ;


// declaración de funciones
float area(const Triangulo&) ;
void print(const Triangulo&) ;



int main()
{
	srand(time(NULL)) ;		// iniciamos varible aleatoria

	// Creamos un array de 10 triángulos
	Triangulo misTriangulos[NUM_TRIANGULOS] ;

	// para cada uno de los triángulos del array...
	for(int i = 0 ; i < NUM_TRIANGULOS ; i++)
	{
		// le damos un identificador al triángulo
		misTriangulos[i].id = i ;

		// generamos una base de forma aleatoria...
		misTriangulos[i].base = random() % (MAX_NUM + 1) ;

		// genereamos una altura de forma aleatoria...
		misTriangulos[i].altura = random() % (MAX_NUM + 1) ;

		// inicializamos el área a cero
		misTriangulos[i].area = 0.0 ;
	}


	// una vez creados y inicializados los triángulos vamos a calcular su área y imprimir el resultado
	for(int i = 0 ; i < NUM_TRIANGULOS ; i++)
	{
		cout << "Triangulo: " << i << endl ;

		// llamamos a la función print() que recibe un triángulo y lo imprime
		print(misTriangulos[i]) ;

		cout << "Area: " << area(misTriangulos[i]) << endl ;
		cout << "----------------------------" << endl ;
	}

	return 0;
}


// -----------------------------------------------------------------------
// area
// Función que recibe un triángulo, calcula su área y devuelve el valor
// - t : referencia constante a un triángulo (podemos usarlo pero no modificarlo)
// -----------------------------------------------------------------------
float area(const Triangulo& t)
{
	return t.base * t.altura / 2.0 ;
}

// -----------------------------------------------------------------------
// print
// Función que recibe un triángulo y imprime su base y altura
// - t : referencia constante a un triángulo (podemos usarlo pero no modificarlo)
// -----------------------------------------------------------------------
void print(const Triangulo& t)
{
	cout << "Base: " << t.base << endl ;
	cout << "Altura: " << t.altura << endl ;
}
