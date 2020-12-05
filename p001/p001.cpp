//============================================================================
// Name        : p001.cpp
// Author      : crt
// Version     : 1.0
// Copyright   : Your copyright notice
// Fecha       : 14/01/2020
// Description : Programa para trabajar los distintos tipos de datos básicos
//					del lenguaje C/C++
//============================================================================

// Directiva de precompilación que define un valor constante que va a ser sustituido en todo el código
//	allí donde aparezca un PI será sustituido por 3.14159 (antes de iniciar la compilación)
#define PI 3.14159

// Directiva de precompilación que indica qué librerías debe incluir nuestro programa, ya que
//	utiliza funciones que han sido definidas por terceros
#include <iostream>		// uso de funciones de entrada i salida de streams (cin, cout)
#include <string>		// uso de cadenas, tipo string

// para que podamos usar las funciones de las librerías STL
using namespace std;

// declaración de una variable global (ya que està fuera de todo ámbito local)
// es de tipo string (cadena de texto) y se inicializa con el valor "Hola".
string saludo{"Hola"} ;


// Función main: función principal del programa y punto de inicio de ejecución
int main()
{
	// declaración y inicialización de variables locales de la función main
	char a = '*' ;					// tipo caracter (8 bytes) - inicializada con el valor '*'
	short b = 100 ;					// tipo short (entero de 2 bytes) - inicializada con el valor 100
	int c = 1000000 ;				// tipo int (entero de 4 bytes) - inicializada con el valor 1000000
	float d = PI ;					// tipo float (real de 4 bytes) - inicializada con el valor de la constante PI definida fuera del main
	double e = 12.1234567890 ;		// tipo double (real de 8 bytes) - inicializada
	bool f = true ;					// topo bool (booleano de 1 byte) - puede tomar valores true o false (en este caso inicializado a true.

	int x = 0 ;
	int y = 1 ;
	x = y ;							// asignación de variables. El valor de x se modifica tomando el valor de y. Por tanto en este punto x = 1.

	cout << x << endl ;				// salida por pantalla del valor de x

	// como afecta la suma de 1 (incremento de 1) a las variables definidas anteriormente
	a = a + 1 ;
	b = b + 1 ;
	c = c + 1 ;
	d = d + 1 ;
	e = e + 1 ;
	f = f + 1 ;

	// salida por pantalla del valor de estas variables
	cout << a << endl ;
	cout << b << endl ;
	cout << c << endl ;
	cout << d << endl ;
	cout << e << endl ;
	cout << f << endl ;
	cout << saludo << endl ;
	cout << PI << endl ;

	// OPERADORES ARITMÉTICOS

	// +, -, *, /, %
	int v1 = 6 ;
	int v2 = 3 ;
	int resultado = 0 ;

	resultado = v1 + v2 ;
	cout << "SUMA: " << resultado << endl ;

	resultado = v1 - v2 ;
	cout << "RESTA: " << resultado << endl ;

	resultado = v1 * v2 ;
	cout << "MULTI: " << resultado << endl ;

	resultado = v1 / v2 ;
	cout << "DIV: " << resultado << endl ;

	resultado = v1 % v2 ;
	cout << "MÓDULO: " << resultado << endl ;


	// OPERADORES ASIGNACIÓN ARITMÉTICOS COMPUESTOS
	// ------------------------------------------------
	// +=, -=, /=, %=, *=, ...

	// v1 = v1 + 3 ;
	v1 = 0 ;
	v1 += 3 ;
	cout << "v1 += 3 = " << v1 << endl ;


	// OPERADORES DE INCREMENTO Y DECREMENTO
	// ----------------------------------------
	// ++, --

	v1 = 0 ;
	v1++ ;
	cout << "v1++ = " << v1 << endl ;

	// INCREMENTO ANTES O DESPUÉS DE LA VARIABLE
	// no es lo mismo:
	// a = ++b ;
	// que
	// a = b++ ;


	v1 = 0 ;
	v2 = 0 ;

	resultado = v1++ ;
	cout << "v1++ = " << resultado << endl ;


	resultado = ++v2 ;
	cout << "++v2 = " << resultado << endl ;

	// OPERADORES DE COMPARACIÓN
	// ----------------------------------------
	// ==, !=, <, >, >=, <=

	bool condicion = false ;

	condicion = (1 == 1) ; 		// comparación de igualdad
	condicion = (1 == 2) ;
	condicion = (1 != 2) ; 		// comparación de diferente
	condicion = (1 != 1) ;
	condicion = (1 > 2) ;		// comparación de mayor que

	// OPERADORES LÓGICOS
	// ----------------------------------------
	// && Y (AND)
	// || O (OR)
	// ! Negación (NOT)

	condicion = (v1 != v2 && v1>=v2) ;
	bool negacion = !condicion ;
	negacion = !negacion ;

	// OPERADOR TERNARIO
	// ----------------------------------------
	// ?
	//
	// (condición) ? (acción si es correcto) : (acción si es falso)

	v1 = 1 ;
	v2 = 2 ;
	condicion = v1 > v2 ? true : false ;
	resultado = v1 > v2 ? 1000 : 2000 ;


	// OPERADORES A NIVEL DE BIT
	// ----------------------------------------
	// & : AND
	// | : OR
	// ^ : XOR
	// ~ : NOT
	// << : Shift left
	// >> : Shift right

	char valor = 179 ;
	char mascara = 16 ;
	char bitRes = valor & mascara ;

	cout << bitRes << endl ;


	// CONVERSIONES
	// ----------------------------------------
	// Usualmente se les llama "casting"
	// para convertir un tipo en otro debemos usar el nombre del tipo a convertir antes de la variable
	// float x = 1.1 ;
	// int y = (int) x ;
	// hemos realizado un casting de x: hemos convertido el valor de x (float) a entero y lo hemos guardado en la variable y.

	int var1 = 0 ;
	float var2 = 3.14 ;
	short var3 = 0 ;
	char var4 = 0 ;

	var1 = (int) var2 ;
	var3 = (short) var2 ;
	var4 = (char) var2 ;

	cout << "CONVERSION 1 : " << var1 << endl ;
	cout << "CONVERSION 2 : " << var3 << endl ;
	cout << "CONVERSION 3 : " << (int) var4 << endl ;

	// ante la duda sobre el tamaño de un tipo podemos usar la función sizeof

	cout << "Tamaño de var1: " << sizeof(var1) << endl ;
	cout << "Tamaño de var2: " << sizeof(var2) << endl ;
	cout << "Tamaño de var3: " << sizeof(var3) << endl ;
	cout << "Tamaño de var4: " << sizeof(var4) << endl ;

	// cuidado con la conversión automática de tipos.
	// si queremos trabajar con numeros reales debemos usar siempre la parte decimal.
	float var5 = 1.0 + 2.0 * 3.0 / 4.0 - 5.0 ;
	int var6 = 1 + 2 * 3 / 4 - 5 ;
	float var7 = 1 + 2 * 3 / 4 - 5 ;
	float var8 = 3 ;

	cout << "RES: " << var5 << endl ;
	cout << "RES: " << var6 << endl ;
	cout << "RES: " << var7 << endl ;
	cout << "RES:" << var8 << endl ;

	// PREDECENDIA DE OPERADORES
	// ----------------------------------------
	// No todos los operadores tienen la misma prioridad, debemos consultar su precedencia para realizar correctamente cálculos.
	// CUANDO HAYA DUDA: USAD PARÉNTESIS!!!!!!

	// como podemos comprobar si quitamos los paréntesis el resultado es muy distinto.
	int var9 = (1 + 2) * (3 - 4) * (5 - 6) ;

	cout << "RES:" << var9 << endl ;

	// Todo programa que termina correctamente debe informar al sistema devolviendo un ZERO (return 0;)
	return 0;
}


