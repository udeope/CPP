//============================================================================
// Name        : p033.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// control de excepciones:
// - bloque: try {}
// - bloque: catch() {}
// - throw()




#include <iostream>
#include <vector>

#include "BD.h"
#include "BDException.h"

using namespace std ;

class exCESF : public exception
{
	string mensaje_ ;

	const string& getMensaje() const { return mensaje_ ; }
	void setMensaje(const string& error) { mensaje_ = error ; }

public:
	exCESF(const string& error) { setMensaje(error) ; }
	virtual ~exCESF() {}

	const char* what() const throw() { return getMensaje().c_str() ; }
};


// main1 --> demostración del uso de try/catch/throw
int main1()
{
	vector<int> v(5) ;



	try
	{
		// cout << "Leo la posición 0: " << v.at(0) << endl ;
		// cout << "Leo la posición 10: " << v.at(10) << endl ;
		// cout << "Todo ha ido bien!" << endl ;

		cout << "VAMOS A DIVIDIR!" << endl ;
		float x = 0.0 ;
		float y = 0.0 ;
		float z = 0.0 ;

		cout << "Entra numerador: " << endl ;
		cin >> x ;
		cout << "Entra denominador: " << endl ;
		cin >> y ;


		if(y == 0.0)
		{
			// int eint = 0 ;
			// throw(eint) ;			// esto lanza una excepción de tipo (int)
			exCESF ex1("División por cero!!!!!!!") ;
			throw(ex1) ;
		}

		z = x/y ;

		cout << "Resultado: " << z << endl ;

	}
	catch(const exCESF& e1)
	{
		// Aquí tratamos la situación excepcional (de tipo exCESF)
		cout << e1.what() << endl ;
	}
	catch(const exception& e2)
	{
		// Aquí tratamos la situación excepcional (de tipo exception)
		cout << "Error STL: " << e2.what() << endl ;
	}
	catch(int i)
	{
		// Aquí tratamos la situación excepcional (de tipo int)
		cout << "Excepcion de entero - denominador: " << i << endl ;
	}
	catch(...)
	{
		// Aquí tratamos la situación excepcional (cualquiera que no haya sido cazada antes)
		cout << "Error inesperado, cerrando programa..." << endl ;
	}

	cout << "SALIENDO DEL PROGRAMA..." << endl ;

	return 0 ;
}




// main para demostración de uso de clase de excepción para el caso de tratamiento de
//	excepciones en una base de datos MySQL
int main()
{
	BD* mysqldb = nullptr ;

	try
	{
		mysqldb = (BD*)new BD("root","123","localhost","Universitat") ;

		bool res = mysqldb->ejecutaQuery("SELE aid, nombre, tel FROM Alumno") ;

		if(res) mysqldb->listaResultado(14) ;
	}
	catch(const BDException& e)
	{
		cout << "Error con MySQL: " << e.queHaPasado() << endl ;
	}
	catch(...)
	{
		cout << "Error inesperado!" << endl ;
	}

	cout << "Saliendo..." << endl ;

	if(mysqldb != nullptr)
	{
		delete mysqldb ;
		mysqldb = nullptr ;
	}

	return 0;
}
