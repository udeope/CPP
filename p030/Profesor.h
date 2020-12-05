/*
 * Profesor.h
 *
 *  Created on: Jun 16, 2020
 *      Author: user
 */

#ifndef PROFESOR_H_
#define PROFESOR_H_

#include <string>
using namespace std ;

#include "Carrera.h"


class Carrera ;

class Profesor
{

private:
	string 		nombre_ ;		// nombre del profesor
	float 		salario_ ;		// salario
	Carrera* 	carrera_ ;		// referencia a la carrera en la que da clases

	void			setCarrera(Carrera*) ;

public:
	Profesor() ;
	Profesor(const string&, float, Carrera*) ;
	virtual ~Profesor() ;
	Profesor(const Profesor &other) ;
	Profesor& operator=(const Profesor &other) ;


	const string& 	getNombre() const ;
	float 			getSalario() const ;

	void 			setNombre(const string&) ;
	void 			setSalario(float) ;

	Carrera*		getCarrera() const ;

	string 			getEstudios() const ;
	string 			getPromocion() const ;

	void			desvinculate() ;
	void			vinculate(Carrera*) ;
	bool			estaVinculado() const ;

	void dump() const ;
} ;

#endif /* PROFESOR_H_ */
