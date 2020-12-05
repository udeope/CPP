//============================================================================
// Name        : p014.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_PRODUCTS 5			// número máximo de productos en la máquina
#define MAX_UNITS 10			// número máximo de unidades por cada producto

// Estructura que define un producto
//  contiene los siguientes atributos:
typedef struct Product
{
	string name ;				// nombre del producto
	float price ;				// precio del producto
	unsigned char units ;		// unidades del producto disponibles para la venta
} Product ;

enum Marcas { COCACOLA = 3, PEPSI = 1, CACAOLAT = 2, AGUA = 0, REDBULL = 4} ;



// declaración de funciones
void init(Product[]) ;
void print(const Product[], const float&) ;
void addProduct(Product[]) ;
void removeProduct(Product[]) ;
void sell(Product[], float&) ;
void printMenuPrincipal() ;
void printMenuVenta(const Product[]) ;
void printMenuGestion(const Product[]) ;
void clear() ;


int main()
{
	// La variable local cash nos servirá para guardar el total de dinero recaudado en la caja de la máquina.
	// Inicialmente hay 0 Euros
	float cash = 0.0 ;

	// La variable stock es un array de Productos, en este caso limitado a 5 productos
	Product stock[MAX_PRODUCTS] ;

	// Inicializamos el stock con todos los productos (nombres, precios y unidades)
	init(stock) ;

	// Realizamos una primera impresión del estado de la máquina de productos
	print(stock,cash) ;

	// variable que nos servirá para guardar la selección del usuario
	char sel1 = ' ';

	// bucle infinito...
	while(true)
	{
		// imprimimos el menú principal
		printMenuPrincipal() ;

		// leemos la opción seleccionada por el usuario desde el teclado
		cin >> sel1 ;

		// según la selección realizada...
		switch(sel1)
		{
			case 'A' : addProduct(stock) ; break ;						// añadimos una unidad de producto a la máquina
			case 'B' : removeProduct(stock) ; break ;					// eliminamos una unidad de producto a la máquina
			case 'C' : sell(stock, cash) ; break ;						// realizamos una venta de producto
			case 'D' : print(stock, cash) ; break ;						// imprimimos el contenido de la máquina
			default : cout << "Opcion in correcta!" << endl ;			// opción incorrecta!
		}
	}

	return 0;
}


// --------------------------------------------------------------------------------------------
// init
// - Función inicializa el array de productos con los 5 productos que hemos acordado
//		poniendo su nombre, precio y unidades disponibles a cero.
// --------------------------------------------------------------------------------------------
void init(Product stock[])
{
	stock[COCACOLA].name = "Coca-Cola" ;
	stock[COCACOLA].price = 1.5 ;
	stock[COCACOLA].units = 0 ;

	stock[PEPSI].name = "Pepsi" ;
	stock[PEPSI].price = 1.4 ;
	stock[PEPSI].units = 0 ;

	stock[CACAOLAT].name = "Cacaolat" ;
	stock[CACAOLAT].price = 1.8 ;
	stock[CACAOLAT].units = 0 ;

	stock[AGUA].name = "Agua" ;
	stock[AGUA].price = 0.5 ;
	stock[AGUA].units = 0 ;

	stock[REDBULL].name = "Red Bull" ;
	stock[REDBULL].price = 2.0 ;
	stock[REDBULL].units = 0 ;
}

// --------------------------------------------------------------------------------------------
// printMenuPrincipal
// - Función que hace un clear y imprimi el menú principal
// --------------------------------------------------------------------------------------------
void printMenuPrincipal()
{
	clear() ;
	cout << "[A] - Add product" << endl ;
	cout << "[B] - Remove product" << endl ;
	cout << "[C] - Sell" << endl ;
	cout << "[D] - Print" << endl ;
	cout << "Selecciona la operación a realizar: " ;
}

// --------------------------------------------------------------------------------------------
// printMenuVenta
// - Función que hace un clear y imprime el menú de venta ocultando los productos que tienen
//		cero unidades en stock
// - Recibe como parámetro el stock de productos
// --------------------------------------------------------------------------------------------
void printMenuVenta(const Product stock[])
{
	clear() ;

	for(int i = 0 ; i < MAX_PRODUCTS ; i++)
	{
		if(stock[i].units > 0)
		{
			cout << "[" << i << "]  " << stock[i].name << endl ;
		}
	}

	cout << "Selecciona un producto: " ;
}

// --------------------------------------------------------------------------------------------
// printMenuGestion
// - Función que hace un clear y imprime el menú de gestión que permite seleccionar un producto
// - Recibe como parámetro el stock de productos
// --------------------------------------------------------------------------------------------
void printMenuGestion(const Product stock[])
{
	clear() ;

	for(int i = 0 ; i < MAX_PRODUCTS ; i++)
	{
		cout << "[" << i << "]  " << stock[i].name << endl ;
	}
	cout << "Selecciona un producto: " ;
}

