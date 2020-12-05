/*
 * Figura.cpp
 *
 *  Created on: May 26, 2020
 *      Author: user
 */

#include "Figura.h"
#include <iostream>
using namespace std ;

Figura::Figura()
{
	setTipo(NINGUNO) ;
}

Figura::Figura(TipoFigura t)
{
	setTipo(t) ;
}

Figura::~Figura()
{
	cout << "Destruyendo figura..." << endl ;
}

void Figura::setTipo(TipoFigura t)
{
	tipo_ = t ;
}

TipoFigura Figura::getTipo() const
{
	return tipo_ ;
}

void Figura::dump() const
{
	string tipo = "" ;

	switch(getTipo())
	{
		case NINGUNO 	: tipo = "Sin definir" ; break ;
		case CUADRADO 	: tipo = "Cuadrado" ; break ;
		case CIRCULO 	: tipo = "Círculo" ; break ;
		case TRIANGULO 	: tipo = "Triángulo" ; break ;
	}
	cout << tipo ;
}





