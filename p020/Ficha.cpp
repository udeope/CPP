/*
 * Ficha.cpp
 *
 *  Created on: Mar 3, 2020
 *      Author: user
 */

#include "Ficha.h"
#include <iostream>
using namespace std ;

Ficha::Ficha()
{
	setVida(MIN_VIDA) ;
	setAtaque(MIN_ATAQUE) ;
	setDefensa(MIN_DEFENSA) ;
	setVelocidad(MIN_VELOCIDAD) ;
	setRango(MIN_RANGO) ;
	setPosicion(0) ;
	setJugador(JUGADOR_1) ;
}

Ficha::Ficha(uchar vida, uchar ataque, uchar defensa, uchar velocidad, uchar rango, uchar pos, const Jugador& jugador)
{
	setVida(vida) ;
	setAtaque(ataque) ;
	setDefensa(defensa) ;
	setVelocidad(velocidad) ;
	setRango(rango) ;
	setPosicion(pos) ;
	setJugador(jugador) ;
}


Ficha::~Ficha()
{

}

Ficha::Ficha(const Ficha &other)
{
	*this = other ;
}

Ficha& Ficha::operator=(const Ficha &other)
{
	setVida(other.getVida()) ;
	setAtaque(other.getAtaque()) ;
	setDefensa(other.getDefensa()) ;
	setVelocidad(other.getVelocidad()) ;
	setRango(other.getRango()) ;
	setPosicion(other.getPosicion()) ;
	setJugador(other.getJugador()) ;

	return *this ;
}





void Ficha::setVida(uchar v) 		{ (v >= MIN_VIDA 		&& v <= MAX_VIDA) ? 		vida_ = v 		: vida_ = MIN_VIDA ; 			}
void Ficha::setAtaque(uchar a) 		{ (a >= MIN_ATAQUE 		&& a <= MAX_ATAQUE) ? 		ataque_ = a 	: ataque_ = MIN_ATAQUE ; 		}
void Ficha::setDefensa(uchar d) 	{ (d >= MIN_DEFENSA 	&& d <= MAX_DEFENSA) ? 		defensa_ = d 	: defensa_ = MIN_DEFENSA ; 		}
void Ficha::setVelocidad(uchar v) 	{ (v >= MIN_VELOCIDAD 	&& v <= MAX_VELOCIDAD) ? 	velocidad_ = v 	: velocidad_ = MIN_VELOCIDAD; 	}
void Ficha::setRango(uchar r)		{ (r >= MIN_RANGO 		&& r <= MAX_RANGO) ? 		rango_ = r 		: rango_ = MIN_RANGO ; 			}
void Ficha::setPosicion(uchar p) 	{ (p >= 0 				&& p <= POSICIONES) ? 		posicion_ = p 	: posicion_ = 0 ; 				}

void Ficha::setJugador(const Jugador& j) 	{ (j >= JUGADOR_1 		&& j <= JUGADOR_2) ? 		jugador_ = j 	: jugador_ = JUGADOR_1 ; 		}

uchar Ficha::getVida() const 		{ return vida_ ; }
uchar Ficha::getAtaque() const 		{ return ataque_ ; }
uchar Ficha::getDefensa() const 	{ return defensa_ ; }
uchar Ficha::getVelocidad() const 	{ return velocidad_ ; }
uchar Ficha::getRango() const 		{ return rango_ ; }
uchar Ficha::getPosicion() const 	{ return posicion_; }
Jugador Ficha::getJugador() const 	{ return jugador_ ; }



void Ficha::dump() const
{
	cout << "-----------------------------------" << endl ;
	cout << "  - Vida: " 		<< (unsigned int)getVida() 		<< endl ;
	cout << "  - Ataque: " 		<< (unsigned int)getAtaque() 	<< endl ;
	cout << "  - Defensa: " 	<< (unsigned int)getDefensa() 	<< endl ;
	cout << "  - Velocidad: " 	<< (unsigned int)getVelocidad() << endl ;
	cout << "  - Rango: " 		<< (unsigned int)getRango() 	<< endl ;
	cout << "  - Posicion: " 	<< (unsigned int)getPosicion() 	<< endl ;
	cout << "  - Jugador: " 	<< (unsigned int)getJugador() 	<< endl ;
}



void Ficha::ataque(Ficha& f) const
{
	if(f.getDefensa() <= getAtaque())
	{
		uchar ataqueEfectivo = getAtaque() - f.getDefensa() ;
		uchar vidaRival = f.getVida() ;
		uchar nuevaVida = 0 ;

		if(ataqueEfectivo < vidaRival)
		{
			nuevaVida = vidaRival - ataqueEfectivo ;
		}
		f.setVida(nuevaVida) ;

		cout << "  - Ataque efectivo: " << (unsigned int) ataqueEfectivo << endl ;
		cout << "  - Vida final: " << (unsigned int)vidaRival << " - " << (unsigned int)ataqueEfectivo << " = " << (unsigned int)nuevaVida << endl ;
	}
	else
	{
		cout << "   - Defensa superior!" << endl ;
	}
}

bool Ficha::atacable(const Ficha& other) const
{
	bool atacable = false ;

	if(this->getRango() >= abs(other.getPosicion() - getPosicion()))
	{
		atacable = true ;
	}

	return atacable ;
}

