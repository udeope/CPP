/*
 * BDException.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: user
 */

#include "BDException.h"

BDException::BDException(const ErrorBD& error)
{
	setError(error) ;
}

BDException::~BDException()
{
}


void BDException::setError(const ErrorBD& error) { error_ = error ; }
const ErrorBD& BDException::getError() const { return error_ ; }

string BDException::queHaPasado() const
{
	string mensaje = "" ;
	switch(getError())
	{
		case BDEXCEPTION_SERVER : { mensaje = "Error de conexión al servidor" ; } break ;
		case BDEXCEPTION_USER : { mensaje = "Error, el usuario especificado no tiene permisos" ; } break ;
		case BDEXCEPTION_NETWORK : { mensaje = "Error, actualmente no se ha encontrado servicio de red" ; } break ;
		case BDEXCEPTION_QUERY : { mensaje = "Error, la query especificada es incorrecta" ; } break ;
		default : { mensaje = "Error desconocido!" ; } break ;
	}

	return mensaje ;
}

