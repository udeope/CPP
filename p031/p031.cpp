//============================================================================
// Name        : p031.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// para instalar mysql: sudo apt-get install libmysqlclient-dev
// incluir en el path de includes: /usr/include/mysql
// incluir en el path de librerías: /usr/lib/x86_64-linux-gnu
// incluir en librerías: mysqlclient (libmysqlclient.so)


#include <iostream>
#include <mysql.h>

using namespace std;

int main()
{
	MYSQL *conn = nullptr ;					// puntero a objeto que controla nuestra conexión con la BD
	MYSQL_RES *res = nullptr ;				// puntero a objeto que guardará el resultado de una QUERY
	MYSQL_ROW row ;							// un objecto que guardar un registro de la tabla de resultados

	string server = "localhost" ;			// URL del servidor donde está la BD 100.32.65.84/path
	string user = "root" ;					// usuario
	string psw = "123123123" ;				// contraseña
	string db = "test" ;					// base de datos

	conn = mysql_init(nullptr) ;			// inicializar la conexión


	// Realizamos la conexión

	bool bConnOk = mysql_real_connect(conn, server.c_str(), user.c_str(), psw.c_str(), db.c_str(), 0, nullptr, 0) ;

	if(!bConnOk)
	{
		cout << "Error: " << mysql_error(conn) << endl ;
	}
	else
	{
		// sustituir TU_TABLA por una tabla de vuestra base de datos
		if(mysql_query(conn, "SELECT * FROM TU_TABLA"))
		//if(mysql_query(conn, "SHOW TABLES"))
		{
			cout << "Error: " << mysql_error(conn) << endl ;
		}
		else
		{
			// Tabla: Amigos
			// ID :  Nombre : Tel
			// 0  : Juan    : 931237127
			// 1  : Maria   : 645923811
			// 2  : José    : 934567890
			// nullptr

			// FETCH : ir de registro en registro
			res = mysql_use_result(conn) ;
			while( (row = mysql_fetch_row(res)) != nullptr)
			{
				// cada indice en row guarda un campo de la tabla
				cout << row[0] << " - " ;		// imprimiría el contenido del campo ID
				cout << row[1] << " - " ;		// imprimiría el contenido del campo Nombre
				cout << row[2] << endl ;		// imprimiría el contenido del campo Tel
			}

			// Resultado:
			// 0 - Juan - 931237127
			// ...
		}

		// libera el resultado de la query
		mysql_free_result(res) ;

		cout << "Conexión OK!" << endl ;
		cout << "Cerrando conexión..." << endl ;
		mysql_close(conn) ;
		cout << "BD Cerrada" << endl ;
	}

	return 0;
}
