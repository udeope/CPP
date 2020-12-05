//============================================================================
// Name        : p019.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Rectangulo.h"
#include <iostream>
using namespace std;

// elementos de la lista
#define NUM_LISTA 10


int main()
{
	srand(time(NULL)) ;

	// PARTE 1 - creación de objectos Rectángulo

	Rectangulo r1 ;					// creación llamando al constructor por defecto
	Rectangulo r2("r2",3,6) ;		// creación llamando al constructor por parámetros
	Rectangulo r3 ;					// creación llamando al constructor por defecto

	r1.setBase(5) ;					// asignamos un valor a la base y a la altura
	r1.setAltura(8) ;

	r1.dump() ;						// imprimimos los tres rectángulos
	r2.dump() ;
	r3.dump() ;


	// PARTE 2 - array de punteros a classe

	// declaramos un array de 10 posiciones de apuntadores a classes Rectangulo
	Rectangulo* lista[NUM_LISTA] ;

	// 1. creación de los 10 elementos (aleatorios)
	for(int i = 0 ; i < NUM_LISTA ; i++)
	{
		string s = "R" + to_string(i) ;
		lista[i] = (Rectangulo*) new Rectangulo(s,true) ;			// cada rectángulo es creado en el HEAP
	}

	// 2. impresión por pantalla de los 10 elementos
	for(int i = 0 ; i < NUM_LISTA ; i++)
	{
		lista[i]->dump() ;
	}

	// 3. destrucción de los 10 elementos
	for(int i = 0 ; i < NUM_LISTA ; i++)
	{
		if(lista[i] != nullptr)							// comprobamos si el puntero es distinto de NULL
		{
			delete lista[i] ;							// si lo es liberamos la memoria
			lista[i] = nullptr ;						// ponemos el puntero a NULL
		}
	}

	// PARTE 3 - USO DE CONTRUCTOR DE COPIA

	Rectangulo r11("R11",true) ;								// llamamos al constructor por parámetros
	Rectangulo r12(r11) ;										// llamamos al constructor de copia
	Rectangulo* r13 = (Rectangulo *) new Rectangulo(r12) ;		// creamos un Rectangulo en el HEAP conel constructor de copia

	// imprimimos resultados...
	r11.dump() ;
	r12.dump() ;
	r13->dump() ;

	// finalmenete antes de terminar eliminamos el Rectangulo del HEAP
	if(r13 != nullptr)
	{
		delete r13 ;
		r13 = nullptr ;
	}

	// PARTE 4 - Operador de asignación

	Rectangulo r21("R21", true) ;
	Rectangulo r22 ;
	Rectangulo r23("R23", true) ;

	r21.dump() ;
	r22.dump() ;
	r23.dump() ;

	if(r22 > r21)
	{
		cout << "El área de " << r22.getNom() << " es MAYOR que la de " << r21.getNom() << endl ;
	}
	else
	{
		cout << "El área de " << r22.getNom() << " es MENOR que la de " << r21.getNom() << endl ;
	}

	cout << "La dirección de R22 es: " << &r22 << endl ;

	cout << "ASIGNACIÓN DE OBJETOS:" << endl ;

	r23 = r22 = r21 ;

	r21.dump() ;
	r22.dump() ;
	r23.dump() ;






	return 0;
}
