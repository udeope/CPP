/*
 * Estudiante.h
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include "Persona.h"
#include <string>
using namespace std ;

class Estudiante : public Persona
{
private:
	float nota_ ;

public:
	Estudiante();
	Estudiante(float);
	Estudiante(float nota, const string& nombre, int edad);
	virtual ~Estudiante();

	void setNota(float) ;
	float getNota() const ;

	void dump(bool empleado = true) const ;
};

#endif /* ESTUDIANTE_H_ */
