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
	setPromocion("") ;
	setEstudios("") ;
}

Carrera::Carrera(const string& promo, const string& estudios)
{
	setPromocion(promo) ;
	setEstudios(estudios) ;
}

Carrera::~Carrera()
{
	// alumnos_ : Relación de agregación, no destruimos los alumnos
	// profesores_ : Relación de asociación, no destruimos los profesores

	profesores_.clear() ;
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

	other.copiaAlumnos(alumnos_) ;
	other.copiaProfesores(profesores_) ;

	return *this ;
}

void Carrera::copiaAlumnos(vector<Alumno*> & al) const
{
	al = alumnos_ ;
}

void Carrera::copiaProfesores(vector<Profesor*> & pr) const
{
	pr = profesores_ ;
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

bool Carrera::matricula(Alumno* al)
{
	bool bOk = false ;

	if(alumnos_.size() < MAX_ALUMNOS_CARRERA)
	{
		alumnos_.push_back(al) ;
		bOk = true ;
	}

	return bOk ;
}

bool Carrera::vincularProfesor(Profesor *pr)
{
	bool bOk = false ;

	if(profesores_.size() < MAX_PROFESORES_CARRERA)
	{
		profesores_.push_back(pr) ;
		pr->vinculate(this) ;
		bOk = true ;
	}

	return bOk ;
}
