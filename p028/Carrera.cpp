/*
 * Carrera.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: user
 */
#include <string>
#include <iostream>
using namespace std ;

#include "Carrera.h"

Carrera::Carrera()
{
	initProfesores() ;
	initAlumnos() ;
	setPromocion("") ;
	setEstudios("") ;
}

Carrera::Carrera(const string& promo, const string& estudios)
{
	initProfesores() ;
	initAlumnos() ;
	setPromocion(promo) ;
	setEstudios(estudios) ;
}

Carrera::~Carrera()
{
	// alumnos_ : Relación de agregación, no destruimos los alumnos
	// profesores_ : Relación de asociación, no destruimos los profesores

	// al eliminar la carrera, ya que conocemos a los profesores, les pedimos que ellos
	//		se desvinculen de la carreara que se va a borrar.
	for(int i = 0 ; i < MAX_PROFESORES_CARRERA ; i++)
	{
		if(profesores_[i] != nullptr)
		{
			profesores_[i]->desvinculate() ;
		}
	}
}

Carrera::Carrera(const Carrera &other)
{
	*this = other ;
}

Carrera& Carrera::operator=(const Carrera &other)
{
	setPromocion(other.getPromocion()) ;
	setEstudios(other.getEstudios()) ;

	// Aquí hace falta copiar TODO TODO TODO el contenido de la clase Carrera
	//	incluye la LISTA DE PROFESORES y ALUMNOS

	for(int i = 0 ; i < MAX_PROFESORES_CARRERA ; i++)
	{
		profesores_[i] = other.getProfesor(i) ;
	}

	for(int i = 0 ; i < MAX_ALUMNOS_CARRERA ; i++)
	{
		alumnos_[i] = other.getAlumno(i) ;
	}

	return *this ;
}

const string& Carrera::getPromocion() const { return promocion_ ; }
const string& Carrera::getEstudios() const { return estudios_ ; }

void Carrera::setPromocion(const string& pr) { promocion_ = pr ; }
void Carrera::setEstudios(const string& es) { estudios_ = es ; }

Profesor* Carrera::getProfesor(int ndx) const
{
	Profesor *profesor = nullptr ;
	if(ndx < MAX_PROFESORES_CARRERA)
	{
		profesor = profesores_[ndx] ;
	}

	return profesor ;
}

Alumno* Carrera::getAlumno(int ndx) const
{
	Alumno *alumno = nullptr ;
	if(ndx < MAX_ALUMNOS_CARRERA)
	{
		alumno = alumnos_[ndx] ;
	}

	return alumno ;
}


void Carrera::dump() const
{
	cout << "+-------------------------------------------------+" << endl ;
	cout << "Carrera: " << getEstudios() << endl ;
	cout << "Promocion: " << getPromocion() << endl ;

}

void Carrera::initAlumnos()
{
	for(int i = 0 ; i < MAX_ALUMNOS_CARRERA ; i++)
	{
		alumnos_[i] = nullptr ;
	}
}

void Carrera::initProfesores()
{
	for(int i = 0 ; i < MAX_PROFESORES_CARRERA ; i++)
	{
		profesores_[i] = nullptr ;
	}

}


bool Carrera::matricula(Alumno* al)
{
	bool bOk = false ;

	for(int i = 0 ; i < MAX_ALUMNOS_CARRERA ; i++)
	{
		if(alumnos_[i] == nullptr)
		{
			alumnos_[i] = al ;
			bOk = true ;
			break ;
		}
	}

	return bOk ;
}

bool Carrera::vincularProfesor(Profesor *pr)
{
	bool bOk = false ;

	for(int i = 0 ; i < MAX_PROFESORES_CARRERA ; i++)
	{
		if(profesores_[i] == nullptr)
		{
			profesores_[i] = pr ;
			pr->vinculate(this) ;
			bOk = true ;
			break ;
		}
	}

	return bOk ;
}
