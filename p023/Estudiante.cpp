/*
 * Estudiante.cpp
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#include "Estudiante.h"
#include <iostream>
using namespace std ;

Estudiante::Estudiante()
{
	setNota(0.0) ;
}

Estudiante::Estudiante(float nota)
{
	setNota(nota) ;
}

Estudiante::Estudiante(float nota, const string& nombre, int edad)
:Persona(nombre, edad)
{
	setNota(nota) ;
}

Estudiante::~Estudiante()
{
	cout << "Destruyendo Estudiante..." << endl ;
}

void Estudiante::setNota(float nota)
{
	nota_ = nota ;
}

float Estudiante::getNota() const
{
	return nota_ ;
}

void Estudiante::dump(bool persona) const
{
	Persona::dump(persona) ;
	cout << "Nota: " << getNota() << endl ;
}
