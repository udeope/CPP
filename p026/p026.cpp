//============================================================================
// Name        : p026.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


// ASOCIACIÓN CON CARDINALIDAD 1

class B
{
private:
	string nombre_ ;
public:
	B() ;
	virtual ~B() ;
	// aquí haría falta constructor de copia
	// aquí haría falta operador de asignación

	void setNombre(const string&) ;
	const string& getNombre() const ;
} ;

// La classe A se asocia con la clase B, con multiplicidad/cardinalidad 1
// DEBE haber relación
class A
{
private:
	B b_ ;				// cardinalidad 1

public:
	A() ;
	virtual ~A() ;
	// aquí haría falta constructor de copia
	// aquí haría falta operador de asignación

	//void setB(B*) ;
	//B* getB() ;

	bool conozcoB() ;

} ;




A::A()
{
	// b_ = nullptr ;
}

A::~A()
{
	cout << "Destruyendo a A..." << endl ;
}





B::B()
{
	setNombre("") ;
}

B::~B()
{
	cout << "Destruyendo a B..." << endl ;
}

void B::setNombre(const string& nombre)
{
	nombre_ = nombre ;
}

const string& B::getNombre() const
{
	return nombre_ ;
}






// ASOCIACIÓN CON CARDINALIDAD 4

class Rueda ;

class Coche
{
private:
	Rueda* neumaticos_[4] ;

	// ...

public:

	void ponRuedas(Rueda *r1, Rueda *r2, Rueda *r3, Rueda *r4 ) ;
};

void Coche::ponRuedas(Rueda *r1, Rueda *r2, Rueda *r3, Rueda *r4 )
{
	neumaticos_[0] = r1 ;
	neumaticos_[1] = r2 ;
	neumaticos_[2] = r3 ;
	neumaticos_[3] = r4 ;
}

class Rueda
{
	// ... tenemos todo lo que necesita una rueda
} ;










int main()
{
	A a1 ;

	// COCHE

	Rueda r1, r2, r3, r4, r5, r6, r7 ;
	Coche coche1 ;

	coche1.ponRuedas(&r1, &r2, &r3, &r4) ;


	return 0;
}
