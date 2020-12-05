//============================================================================
// Name        : p034.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Coche.h"
#include "Parking.h"

void printMenu() ;
void entraCoche(Parking*) ;
void sacaCoche(Parking*) ;
void imprime(Parking*) ;


int main()
{
	Parking P1 ;

	bool fin = false ;
	int opcion = 0 ;

	while(!fin)
	{
		printMenu() ;

		cin >> opcion ;

		switch(opcion)
		{
			case 1 : entraCoche(&P1) ; break ;
			case 2 : sacaCoche(&P1) ; break ;
			case 3 : imprime(&P1) ; break ;
			case 4 : fin = true ; break ;
			default : cout << "Opción incorrecta! Vuelve a intentarlo." << endl << endl ;
		}
	}

	cout << " ************* Bye bye! ************* " << endl ;

	return 0;
}


void printMenu()
{
	cout << endl << " =========================== " << endl ;
	cout << "   [1] Entra coche" << endl ;
	cout << "   [2] Saca coche" << endl ;
	cout << "   [3] Imprime" << endl ;
	cout << "   [4] Salir" << endl ;
}

void entraCoche(Parking* P1)
{
	int opcion = 0 ;
	MarcaCoche marca = MC_NO ;
	ColorCoche color = CC_NO ;
	unsigned int anyo = 2001 ;
	unsigned int fila = 0 ;
	unsigned int columna = 0 ;

	cout << "Selecciona una marca de coche:" << endl ;
	for(int i = 1 ; i < NUM_MARCAS ; i++)
	{
		cout << "  [" << i << "] " << marcas[i] << endl ;
	}
	cin >> opcion ;

	marca = (MarcaCoche)opcion ;



	cout << "Selecciona un color de coche:" << endl ;
	for(int i = 1 ; i < NUM_COLORES ; i++)
	{
		cout << "  [" << i << "] " << colores[i] << endl ;
	}
	cin >> opcion ;
	color = (ColorCoche)opcion ;

	cout << "Selecciona un año del 2001 al 2020" << endl ;
	cin >> anyo ;

	cout << "En qué fila quieres aparcar?" << endl ;
	cin >> fila ;

	cout << "En qué columna quieres aparcar?" << endl ;
	cin >> columna ;

	// Hace falta comprobar fila y columna (rangos)

	Coche* c = new Coche(marca, color, anyo) ;

	if(P1->entraCoche(c, fila, columna))
	{
		cout << "Coche aparcado correctamente!" << endl ;
	}
	else
	{
		delete c ;
		c = nullptr ;
		cout << "Lo siento, plaza ocupada!" << endl ;
	}
}


void sacaCoche(Parking* P1)
{
	unsigned int fila = 0 ;
	unsigned int columna = 0 ;

	cout << "En qué fila está el coche?" << endl ;
	cin >> fila ;

	cout << "En qué columna está el coche?" << endl ;
	cin >> columna ;

	if(!P1->sacaCoche(fila, columna))
	{
		cout << "Plaza de parking no ocupada!" << endl ;
	}

}

void imprime(Parking* P1)
{
	P1->dump() ;
}

