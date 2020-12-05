/*
 * Empleado.h
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#include "Persona.h"

class Empleado : public Persona
{
	int numeroSegSocial_ ;

public:
	Empleado();
	Empleado(int nss, const string& nombre, int edad);
	virtual ~Empleado();

	void setNumeroSegSocial(int) ;
	int getNumeroSegSocial() const ;

	void dump(bool persona = true) const ;
};

#endif /* EMPLEADO_H_ */
