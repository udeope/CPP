//============================================================================
// Name        : p005.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Uso de las sentencias DO... WHILE, FOR(...) con BREAK y CONTINUE
//============================================================================

// Definición de constantes de preprocesador. No se consideran constantes de lenguaje sino valores que se sustituirán
//	en el código antes de la compilación
#define LIMITE_CONTADOR 100
#define DIVISOR_MODULO  3

#define LIMITE_NUM_ALEATORIO 10
#define LIMITE_INTENTOS 20

#include <stdlib.h>			// librería que necesitamos para usar la variable aleatoria
#include <time.h>			// librería que necesitamos para usar la función de tiempo que inicializa la variable aleatoria
#include <iostream>
using namespace std;

// Constante global. Esta sí que es una variable constante.
// Es global por qué está declarada fuera de todo ámbito
const int miLimite = 100 ;


// Función principal del sistema
int main()
{
	// Inicialización de la variable aleatoria mediante el tiempo.
	// Sólo se inicializa al principio del programa
	srand(time(NULL)) ;


	// declaración de variable entera local inicializada a cero
	int contador = 0 ;



	// BUCLE DO...WHILE
	// al menos se ejecuta una vez el cuerpo del bucle

	// usaremos el operador aritmético Módulo (significa resto de la división) por ejemplo 6 % 4 = 2 ( el resto de dividir 6 entre 4 es 2).

	do
	{
		// Si la variable contador es divisible por dos...
		if(contador % DIVISOR_MODULO == 0)
		{
			// imprimimos por pantalla el valor de la variable
			cout << contador << endl ;
		}

		// la incrementamos en uno (contador = contador + 1 ;)
		contador ++ ;

		// esto va a seguir en bucle mientras contador sea menor o igual que 100
	} while (contador <= LIMITE_CONTADOR) ;


	// BUCLE FOR
	// desde i = 0, mientras i sea menor o igual que 100, i = i + 1
	// este primer FOR contará de 0 a 100

	for(int i = 0 ; i <= LIMITE_CONTADOR ; i++)
	{
		// imprimimos el valor de i
		cout << i << endl ;
	}

	// en este caso decrementamos la variable i, por tanto:
	// en este segundo FOR contará de 100 a 0
	for(int i = LIMITE_CONTADOR ; i >= 0 ; i--)
	{
		cout << i << endl ;
	}

	// Realizamos el conteo de 0 a 100 y de 100 a 0 en un único FOR
	// lo conseguimos contando de 0 a 200 pero realizaramos una comparación con dos IFs
	for(int i = 0 ; i <= LIMITE_CONTADOR * 2 ; i++ )
	{
		// si el número es infoerior o igual a 100 imprimimos el número
		if(i <= LIMITE_CONTADOR)
		{
			cout << i << endl ;
		}

		// si el número es superior o igual a 100 imprimiremos la cuenta atrás
		if(i >= LIMITE_CONTADOR)
		{
			cout << LIMITE_CONTADOR - (i - LIMITE_CONTADOR) << endl ;
		}
	}

	// ADIVINAR UN NUMERO
	// realizamos ahora un programa que intentará adivinar un número que previamente habremos introducido.


	// declaracióin de variables locales y inicialización
	unsigned short num = 0 ;
	int alea = 0 ;
	char val = ' ' ;
	bool adivinado = false ;

	// imprimimos en pantalla ...
	cout << endl << endl << endl ;
	cout << " Dime el número que quieres que adivine entre 0 y " << LIMITE_NUM_ALEATORIO << ": " ;

	// y guardamos la respuesta en la variable num
	cin >> num ;

	// la máquina intentará fins a 20 intents (LIMITE_INTENTOS=
	for(int i = 0 ; i < LIMITE_INTENTOS ; i++)
	{
		// generamos un número aleatorio entre 0 y 10. Para ello usamos el módulo 11.
		// qualquier número dividido por 11 tendrá un resto entre 0 y 10.
		// la función rand() genera un número aleatorio.
		alea = rand() % 11 ;

		// preguntamos al usuario si el número es el calculado "alea"
		cout << "[" << i << "] Es el número " << alea << " ? " ;

		// y recogemos el valor por teclado (s/n)
		cin >> val ;

		// si el valor es 's' o 'S', que indica que sí...
		if(val == 's' || val == 'S')
		{
			// ponemos la variable local "adivinado" a true (verdad)
			adivinado = true ;

			// imprimimos por pantalla que hemos adivinado
			cout << "Lo adiviné!" << endl ;

			// hacemos un break: que nos hará salir del FOR
			break ;

			// también podríamos asignar la variable i a 20 para forzar a salir del FOR
			//i = LIMITE_INTENTOS ;
		}
	}

	// una vez fuera del FOR nos preguntamos si hemos adivinado o no
	if(adivinado == false)
	{
		// en ese caso imprimiremos que no hemos podido acertar.
		cout << "No lo he adivinado, has ganado!" << endl ;
	}

	// FOR ANIDADO
	// Ejemplo de for anidado con una sentencia CONTINUE
	// En este caso cuando j es 5 saltaremos a la siguiente iteración sin terminar el bucle
	// por tanto la salida será...
	//[0][0]
	//[0][1]
	//[0][2]
	//[0][3]
	//[0][4]
	//[0][6] << ---- Nos hemos saltado el 5...


	for(int i = 0 ; i < 10 ; i++)
	{
		for(int j = 0 ; j < 10 ; j++ )
		{
			if(j == 5) continue ;
			cout << "[" << i << "][" << j << "]" << endl ;
		}
	}








	return 0 ;
}
