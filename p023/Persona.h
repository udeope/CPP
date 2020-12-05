/*
 * Persona.h
 *
 *  Created on: May 25, 2020
 *      Author: user
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include <string>
using namespace std ;

class Persona
{
private:
	string nombre_ ;
	int edad_ ;

public:
	Persona();
	Persona(const string&, int);
	virtual ~Persona() ;

	void setNombre(const string&) ;
	void setEdad(int) ;
	const string& getNombre() const ;
	int getEdad() const ;

	void dump(int n) ;
	virtual void dump(bool persona = true) const ;
};

#endif /* PERSONA_H_ */
