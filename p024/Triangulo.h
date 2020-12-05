/*
 * Triangulo.h
 *
 *  Created on: May 26, 2020
 *      Author: user
 */

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"

class Triangulo: public Figura
{
private:
	unsigned int base_ ;
	unsigned int altura_ ;

public:
	Triangulo();
	Triangulo(unsigned int base, unsigned int altura);
	virtual ~Triangulo();

	void setBase(unsigned int l) ;
	unsigned int getBase() const ;
	void setAltura(unsigned int l) ;
	unsigned int getAltura() const ;

	void dump() const ;
	float area() const ;

};

#endif /* TRIANGULO_H_ */
