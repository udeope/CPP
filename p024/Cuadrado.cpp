/*
 * Cuadrado.cpp
 *
 *  Created on: May 26, 2020
 *      Author: user
 */

#include "Cuadrado.h"
#include <iostream>
using namespace std ;

Cuadrado::Cuadrado()
{
	setLado(0) ;
}

Cuadrado::Cuadrado(unsigned int l)
: Figura(CUADRADO)
{
	setLado(l) ;
}

Cuadrado::~Cuadrado()
{
	cout << "Destruyendo cuadrado..." << endl ;
}

void Cuadrado::setLado(unsigned int l)
{
	lado_ = l ;
}

unsigned int Cuadrado::getLado() const
{
	return lado_ ;
}

void Cuadrado::dump() const
{
	Figura::dump() ;
	cout << " - Lado: " << getLado() << endl ;
}


float Cuadrado::area() const
{
	return getLado() * getLado() ;
}
