/*
 * Universidad.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: user
 */

#include <string>
#include <iostream>
using namespace std ;

#include "Universidad.h"

Universidad::Universidad()
{
	iniciaAlumnos() ;
	iniciaProfesores() ;
	iniciaCarreras() ;
}

Universidad::~Universidad()
{
	destruyeAlumnos() ;
	destruyeProfesores() ;
	destruyeCarreras() ;
}


void Universidad::iniciaAlumnos()
{
	for(int i = 0 ; i < MAX_ALUMNOS ; i++)
	{
		alumnos_[i] = nullptr ;
	}
}

void Universidad::iniciaProfesores()
{
	for(int i = 0 ; i < MAX_PROFESORES ; i++)
	{
		profesores_[i] = nullptr ;
	}
}

void Universidad::iniciaCarreras()
{
	for(int i = 0 ; i < MAX_CARRERAS ; i++)
	{
		carreras_[i] = nullptr ;
	}
}

void Universidad::destruyeAlumnos()
{
	for(int i = 0 ; i < MAX_ALUMNOS ; i++)
	{
		if(alumnos_[i] != nullptr)
		{
			delete alumnos_[i] ;
			alumnos_[i] = nullptr ;
		}
	}
}

void Universidad::destruyeProfesores()
{
	for(int i = 0 ; i < MAX_PROFESORES ; i++)
	{
		if(profesores_[i] != nullptr)
		{
			delete profesores_[i] ;
			profesores_[i] = nullptr ;
		}
	}
}

void Universidad::destruyeCarreras()
{
	for(int i = 0 ; i < MAX_CARRERAS ; i++)
	{
		if(carreras_[i] != nullptr)
		{
			delete carreras_[i] ;
			carreras_[i] = nullptr ;
		}
	}
}

int Universidad::getNuevoCodigoAlumno() const
{
	return nuevoCodigoAlumno_ ;
}

void Universidad::setNuevoCodigoAlumno(int codigo)
{
	nuevoCodigoAlumno_ = codigo ;
}

int Universidad::generaNuevoCodigoAlumno()
{
	int codigo = getNuevoCodigoAlumno() ;
	setNuevoCodigoAlumno(codigo+1) ;

	return codigo ;
}

Alumno* Universidad::registrarAlumno(const string& nombre)
{
	Alumno* al = nullptr ;

	for(int i = 0 ; i < MAX_ALUMNOS ; i++)
	{
		if(alumnos_[i] == nullptr)
		{
			al = (Alumno*) new Alumno(nombre, generaNuevoCodigoAlumno()) ;
			alumnos_[i] = al ;
			break ;
		}
	}


	return al ;
}


Profesor* 	Universidad::registrarProfesor(const string& nombre, float salario)
{
	Profesor* pr = nullptr ;

	for(int i = 0 ; i < MAX_PROFESORES ; i++)
	{
		if(profesores_[i] == nullptr)
		{
			pr = (Profesor*) new Profesor(nombre, salario, nullptr) ;
			profesores_[i] = pr ;
			break ;
		}
	}


	return pr ;
}

Carrera*	Universidad::crearPromocion(const string& promocion, const string& estudios)
{
	Carrera* ca = nullptr ;

	for(int i = 0 ; i < MAX_CARRERAS ; i++)
	{
		if(carreras_[i] == nullptr)
		{
			ca = (Carrera*) new Carrera(promocion, estudios) ;
			carreras_[i] = ca ;
			break ;
		}
	}

	return ca ;
}

int Universidad::getNumCarreras() const
{
	int num = 0 ;

	while(carreras_[num] != nullptr)
	{
		num++ ;
	}

	return num ;
}

int Universidad::getNumProfesores() const
{
	int num = 0 ;

	while(profesores_[num] != nullptr)
	{
		num++ ;
	}

	return num ;
}

int Universidad::getNumAlumnos() const
{
	int num = 0 ;

	while(alumnos_[num] != nullptr)
	{
		num++ ;
	}

	return num ;
}

Carrera * Universidad::getCarrera(unsigned int n)
{
	Carrera *c = nullptr ;

	if(n < MAX_CARRERAS)
	{
		c = carreras_[n] ;
	}

	return c ;
}

Alumno * Universidad::getAlumno(unsigned int n)
{
	Alumno *al = nullptr ;

	if(n < MAX_ALUMNOS)
	{
		al = alumnos_[n] ;
	}

	return al ;
}

Profesor* Universidad::getProfesor(unsigned int n)
{
	Profesor *pr = nullptr ;

	if(n < MAX_PROFESORES)
	{
		pr = profesores_[n] ;
	}

	return pr ;
}

void Universidad::dump() const
{
	cout << "================================================" << endl ;
	cout << "UNIVERSIDAD" << endl ;
	cout << "Carreras: " << getNumCarreras() << endl ;
	cout << "Profesores: " << getNumProfesores() << endl ;
	cout << "Alumnos: " << getNumAlumnos() << endl ;
}

void Universidad::dumpAlumnos() const
{
	for(int i = 0 ; i < MAX_ALUMNOS ; i++)
	{
		if(alumnos_[i] != nullptr)
		{
			cout << "[" << i << "] - " << alumnos_[i]->getNombre() << " <" << alumnos_[i]->getCodigo() << endl ;
		}
	}
}

void Universidad::dumpProfesores() const
{
	for(int i = 0 ; i < MAX_PROFESORES ; i++)
	{
		if(profesores_[i] != nullptr)
		{
			string vinculado = "" ;
			if(profesores_[i]->estaVinculado())
			{
				vinculado = " - [DOCENTE]" ;
			}
			cout << "[" << i << "] - " << profesores_[i]->getNombre() << " " << profesores_[i]->getSalario() << vinculado << endl ;
		}
	}
}

void Universidad::dumpCarreras() const
{
	for(int i = 0 ; i < MAX_CARRERAS ; i++)
	{
		if(carreras_[i] != nullptr)
		{
			cout << "[" << i << "] - " << carreras_[i]->getEstudios() << " <" << carreras_[i]->getPromocion() << endl ;
		}
	}
}
