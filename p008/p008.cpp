//============================================================================
// Name        : p008.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// declaración de la función factorial
int factorial(int) ;

int main()
{
	// imprimimos por pantalla el cálculo de factorial del número 4
	cout << factorial(4) ;
	return 0;
}

// ----------------------------------------------------------------------------------------
// factorial
// Descripción: función recursiva que se llama a sí misma hasta llegar a un valor = 1
// - n: número para calcular el factoria
// Retorno: el cálculo realizado
//
// Nota: para entender como funciona recomiendo debugar paso a paso el proyecto
int factorial(int n)
{
	int res = 0 ;

	if(n <= 1) res = 1 ;
	else res = n * factorial(n-1) ;

	return res ;
}
