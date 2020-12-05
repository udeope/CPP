//============================================================================
// Name        : p020.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Ficha.h"
#include <unistd.h>
#include <iostream>
using namespace std;

#define SLEEP 1

void printTablero() ;

Ficha* tablero[POSICIONES] ;

// MAIN CON FICHAS EN ESTÁTICO (STACK)
int main2()
{
	// 1. inicializar el tablero (poner todos los punteros a nullptr)

	for(int i = 0 ; i < POSICIONES ; i++)
	{
		tablero[i] = nullptr ;
	}

	// 2. Creamos ficha A con posicion 0

	Ficha A(5,4,3,1,1,0,JUGADOR_1) ;

	// 3. Cramos ficha B con posición 19
	Ficha B(5,4,3,1,1,POSICIONES-1,JUGADOR_2) ;

	// 4. Insertamos A en tablero y B en tablero
	tablero[A.getPosicion()] = &A ;
	tablero[B.getPosicion()] = &B ;

	printTablero() ;

	bool fin = false ;
	bool choque = false ;
	uchar vidaA = 0 ;
	uchar vidaB = 0 ;

	// 5. Bucle sleep(1) donde en cada bucle:
	while(!fin)
	{
		// 5.1 movemos fichas (si se puede)
		uchar posA2 = A.getPosicion() + A.getVelocidad() ;
		uchar posB2 = B.getPosicion() - B.getVelocidad() ;

		if(posA2 < posB2)
		{
			// quitamos las fichas del tablero
			tablero[A.getPosicion()] = nullptr ;
			tablero[B.getPosicion()] = nullptr ;

			// asignamos su nueva posición
			A.setPosicion(posA2) ;
			B.setPosicion(posB2) ;

			// ponemos de nuevo las fichas en el tablero
			tablero[A.getPosicion()] = &A ;
			tablero[B.getPosicion()] = &B ;

		}
		else
		{
			choque = true ;
		}

		// 5.2 generamos ataques de A y de B (si están en rango)
		if(A.atacable(B))
		{
			cout << "A ataca a B " << endl ;
			A.ataque(B) ;
		}

		if(B.atacable(A))
		{
			cout << "B ataca a A " << endl ;
			B.ataque(A) ;
		}

		// 5.3 comprobamos la vida de A y B --> Cuando una muera gana la otra y finalizamos
		if(A.getVida() == 0 && B.getVida() == 0)
		{
			fin = true ;
			cout << "EMPATE!" << endl ;
		}
		else if(A.getVida() == 0)
		{
			fin = true ;
			cout << "GANA FICHA B!" << endl ;
		}
		else if(B.getVida() == 0)
		{
			fin = true ;
			cout << "GANA FICHA A!" << endl ;
		}

		if(choque)
		{
			if(vidaA == A.getVida() && vidaB == B.getVida())
			{
				fin = true ;
				cout << "EMPATE!" << endl ;
			}
			else
			{
				vidaA = A.getVida() ;
				vidaB = B.getVida() ;
			}
		}

		printTablero() ;

		sleep(SLEEP) ;

	}
























//	uchar posA = 5 ;
//	uchar posB = 10 ;
//	Ficha A(7,4,3,2,1,posA,JUGADOR_1) ;
//	Ficha B(6,4,2,1,1,posB,JUGADOR_2) ;
//
//	A.dump() ;
//	B.dump() ;
//
//	if(A.atacable(B))
//	{
//		cout << "Generando ataque contra B!" << endl ;
//		A.ataque(B) ;
//	}
//	else
//	{
//		cout << "B no está en el rango de ataque de A" << endl ;
//	}
//
//	A.dump() ;
//	B.dump() ;





	return 0;
}

