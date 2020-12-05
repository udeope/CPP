//============================================================================
// Name        : p028.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Universidad.h"

typedef enum MenuPrincipal { CARRERA = 0, PROFESOR = 1, ALUMNO = 2, SALIR = 9 } MenuPrincipal ;
typedef enum MenuCarrera { CARRERA_VER= 0, CARRERA_CREAR = 1, CARRERA_SALIR = 9 } MenuCarrera ;
typedef enum MenuProfesor{ PROFESOR_VER= 0, PROFESOR_CREAR = 1, PROFESOR_VINCULAR=2, PROFESOR_DETALLES=3, PROFESOR_SALIR = 9 } MenuProfesor ;
typedef enum MenuAlumno{ ALUMNO_VER= 0, ALUMNO_CREAR = 1, ALUMNO_MATRICULAR = 2, ALUMNO_SALIR = 9 } MenuAlumno ;


MenuPrincipal menu1() ;

void menuCarrera() ;
void crearCarrera() ;

void menuProfesor() ;
void crearProfesor() ;
void vincularProfesor() ;
void detallesProfesor() ;


void menuAlumno() ;
void crearAlumno() ;
void matricularAlumno() ;


Universidad uni ;

int main()
{
	bool bOk = false ;
	MenuPrincipal menu ;

	while(!bOk)
	{
		menu = menu1() ;

		switch(menu)
		{
		case CARRERA : menuCarrera() ; break ;
		case PROFESOR : menuProfesor() ; break ;
		case ALUMNO : menuAlumno() ; break ;
		case SALIR : bOk = true ; break ;
		}
	}


	cout << endl << "HASTA PRONTO!" << endl ;

	return 0;
}


MenuPrincipal menu1()
{
	bool bOk = false ;
	char seleccion = ' ' ;
	MenuPrincipal menu = SALIR ;

	while(!bOk)
	{
		std::system("clear") ;
		cout << " ------ PRINCIPAL -------" << endl << endl ;
		cout << " [1] - Carreras" << endl ;
		cout << " [2] - Profesores" << endl ;
		cout << " [3] - Alumnos" << endl ;
		cout << " [Q] - Salir" << endl ;
		cout << endl << "Selección: " ;
		cin >> seleccion ;

		switch(seleccion)
		{
			case '1' : menu = CARRERA ; bOk = true ; break ;
			case '2' : menu = PROFESOR ; bOk = true ; break ;
			case '3' : menu = ALUMNO ; bOk = true ; break ;
			case 'Q' : menu = SALIR ; bOk = true ; break ;
		}
	}

	return menu ;

}



void menuCarrera()
{
	bool bOk = false ;
	char seleccion = ' ' ;
	MenuCarrera menu = CARRERA_SALIR ;

	while(!bOk)
	{
		std::system("clear") ;
		cout << " ------ CARRERAS -------" << endl << endl ;
		cout << " [1] - Ver carrares" << endl ;
		cout << " [2] - Crear carrera/promoción" << endl ;
		cout << " [Q] - Salir" << endl ;
		cout << endl << "Selección: " ;
		cin >> seleccion ;

		switch(seleccion)
		{
			case '1' :
			{
				menu = CARRERA_VER ;
				uni.dumpCarreras() ;
				bOk = true ;
			} break ;
			case '2' :
			{
				menu = CARRERA_CREAR ;
				crearCarrera() ;
				bOk = true ;
				break ;
			}
			case 'Q' : menu = CARRERA_SALIR ; bOk = true ; break ;
		}
	}

	char s ;
	cin >> s ;

}



void menuProfesor()
{
	bool bOk = false ;
	char seleccion = ' ' ;
	MenuProfesor menu = PROFESOR_SALIR ;

	while(!bOk)
	{
		std::system("clear") ;
		cout << " ------ PROFESORES -------" << endl << endl ;
		cout << " [1] - Ver profesores" << endl ;
		cout << " [2] - Registrar profesor" << endl ;
		cout << " [3] - Vincular profesor a carrera" << endl ;
		cout << " [4] - Detalles de profesor" << endl ;
		cout << " [Q] - Salir" << endl ;
		cout << endl << "Selección: " ;
		cin >> seleccion ;

		switch(seleccion)
		{
			case '1' :
			{
				uni.dumpProfesores() ;
				menu = PROFESOR_VER ;
				bOk = true ;
			} break ;
			case '2' :
			{
				crearProfesor() ;
				menu = PROFESOR_CREAR ;
				bOk = true ;
			} break ;
			case '3' :
			{
				vincularProfesor() ;
				menu = PROFESOR_VINCULAR ;
				bOk = true ;
			} break ;
			case '4' :
			{
				detallesProfesor() ;
				menu = PROFESOR_DETALLES ;
				bOk = true ;
			} break ;
			case 'Q' : menu = PROFESOR_SALIR ; bOk = true ; break ;
		}
	}

	char s ;
	cin >> s ;
}



