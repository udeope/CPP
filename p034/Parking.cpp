/*
 * Parking.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: user
 */

#include "Parking.h"

Parking::Parking()
{
	inicializa() ;
}

Parking::~Parking()
{
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			if(coches_[i][j] != nullptr)
			{
				delete coches_[i][j] ;
				coches_[i][j] = nullptr ;
			}
		}
	}
}


void Parking::inicializa()
{
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			coches_[i][j] = nullptr ;
		}
	}
}

void Parking::dump() const
{
	int coches = 0 ;
	for(int i = 0 ; i < FILAS ; i++)
	{
		for(int j = 0 ; j < COLUMNAS ; j++)
		{
			if(coches_[i][j] != nullptr)
			{
				coches_[i][j]->dump() ;
				cout << " [Fila " << i << "] [Columna " << j << "]" << endl ; // SEAT - BLANCO - 2003 [Fila 4] [Columna 12]
				coches++ ;
			}
		}
	}

	if(coches == 0)
	{
		cout << "El parking está vacío." << endl ;
	}
}

bool Parking::entraCoche(Coche* c, unsigned int fila, unsigned int columna)
{
	bool res = true ;

	if(coches_[fila][columna] == nullptr)
	{
		coches_[fila][columna] = c ;
	}
	else
	{
		res = false ;
	}

	return res ;
}

bool Parking::sacaCoche(unsigned int fila, unsigned int columna)
{
	bool res = true ;

	if(coches_[fila][columna] != nullptr)
	{
		cout << "Sacando coche: " ;
		coches_[fila][columna]->dump() ;
		cout << endl ;
		delete coches_[fila][columna] ;
		coches_[fila][columna] = nullptr ;
	}
	else
	{
		res = false ;
	}

	return res ;
}