// MAIN CON FICHAS EN DINÁMICO (HEAP)
int main()
{
	// 1. inicializar el tablero (poner todos los punteros a nullptr)

	for(int i = 0 ; i < POSICIONES ; i++)
	{
		tablero[i] = nullptr ;
	}

	// 2. Creamos ficha A con posicion 0
	Ficha *ptrA = (Ficha *) new Ficha(9,4,3,1,1,0,JUGADOR_1) ;

	// 3. Cramos ficha B con posición 19
	Ficha* ptrB = (Ficha *) new Ficha(5,4,3,2,2,POSICIONES-1,JUGADOR_2) ;

	// 4. Insertamos A en tablero y B en tablero
	tablero[ptrA->getPosicion()] = ptrA ;
	tablero[ptrB->getPosicion()] = ptrB ;

	printTablero() ;

	bool fin = false ;
	bool choque = false ;
	uchar vidaA = 0 ;
	uchar vidaB = 0 ;

	// 5. Bucle sleep(1) donde en cada bucle:
	while(!fin)
	{
		// 5.1 movemos fichas (si se puede)
		uchar posA2 = ptrA->getPosicion() + ptrA->getVelocidad() ;
		uchar posB2 = ptrB->getPosicion() - ptrB->getVelocidad() ;

		if(posA2 < posB2)
		{
			// quitamos las fichas del tablero
			tablero[ptrA->getPosicion()] = nullptr ;
			tablero[ptrB->getPosicion()] = nullptr ;

			// asignamos su nueva posición
			ptrA->setPosicion(posA2) ;
			ptrB->setPosicion(posB2) ;

			// ponemos de nuevo las fichas en el tablero
			tablero[ptrA->getPosicion()] = ptrA ;
			tablero[ptrB->getPosicion()] = ptrB ;

		}
		else
		{
			choque = true ;
		}

		// 5.2 generamos ataques de A y de B (si están en rango)
		if(ptrA->atacable(*ptrB))
		{
			cout << "A ataca a B " << endl ;
			ptrA->ataque(*ptrB) ;
		}

		if(ptrB->atacable(*ptrA))
		{
			cout << "B ataca a A " << endl ;
			ptrB->ataque(*ptrA) ;
		}

		// 5.3 comprobamos la vida de A y B --> Cuando una muera gana la otra y finalizamos
		if(ptrA->getVida() == 0 && ptrB->getVida() == 0)
		{
			fin = true ;
			cout << "EMPATE!" << endl ;
		}
		else if(ptrA->getVida() == 0)
		{
			fin = true ;
			cout << "GANA FICHA B!" << endl ;
		}
		else if(ptrB->getVida() == 0)
		{
			fin = true ;
			cout << "GANA FICHA A!" << endl ;
		}

		if(choque)
		{
			if(vidaA == ptrA->getVida() && vidaB == ptrB->getVida())
			{
				fin = true ;
				cout << "EMPATE (por choque eterno)!" << endl ;
			}
			else
			{
				vidaA = ptrA->getVida() ;
				vidaB = ptrB->getVida() ;
			}
		}

		printTablero() ;

		sleep(SLEEP) ;

	}

	if(ptrA != nullptr)
	{
		delete ptrA ;
		ptrA = nullptr ;
	}

	if(ptrB != nullptr)
	{
		delete ptrB ;
		ptrB = nullptr ;
	}























//	uchar posA = 5 ;
//	uchar posB = 10 ;
//	Ficha A(7,4,3,2,1,posA,JUGADOR_1) ;
//	Ficha B(6,4,2,1,1,posB,JUGADOR_2) ;
//
//	A.dump() ;
//	ptrB->dump() ;
//
//	if(A.atacable(B))
//	{
//		cout << "Generando ataque contra B!" << endl ;
//		A.ataque(B) ;
//	}
//	else
//	{
//		cout << "B no está en el rango de ataque de A" << endl ;
//	}
//
//	A.dump() ;
//	ptrB->dump() ;





	return 0;
}






void printTablero()
{
	for(int i = 0 ; i < POSICIONES ; i++)
	{
		if(tablero[i] != nullptr)
		{
			if(tablero[i]->getJugador() == JUGADOR_1 ) cout << "|A" ;
			else cout << "|B" ;
		}
		else
		{
			cout << "| " ;
		}
	}
	cout << endl ;
}