void menuAlumno()
{
	bool bOk = false ;
	char seleccion = ' ' ;
	MenuAlumno menu = ALUMNO_SALIR ;

	while(!bOk)
	{
		cout << " ------ ALUMNOS -------" << endl << endl ;
		std::system("clear") ;
		cout << " [1] - Ver alumnos" << endl ;
		cout << " [2] - Registrar alumno" << endl ;
		cout << " [3] - Matricular alumno" << endl ;
		cout << " [Q] - Salir" << endl ;
		cout << endl << "Selección: " ;
		cin >> seleccion ;

		switch(seleccion)
		{
			case '1' :
			{
				uni.dumpAlumnos() ;
				menu = ALUMNO_VER ;
				bOk = true ;
			} break ;
			case '2' :
			{
				crearAlumno() ;
				menu = ALUMNO_CREAR ;
				bOk = true ;
			} break ;
			case '3' :
			{
				matricularAlumno() ;
				menu = ALUMNO_MATRICULAR ;
				bOk = true ;
			} break ;
			case 'Q' : menu = ALUMNO_SALIR ; bOk = true ; break ;
		}
	}

	char s ;
	cin >> s ;

}


void crearCarrera()
{
	string estudios ;
	string promocion ;

	cout << " Estudios: " ;
	cin >> estudios ;
	cout << " Promoción: " ;
	cin >> promocion ;

	Carrera *c = uni.crearPromocion(promocion, estudios) ;
	if(c != nullptr)
	{
		cout << "Carrera creada con éxito!" << endl << endl ;
		c->dump() ;
	}
	else
	{
		cout << "La carrera no pudo crearse correctamente!" << endl << endl ;
	}

}

void crearProfesor()
{
	string nombre = "" ;
	float salario = 0.0 ;
	int carrera = 0 ;


	cout << " Nombre: " ;
	cin >> nombre ;
	cout << " Salario: " ;
	cin >> salario ;

	Profesor *p = uni.registrarProfesor(nombre, salario) ;
	if(p != nullptr)
	{
		cout << "Profesor creado con éxito!" << endl << endl ;
		p->dump() ;
	}
	else
	{
		cout << "La carrera no pudo crearse correctamente!" << endl << endl ;
	}

}


void crearAlumno()
{
	string nombre = "" ;

	cout << " Nombre: " ;
	cin >> nombre ;

	Alumno *al = uni.registrarAlumno(nombre) ;
	if(al != nullptr)
	{
		cout << "Alumno creado con éxito!" << endl << endl ;
		//al->dump() ;
	}
	else
	{
		cout << "El alumno no pudo crearse correctamente!" << endl << endl ;
	}

}

void matricularAlumno()
{
	unsigned int alumno = 0 ;
	unsigned int carrera = 0 ;


	uni.dumpAlumnos() ;
	cout << "Selecciona el nº de alumno: " ;
	cin >> alumno ;

	uni.dumpCarreras() ;
	cout << "Selecciona la carrera/promoción: " ;
	cin >> carrera ;

	Alumno* al = uni.getAlumno(alumno) ;
	Carrera* ca = uni.getCarrera(carrera) ;

	if(al != nullptr && ca != nullptr)
	{
		if(ca->matricula(al))
		{
			cout << "Alumno matriculado OK" << endl ;
		}
		else
		{
			cout << "No se ha podido matricular, curso lleno!" << endl ;
		}
	}
}


void vincularProfesor()
{
	unsigned int profesor = 0 ;
	unsigned int carrera = 0 ;


	uni.dumpProfesores() ;
	cout << "Selecciona el nº de profesor: " ;
	cin >> profesor ;

	uni.dumpCarreras() ;
	cout << "Selecciona la carrera/promoción: " ;
	cin >> carrera ;

	Profesor* pr = uni.getProfesor(profesor) ;
	Carrera* ca = uni.getCarrera(carrera) ;

	if(pr != nullptr && ca != nullptr)
	{
		if(pr->getCarrera() == nullptr)
		{
			if(ca->vincularProfesor(pr))
			{
				cout << "Profesor vinculado a carrera correctamente" << endl ;
			}
			else
			{
				cout << "No se pueden vincular más profesores a esta carrera" << endl ;
			}
		}
		else
		{
			cout << "El profesor ya está vinculado a otra carrera!" << endl ;
		}
	}
}


void detallesProfesor()
{
	unsigned int profesor = 0 ;


	uni.dumpProfesores() ;
	cout << "Selecciona el nº de profesor: " ;
	cin >> profesor ;

	Profesor* pr = uni.getProfesor(profesor) ;

	if(pr != nullptr)
	{
		pr->dump() ;
	}
	else
	{
		cout << "Profesor incorrecto" << endl ;
	}
}
