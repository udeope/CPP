/*
 * Poligono.h
 *
 *  Created on: Mar 10, 2020
 *      Author: user
 */

#ifndef POLIGONO_H_
#define POLIGONO_H_

#include <string>
using namespace std ;

class Poligono
{
private:
	string nombre_ ;
	unsigned int lados_ ;

public:
	Poligono();
	Poligono(const string&, unsigned int) ;
	virtual ~Poligono();
	Poligono(const Poligono &other);
	Poligono& operator=(const Poligono &other);

	string getNombre() const ;
	unsigned int getLados() const ;

	void setNombre(const string&) ;
	void setLados(unsigned int) ;

	void dump() const ;
};

#endif /* POLIGONO_H_ */
