/*
 * Rectangulo.cpp
 *
 *  Created on: Mar 10, 2020
 *      Author: user
 */

#include "Rectangulo.h"
#include <iostream>
using namespace std ;

Rectangulo::Rectangulo()
{
	cout << "Construtor Rectangulo (def)" << getNombre() << endl ;

	setBase(0) ;
	setAltura(0) ;
}

Rectangulo::Rectangulo(const string &nombre, unsigned int base, unsigned int altura)
: Poligono(nombre, 4)
{
	cout << "Construtor Rectangulo (param) " << getNombre() << endl ;
	setBase(base) ;
	setAltura(altura) ;
}

Rectangulo::~Rectangulo()
{
	cout << "Destructor Rectangulo " << getNombre() << endl ;
}

Rectangulo::Rectangulo(const Rectangulo &other)
{
	*this = other ;

	cout << "Construtor Rectangulo (copy)" << getNombre() << endl ;

}

Rectangulo& Rectangulo::operator=(const Rectangulo &other)
{
	Poligono::operator=(other) ;

	setBase(other.getBase()) ;
	setAltura(other.getAltura()) ;

	return *this ;
}

void Rectangulo::setBase(unsigned int base) { base_ = base ; }
void Rectangulo::setAltura(unsigned int altura) { altura_ = altura ; }

unsigned int Rectangulo::getBase() const { return base_ ; }
unsigned int Rectangulo::getAltura() const { return altura_ ; }

void Rectangulo::dump() const
{
	Poligono::dump() ;
	cout << "[RECT] Base: " << getBase() << endl ;
	cout << "[RECT] Altura: " << getAltura() << endl ;
}


