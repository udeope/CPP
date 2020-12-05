/*
 * BD.h
 *
 *  Created on: Jun 30, 2020
 *      Author: user
 */

#ifndef BD_H_
#define BD_H_

#include <string>
#include <vector>
#include <mysql.h>

using namespace std ;


#define TABLA_ALUMNOS "Alumno"
#define TABLA_PROFESORES "Profesor"
#define TABLA_CARRERAS "Carrera"


class BD
{
	string user_ ;
	string pass_ ;
	string server_ ;
	string db_ ;

	MYSQL *conn_ ;

	MYSQL* getConn() ;
	const MYSQL* getConnC() const ;
	void setConn(MYSQL *conn) ;



public:
	BD(const string& user, const string& pass, const string& server, const string& db) ;
	virtual ~BD();

	bool ok() const ;

	bool ejecutaQuery(const string&) ;
	bool listaResultado(int) throw();

	const string& getDb() const;
	void setDb(const string &db) ;
	const string& getPass() const ;
	void setPass(const string &pass) ;
	const string& getServer() const ;
	void setServer(const string &server) ;
	const string& getUser() const ;
	void setUser(const string &user) ;

};

#endif /* BD_H_ */
