//============================================================================
// Name        : p021.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// #include "Poligono.h"
#include "Rectangulo.h"

#include <iostream>
using namespace std;

int main()
{
	Rectangulo r1("R1",10,5) ;
	Rectangulo r2(r1) ;
	Rectangulo r3 = r2 ;

	r1.dump() ;
	r2.dump() ;
	r3.dump() ;


	return 0;
}
