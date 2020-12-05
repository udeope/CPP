/*
 * Analista.cpp
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#include "Analista.h"
#include <iostream>
using namespace std ;

Analista::Analista()
{
	setProyecto("") ;
}

Analista::Analista(const string& nombre, int edad, float nota, const string& especialidad, int nss, const string proyecto)
: Empleado(nss, nombre, edad), Ingeniero(especialidad, nota, nombre, edad)
{
	setProyecto(proyecto) ;
}


Analista::~Analista()
{
	cout << "Destruyendo Analista..." << endl ;
}


void Analista::setProyecto(const string& proyecto)
{
	proyecto_ = proyecto ;
}

const string& Analista::getProyecto() const
{
	return proyecto_ ;
}

void Analista::dump(bool persona) const
{
	//Empleado::dump(!persona) ;
	Ingeniero::dump(persona) ;
	cout << "NSS: " << getNumeroSegSocial() << endl ;
	cout << "Proyecto: " << getProyecto() << endl ;
}
