/*
 * Triangulo.cpp
 *
 *  Created on: May 26, 2020
 *      Author: user
 */

#include "Triangulo.h"
#include <iostream>
using namespace std ;

Triangulo::Triangulo()
{
	setBase(0) ;
	setAltura(0) ;
}

Triangulo::Triangulo(unsigned int b, unsigned int a)
: Figura(TRIANGULO)
{
	setBase(b) ;
	setAltura(a) ;
}

Triangulo::~Triangulo()
{
	cout << "Destruyendo triángulo ..." << endl ;
}

void Triangulo::setBase(unsigned int b)
{
	base_ = b ;
}
void Triangulo::setAltura(unsigned int a)
{
	altura_ = a ;
}

unsigned int Triangulo::getBase() const
{
	return base_ ;
}

unsigned int Triangulo::getAltura() const
{
	return altura_ ;
}

void Triangulo::dump() const
{
	Figura::dump() ;
	cout << " - Base: " << getBase() ;
	cout << " - Altura: " << getAltura() << endl ;
}


float Triangulo::area() const
{
	return getBase() * getAltura() / 2.0 ;
}


