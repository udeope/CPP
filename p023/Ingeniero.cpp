/*
 * Ingeniero.cpp
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#include "Ingeniero.h"
#include <iostream>
using namespace std ;

Ingeniero::Ingeniero()
{
	setEspecialidad("") ;
}

Ingeniero::Ingeniero(const string& especialidad, float nota, const string& nombre, int edad)
:Estudiante(nota, nombre, edad)
{
	setEspecialidad(especialidad) ;
}

Ingeniero::~Ingeniero()
{
	cout << "Destruyendo Ingeniero..." << endl ;
}

void Ingeniero::setEspecialidad(const string& especialidad)
{
	especialidad_ = especialidad ;
}

const string& Ingeniero::getEspecialidad() const
{
	return especialidad_ ;
}

void Ingeniero::dump(bool persona) const
{
	Estudiante::dump(persona) ;
	cout << "Especialidad: " << getEspecialidad() << endl ;
}
