/*
 * Profesor.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: user
 */

#include <string>
#include <iostream>
using namespace std ;

#include "Profesor.h"

Profesor::Profesor()
{
	setNombre("") ;
	setSalario(0.0) ;
	setCarrera(nullptr) ;
}

Profesor::Profesor(const string& nombre, float salario, Carrera* carrera)
{
	setNombre(nombre) ;
	setSalario(salario) ;
	setCarrera(carrera) ;
}

Profesor::~Profesor()
{
	setCarrera(nullptr) ;
}

Profesor::Profesor(const Profesor &other)
{
	*this = other ;
}

Profesor& Profesor::operator=(const Profesor &other)
{
	setNombre(other.getNombre()) ;
	setSalario(other.getSalario()) ;
	setCarrera(other.getCarrera()) ;

	return *this ;
}

void Profesor::setCarrera(Carrera* c)
{
	carrera_ = c ;
}

Carrera* Profesor::getCarrera() const
{
	return carrera_ ;
}

void Profesor::setNombre(const string& nombre)
{
	nombre_ = nombre ;
}

void Profesor::setSalario(float salario)
{
	salario_ = salario ;
}

const string& Profesor::getNombre() const
{
	return nombre_ ;
}

float Profesor::getSalario() const
{
	return salario_ ;
}

string Profesor::getEstudios() const
{
	string estudios = "" ;
	if(carrera_ != nullptr)
	{
		estudios = carrera_->getEstudios() ;
	}
	return estudios ;
}


string Profesor::getPromocion() const
{
	string promocion = "" ;
	if(carrera_ != nullptr)
	{
		promocion = carrera_->getPromocion() ;
	}
	return promocion ;
}

void Profesor::desvinculate()
{
	setCarrera(nullptr) ;
}

void Profesor::vinculate(Carrera* ca)
{
	setCarrera(ca) ;
}

bool Profesor::estaVinculado() const
{
	bool v = false ;

	if(getCarrera() != nullptr)
	{
		v = true ;
	}

	return v ;
}

void Profesor::dump() const
{

	cout << "+-------------------------------------------------+" << endl ;
	cout << "Nombre: " << getNombre() << endl ;
	cout << "Salario: " << getSalario() << endl ;
	cout << "Docente de: " << getEstudios() << " " << getPromocion() << endl ;
}
