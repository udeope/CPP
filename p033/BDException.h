/*
 * BDException.h
 *
 *  Created on: Jul 7, 2020
 *      Author: user
 */

#ifndef BDEXCEPTION_H_
#define BDEXCEPTION_H_

#include <string>
using namespace std ;

// 0. Error de conexión al servidor de bd
// 1. Error de permiso
// 2. Error de red
// 3. Error query incorrecta
// 4. ....

typedef enum ErrorBD
{
	BDEXCEPTION_SERVER = 0,
	BDEXCEPTION_USER = 1,
	BDEXCEPTION_NETWORK = 2,
	BDEXCEPTION_QUERY = 3
} ErrorBD ;


class BDException
{
	ErrorBD error_ ;

	void setError(const ErrorBD&) ;
	const ErrorBD& getError() const ;

public:
	BDException(const ErrorBD&) ;
	virtual ~BDException() ;

	string queHaPasado() const ;
};

#endif /* BDEXCEPTION_H_ */
