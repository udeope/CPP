//============================================================================
// Name        : p025.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


// ASOCIACIÓN CON CARDINALIDAD 0,1

class B ;

// La classe A se asocia con la clase B, con multiplicidad/cardinalidad 0,1
// puede haber relación o no
class A
{
private:
	B* b_ ;				// cardinalidad 0,1

public:
	A() ;
	virtual ~A() ;
	// aquí haría falta constructor de copia
	// aquí haría falta operador de asignación

	void setB(B*) ;
	B* getB() ;

	bool conozcoB() ;

} ;

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


A::A()
{
	b_ = nullptr ;
}

A::~A()
{
}

B* A::getB()
{
	return b_ ;
}

void A::setB(B* b)
{
	b_ = b ;
}

bool A::conozcoB()
{
	if(getB() != nullptr)
	{
		cout << "Conozco a " << getB()->getNombre() << endl ;
		return true ;
	}
	else return false ;
}


B::B()
{
	setNombre("") ;
}

B::~B() {}

void B::setNombre(const string& nombre)
{
	nombre_ = nombre ;
}

const string& B::getNombre() const
{
	return nombre_ ;
}



class Persona
{
private:
	Persona* conyuge_ ;
	string nombre_ ;
	bool sexo_ ;

public:
	Persona() ;
	Persona(const string&, bool) ;
	Persona(const Persona&) ;
	virtual ~Persona() ;
	const Persona& operator=(const Persona&) ;

	const string& getNombre() const ;
	bool getSexo() const ;
	Persona* getConyuge() const ;

	void setNombre(const string&) ;
	void setSexo(bool) ;
	void setConyuge(Persona*) ;

	void dump() const ;

};



Persona::Persona()
{
	setConyuge(nullptr) ;
	setNombre("") ;
	setSexo(true) ;
}

Persona::Persona(const string& nombre, bool sexo)
{
	setConyuge(nullptr) ;
	setNombre(nombre) ;
	setSexo(sexo) ;
}


Persona::Persona(const Persona& persona)
{
	*this = persona ;
}

Persona::~Persona()
{
	// TODO tengo que terminar el destructor
}

const Persona& Persona::operator=(const Persona& persona)
{
	setConyuge(persona.getConyuge()) ;
	setNombre(persona.getNombre()) ;
	setSexo(persona.getSexo()) ;

	return *this ;
}

void Persona::setConyuge(Persona* persona)
{
	conyuge_ = persona ;
}

void Persona::setNombre(const string& nombre)
{
	nombre_ = nombre ;
}

void Persona::setSexo(bool s)
{
	sexo_ = s ;
}

Persona* Persona::getConyuge() const
{
	return conyuge_ ;
}

const string & Persona::getNombre() const
{
	return nombre_ ;
}

bool Persona::getSexo() const
{
	return sexo_ ;
}


void Persona::dump() const
{
	string sexo ;
	string matrimonio ;
	string conyuge ;

	if(getSexo()) sexo = "hombre" ;
	else sexo = "mujer" ;

	if(getConyuge() != nullptr)
	{
		matrimonio = " y tiene un matrimonio con " ;
		conyuge = getConyuge()->getNombre() ;
	}

	cout << "------------------------------" << endl ;
	cout << getNombre() << " es " << sexo << matrimonio << conyuge << endl ;
}



void divorcio(Persona *p1, Persona *p2)
{
	p1->setConyuge(nullptr) ;
	p2->setConyuge(nullptr) ;
}

void matrimonio(Persona *p1, Persona *p2)
{
	p1->setConyuge(p2) ;
	p2->setConyuge(p1) ;
}



int main()
{
	A *a1 = new A ;
	B *b1 = new B ;

	b1->setNombre("Objeto B1") ;

	cout << a1->conozcoB() << endl ;

	a1->setB(b1) ;

	cout << a1->conozcoB() << endl ;


	a1->setB(nullptr) ;
	delete b1 ;

	delete a1 ;


	// MATRIMONIO

	cout << " *********************************************************** " << endl ;


	Persona Juan("Juan",true) ;
	Persona Maria("Maria",false) ;

	matrimonio(&Juan, &Maria) ;

	Juan.dump() ;
	Maria.dump() ;

	divorcio(&Juan, &Maria) ;

	Juan.dump() ;
	Maria.dump() ;



	return 0;
}
