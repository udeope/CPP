//============================================================================
// Name        : p003.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Uso del IF ... ELSE
//============================================================================

// librería de entrada/salida (uso de cin, cout)
#include <iostream>
using namespace std;

int main()
{
	// declaración y inicialización de variables locales
	float base = 0.0 ;
	float altura = 0.0 ;
	float lado = 0.0 ;
	float area = 0.0 ;
	int figura = 0 ;

	// imprimimos por pantalla...
	cout << "Quieres calcular el área de un [1] cuadradro o de [2] un triángulo? " ;
	// esperamos una entrada de teclado
	cin >> figura ;

	// en la variable figura (tipo int) guardamos el valor de respuesta por teclado

	// si la elección ha sido 1 (usamos el operador de comparación de igualdad ==
	if(figura == 1)
	{
		// FIGURA CUADRADO
		cout << " --- CÁLCULO DEL AREA DE UN CUADRADO ---" << endl ;
		cout << "Valor del lado: " ;
		cin >> lado ;

		// realizamos el cálculo del área (base x altura) y guardamos el resultado en la variable local area.
		area = lado * lado ;
		cout << "Area = " << area << endl ;
	}
	else	// si el valor es distinto de 1...
	{
		// si el valor es 2...
		if(figura == 2)
		{
			// FIGURA TRIÁNGULO
			cout << " --- CÁLCULO DEL AREA DE UN TRIÁNGULO ---" << endl ;
			cout << "Valor de la base: " ;
			cin >> base ;
			cout << "Valor de la altura: " ;
			cin >> altura ;

			// realizamos el cálculo del área (base x altur / 2) Cuadado que si queremos precisión decimal debemos dividir por 2.0 (no por 2!)
			area = base * altura / 2.0 ;
			cout << "Area = " << area << endl ;
		}
		else // si es distinto de 2 (y obviamente distinto de 1)
		{
			cout << "Opción incorrecta!!!!!" << endl ;
		}
	}





	return 0;
}
