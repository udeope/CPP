//============================================================================
// Name        : p006.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Uso de SWITCH...CASE...DEFAULT .... BREAK y introducción a FUNCIONES
//============================================================================

// definición de PI
#define PI 3.14159

#include <iostream>
using namespace std;

// declaración de las funciones utilizadas.
// En C++ necesitmos declarar cualqueir cosa (función o variable) antes de usarla, así que las funciones las declaramos antes del main para poderlas usar dentro.
float areaCuadrado(float lado) ;
float areaTriangulo(float base, float altura) ;
float areaCirculo(float radio) ;
float areaRectangulo(float base, float altura) ;


int main()
{
	// variables locales inicializadas
	char seleccion = '0' ;
	bool continuar = true ;

	// mientras la varible booleana sea verdadera (true) ...
	while(continuar)
	{
		// imprimimosel menú de opciones...
		cout << "Qué figura quieres calcular ? " << endl ;
		cout << "   [1] - Cuadrado" << endl ;
		cout << "   [2] - Triángulo" << endl ;
		cout << "   [3] - Círculo" << endl ;
		cout << "   [4] - Rectángulo" << endl ;
		cout << "   [0] - Salir" << endl ;
		cout << "Opción: " ;

		// recogemos la selección por teclado...
		cin >> seleccion ;
		cout << endl ;

		// según sea la selección (variable seleccion de tipo char)...
		switch(seleccion)
		{
			case '0' :	// en caso de ser el 0
				{
					cout << ">>> Vuelve pronto!" << endl ;

					// continuar a false nos hará salir del bucle WHILE en la siguiente iteración...
					continuar = false ;
				} break ;

			case '1' :	// en caso de ser 1 ...
				{
					float lado = 0 ;
					float res = 0.0 ;
					cout << "Entra el lado del cuadrado: " << endl ;
					cin >> lado ;

					// llamamos a la función que calcua el área del cuadrado llamada areaCuadrado pasándole como parámetro el valor del lado del cuadrado
					// el resultado lo almacenamos en la varible local "res"
					res = areaCuadrado(lado) ;
					cout << "El área del cuadrado es: " << res << endl ;
				} break ;

			case '2' : // en caso de ser 2 ...
				{
					cout << ">>> Triángulo: Area = base * altura / 2" << endl << endl ;
					float base = 0 ;
					float altura = 0 ;
					float res = 0.0 ;

					cout << "Entra la base del triángulo: " << endl ;
					cin >> base ;
					cout << "Entra la altura del triángulo: " << endl ;
					cin >> altura ;

					// llamamos a la función que calcua el área del triángulo llamada areaTraingulo pasándole como parámetro el valor de la base y la altura
					// el resultado lo almacenamos en la varible local "res"
					res = areaTriangulo(base, altura) ;
					cout << "El área del triángulo es: " << res << endl ;
				} break ;

			case '3' : // en caso de ser 3 ...
				{
					cout << ">>> Círculo: Area = PI * radio * radio" << endl << endl ;
					float radio = 0 ;
					float res = 0.0 ;
					cout << "Entra el radio del círculo: " << endl ;
					cin >> radio ;
					res = areaCirculo(radio) ;
					cout << "El área del círculo es: " << res << endl ;
				} break ;

			case '4' : // en caso de ser 4 ...
				{
					cout << ">>> Rectángulo: Area = base * altura" << endl << endl ;
					float base = 0 ;
					float altura = 0 ;
					float res = 0.0 ;

					cout << "Entra la base del Rectángulo: " << endl ;
					cin >> base ;
					cout << "Entra la altura del Rectángulo: " << endl ;
					cin >> altura ;

					res = areaRectangulo(base, altura) ;
					cout << "El área del Rectángulo es: " << res << endl ;
				} break ;

			default: cout << ">>> Selección incorrecta..." << endl << endl ; break ;
		}


		cout << "Pulsa ENTER para continuar..." << endl ;
		getchar() ;
		getchar() ;

	}

	return 0;
}


// -------------------------------------------------------------
// Función: areaCuadrado
// Descripción: calcula el área de un cuadrado
// Parámetros:
//	- lado: lado
// Salida:
// - Área del cuadrado
// --------------------------------------------------------------------
float areaCuadrado(float lado)
{
	return lado * lado ;
}

// -------------------------------------------------------------
// Función: areaTriangulo
// Descripción: calcula el área de un triángulo
// Parámetros:
//	- base: base
//	- altura : altura
// Salida:
// - Área del triángulo
// --------------------------------------------------------------------
float areaTriangulo(float base, float altura)
{
	return base * altura / 2.0 ;
}

// -------------------------------------------------------------
// Función: areaCirculo
// Descripción: calcula el área de un círculo
// Parámetros:
//	- radio: radio del círculo
// Salida:
// - Área del círculo
// --------------------------------------------------------------------
float areaCirculo(float radio)
{
	return PI * radio * radio ;
}


// -------------------------------------------------------------
// Función: areaRectangulo
// Descripción: calcula el área de un rectángulo
// Parámetros:
//	- base: base
//	- altura : altura
// Salida:
// - Área del rectángulo
// --------------------------------------------------------------------
float areaRectangulo(float base, float altura)
{
	return base * altura ;
}














