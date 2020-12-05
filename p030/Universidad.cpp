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
	setNuevoCodigoAlumno(0) ;
}

Universidad::~Universidad()
{
	destruyeAlumnos() ;
	destruyeProfesores() ;
	destruyeCarreras() ;
}



void Universidad::destruyeAlumnos()
{
	// como alumnos_ es un vector de punteros necesito liberar el objeto al qual apuntan
	//haciendo un clear NO se destruyen solos.

	vector<Alumno*>::iterator it ;
	for(it = alumnos_.begin() ; it != alumnos_.end() ; it++)
	{
		if( (*it) != nullptr)
		{
			delete (*it) ;
			*it = nullptr ;
		}
	}

	alumnos_.clear() ;
}

void Universidad::destruyeProfesores()
{
	// como profesores_ es un vector de punteros necesito liberar el objeto al qual apuntan
	//haciendo un clear NO se destruyen solos.

	vector<Profesor*>::iterator it ;
	for(it = profesores_.begin() ; it != profesores_.end() ; it++)
	{
		if( (*it) != nullptr)
		{
			delete (*it) ;
			*it = nullptr ;
		}
	}
	profesores_.clear() ;
}

void Universidad::destruyeCarreras()
{
	// como carreras_ es un vector de objetos no necesito liberarlos, se destruyen solos al hacer el clear()
	carreras_.clear() ;
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

	if(alumnos_.size() < MAX_ALUMNOS)
	{
		al = (Alumno*) new Alumno(nombre, generaNuevoCodigoAlumno()) ;
		alumnos_.push_back(al) ;
	}

	return al ;
}


Profesor* 	Universidad::registrarProfesor(const string& nombre, float salario)
{
	Profesor* pr = nullptr ;

	if(profesores_.size() < MAX_PROFESORES)
	{
		pr = (Profesor*) new Profesor(nombre, salario, nullptr) ;
		profesores_.push_back(pr) ;
	}


	return pr ;
}

Carrera*	Universidad::crearPromocion(const string& promocion, const string& estudios)
{
	Carrera *ca = nullptr ;

	if(carreras_.size() < MAX_CARRERAS)
	{
		Carrera car(promocion, estudios) ;
		carreras_.push_back(car) ;
		ca = &(carreras_.back()) ;
	}

	return ca ;
}

int Universidad::getNumCarreras() const
{
	return carreras_.size() ;
}

int Universidad::getNumProfesores() const
{
	return profesores_.size() ;
}

int Universidad::getNumAlumnos() const
{
	return alumnos_.size() ;
}

Carrera * Universidad::getCarrera(unsigned int n)
{
	Carrera *c = nullptr ;

	if(n < MAX_CARRERAS)
	{
		c = &(carreras_[n]) ;
	}

	return c ;
}

Alumno * Universidad::getAlumno(unsigned int n)
{
	Alumno *al = nullptr ;

	if(n < MAX_ALUMNOS)
	{
		al = (alumnos_[n]) ;
	}

	return al ;
}

Profesor* Universidad::getProfesor(unsigned int n)
{
	Profesor *pr = nullptr ;

	if(n < MAX_PROFESORES)
	{
		pr = (profesores_[n]) ;
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
	vector<Alumno*>::const_iterator cit ;
	int i = 0 ;

	if(alumnos_.size() == 0)
	{
		cout << "No hay alumnos registrados en la universidad" << endl ;
	}
	else
	{

		for(cit = alumnos_.cbegin() ; cit != alumnos_.cend() ; cit++)
		{
			cout << "[" << i << "] - " << (*cit)->getNombre() << " <" << (*cit)->getCodigo() << endl ;
			i++ ;
		}
	}
}

void Universidad::dumpProfesores() const
{
	vector<Profesor*>::const_iterator cit ;
	int i = 0 ;

	if(profesores_.size() == 0)
	{
		cout << "No hay profesores registrados en la universidad" << endl ;
	}
	else
	{

		for(cit = profesores_.cbegin() ; cit != profesores_.cend() ; cit++)
		{
			string vinculado = "" ;
			if((*cit)->estaVinculado())
			{
				vinculado = " - [DOCENTE]" ;
			}
			cout << "[" << i << "] - " << (*cit)->getNombre() << " <" << (*cit)->getSalario() << vinculado << endl ;
			i++ ;
		}
	}
}

void Universidad::dumpCarreras() const
{
	vector<Carrera>::const_iterator cit ;
	int i = 0 ;

	if(carreras_.size() == 0)
	{
		cout << "No hay carreras registrados en la universidad" << endl ;
	}
	else
	{

		for(cit = carreras_.cbegin() ; cit != carreras_.cend() ; cit++)
		{
			cout << "[" << i << "] - " << cit->getEstudios() << " <" << cit->getPromocion() << endl ;
			i++ ;
		}
	}
}

