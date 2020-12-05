/*
 * Empleado.cpp
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#include "Empleado.h"
#include <iostream>
using namespace std ;

Empleado::Empleado()
{
	setNumeroSegSocial(0) ;
}

Empleado::Empleado(int ss, const string& nombre, int edad)
:Persona(nombre, edad)
{
	setNumeroSegSocial(ss) ;
}


Empleado::~Empleado()
{
	cout << "Destruyendo Empleado..." << endl ;
}

void Empleado::setNumeroSegSocial(int ss)
{
	numeroSegSocial_ = ss ;
}

int Empleado::getNumeroSegSocial() const
{
	return numeroSegSocial_ ;
}

void Empleado::dump(bool persona) const
{
	Persona::dump(persona) ;
	cout << "NSS: " << getNumeroSegSocial() << endl ;
}
