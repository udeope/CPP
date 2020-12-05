/*
 * Ingeniero.h
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#ifndef INGENIERO_H_
#define INGENIERO_H_

#include "Estudiante.h"
#include <string>
using namespace std ;

class Ingeniero : public Estudiante
{
	string especialidad_ ;

public:
	Ingeniero();
	Ingeniero(const string&, float nota, const string& nombre, int edad);
	virtual ~Ingeniero();

	void setEspecialidad(const string&) ;
	const string& getEspecialidad() const ;

	void dump(bool persona = true) const ;

};

#endif /* INGENIERO_H_ */
