/*
 * Alumno.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: user
 */

#include <string>
#include <iostream>
using namespace std ;

#include "Alumno.h"

Alumno::Alumno()
{
	setNombre("") ;
	setCodigo(-1) ;
}

Alumno::Alumno(const string& nombre, int codigo)
{
	setNombre(nombre) ;
	setCodigo(codigo) ;
}

Alumno::~Alumno()
{
}

Alumno::Alumno(const Alumno &other)
{
	*this = other ;
}

Alumno& Alumno::operator=(const Alumno &other)
{
	setNombre(other.getNombre()) ;
	setCodigo(other.getCodigo()) ;

	return *this ;
}


void Alumno::setNombre(const string& n) { nombre_ =  n ; }
void Alumno::setCodigo(int c) { codigo_ = c ; }
const string& Alumno::getNombre() const { return nombre_ ; }
int Alumno::getCodigo() const { return codigo_ ; }


void Alumno::dump() const
{
	cout << "+-------------------------------------------------+" << endl ;
	cout << "Nombre: " << getNombre() << endl ;
	cout << "Código: " << getCodigo() << endl ;
}
