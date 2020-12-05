/*
 * BD.cpp
 *
 *  Created on: Jun 30, 2020
 *      Author: user
 */

#include <sstream>
#include <iostream>
#include "BD.h"
#include "BDException.h"

using namespace std ;

BD::BD(const string& user, const string& pass, const string& server, const string& db)
{
	setUser(user) ;
	setPass(pass) ;
	setServer(server) ;
	setDb(db) ;
	setConn(nullptr) ;

	setConn(mysql_init(nullptr)) ;			// inicializar la conexión

	bool bConnOk = mysql_real_connect(getConn(),
									getServer().c_str(),
									getUser().c_str(),
									getPass().c_str(),
									getDb().c_str(),
									0,
									nullptr,
									0) ;


	if(!bConnOk)
	{
		BDException e1(BDEXCEPTION_USER) ;
		throw(e1) ;
		setConn(nullptr) ;
	}
}



BD::~BD()
{
	if(getConn() != nullptr)
	{
		mysql_close(getConn()) ;
		setConn(nullptr) ;
	}
}


bool BD::ok() const
{
	if(getConnC() != nullptr) return true ;
	else return false ;
}

bool BD::ejecutaQuery(const string& query)
{
	bool res = true ;

	if(mysql_query(getConn(), query.c_str()) == 0)
	{
		res = true ;
	}
	else
	{
		BDException e(BDEXCEPTION_QUERY) ;
		throw(e) ;
		res = false ;
	}

	return res ;
}

bool BD::listaResultado(int rows) throw()
{
	bool res = false ;
	MYSQL_RES *lista = nullptr ;
	MYSQL_ROW row ;

	lista = mysql_use_result(getConn()) ;

	if(lista != nullptr)
	{
		while( (row = mysql_fetch_row(lista)) != nullptr)
		{
			for(int i = 0 ; i < rows ; i++)
			{
				cout << " | " << row[i] ;
			}
			cout << endl ;
		}

		mysql_free_result(lista) ;
		res = true ;
	}
	else
	{
		cout << "Error: " << mysql_error(getConn()) << endl ;
		res = false ;
	}

	return res ;
}

const string& BD::getDb() const { return db_; }
const string& BD::getPass() const { return pass_; }
const string& BD::getServer() const { return server_; }
const string& BD::getUser() const {	return user_; }
MYSQL* BD::getConn() { return conn_; }
const MYSQL* BD::getConnC() const { return conn_; }

void BD::setDb(const string &db) { db_ = db; }
void BD::setPass(const string &pass) { pass_ = pass; }
void BD::setServer(const string &server) { server_ = server; }
void BD::setUser(const string &user) { user_ = user; }
void BD::setConn(MYSQL *conn) { conn_ = conn; }

