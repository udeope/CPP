/*
 * Ficha.h
 *
 *  Created on: Mar 3, 2020
 *      Author: user
 */

#ifndef FICHA_H_
#define FICHA_H_

typedef enum Jugador { JUGADOR_1 = 0 , JUGADOR_2 = 1 } Jugador ;
typedef unsigned short uchar ;

#define MAX_VIDA 9
#define MIN_VIDA 0
#define MAX_ATAQUE 5
#define MIN_ATAQUE 1
#define MAX_DEFENSA 5
#define MIN_DEFENSA 1
#define MAX_VELOCIDAD 3
#define MIN_VELOCIDAD 1
#define MAX_RANGO 1
#define MIN_RANGO 1

#define POSICIONES 20

class Ficha
{
private:

	uchar vida_ ;
	uchar ataque_ ;
	uchar defensa_ ;
	uchar velocidad_ ;
	uchar rango_ ;
	uchar posicion_ ;
	Jugador jugador_ ;


public:
	Ficha();
	Ficha(uchar vida, uchar ataque, uchar defensa, uchar velocidad, uchar rango, uchar pos, const Jugador& jugador);
	virtual ~Ficha();
	Ficha(const Ficha &other);
	Ficha& operator=(const Ficha &other);

	void dump() const ;
	void ataque(Ficha&) const ;
	bool atacable(const Ficha&) const ;


	void setVida(uchar) ;
	void setAtaque(uchar) ;
	void setDefensa(uchar) ;
	void setVelocidad(uchar) ;
	void setRango(uchar) ;
	void setPosicion(uchar) ;
	void setJugador(const Jugador&) ;

	uchar getVida() const ;
	uchar getAtaque() const ;
	uchar getDefensa() const ;
	uchar getVelocidad() const ;
	uchar getRango() const ;
	uchar getPosicion() const ;
	Jugador getJugador() const ;


};

#endif /* FICHA_H_ */
