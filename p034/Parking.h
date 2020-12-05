/*
 * Parking.h
 *
 *  Created on: Sep 8, 2020
 *      Author: user
 */

#ifndef PARKING_H_
#define PARKING_H_

#include "Coche.h"

#define FILAS 20
#define COLUMNAS 15

class Parking
{
private:
	Coche* coches_[FILAS][COLUMNAS] ;

	void inicializa() ;

public:
	Parking();
	virtual ~Parking();

	bool entraCoche(Coche* c, unsigned int fila, unsigned int columna) ;
	bool sacaCoche(unsigned int fila, unsigned int columna) ;
	void dump() const ;
};

#endif /* PARKING_H_ */
