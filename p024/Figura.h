/*
 * Figura.h
 *
 *  Created on: May 26, 2020
 *      Author: user
 */

#ifndef FIGURA_H_
#define FIGURA_H_

#define TIPOS_DE_FIGURA 3
typedef enum TipoFigura { NINGUNO = 0, CUADRADO = 1, CIRCULO = 2, TRIANGULO = 3 } TipoFigura ;

class Figura
{
private:
	TipoFigura tipo_ ;

public:
	Figura();
	Figura(TipoFigura);
	virtual ~Figura();

	void setTipo(TipoFigura t) ;
	TipoFigura getTipo() const ;

	virtual void dump() const ;

	virtual float area() const = 0 ;
};

#endif /* FIGURA_H_ */
