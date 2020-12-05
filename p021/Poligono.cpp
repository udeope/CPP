/*
 * Poligono.cpp
 *
 *  Created on: Mar 10, 2020
 *      Author: user
 */

#include "Poligono.h"
#include <iostream>
using namespace std ;


Poligono::Poligono()
{
	setNombre("") ;
	setLados(0) ;

	cout << "Construtor Poligono (def)" << getNombre() << endl ;
}

Poligono::Poligono(const string& nombre, unsigned int lados)
{
	setNombre(nombre) ;
	setLados(lados) ;

	cout << "Construtor Poligono (param)" << getNombre() << endl ;
}

Poligono::~Poligono()
{
	cout << "Destructor Poligono " << getNombre() << endl ;
}

Poligono::Poligono(const Poligono &other)
{
	*this = other ;
	cout << "Construtor Poligono (copy)" << getNombre() << endl ;
}

Poligono& Poligono::operator=(const Poligono &other)
{
	this->setLados(other.getLados()) ;
	setNombre(other.getNombre()) ;

	return *this ;
}

void Poligono::setNombre(const string& nombre) { nombre_ = nombre; }
void Poligono::setLados(unsigned int lados) { lados_ = lados ; }

unsigned int Poligono::getLados() const { return lados_ ; }
string Poligono::getNombre() const { return nombre_ ; }

void Poligono::dump() const
{
	cout << "-----------------------------------------" << endl ;
	cout << "[POLI] Nombre: " << getNombre() << endl ;
	cout << "[POLI] Lados: " << getLados() << endl ;
}


