/*
 * Circulo.cpp
 *
 *  Created on: May 26, 2020
 *      Author: user
 */

#include "Circulo.h"
#include <iostream>
using namespace std ;

Circulo::Circulo()
{
	setRadio(0) ;
}

Circulo::Circulo(unsigned int l)
: Figura(CIRCULO)
{
	setRadio(l) ;
}

Circulo::~Circulo()
{
	cout << "Destruyendo círculo..." << endl ;
}

void Circulo::setRadio(unsigned int r)
{
	radio_ = r ;
}

unsigned int Circulo::getRadio() const
{
	return radio_ ;
}

void Circulo::dump() const
{
	Figura::dump() ;
	cout << " - Radio: " << getRadio() << endl ;
}


float Circulo::area() const
{
	return 3.14 * getRadio() * getRadio() ;
}



