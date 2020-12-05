//============================================================================
// Name        : p029.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
//using namespace std ;





class Alumno
{
	std::string nombre_ ;
	int nota_ ;

public:
	Alumno() ;
	Alumno(const std::string&, int) ;
	Alumno(const Alumno&) ;
	virtual ~Alumno() ;
	Alumno& operator=(const Alumno&) ;

	void setNombre(const std::string& n) { nombre_ = n ; }
	void setNota(int n) { nota_ = n ; }
	const std::string& getNombre() const { return nombre_ ; }
	int getNota() const { return nota_ ; }

	std::string dump() const ;
};


Alumno::Alumno()
{
	nombre_ = "" ;
	nota_ = 0 ;
}

Alumno::Alumno(const std::string& n, int nt)
{
	nombre_ = n ;
	nota_ = nt ;
}

Alumno::Alumno(const Alumno& al)
{
	*this = al ;
}

Alumno::~Alumno()
{
}

Alumno& Alumno::operator=(const Alumno& al)
{
	setNombre(al.getNombre()) ;
	setNota(al.getNota()) ;

	return *this ;
}


std::string Alumno::dump() const
{
	std::string res ;
	std::stringstream ss ;

	ss << getNombre() << " - " << getNota() ;

	// Juan - 8

	res = ss.str() ;

	return res ;
}




void printVector(const std::vector<int>& vec) ;
void printVector(const std::vector<char>& vec) ;
void printVector(const std::vector<Alumno>& vec) ;
void printVector(const std::vector<Alumno*>& vec) ;

int main()
{
	std::cout << "PROGRAMA PARA USO DE STANDARD TEMPLATE LIBRARY" << std::endl ;

//	std::vector<Alumno*> listaAlumnos1 ;
//	std::vector<Alumno*> listaAlumnos2(3,nullptr) ;	// (null, null, null)
//	std::vector<Alumno> listaAlumno3 ;


	// iterador para vector de enteros
	std::vector<int>::iterator iterador ;

	// vector vacío
	std::vector<int> listaIntV1 ;

	// vector con N elementos iguales
	std::vector<int> listaIntV2(5,10) ;			// (10, 10, 10, 10, 10)


	// vector que se construye a partir de un array de ints
	int misNumeros[] = { 1, 1, 2, 3, 5, 8, 13 } ;
	std::vector<int> listaIntV3(misNumeros, misNumeros + sizeof(misNumeros) / sizeof(int)) ;



//  int listaInt[MAX] ;
//	for(int i = 0 ; i < MAX ; i++)
//	{
//		std::cout << listaInt[i] << std::endl ;
//	}

	for(iterador = listaIntV3.begin() ; iterador != listaIntV3.end() ; iterador++)
	{
		std::cout << *iterador << std::endl ;
	}


	// 2,3

	std::vector<int> listaIntV4(listaIntV3.begin()+2 , listaIntV3.end() - 3) ;


	for(iterador = listaIntV4.begin() ; iterador != listaIntV4.end() ; iterador++)
	{
		std::cout << *iterador << std::endl ;
	}


	// El vector tiene el operador de asignación implementado
	// Clase Canónica Ortodoxa
	// Cada copia del vector es una copia independiente

	std::cout << "Operador de asignación ..." << std::endl ;

	std::vector<int> vectorNuevo ;

	vectorNuevo = listaIntV4 ;	// asignación

	vectorNuevo.push_back(4) ;	// añadimos un elemento

	printVector(vectorNuevo) ;
	printVector(listaIntV4) ;



	Alumno al1("Juan", 8) ;
	Alumno al2("Maria", 9) ;
	Alumno al3("Jordi", 4) ;

	// Contenedor de objetos
	std::vector<Alumno> voAlumnos ;		// vector de objectos alumno

	voAlumnos.push_back(al1) ;
	voAlumnos.push_back(al2) ;
	voAlumnos.push_back(al3) ;


	al1.setNombre("Nuria") ;

	printVector(voAlumnos) ;

	al1.setNombre("Juan") ;

	// Contenedor de objetos
	std::vector<Alumno*> vpAlumnos ;	// vector de punteros a alumno
	std::vector<Alumno*> vpAlumnosCopia ;	// vector de punteros a alumno

	vpAlumnos.push_back(&al1) ;
	vpAlumnos.push_back(&al2) ;
	vpAlumnos.push_back(&al3) ;

	printVector(vpAlumnos) ;		// Juan ... Maria ... Jordi ...

	al1.setNombre("Nuria") ;

	printVector(vpAlumnos) ;		// Nuria ... Maria ... Jordi ...

	vpAlumnosCopia = vpAlumnos ;

	printVector(vpAlumnosCopia) ;		// Nuria ... Maria ... Jordi ...


	// función para acceder a un elemento concreto del vector

	// con un array sería...
	//int miArray[10] ;
	//std::cout << miArray[0] << std::endl ;

	// en STL ...
	// function at()
	// funcion operator[]

	std::cout << vpAlumnos[1]->dump() << std::endl ;
	std::cout << vpAlumnos.at(1)->dump() << std::endl ;


	// iteradores
	// begin() --> devuelve el iterador al primer elemento
	// end() --> devuelve el iterador al último elemento + 1
	// back()  --> devuelve el contenido del último elemento
	// front() --> devuelve el contenido del primer elemento
	// cbegin()
	// cend()
	// rbegin()
	// rend()
	// crbegin()
	// crend()

	std::cout << vpAlumnos.back()->dump() << std::endl ;
	std::cout << vpAlumnos.front()->dump() << std::endl ;

	std::vector<Alumno*>::iterator it ;

	it = vpAlumnos.begin() ;
	std::cout << (*it)->dump() << std::endl ;


	// tamaños
	// size() --> devuelve el número de elementos en el vector
	// capacity() --> el tamaño actual del vector

	std::cout << "Elementos en vector: " << vpAlumnos.size() << std::endl ;
	std::cout << "Tamaño del vector: " << vpAlumnos.capacity() << std::endl ;


	// eliminar todo el contenido del vector

	vpAlumnos.clear() ;

    // función para sabersi el vector está vacío
	// empty()

	bool vacio = false ;
	vacio = (vpAlumnos.begin() == vpAlumnos.end()) ;
	vacio = vpAlumnos.empty() ;


	// push_back() --> insertar al final del vector
	Alumno al4("Alberto", 10) ;
	vpAlumnos.push_back(&al4) ;

	// pop_back() --> elimina al final del vector (último)
	vpAlumnos.pop_back() ;

	// erase() --> borra elemento(s) del vector

	std::vector<Alumno*>::iterator it1 ;
	std::vector<Alumno*>::iterator it2 ;

	vpAlumnos.push_back(&al1) ;
	vpAlumnos.push_back(&al2) ;
	vpAlumnos.push_back(&al3) ;

	it1 = vpAlumnos.begin() ;
	it1 = it1 + 1 ;
	vpAlumnos.erase(it1) ;  // borrando a Maria

	printVector(vpAlumnos) ;	// Juan ... Jordi


	// [ A B C D E F G H ]

	std::vector<char> vChar ;
	std::vector<char>::iterator cit1 ;
	std::vector<char>::iterator cit2 ;
	vChar.push_back('A') ;
	vChar.push_back('B') ;
	vChar.push_back('C') ;
	vChar.push_back('D') ;
	vChar.push_back('E') ;
	vChar.push_back('F') ;
	vChar.push_back('G') ;
	vChar.push_back('H') ;

	printVector(vChar) ;

	cit1 = vChar.begin() + 2 ;
	cit2 = vChar.begin() + 6 ;
	vChar.erase(cit1, cit2) ;

	printVector(vChar) ;


	// eliminaría los alumnos desde  C, hasta F (incluida)
	// [A B G H]

	// insert() --> insertar un elemento dentro del vector
	// partimos de [A B G H]
	// vamos a insertar un elemento después de B, el Z

	cit1 = vChar.begin() + 2 ;
	vChar.insert(cit1, 'Z') ;

	printVector(vChar) ;


	// tendremos [A B Z G H]


	// swap() --> intercambia el contenidode vectores del mismo tipo

	std::vector<char> vChar2 ;
	vChar2.push_back('1') ;
	vChar2.push_back('2') ;
	vChar2.push_back('3') ;
	vChar2.push_back('4') ;
	vChar2.push_back('5') ;
	vChar2.push_back('6') ;
	vChar2.push_back('7') ;
	vChar2.push_back('8') ;
	vChar2.push_back('9') ;

	// vChar: [A B Z G H]
	// vChar2: [1 2 3 4 5 6 7 8]

	std::cout << "===============================" << std::endl ;
	std::cout << vChar.size() << " : " << vChar.capacity() << std::endl ;
	std::cout << vChar2.size() << " : " << vChar2.capacity() << std::endl ;

	vChar.swap(vChar2) ;

	std::cout << vChar.size() << " : " << vChar.capacity() << std::endl ;
	std::cout << vChar2.size() << " : " << vChar2.capacity() << std::endl ;


	// vChar2: [A B Z G H]
	// vChar: [1 2 3 4 5 6 7 8]




	return 0;
}


