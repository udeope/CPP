/*
 * Coche.h
 *
 *  Created on: Sep 8, 2020
 *      Author: user
 */

#ifndef COCHE_H_
#define COCHE_H_

#include <iostream>
using namespace std ;

typedef enum MarcaCoche { MC_NO = 0, MC_SEAT = 1 , MC_RENAULT = 2, MC_FIAT = 3, MC_AUDI = 4, MC_FERRARI = 5 } MarcaCoche ;
#define NUM_MARCAS 6

typedef enum ColorCoche { CC_NO = 0, CC_BLANCO = 1, CC_NEGRO = 2, CC_AZUL = 3, CC_AMARILLO = 4, CC_ROJO = 5, CC_VERDE = 6, CC_GRIS = 7 } ColorCoche ;
#define NUM_COLORES 8

#define MAX_ANYO 2020
#define MIN_ANYO 2001

const string marcas[NUM_MARCAS] = {"No","SEAT","RENAULT","FIAT","AUDI", "FERRARI"} ;
const string colores[NUM_COLORES] = {"No", "BLANCO", "NEGRO", "AZUL", "AMARILLO", "ROJO", "VERDE", "GRIS" } ;

class Coche
{
private:

	MarcaCoche marca_ ;
	ColorCoche color_ ;
	unsigned int anyo_ ;

public:
	Coche() ;
	Coche(const MarcaCoche&, const ColorCoche&, unsigned int) ;
	Coche(const Coche &other) ;
	Coche& operator=(const Coche &other) ;
	virtual ~Coche() ;

	string dump() const ;

	void setMarca(const MarcaCoche&) ;
	void setColor(const ColorCoche&) ;
	void setAnyo(unsigned int) ;

	MarcaCoche getMarca() const ;
	ColorCoche getColor() const ;
	unsigned int getAnyo() const ;
};

#endif /* COCHE_H_ */
