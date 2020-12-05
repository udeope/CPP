//============================================================================
// Name        : p012.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// En este proyecto veremos todos los ejercicios del examen que requieren programación
// cada ejercicio tiene su propia función
// dado que se han explicado en detalle en clase, no hay más comentarios

void ejercicio3() ;
void ejercicio4() ;
void ejercicio6() ;
void ejercicio7() ;
void ejercicio8() ;
void ejercicio9() ;
int ejercicio10(int g, int e, int p) ;
bool ejercicio11(int val, float&, float&, bool&) ;
void ejercicio12() ;

void mostrarSaldo(const float&) ;
void retirar(float&) ;
void ingresar(float&) ;

int main()
{
	ejercicio12() ;


	return 0;
}

void ejercicio3()
{
	int n1 = 0 ;
	int n2 = 0 ;

	cin >> n1 ;
	cin >> n2 ;

	cout << "SUMA: " << n1 + n2 << endl ;
	cout << "RESTA: " << n1 - n2 << endl ;
	cout << "MULTI: " << n1 * n2 << endl ;
	cout << "DIV: " << n1 / (float) n2 << endl ;
	cout << "MOD: " << n1 % n2 << endl ;
}

void ejercicio4()
{
	int n1 = 0 ;
	bool div2 = false ;
	bool div3 = false ;

	cout << "Entra un número de 0 a 100: " << endl ;
	cin >> n1 ;


	// ? :   (con operador ternario)
	div2 = (n1 % 2) == 0 ? true : false ;
	div3 = (n1 % 3) == 0 ? true : false ;

	// if(n1 % 2 == 0 || n1 % 3 == 0)
	// if(div2 || div3 )
	if(div2 == true || div3 == true)
	{
		cout << "OK" << endl ;
	}
	else
	{
		cout << "NO OK" << endl ;
	}
}


void ejercicio6()
{
	unsigned short i = 0 ;

	do
	{
		cout << i << endl ;
		i = i + 1 ;
	} while(i <= 10) ;
}


void ejercicio7()
{
	for(short i = 10 ; i>= 0 ; i--)
	{
		cout << i << endl ;
	}
}

void ejercicio8()
{
	srand(time(NULL)) ;

	int val = 0 ;

	for(short i = 0 ; i < 10 ; i++)
	{
		val = rand() % 101 ;

		cout << val ;

		if(i < 9) cout << "," ;
		else cout << "." ;

		// alternativa con operador ternario
		// cout << (i<9) ? "," : "." ;
	}
}


void ejercicio9()
{
	srand(time(NULL)) ;
	cout << "[1] – Número de 0 a 9" << endl ;
	cout << "[2] – Número de 10 a 19" << endl ;
	cout << "[3] – Número de 20 a 29" << endl ;
	cout << "[4] – Número de 30 a 39" << endl ;
	cout << "[5] – Numero de 40 a 49" << endl ;
	cout << "Opción: " ;

	char opcion = '0' ;
	int val = rand() % 10 ;

	cin >> opcion ;

	switch(opcion)
	{
		default : cout << "Error" << endl ; break ;
		case '1' : break ;
		case '2' : val += 10 ; break ;
		case '3' : val += 20 ; break ;
		case '4' : val += 30 ; break ;
		case '5' : val += 40 ; break ;
	}

// opcion con un IF...
//	int opcion2 = 0 ;
//	cin >> opcion2 ;
//
//	if(opcion2 >= 1 && opcion2 <= 5)
//	{
//		val = val + ((opcion2-1) * 10) ;
//	}

	cout << "RES: " << val << endl ;
}

int ejercicio10(int ganados, int empatados, int perdidos)
{
	return (ganados * 3) + empatados ;
}


bool ejercicio11(int val, float& cuadrado, float& inverso, bool& div2)
{
	bool res = false ;

	if(val >= 0)
	{
		cuadrado = val * val ;
		div2 = (val % 2) == 0 ? true : false ;

		if(val ==0)
		{
			inverso = 1.0 / 0.0000001 ;
		}
		else
		{
			inverso = 1.0 / (float) val ;
		}

		res = true ;
	}
	else
	{
		cuadrado = 0.0 ;
		inverso = 0.0 ;
		div2 = false ;
	}

	return res ;
}


void ejercicio12()
{
	char opcion = ' ' ;
	float saldo = 1000.0 ;

	while(opcion != 'D')
	{
		cout << "A – Mostrar saldo" << endl ;
		cout << "B – Ingressar diners" << endl ;
		cout << "C – Treure diners" << endl ;
		cout << "D – Sortir" << endl ;

		cout << "Selección: " ;
		cin >> opcion ;

		switch(opcion)
		{
		case 'A' : mostrarSaldo(saldo) ; break ;
		case 'B' : ingresar(saldo) ; break ;
		case 'C' : retirar(saldo) ; break ;
		case 'D' :
			{
				cout << " Hasta pronto!" << endl ;
			} break ;
		default :
			{
				cout << "Opción incorrecta!" << endl ;
			}
		}

		cout << endl << endl ;

	}

}

void mostrarSaldo(const float& saldo)
{
	cout << "SALDO: " << saldo << endl ;
}

void retirar(float& saldo)
{
	float cantidad = 0.0 ;

	cout << "Cantidad a retirar: " << endl ;
	cin >> cantidad ;
	if(cantidad <= saldo)
		saldo = saldo - cantidad ;
	else
		cout << "Saldo insuficiente!" << endl ;
}

void ingresar(float& saldo)
{
	float cantidad = 0.0 ;

	cout << "Cantidad a ingresar: " << endl ;
	cin >> cantidad ;
	saldo = saldo + cantidad ;
}