void printVector(const std::vector<int>& v)
{
	std::vector<int>::const_iterator iterador ;

	std::cout << " -------------------- " << std::endl ;

	for(iterador = v.begin() ; iterador != v.end() ; iterador++)
	{
		std::cout << *iterador << std::endl ;
	}

	std::cout << " -------------------- " << std::endl ;
}

void printVector(const std::vector<char>& v)
{
	std::vector<char>::const_iterator iterador ;

	std::cout << " -------------------- " << std::endl ;

	for(iterador = v.begin() ; iterador != v.end() ; iterador++)
	{
		std::cout << *iterador << std::endl ;
	}

	std::cout << " -------------------- " << std::endl ;
}


void printVector(const std::vector<Alumno>& v)
{
	std::vector<Alumno>::const_iterator iterador ;

	std::cout << " -------------------- " << std::endl ;

	for(iterador = v.begin() ; iterador != v.end() ; iterador++)
	{
		std::cout << iterador->dump() << std::endl ;
		// std::cout << (*iterador).dump() << std::endl ;
	}

	std::cout << " -------------------- " << std::endl ;
}

void printVector(const std::vector<Alumno*>& v)
{
	std::vector<Alumno*>::const_iterator iterador ;

	std::cout << " -------------------- " << std::endl ;

	for(iterador = v.begin() ; iterador != v.end() ; iterador++)
	{
		std::cout << &(*iterador) << " : " << (*iterador)->dump() << std::endl ;
		// std::cout << (*(*iterador)).dump() << std::endl ;
	}

	std::cout << " -------------------- " << std::endl ;
}


