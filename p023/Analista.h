/*
 * Analista.h
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#ifndef ANALISTA_H_
#define ANALISTA_H_

#include "Empleado.h"
#include "Ingeniero.h"
#include <string>
using namespace std ;

class Analista: public Empleado, public Ingeniero
{
private:
	string proyecto_ ;

public:
	Analista();
	Analista(const string& nombre, int edad, float nota, const string& especialidad, int nss, const string proyecto);
	virtual ~Analista();

	void setProyecto(const string&) ;
	const string& getProyecto() const ;

	void dump(bool persona = true) const ;
};

#endif /* ANALISTA_H_ */
