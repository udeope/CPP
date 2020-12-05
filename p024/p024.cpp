//============================================================================
// Name        : p024.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define NUM_FIGURAS 5

#include <iostream>
using namespace std ;

#include "Cuadrado.h"
#include "Circulo.h"
#include "Triangulo.h"

Figura* figuras[NUM_FIGURAS] ;

#define MAX_LADO_CUADRADO 100
#define MAX_RADIO_CIRCULO 100
#define MAX_ALTURA_TRIANGULO 100
#define MAX_BASE_TRIANGULO 100

//void eliminarFigura() ;
//void crearFigura() ;


// en este main creamos de forma aleatoria NUM_FIGURAS figuras y usando el polimorfimos imprimimos su valor
// luego eliminamos todas las figuras
int main()
{
	srand(time(NULL)) ;

	// creamos de forma aleatoria NUM_FIGURAS
	for(int i = 0 ; i < NUM_FIGURAS ; i++)
	{
		// dependiendo del tipo aleatorio...
		switch((rand() % TIPOS_DE_FIGURA) + 1 )
		{
			case CUADRADO :	// si es un cuadrado
			{
				int lado = 1 + rand() % MAX_LADO_CUADRADO ;
				Cuadrado *c = (Cuadrado*) new Cuadrado(lado) ;
				figuras[i] = c ;
			} break ;

			case CIRCULO :	// si es un círculo
			{
				int radio = 1 + rand() % MAX_RADIO_CIRCULO ;
				Circulo *c = (Circulo*) new Circulo(radio) ;
				figuras[i] = c ;
			} break ;

			case TRIANGULO:	// si es un triángulo
			{
				int base = 1 + rand() % MAX_BASE_TRIANGULO ;
				int altura = 1 + rand() % MAX_ALTURA_TRIANGULO ;
				Triangulo *c = (Triangulo*) new Triangulo(base, altura) ;
				figuras[i] = c ;
			} break ;

			default: // en caso de cualquier otro tipo...
			{
				cout << "Error! Tipo de figura desconocida!" << endl ;
			}
		}
	}


	// usando el polimorfismo podemos imprimir todas las figuras sin tener que saber si son de un tipo u otro...
	for(int i = 0 ; i < NUM_FIGURAS ; i++)
	{
		figuras[i]->dump() ;
	}

	// igualmente llamamos a sus desctructures virtuales
	for(int i = 0 ; i < NUM_FIGURAS ; i++)
	{
		if(figuras[i] != nullptr)
		{
			delete figuras[i] ;
			figuras[i] = nullptr ;
		}
	}


	return 0 ;
}
