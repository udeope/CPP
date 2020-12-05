/*
 * Rectangulo.h
 *
 *  Created on: Mar 10, 2020
 *      Author: user
 */

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Poligono.h"

class Rectangulo: public Poligono
{
private:
	unsigned int base_ ;
	unsigned int altura_ ;

public:
	Rectangulo() ;
	Rectangulo(const string&, unsigned int, unsigned int) ;
	virtual ~Rectangulo() ;
	Rectangulo(const Rectangulo &other) ;
	Rectangulo& operator=(const Rectangulo &other) ;


	unsigned int getBase() const ;
	unsigned int getAltura() const ;

	void setBase(unsigned int) ;
	void setAltura(unsigned int) ;

	void dump() const ;
};

#endif /* RECTANGULO_H_ */
