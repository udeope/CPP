//============================================================================
// Name        : p015.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


typedef struct Rectangulo
{
	int base ;
	int altura ;
	int area ;
	int id ;
	bool ok ;
} Rectangulo ;

void printRectangulo(Rectangulo& r) ;
void prueba1() ;
void printPuntero(int* ptr) ;
void initRectangulo(Rectangulo *, int) ;
void printRectangulo(Rectangulo*) ;
Rectangulo* creaRectangulo(int) ;
void eliminaRectangulo(Rectangulo *ptr) ;

int main()
{
	Rectangulo rectangulos[10] ;
	Rectangulo* rectangulosPtr[10] ;
	Rectangulo r1 ;
	Rectangulo r2 ;
	Rectangulo* pr = nullptr ;

	// llamada a la función prueba (ejercicio de punteros)
	prueba1() ;

	for(int i = 0 ; i < 10 ; i++)
	{
		rectangulos[i].id = i ;
	}

	pr = &(rectangulos[0]) ;

	// esto es exactamente igual que
	pr = rectangulos ;

	for(int i = 0 ; i < 10 ; i++)
	{
		initRectangulo(pr, i) ;
		pr++ ;
	}

	pr = rectangulos ;
	for(int i = 0 ; i < 10 ; i++)
	{
		printRectangulo(pr) ;
		pr++ ;
	}


	r1.altura = 10 ;
	r1.base = 11 ;
	r1.area = 12 ;
	r1.id = 1 ;
	r1.ok = true ;

	r2.altura = 20 ;
	r2.base = 21 ;
	r2.area = 22 ;
	r2.id = 2 ;
	r2.ok = false ;

	printRectangulo(r1) ;
	printRectangulo(r2) ;

	pr = &r1 ;

	printRectangulo(*pr) ;

	pr = &r2 ;

	printRectangulo(*pr) ;

	// CREACION DE UN RECTANGULO EN EL HEAP (memoria dinamica)

	// inicializar el array
	for(int i = 0 ; i < 10 ; i++)
	{
		rectangulosPtr[i] = nullptr ;
	}

	for(int i = 0 ; i < 10 ; i++)
	{
		rectangulosPtr[i] = creaRectangulo(i) ;
	}

	// ................



	for(int i = 0 ; i < 10 ; i++)
	{
		eliminaRectangulo(rectangulosPtr[i]) ;
		rectangulosPtr[i] = nullptr ;
	}



	return 0;
}


void printRectangulo(Rectangulo& r)
{
	cout << "Base: " << r.base << endl ;
	cout << "Altura: " << r.altura << endl ;
	cout << "Area: " << r.area << endl ;
	cout << "Id: " << r.id << endl ;
	cout << "OK: " << (r.ok ? "OK" : "KO") << endl ;
	cout << "------------------" << endl ;
}



void prueba1()
{
	  int num[5];
	  int * p;

	  p = num;

	  *p = 100;

	  p++;

	  *p = 200;

	  p = &num[2];

	  *p = 300;

	  p = num + 3;

	  *p = 400;

	  p = num;

	  *(p+4) = 500;

	  for (int n=0; n<5; n++)
	  {
	    cout << "num[n]: " << num[n] << endl ;
	    cout << "dir: " << &num[n] << endl ;
	    cout << "puntero: " << p << endl ;
	    // p++ ;
	  }

	  printPuntero(p) ;
}

void printPuntero(int* p)
{
	cout << "========================" << endl ;
	for(int i = 0 ; i < 6 ; i++)
	{
		cout << *p << endl ;
		p++ ;
	}
}


void initRectangulo(Rectangulo* p, int id)
{
	// (*p).altura = 0 ;
	p->altura = 0 ;
	p->base = 0 ;
	p->area = 0 ;
	p->id = id ;
	p->ok = false ;
}

void printRectangulo(Rectangulo* p)
{
	cout << "Altura: " << p->altura << endl ;
	cout << "Base: " << p->base << endl ;
	cout << "Area: " << p->area << endl ;
	cout << "Id: " << p->id << endl ;
	cout << "Ok: " << p->ok << endl ;
	cout << "------------" << endl ;
}

Rectangulo* creaRectangulo(int id)
{
	Rectangulo *r = nullptr ;

	r = (Rectangulo*) new Rectangulo ;
	r->altura = 0 ;
	r->base = 0 ;
	r->area = 0 ;
	r->id = id ;
	r->ok = false ;

	return r ;
}


void eliminaRectangulo(Rectangulo *ptr)
{
	if(ptr != nullptr)
	{
		delete ptr ;
	}
}




