/*
 * Cuadrado.h
 *
 *  Created on: May 26, 2020
 *      Author: user
 */

#ifndef CUADRADO_H_
#define CUADRADO_H_

#include "Figura.h"

class Cuadrado: public Figura
{
private:
	unsigned int lado_ ;

public:
	Cuadrado();
	Cuadrado(unsigned int lado);
	virtual ~Cuadrado();

	void setLado(unsigned int l) ;
	unsigned int getLado() const ;

	void dump() const ;
	float area() const ;
};

#endif /* CUADRADO_H_ */
