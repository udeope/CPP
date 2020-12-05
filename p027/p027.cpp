//============================================================================
// Name        : p027.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


#define MAX_LIBROS 100
#define MAX_CATALOGO 1000

// AGREGACIÓN CON CARDINALIDAD 0..N

class Libro
{
private:
	string nombre_ ;
public:
	Libro() ;
	Libro(const string&) ;
	Libro(const Libro&) ;
	virtual ~Libro() ;
	const Libro& operator=(const Libro&) ;


	void setNombre(const string&) ;
	const string& getNombre() const ;
	void dump() const ;
} ;

// La classe Biblioteca se asocia con la clase Libro, con multiplicidad/cardinalidad 0..N (agregación)
class Biblioteca
{
private:
	Libro* libros_[MAX_LIBROS] ;				// cardinalidad 1

public:
	Biblioteca() ;
	virtual ~Biblioteca() ;

	bool registraLibro(Libro*) ;

	void dump() ;

} ;


// La clase Catalogo contiene libros como composición
class Catalogo
{
private:
	Libro* libros_[MAX_CATALOGO] ;

public:
	Catalogo() ;
	virtual ~Catalogo() ;

	int creaLibro(const string&) ;
	Libro* getLibro(int) ;

};



Libro::Libro()
{
	setNombre("") ;
}

Libro::Libro(const string& nombre)
{
	setNombre(nombre) ;
}

Libro::Libro(const Libro& l)
{
	*this = l ;
}

Libro::~Libro()
{

}

const Libro& Libro::operator=(const Libro& l)
{
	setNombre(l.getNombre()) ;

	return *this ;
}


void Libro::dump() const
{
	cout << getNombre() << endl ;
}



Biblioteca::Biblioteca()
{
	for(int i = 0 ; i < MAX_LIBROS ; i++)
	{
		libros_[i] = nullptr ;
	}
}


Biblioteca::~Biblioteca()
{
}



bool Biblioteca::registraLibro(Libro* l)
{
	bool bOk = false ;

	for(int i = 0 ; i < MAX_LIBROS ; i++)
	{
		if(libros_[i] == nullptr)
		{
			libros_[i] = l ;
			bOk = true ;
			break ;
		}
	}

	return bOk ;
}



Catalogo::Catalogo()
{
	for(int i = 0 ; i < MAX_CATALOGO ; i++)
	{
		libros_[i] = nullptr ;
	}
}


Catalogo::~Catalogo()
{
	for(int i = 0 ; i < MAX_CATALOGO ; i++)
	{
		if(libros_[i] != nullptr)
		{
			delete libros_[i] ;
			libros_[i] = nullptr ;
		}
	}
}

int Catalogo::creaLibro(const string& nombre)
{
	int indice = -1 ;

	for(int i = 0 ; i < MAX_CATALOGO ; i++)
	{
		if(libros_[i] == nullptr)
		{
			Libro *l = (Libro *) new Libro(nombre) ;
			libros_[i] = l ;
			indice = i ;
			break ;
		}
	}

	return indice ;
}


Libro* Catalogo::getLibro(int indice)
{
	Libro *l = nullptr ;

	if(indice >= 0 && indice < MAX_CATALOGO)
	{
		l = libros_[indice] ;
	}

	return l ;
}






int main()
{

	// creamos el catálogo
	Catalogo* Ktalog = (Catalogo *) new Catalogo ;

	// creo la biblioteca
	Biblioteca* BBTK = (Biblioteca*) new Biblioteca ;

	// lleno mi catálogo de libros
	for(int x = 0 ; x < 1000 ; x++)
	{
		Ktalog->creaLibro("") ;
	}

	// registro en la biblioteca aquellos que necesito
	// en este caso sólo los que són múltiples de 10
	for(int x = 0 ; x < 1000 ; x++)
	{
		if(x%10)
		{
			Libro *l = Ktalog->getLibro(x) ;
			BBTK->registraLibro(l) ;

			//BBTK->registraLibro(Ktalog->getLibro(x)) ;
		}
	}

	// destruyo la biblioteca
	// pero NO se destruyen los libros
	if(BBTK != nullptr)
	{
		delete BBTK ;
		BBTK = nullptr ;
	}

	// destruyo el catálogo
	// con él todos sus libros
	if(Ktalog!= nullptr)
	{
		delete Ktalog ;
		Ktalog = nullptr ;
	}




	return 0;
}
