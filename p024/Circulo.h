/*
 * Circulo.h
 *
 *  Created on: May 26, 2020
 *      Author: user
 */

#ifndef CIRCULO_H_
#define CIRCULO_H_

#include "Figura.h"

class Circulo: public Figura
{
private:
	unsigned int radio_ ;

public:
	Circulo();
	Circulo(unsigned int lado);
	virtual ~Circulo();

	void setRadio(unsigned int l) ;
	unsigned int getRadio() const ;

	void dump() const ;
	float area() const ;
};

#endif /* CIRCULO_H_ */
