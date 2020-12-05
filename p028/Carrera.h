/*
 * Carrera.h
 *
 *  Created on: Jun 16, 2020
 *      Author: user
 */

#ifndef CARRERA_H_
#define CARRERA_H_


#define MAX_ALUMNOS_CARRERA 10
#define MAX_PROFESORES_CARRERA 4

#include <string>
using namespace std ;

#include "Alumno.h"
#include "Profesor.h"

class Profesor ;

class Carrera
{
private:
	string promocion_ ;
	string estudios_ ;

	Alumno* alumnos_[MAX_ALUMNOS_CARRERA] ;
	Profesor* profesores_[MAX_PROFESORES_CARRERA] ;

	void initProfesores() ;
	void initAlumnos() ;

public:
	Carrera() ;
	Carrera(const string&, const string&) ;
	virtual ~Carrera() ;
	Carrera(const Carrera &other) ;
	Carrera& operator=(const Carrera &other) ;

	bool matricula(Alumno*) ;
	bool vincularProfesor(Profesor*) ;

	const string& 	getPromocion() const ;
	const string& 	getEstudios() const ;

	void 			setPromocion(const string&) ;
	void 			setEstudios(const string&) ;

	Profesor*		getProfesor(int) const ;
	Alumno*			getAlumno(int) const ;

	void dump() const ;

};

#endif /* CARRERA_H_ */
