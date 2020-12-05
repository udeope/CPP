//============================================================================
// Name        : p023.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "Analista.h"
#include <iostream>
using namespace std;

int main()
{
	// creamos el objecto de tipo Analista usando el constructor por parámetros
	Analista a1("Juan", 35, 8.5, "Informático", 295829312, "Robot") ;

	// realizamos el dump
	a1.dump() ;


	// a continuacion con código comentado vemos alternativas a esto usando punteros y memória dinámica

//	Analista a1("Juan", 35, 8.5, "Informática", 12345678, "Robot" ) ;
//	Empleado a2(1234134,"José",23) ;
//	Empleado *ptr = nullptr ;
//
//	ptr = &a1 ;
//
//	a1.dump() ;
//	cout << "----------------------------------------------" << endl ;
//	a2.dump() ;
//	cout << "----------------------------------------------" << endl ;
//
//	ptr->dump() ;

//	Empleado a2(1234134,"José",23) ;
//
//	// a2.dump() ;
//
//	Empleado *ePtr = &a2 ;
//	Persona *pPtr = &a2 ;
//
//	ePtr->dump() ;
//	cout << "-----------------------" << endl ;
//	pPtr->dump() ;
//
//
//	Empleado e1(123123,"Frank",28) ;
//	Analista a1("Manuel", 35, 8.5, "Informática", 12345678, "Robot") ;
//	Estudiante es1(9.9,"Judith",33) ;
//
//	Empleado *e2 = new Empleado(43234,"Carlos",44) ;
//
//	delete e2 ;
//
//
//	es1.dump() ;
//
//	Estudiante *estPtr = &es1 ;
//	estPtr->dump() ;
//	estPtr->dump(4) ;
//
//	Persona *perPtr = &es1 ;
//	perPtr->dump() ;
//
//	// Podemos llamar a la función dump() de la clase base, cuando esta es virtual?
//
//
//
//	Persona *personas[100] ;
//
//	for(int i = 0 ; i < 100 ; i++)
//	{
//		personas[i] = nullptr ;
//	}
//
//	personas[0] = &e1 ;
//	//personas[1] = &a1 ;
//	personas[2] = &es1 ;
//
//	for(int i = 0 ; i < 100 ; i++)
//	{
//		if(personas[i] != nullptr)
//		{
//			personas[i]->dump() ;
//			cout << "---------------------------------" << endl ;
//		}
//	}



	return 0 ;
}
