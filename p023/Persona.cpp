/*
 * Persona.cpp
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#include "Persona.h"
#include <iostream>
using namespace std ;

Persona::Persona()
{
	setNombre("") ;
	setEdad(0) ;
}

Persona::Persona(const string& nombre, int edad)
{
	setNombre(nombre) ;
	setEdad(edad) ;
}

Persona::~Persona()
{
	cout << "Destruyendo Persona..." << endl ;
}

void Persona::setNombre(const string& nombre)
{
	nombre_ = nombre ;
}

void Persona::setEdad(int edad)
{
	edad_ = edad ;
}

const string& Persona::getNombre() const
{
	return nombre_ ;
}

int Persona::getEdad() const
{
	return edad_ ;
}

void Persona::dump(bool persona) const
{
	if(persona == true)
	{
		cout << "Nombre: " << getNombre() << endl ;
		cout << "Edad: " << getEdad() << endl ;
	}
}
