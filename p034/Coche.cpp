/*
 * Coche.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: user
 */

#include "Coche.h"
#include <sstream>

Coche::Coche()
{
	setMarca(MC_NO) ;
	setColor(CC_NO) ;
	setAnyo(MIN_ANYO) ;
}

Coche::Coche(const MarcaCoche& mc, const ColorCoche& cc, unsigned int anyo)
{
	setMarca(mc) ;
	setColor(cc) ;
	setAnyo(anyo) ;
}

Coche::Coche(const Coche &other)
{
	*this = other ;
}

Coche::~Coche()
{
}



Coche& Coche::operator=(const Coche &other)
{
	setMarca(other.getMarca()) ;
	setColor(other.getColor()) ;
	setAnyo(other.getAnyo()) ;

	return *this ;
}


// SEAT - BLANCO - 2002
string Coche::dump() const
{
	stringstream ss ;
	ss << marcas[getMarca()] << " - " << colores[getColor()] << " - " << getAnyo() ;

	return ss.str() ;
}


void Coche::setMarca(const MarcaCoche& mc) { marca_ = mc ; }
void Coche::setColor(const ColorCoche& cc) { color_ = cc ; }
void Coche::setAnyo(unsigned int a)
{
	if(a < MIN_ANYO) anyo_ = MIN_ANYO ;
	else if(a > MAX_ANYO) anyo_ = MAX_ANYO ;
	else anyo_ = a ;
}

MarcaCoche Coche::getMarca() const { return marca_ ; }
ColorCoche Coche::getColor() const { return color_ ; }
unsigned int Coche::getAnyo() const { return anyo_ ; }


