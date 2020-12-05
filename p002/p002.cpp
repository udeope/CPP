//============================================================================
// Name        : p002.cpp
// Author      : crt
// Version     : 1.0
// Copyright   : Your copyright notice
// Fecha       : 20/01/2020
// Description : Programa para trabajar funciones de entrada y salida
//				cin - para entradas por teclado
//				cout - para salidas por pantalla
//============================================================================

// incluimos la librería de entrada salida
#include <iostream>
// inlcluimos la librería matemática para poder realizar algunos cálculos
#include <math.h>

using namespace std;

int main()
{
	// 1 - cálculo del area de un triángulo

	// declaración de variables locales (las inicializamos a cero)
	float area = 0.0 ;
	float base = 0.0 ;
	float altura = 0.0 ;

	cout << "Base del triángulo: " ;			// imprimimos por pantalla para solicitar la base
	cin >> base ;								// recogemos el valor de la base desde teclado y lo guardamos en la variable base

	cout << "Altura del triángulo: " ;			// imprimimos por pantalla para solicitar la altura
	cin >> altura ;								// recogemos el valor de la altura desde teclado y lo guardamos en la variable altura

	area = base * altura / 2.0 ;				// aplicamos la fórmula del area del triángulo (Base * Altura) / 2.0
	cout << "Área: " << area << endl << endl ;	// mostramos el resultado por pantalla.


	// 2 - cálculo de las soluciones de una ecuacion de segundo grado

	// decalaración de variables locales (las inicializamos a cero)
	float a = 0.0 ;
	float b = 0.0 ;
	float c = 0.0 ;
	float res1 = 0.0 ;
	float res2 = 0.0 ;

	// imprimimos en pantalla un mensaje de inicio
	cout << " ***** EQUACIÓN DE SEGUNDO GRADO ******" << endl ;
	cout << "             ax2 + bx + c = 0 " << endl << endl ;

	// pedimos el valor de a
	cout << "Valor del coeficiente 'a': " ;
	cin >> a ;

	// pedimos el valor de b
	cout << "Valor del coeficiente 'b': " ;
	cin >> b ;

	// pedimos el valor de c
	cout << "Valor del coeficiente 'c': " ;
	cin >> c ;

	// aplicamos la fórmula para la primera solución de la ecuación
	res1 = (-b + sqrt(b*b - 4.0 * a * c ))/(2.0 * a) ;

	// aplicamos la fórmula para la segunda solución de la ecuación
	res2 = (-b - sqrt(b*b - 4.0 * a * c ))/(2.0 * a) ;

	// ponemos un mensaje de confirmación del cálculo a realizar...
	cout << "Calculando las soluciones de " << a << "x2 + " << b << "x + " << c << endl ;

	// mostramos los resultados obtenidos
	cout << "x = " << res1 << endl ;
	cout << "x = " << res2 << endl ;

	// mostramos el fin del programa
	cout << "*** FIN ***" << endl ;


	return 0;
}
