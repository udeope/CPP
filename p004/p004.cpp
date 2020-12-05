//============================================================================
// Name        : p004.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Uso del WHILE(...) realizamos el mismo programa que en p003
//					incorporando el uso del WHILE que nos permitirá seguir usando
//					el programa hasta pulsar la opción de salida.
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	// declaración y inicialización de variables locales
	float base = 0.0 ;
	float altura = 0.0 ;
	float lado = 0.0 ;
	float area = 0.0 ;
	int opcion = 0 ;


	// while -> mientras se cumpla la condición (opcion diferente de 3)
	while(opcion != 3)
	{
		// imprimimos el menú por pantalla...
		cout << "[1] - Área del cuadrado" << endl ;
		cout << "[2] - Área del triángulo" << endl ;
		cout << "[3] - Salir" << endl ;
		cout << " Opción? " ;

		// recogemos la opción del usuario por teclado y la guardamos en la variable opcion.
		cin >> opcion ;

		// si la opción igual a 1 (operador de comparación de igualdad ==)
		if(opcion == 1)
		{
			// FIGURA CUADRADO
			cout << " --- CÁLCULO DEL AREA DE UN CUADRADO ---" << endl ;
			cout << "Valor del lado: " ;
			cin >> lado ;
			area = lado * lado ;
			cout << "Area = " << area << endl << endl ;
		}
		else
		{
			// si la opción es 2...
			if(opcion == 2)
			{
				// FIGURA TRIÁNGULO
				cout << " --- CÁLCULO DEL AREA DE UN TRIÁNGULO ---" << endl ;
				cout << "Valor de la base: " ;
				cin >> base ;
				cout << "Valor de la altura: " ;
				cin >> altura ;
				area = base * altura / 2.0 ;
				cout << "Area = " << area << endl << endl ;
			}
			else
			{
				//  si la opción es 3...
				if(opcion == 3)
				{
					cout << "Bye bye!" << endl ;
				}
				else // si la opción es diferente de 1, 2 y 3...
				{
					cout << "Opción incorrecta... empezamos de nuevo!" << endl << endl ;

					// realizando un clear() y un ignore() de cin. Esto es: vaciamos la entrada de teclado y lo volvemos a dejar a cero.
					cin.clear() ;
					cin.ignore() ;
				}
			}
		}
	}
}
