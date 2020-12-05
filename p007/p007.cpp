//============================================================================
// Name        : p007.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Uso de funciones y parámetros por valor y referencia
//============================================================================

// zona de includes: aquellas funciones que requieren librerías aparte se incluyen
#include <math.h>			// incluimos math.h para poder usar la función sqrt() y isnan()
#include <iostream>			// incluimos iostream para usar cin / cout
using namespace std;

// definimos NUM_TABLA para usar un valor de 10
#define NUM_TABLA 10

// declaración de funciones
// no es necesario poner el nombre de los parámetros, como se puede observar a continuación algunas funciones
//	lo tienen y otras no.
// Las funciones que utilizan parámetros con el símbolo & indican que esos parámetros son pasados por referencia
float multiplica(float, float) ;
void multiplica(float, float, float& res) ;
float sumamultiplica(float) ;
void escribir(float val) ;
int eq2(float, float, float, float &sol1, float &sol2) ;
void printEq2(float a, float b, float c, int num, float sol1, float sol2) ;


int main()
{
	// declaración y inicialización de varibles locales
	float val1 = 3.0 ;
	float val2 = 4.2 ;
	float res = 0.0 ;

	// paso de parámetros de función por VALOR
	// float res = multiplica(val1, val2) ;

	// en la siguiente llamada a la función multiplica, el tercer parámetro se pasa por referencia
	//	esto significa que la función multiplica si modifica el valor de res, este valor permanecerá
	//	en la variable.
	multiplica(val1, val2, res) ;

	// llamada a la función sumamultiplica con parámetro por valor
	float res2 = sumamultiplica(5.0) ;

	// escritura por pantalla usando la función escribir()
	escribir(res) ;
	escribir(res2) ;


	// Llamadas a las funciones que calculan ecuaciones de segundo grado
	// variables locales
	float sol1 = 0.0 ;
	float sol2 = 0.0 ;
	int soluciones = 0 ;

	// llamada a la función eq2 con la ecuación x2-5x+6
	soluciones = eq2(1,-5,6,sol1, sol2) ;

	// llama a la función que imprime por pantalla la ecuación y sus soluciones
	printEq2(1,-5,6,soluciones,sol1, sol2) ;

	// llamada a la función eq2 con la ecuación x2
	soluciones = eq2(1,0,0,sol1, sol2) ;

	// llama a la función que imprime por pantalla la ecuación y sus soluciones
	printEq2(1,0,0,soluciones,sol1, sol2) ;

	// llamada a la función eq2 con la ecuación x2+1
	soluciones = eq2(1,0,1,sol1, sol2) ;

	// llama a la función que imprime por pantalla la ecuación y sus soluciones
	printEq2(1,0,1,soluciones,sol1, sol2) ;



	return 0;
}



// ----------------------------------------------------------
// multiplica
// Descripción: función que multiplica dos valores y devuelve el resultado
// Parámetros:
// - val1 - parámetro por valor
// - val2 - parámetro por valor
float multiplica(float val1, float val2)
{
	float resultado = val1 * val2 ;

	return resultado ;
}

// ----------------------------------------------------------
// multiplica
// Descripción: función que multiplica dos valores y devuelve el resultado por referencia
// Parámetros:
// - val1 - parámetro por valor
// - val2 - parámetro por valor
// - res - parámetro por referencia
void multiplica(float val1, float val2, float& res)
{
	res = val1 * val2 ;
}


// ----------------------------------------------------------
// escribir
// Descripción: escribe el valor pasado en el parámetro por pantalla
// Parámetros:
// - val1 - parámetro por valor
void escribir(float val)
{
	cout << val << endl ;
}


// ----------------------------------------------------------
// sumamultiplica
// Descripción: función que suma todos los valores de la tabla de
//				multiplicar del parámetro pasado por valor
//				por ejemplo: 5 -> 5x0 + 5x1 + 5x2 + 5x3 + ... + 5x9 + 5x10 = 275
// Parámetros:
// - a : parámetro pasado por valor
float sumamultiplica(float a)
{
	float suma = 0.0 ;

	for(int i = 0 ; i <= NUM_TABLA ; i++)
	{
		// en la variable suma guardamos el valor acumulado de las sumas anteriores más la actual
		suma = suma + (a * i) ;
	}

	return suma ;
}





// ----------------------------------------------------------
// eq2
// Descripción: función que calcula las soluciones a la ecuación de segundo grado
//	que puede tener 0, 1 o 2 soluciones.
//	La función devuelve un entor
// Parámetros:
// - a : parámetro pasado por valor
int eq2(float a, float b, float c, float &sol1, float &sol2)
{
	int res = 0 ;

	// cálculo de las dos posibles soluciones de la ecuación de 2 grado
	sol1 = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a) ;
	sol2 = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a) ;

	// con isnan coprobamos si la solución es inválida, en ese caso el número de soluciones será cero.
	if(isnan(sol1)) res = 0 ;
	else
	{
		// comprobamos si hay una única solución o son dos
		if(sol1 == sol2) res = 1 ;
		else res = 2 ;
	}

	return res ;
}


// ----------------------------------------------------------
// printEq2
// Descripción: función que imprime la ecuación y sus soluciones (si las tiene)
// Parámetros:
// - a, b, c: coeficientes de la ecuación
// - num: número de soluciones válidas
// - sol1, sol2: soluciones
void printEq2(float a, float b, float c, int num, float sol1, float sol2)
{
	cout << "La ecuación: " << a << "x2 + " << b << "x + " << c <<" = 0" << "   tiene " << num << " soluciones" << endl ;
	if(num > 0)
	{
		if(num >= 1) cout << "x = " << sol1 << endl ;
		if(num == 2) cout << "x = " << sol2 << endl ;
	}

	cout << endl ;
}


