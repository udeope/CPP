/*
 * Rectangulo.h
 *
 *  Created on: Mar 3, 2020
 *      Author: user
 */

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include <string>
using namespace std ;

// clase rectángulo
class Rectangulo
{
private:				// atributos privados: sólo accesibles por la propia clase
	string nom_ ;
	int base_ ;
	int altura_ ;

public:				// funciones públicas

	Rectangulo() ;											// constructor por defecto
	Rectangulo(const string&, const int& base, const int& altura) ;		// constructor parámetros
	Rectangulo(const string&, bool) ;						// constructor parámetros
	Rectangulo(const Rectangulo&) ;							// constructor de copia
	virtual ~Rectangulo() ;
	bool operator>(const Rectangulo&) ;
	bool operator<(const Rectangulo&) ;
	bool operator>=(const Rectangulo&) ;
	bool operator<=(const Rectangulo&) ;
	bool operator==(const Rectangulo&) ;
	bool operator!=(const Rectangulo&) ;

	Rectangulo& operator=(const Rectangulo&) ;



public:			// SETTERS & GETTERS   --- funciones para acceso a los atributos

	void setBase(const int& b) ;
	void setAltura(const int& a) ;
	void setNom(const string& n) ;

	int getBase() const ;
	int getAltura() const ;
	string getNom() const ;

				// Otras funciones públicas

	int area() const ;
	void dump() ;
};


#endif /* RECTANGULO_H_ */
