/*
 * Alumno.h
 *
 *  Created on: Jun 16, 2020
 *      Author: user
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#include <string>
using namespace std ;

class Alumno
{
private:
	string 	nombre_ ;
	int 	codigo_ ;

public:
	Alumno() ;
	Alumno(const string&, int) ;
	virtual ~Alumno() ;
	Alumno(const Alumno &other) ;
	Alumno& operator=(const Alumno &other) ;

	const string& 	getNombre() const ;
	int 			getCodigo() const ;

	void 			setNombre(const string&) ;
	void 			setCodigo(int) ;

	void dump() const ;

};

#endif /* ALUMNO_H_ */
