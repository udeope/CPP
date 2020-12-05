/*
 * Universidad.h
 *
 *  Created on: Jun 16, 2020
 *      Author: user
 */

#ifndef UNIVERSIDAD_H_
#define UNIVERSIDAD_H_

#define MAX_ALUMNOS 20
#define MAX_PROFESORES 10
#define MAX_CARRERAS 5

#include "Alumno.h"
#include "Profesor.h"
#include "Carrera.h"

#include <vector>
using namespace std ;

class Universidad
{
private:

	int nuevoCodigoAlumno_ ;

	vector<Alumno*> alumnos_ ;
	vector<Profesor*> profesores_ ;
	vector<Carrera> carreras_ ;


	void iniciaAlumnos() ;
	void iniciaProfesores() ;
	void iniciaCarreras() ;
	void destruyeAlumnos() ;
	void destruyeProfesores() ;
	void destruyeCarreras() ;

	int generaNuevoCodigoAlumno() ;
	int getNuevoCodigoAlumno() const ;
	void setNuevoCodigoAlumno(int) ;

	int getNumCarreras() const ;
	int getNumProfesores() const ;
	int getNumAlumnos() const ;

public:
	Universidad() ;
	virtual ~Universidad() ;

	Alumno* 	registrarAlumno(const string& nombre) ;
	Profesor* 	registrarProfesor(const string& nombre, float) ;
	Carrera*	crearPromocion(const string& promo, const string& estudios) ;

	Carrera*	getCarrera(unsigned int) ;
	Alumno*		getAlumno(unsigned int) ;
	Profesor*	getProfesor(unsigned int) ;

	void dump() const ;
	void dumpAlumnos() const ;
	void dumpProfesores() const ;
	void dumpCarreras() const ;
};

#endif /* UNIVERSIDAD_H_ */