// --------------------------------------------------------------------------------------------
// print
// - Función que imprime todos los detalles del stock actual y también el contenido de caja
// --------------------------------------------------------------------------------------------
void print(const Product stock[], const float& cash)
{
	cout << "Posición" << setw(15) << "Producto" << setw(10) << "Precio" << setw(15) << "Unidades" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	for(int i = 0 ; i < MAX_PRODUCTS; i++)
	{
		cout << "[" << i << "]" << setw(20) << stock[i].name << setw(10) << stock[i].price << " €" << setw(10) <<(int)stock[i].units << endl ;
	}
	cout << "---------------------------------------------------------" << endl ;
	cout << "CASH: " << cash << " €" << endl ;
	cout << "---------------------------------------------------------" << endl ;
}

// --------------------------------------------------------------------------------------------
// addProduct
// - Función que añade una unidad de producto al stock
// - Recibe como parámetro el stock de productos
// --------------------------------------------------------------------------------------------
void addProduct(Product stock[])
{
	int sel = 0 ;

	// 1. imprime el menú de gestión
	printMenuGestion(stock) ;

	// 2. selecciona el tipo de producto al cual añadir UNA unidad
	cin >> sel ;

	// 3. si el producto es uno de la lista (de 0 a 4)
	if(sel >= 0 && sel < MAX_PRODUCTS)
	{
		// 4. si el producto no ha llegado al máximo de unidades...
		if(stock[sel].units < MAX_UNITS)
		{
			// aumentamos en uno las unidades del producto seleccionado
			stock[sel].units++ ;

			// ponemos un mensaje en pantalla confirmando la operación
			cout << "OK! Ahora hay " << (int) stock[sel].units << " unidad(es) de " << stock[sel].name << endl ;
 		}
		else
		{
			// ponemos un mensaje advirtiendo que no podemos añadir unidades por qué hemos llegado al máximo
			cout << "Las unidades del producto " << stock[sel].name << " han llegado a su máximo" << endl ;
		}

	}
	else
	{
		// advertimos de una selección errónea
		cout << "Selección de producto erronea!" << endl ;
	}

}


// --------------------------------------------------------------------------------------------
// removeProduct
// - Función que elimina una unidad de producto al stock
// - Recibe como parámetro el stock de productos
// --------------------------------------------------------------------------------------------
void removeProduct(Product stock[])
{
	int sel = 0 ;

	// 1. imprime el menú de gestión
	printMenuGestion(stock) ;

	// 2. selecciona el tipo de producto al cual añadir UNA unidad
	cin >> sel ;

	// 3. si el producto es uno de la lista (de 0 a 4)
	if(sel >= 0 && sel < MAX_PRODUCTS)
	{
		// 4. si existe al menos una unidad de producto para poder eliminarla...
		if(stock[sel].units > 0)
		{
			// disminuimos en uno las unidades del producto seleccionado
			stock[sel].units-- ;

			// ponemos un mensaje en pantalla confirmando la operación
			cout << "OK! Ahora hay " << (int) stock[sel].units << " unidad(es) de " << stock[sel].name << endl ;
 		}
		else
		{
			// ponemos un mensaje advirtiendo que no podemos quitar unidades por qué ya no hay ninguna
			cout << "Las unidades del producto " << stock[sel].name << " ya son nulas" << endl ;
		}

	}
	else
	{
		// advertimos de una selección errónea
		cout << "Selección de producto erronea!" << endl ;
	}

}

// --------------------------------------------------------------------------------------------
// sell
// - Función que efectúa una venta:
//		1. Elimina una unidad del producto seleccionado
//		2. Añade la cantidad de dinero en caja correspondiente al producto entregado
// - Recibe como parámetro el stock de productos y la cantidad en caja (como referencia)
// --------------------------------------------------------------------------------------------
void sell(Product stock[], float& cash)
{
	int sel = 0 ;

	// imprime el menú de productos a vender
	printMenuVenta(stock) ;

	// obtiene la selección del usuario
	cin >> sel ;

	// si la selección está en el rango permitido de productos (0-4)
	if(sel >= 0 && sel < MAX_PRODUCTS)
	{
		// si hay stock disponible del producto seleccionado...
		if(stock[sel].units > 0)
		{
			// disminuimos la cantidad de unidades del producto seleccionado
			stock[sel].units-- ;

			// imprimimos la confirmación de la venta...
			cout << "Vendida una unidad de " << stock[sel].name << "!" << endl ;

			// aumentamos la cantidad de dinero en caja
			cash += stock[sel].price ;
 		}
		else
		{
			// advertimos que el producto que se ha seleccionado no está disponible (ya no quedan unidades)
			cout << "Lo siento, no quedan " << stock[sel].name << "s" << endl ;
		}

	}
	else
	{
		// advertimos que se ha seleccionado algo erróneo
		cout << "Selección de producto erronea!" << endl ;
	}

}


// --------------------------------------------------------------------------------------------
// clear
// - Función que pone 10 saltos de línea para que sea más clara la impresión de menús
// --------------------------------------------------------------------------------------------
void clear()
{
	for(int i = 0 ; i < 10 ; i++) cout << endl ;
}
