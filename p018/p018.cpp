//============================================================================
// Name        : p018.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Primeras clases
//============================================================================

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// elementos de la lista
#define NUM_LISTA 10

// clase rectángulo
class Rectangulo
{
private:				// atributos privados: sólo accesibles por la propia clase
	string nom_ ;
	int base_ ;
	int altura_ ;

public:				// funciones públicas

	Rectangulo() ;											// constructor por defecto
	Rectangulo(const string&, const int&, const int&) ;		// constructor parámetros
	Rectangulo(const string&, bool) ;						// constructor parámetros
	Rectangulo(const Rectangulo&) ;							// constructor de copia
	virtual ~Rectangulo() ;


public:			// SETTERS & GETTERS   --- funciones para acceso a los atributos

	void setBase(const int& b) ;
	void setAltura(const int& a) ;
	void setNom(const string& n) ;

	int getBase() const ;
	int getAltura() const ;
	string getNom() const ;

				// Otras funciones públicas

	int area() ;
	void dump() ;
};


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

	setBase(r1.getBase()) ;
	setAltura(r1.getAltura()) ;
	setNom(r1.getNom()) ;
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
int Rectangulo::area()
{
	return getBase() * getAltura() ;
}





int main()
{
	srand(time(NULL)) ;

	// PARTE 1 - creación de objectos Rectángulo

	Rectangulo r1 ;					// creación llamando al constructor por defecto
	Rectangulo r2("r2",3,6) ;		// creación llamando al constructor por parámetros
	Rectangulo r3 ;					// creación llamando al constructor por defecto

	r1.setBase(5) ;					// asignamos un valor a la base y a la altura
	r1.setAltura(8) ;

	r1.dump() ;						// imprimimos los tres rectángulos
	r2.dump() ;
	r3.dump() ;


	// PARTE 2 - array de punteros a classe

	// declaramos un array de 10 posiciones de apuntadores a classes Rectangulo
	Rectangulo* lista[NUM_LISTA] ;

	// 1. creación de los 10 elementos (aleatorios)
	for(int i = 0 ; i < NUM_LISTA ; i++)
	{
		string s = "R" + to_string(i) ;
		lista[i] = (Rectangulo*) new Rectangulo(s,true) ;			// cada rectángulo es creado en el HEAP
	}

	// 2. impresión por pantalla de los 10 elementos
	for(int i = 0 ; i < NUM_LISTA ; i++)
	{
		lista[i]->dump() ;
	}

	// 3. destrucción de los 10 elementos
	for(int i = 0 ; i < NUM_LISTA ; i++)
	{
		if(lista[i] != nullptr)							// comprobamos si el puntero es distinto de NULL
		{
			delete lista[i] ;							// si lo es liberamos la memoria
			lista[i] = nullptr ;						// ponemos el puntero a NULL
		}
	}

	// PARTE 3 - USO DE CONTRUCTOR DE COPIA

	Rectangulo r11("R11",true) ;								// llamamos al constructor por parámetros
	Rectangulo r12(r11) ;										// llamamos al constructor de copia
	Rectangulo* r13 = (Rectangulo *) new Rectangulo(r12) ;		// creamos un Rectangulo en el HEAP conel constructor de copia

	// imprimimos resultados...
	r11.dump() ;
	r12.dump() ;
	r13->dump() ;

	// finalmenete antes de terminar eliminamos el Rectangulo del HEAP
	if(r13 != nullptr)
	{
		delete r13 ;
		r13 = nullptr ;
	}


	return 0;
}
