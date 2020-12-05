/*
 * Rectangulo.cpp
 *
 *  Created on: Mar 3, 2020
 *      Author: user
 */

#include "Rectangulo.h"


#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std ;

// --------------------------------------------------------------------------------
// Constructor por defecto
// --------------------------------------------------------------------------------
Rectangulo::Rectangulo()
{
	cout << "Estoy construyendo (por defecto) un Rectángulo" << endl ;
	setNom("Nuevo") ;
	setBase(0) ;
	setAltura(0) ;
}

// --------------------------------------------------------------------------------
// Constructor por parámetros
// Le pasamos nombre, base y altura
// --------------------------------------------------------------------------------
Rectangulo::Rectangulo(const string& n, const int& b, const int& a)
{
	cout << "Estoy construyendo (por parámetro) un Rectángulo" << endl ;
	setNom(n) ;
	setBase(b) ;
	setAltura(a) ;
}

// --------------------------------------------------------------------------------
// Constructor por parámetros
// Le pasamos nombre y
//	true para que construya el rectangulo con valores aleatorios
// 	false -> con valor = 0
// --------------------------------------------------------------------------------
Rectangulo::Rectangulo(const string& n, bool al)
{
	int a, b;

	if(al)
	{
		b = 1 + rand() % 100 ;
		a = 1 + rand() % 100 ;
	}
	else
	{
		a = 0 ;
		b = 0 ;
	}

	setNom(n) ;
	setBase(b) ;
	setAltura(a) ;
}

// --------------------------------------------------------------------------------
// Constructor de copia
// Le pasamos una referencia a un objecto constante de la misma clase y buscamos
// 	crear un objecto nuevo que sea una copia idéntica al objecto pasado
// --------------------------------------------------------------------------------
Rectangulo::Rectangulo(const Rectangulo& r1)
{
	// En lugar de usar directamente los atributos usaremos getters y setters
	//	para asegurarnos que todo se realiza como queremos

//	setBase(r1.getBase()) ;
//	setAltura(r1.getAltura()) ;
//	setNom(r1.getNom()) ;

	*this = r1 ;
}

// --------------------------------------------------------------------------------
// Destructor
// Función que es llamada antes de que el objeto sea definitivamente destruido.
// El constructor es único. No tiene parámetros ni tipo de retorno y tiene el
//	símbolo ~ antes del nombre de la clase.
// Generalmente en el destructor debemos realizar limpieza de los recursos que
//	deban ponerse en orden: cerrar connexiones con BBDD, cerrar ficheros abiertos
//	cerrar comunicaciones, liberar objectos refereciados con apuntadores...
// --------------------------------------------------------------------------------
Rectangulo::~Rectangulo()
{
	cout << getNom() << ": Adiós mundo cruel!" << endl ;
	setAltura(0) ;
	setBase(0) ;
	setNom(" ") ;
}


// --------------------------------------------------------------------------------
// Función que imprime por pantalla los atributos del rectangulo
// --------------------------------------------------------------------------------
void Rectangulo::dump()
{
	cout << "----------- Imprimiendo valores del Rectángulo: " << endl ;
	cout << "Nom: " << getNom() << endl ;
	cout << "Base: " << getBase() << endl ;
	cout << "Altura: " << getAltura() << endl ;
	cout << "------------" << endl ;
}

// --------------------------------------------------------------------------------
// Función que permite acceder al atributo base_
// Se comprobará que el valor va de 1 a 100 y si no es así le asignaremos 0.
// --------------------------------------------------------------------------------
void Rectangulo::setBase(const int& b)
{
	if( b > 0 && b <= 100)
	{
		base_ = b ;
	}
	else
	{
		base_ = 0 ;
	}
}

// --------------------------------------------------------------------------------
// Función que permite acceder al atributo altura_
// Se comprobará que el valor va de 1 a 100 y si no es así le asignaremos 0.
// --------------------------------------------------------------------------------
void Rectangulo::setAltura(const int& a)
{
	if( a > 0 && a <= 100)
	{
		altura_ = a ;
	}
	else
	{
		altura_ = 0 ;
	}
}

void Rectangulo::setNom(const string& n)	{ nom_ = n ; }
int Rectangulo::getBase() const 	{ return base_ ; }
int Rectangulo::getAltura() const	{ return altura_ ; }
string Rectangulo::getNom() const	{ return nom_ ; }



// --------------------------------------------------------------------------------
// Función: area
// devuelve el área del rectángulo
// --------------------------------------------------------------------------------
int Rectangulo::area() const
{
	return getBase() * getAltura() ;
}

// --------------------------------------------------------------------------------
// Función: operator>
// compara dor rectángulos por su área
// --------------------------------------------------------------------------------
bool Rectangulo::operator>(const Rectangulo& r)
{
	return (area() > r.area()) ;
}

bool Rectangulo::operator<(const Rectangulo& r)
{
	return (area() < r.area()) ;
}

bool Rectangulo::operator>=(const Rectangulo& r)
{
	return (area() >= r.area()) ;
}

bool Rectangulo::operator<=(const Rectangulo& r)
{
	return (area() <= r.area()) ;
}

bool Rectangulo::operator==(const Rectangulo& r)
{
	return (area() == r.area()) ;
}

bool Rectangulo::operator!=(const Rectangulo& r)
{
	return (area() != r.area()) ;
}
// Rectangulo A ;
// Rectangulo B ;
// Rectangulo C ;
// C = (B = A) ;

Rectangulo& Rectangulo::operator=(const Rectangulo& r)
{
	setBase(r.getBase()) ;
	setAltura(r.getAltura()) ;
	setNom(r.getNom()) ;

	return *this ;
}








