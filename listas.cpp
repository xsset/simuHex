/*
 * listas.cpp
 *
 *  Created on: Jan 20, 2015
 *      Author: xsset
 */

#include "listas.h"

Lista::Lista() {
	// TODO Auto-generated constructor stub
//	this->valor= 0;
//	this->siguiente = NULL;
//	this->atras = NULL;
	nodoUltimoMovimientoX = NULL;
	nodoUltimoMovimientoY = NULL;
	debug = new DebugClass();
	inicioX = NULL;
	numNodoX = 0;
	numNodoY = 0;
	nodoRojo = 0;
	nodoNegro = 0;
	nodoBlanco = 0;
//	if( inicioX)
//		debug->setDebugString("inicioX\n");
//	else
//		debug->setDebugString("No existe inicioX\n");
//	x =0;
//	y = 0;
}

Lista::~Lista() {
	// TODO Auto-generated destructor stub
}

//void Lista::insertarAdelante(Lista* siguiente) {
//	this->siguiente = siguiente;
//}
//
//void Lista::insertarAtras( Lista* atras) {
//	this->atras = atras;
//}

//void Lista::eliminar() {
////	if(this->atras != NULL)
////		this->atras->siguiente= this->siguiente;
//////	else
//////	{
////////		this->siguiente->atras = NULL;
//////////		inicio = this->siguiente;
//////	}
////	if(this->siguiente != NULL)
////		this->siguiente->atras = this->atras;
//////	else
//////	{
//////		this->atras->siguiente = NULL;
//////	}
//
//	delete this;
//}

void Lista::vaciar() {

}

void Lista::insertarN(int x, int y, int valor)
{

//	debug->setDebugString("Se insertara: ");
//	debug->setDebugString(x);
//	debug->setDebugString(",");
//	debug->setDebugString(y);
//	debug->setDebugString("--");
//	debug->setDebugString((int)valor);
//	debug->setDebugString("\n");
	NodoX * nodox;

	nodox = insertarX(x);
	nodoUltimoMovimientoX = nodox;
	nodoUltimoMovimientoY =  insertarY(y,nodox,valor);
//	if(nodoUltimoMovimientoX)
//		numNodoX++;
//	if(nodoUltimoMovimientoY)
//		numNodoY++;
//	impimirX();
}

NodoX * Lista::insertarX(int x) {
//	debug->setDebugString("insertar\n");
//	debug->setDebugString("valorX: ");
//	debug->setDebugString(x);
//	debug->setDebugString("\n");
	NodoX * temp = inicioX;
	NodoX * nuevo;// = new NodoX(x);


	//si es el inicio de la lista
	if(! temp)
	{
//		debug->setDebugString("inicioX\n");
		nuevo = new NodoX(x);
		inicioX = nuevo;
		numNodoX++;
		return inicioX;
	}

	//mientras temp exista
	while(temp)
	{
//		debug->setDebugString("x = ");
//		debug->setDebugString(x);
//		debug->setDebugString(" -temp->x = ");
//		debug->setDebugString(temp->x);
//		debug->setDebugString("\n");


		if(temp->x == x)
		{
//			debug->setDebugString("x = temp->x\n");
//			debug->setDebugString(x);
//			debug->setDebugString(" = ");
//			debug->setDebugString(temp->x);
//			debug->setDebugString("\n");
			return temp;
		}
		//si x es menor que temp->x se inserta
		else if ( x < temp->x && !temp->siguiente)
		{
			//temp->siguiente es NULL  se inserta el nuevo;
//			debug->setDebugString("es menor que X\n");
			nuevo = new NodoX(x);
			if( inicioX == temp )
			{
				inicioX = nuevo ;
				nuevo->siguiente = temp;
			}
//			temp->siguiente = nuevo;
			numNodoX++;
			return nuevo;

		}

		//si el siguiente existe comparamos
		else if(temp->siguiente)
		 {
			//si x es mayor que el valor de x del nodo siguiente
			 if( x> temp->x  )
			 {
				 // si x es mayor al nodo temp y menor al temp->siguiente se inserta
				 if ( x < temp->siguiente->x)
				 {
//					 debug->setDebugString("se insertaraX ");
//					 debug->setDebugString(x);
//					 debug->setDebugString("\n");
					 nuevo = new NodoX(x);

					 nuevo->siguiente = temp->siguiente;
					 temp->siguiente = nuevo;
					 numNodoX++;
					 return nuevo;
				 }
				 // si x es igual al x del temp->siguiente
				 else if( x == temp->siguiente->x)
				 {
//					 debug->setDebugString("x = temp->siguiente->x\n");
//					 debug->setDebugString(x);
//					 debug->setDebugString(" = Siguiente: ");
//					 debug->setDebugString(temp->siguiente->x);
//					 debug->setDebugString("\n");
					 //					impimirX();
					 return temp->siguiente;
				 }
				 //en caso que temp->siguiente->x sea menor que x se avanza al siguiente nodo;
				 else
				 {
					 temp = temp->siguiente;
				 }
			 }
			 else if( x == temp->x)
			 {
//				 debug->setDebugString("retornando temp");
//				 debug->setDebugString("\n");
				 return temp;
			 }
			 //si x es menor que el valor de x del nodo siguiente
			 else
			 {
				 nuevo = new NodoX(x);
				 nuevo->siguiente = temp;
				 inicioX = nuevo;
//				 debug->setDebugString("retornando nuevo");
//				 debug->setDebugString("\n");
				 numNodoX++;
				 return nuevo;
			 }
		 }
		//si no existe se inserta
		 else
		 {
			 nuevo = new NodoX(x);
			 temp->siguiente = nuevo;
		 }

	}

	//si hubo error returna NULL
//	debug->setDebugString("retur NULL\n");
	return NULL;
}

NodoY * Lista::insertarY(int y,NodoX * tempX,char valor)
{
//	debug->setDebugString("insertar Y\n");
//	debug->setDebugString("en Y: ");
//	debug->setDebugString(y);
//	debug->setDebugString(" en X: ");
//	debug->setDebugString(tempX->x);
//	debug->setDebugString(" valor:  ");
//	debug->setDebugString(valor);
//	debug->setDebugString("\n");


	NodoY * temp = tempX->nodoY;
	NodoY * nuevo;// = new NodoX(x);
	NodoY * anteriorY;


	//si es el inicio de la lista
	if(! temp)
	{
//		debug->setsDebugString("inicioY\n");
		nuevo = new NodoY(y);
		nuevo->valor = valor;
		tempX->nodoY = nuevo;
		temp = nuevo;
		numNodoY++;
		insertar(valor);
		return temp;
	}

	//mientras temp exista
	while(temp)
	{
//		debug->setDebugString("adentro while \n");
		if(temp->y == y)
		{
//			debug->setDebugString("y = temp->y\n");
//			debug->setDebugString(y);
//			debug->setDebugString(" = ");
//			debug->setDebugString(temp->y);
//			debug->setDebugString("\n");
			eliminar(temp->valor);
			insertar(valor);
			temp->valor = valor;
			return temp;
		}
		//si x es menor que temp->x se inserta
		else if ( y < temp->y  && ! temp->siguiente )
		{///3 2 4 6
			//temp->siguiente es NULL  se inserta el nuevo;
//			debug->setDebugString("es menor que Y\n");
//			debug->setDebugString("se insertaraY ");
//			debug->setDebugString(y);
//			debug->setDebugString("\n");
			nuevo = new NodoY(y);
			nuevo->valor = valor;
			if( tempX->nodoY == temp )
			{
				 tempX->nodoY = nuevo ;
				nuevo->siguiente = temp;
			}
			//			temp->siguiente = nuevo;
			numNodoY++;
			insertar(valor);
			return nuevo;

		}
		//si el siguiente existe comparamos
		 if(temp->siguiente)
		{
			//si x es mayor que el valor de x del nodo siguiente
			if( y> temp->y  )
			{//4 3 5 7
				// si x es menor al nodo temp y menor al temp->siguiente se inserta
				if ( y < temp->siguiente->y)
				{
//					debug->setDebugString("se insertara ");
//					debug->setDebugString(y);
//					debug->setDebugString("\n");
					nuevo = new NodoY(y);
					nuevo->valor = valor;
					nuevo->siguiente = temp->siguiente;
					temp->siguiente = nuevo;
					numNodoY++;
					insertar(valor);
					return nuevo;
				}
				// si x es igual al x del temp->siguiente
				else if( y == temp->siguiente->y)
				{
//					debug->setDebugString("y = temp->siguiente->y\n");
//					debug->setDebugString(y);
//					debug->setDebugString(" = Siguiente: ");
//					debug->setDebugString(temp->siguiente->y);
//					debug->setDebugString("\n");
					eliminar(temp->siguiente->valor);
					insertar(valor);
					temp->siguiente->valor = valor;
					return temp->siguiente;
				}
				//en caso que temp->siguiente->x sea menor que x se avanza al siguiente nodo;
				else
				{
//					debug->setDebugString("siguiente \n");
					temp = temp->siguiente;
				}
			}
			else if( y == temp->y)
			{
//				debug->setDebugString("se actualizo valor de ");
//				debug->setDebugString(y);
//				debug->setDebugString("\n");
				eliminar(temp->valor);
				insertar(valor);
				temp->valor = valor;
				return temp;
			}
//			si x es menor que el valor de x del nodo siguiente
			else
			{
//				debug->setDebugString("se insertaraY ");
//				debug->setDebugString(y);
//				debug->setDebugString("\n");
				nuevo = new NodoY(y);
				nuevo->siguiente = temp;
				tempX->nodoY = nuevo;
				nuevo->valor = valor;
				numNodoY++;
				insertar(valor);
				return nuevo;
			}
		}
		//si no existe se inserta
		else
		{
//			temp->siguiente es NULL  se inserta el nuevo;
//			debug->setDebugString("siguiente Nullo\n");
//			debug->setDebugString("se insertaraY ");
//			debug->setDebugString(y);
//			debug->setDebugString("\n");
			nuevo = new NodoY(y);
			temp->siguiente = nuevo;
			nuevo->valor = valor;
			numNodoY++;
			insertar(valor);
			return nuevo;

		}
//		debug->setDebugString("ciclo \n");
	}

	//si hubo error returna NULL
//	debug->setDebugString("retur NULL\n");
	return NULL;
}

void Lista::impimirX() {
	NodoX * temp = inicioX;
//	NodoY * tempY = inicioY;

	debug->setDebugString("\t imprimir X--\n");
	if (temp)
	{
		debug->setDebugString("\t \t existe X\n");

	}
	else
	{

		debug->setDebugString("\t \t No existe X\n");
	}
	while(temp)
	{
		debug->setDebugString("\t \t \t x = ");
		debug->setDebugString(temp->x);
		debug->setDebugString("\n");

		impimirY(temp);
		temp = temp->siguiente;
	}
	debug->setDebugString("\t Saliendo X--\n");
}

void Lista::impimirY(NodoX * tempX) {
	NodoY * temp = tempX->nodoY;

	debug->setDebugString("\t imprimir Y--\n");
	while(temp)
	{
		debug->setDebugString("\t \t \t y = ");
		debug->setDebugString(temp->y);
		debug->setDebugString(", valor = ");
		debug->setDebugString((int)temp->valor);
		debug->setDebugString("\n");


		temp = temp->siguiente;
	}
	debug->setDebugString("\t Saliendo --\n");
}

void Lista::eliminar(NodoX* nodoX, NodoY* nodoY) {

	NodoY * temporalY;
	NodoX * temporalX;
	NodoY * anteriorY;
	NodoX * anteriorX;

//	if(nodoX && nodoY)
//	{
//		debug->setDebugString("eliminar Nodo X: ");
//		debug->setDebugString(nodoX->x);
//		debug->setDebugString(",");
//		debug->setDebugString(nodoY->y);
//		debug->setDebugString("\n");
//	}

	if(nodoX && nodoY)
	{
		temporalY = nodoX->nodoY;
		anteriorY = temporalY;

		while( temporalY)
		{
			anteriorY = temporalY;
			if(temporalY == nodoY)
			{
				anteriorY->siguiente = nodoY->siguiente;
//				debug->setDebugString("eliminandoY : ");
//				debug->setDebugString(nodoY->y);
//				debug->setDebugString("\n");
				if(nodoX->nodoY == nodoY)
					nodoX->nodoY = nodoY->siguiente;
				numNodoY--;
				eliminar(nodoY->valor);
//				insertar(valor);
				delete nodoY;
				if(! nodoX->nodoY)
				{
					temporalX = inicioX;
					while(temporalX)
					{
						anteriorX = temporalX;
						if(temporalX == nodoX)
						{
							anteriorX->siguiente = nodoX->siguiente;
//							debug->setDebugString("eliminandoX : ");
//							debug->setDebugString(nodoX->x);
//							debug->setDebugString("\n");
							if(inicioX == nodoX)
							{
								inicioX = nodoX->siguiente;
							}
							numNodoX--;
							delete nodoX;
//								impimirX();
//								debug->setDebugString("Saliendo eliminar\n");
							return;

						}
						else
						{
							temporalX = temporalX->siguiente;
						}
					}
				}
//				impimirX();
//				debug->setDebugString("Saliendo eliminar\n");
				return;
			}
			else
			{
				temporalY = temporalY->siguiente;
			}
		}
	}

}

void Lista::insertar(char valor)
{
	if(valor == BLANCO)
		nodoBlanco++;
	else if(valor == ROJO)
		nodoRojo++;
	else if(valor == NEGRO)
		nodoNegro++;
}

void Lista::eliminar(char valor) {
	if(valor == BLANCO)
		nodoBlanco--;
	else if(valor == ROJO)
		nodoRojo--;
	else if(valor == NEGRO)
		nodoNegro--;
}

NodoY* Lista::buscar(int x, int y)
{
//	return NULL;
//	inicioX = NULL;
	NodoX * tempX =  inicioX;
	NodoY * tempY;

//	debug->setDebugString("inicio Buscar\n");
//	debug->setDebugString(x);
//	debug->setDebugString(" , ");
//	debug->setDebugString(y);
//	debug->setDebugString("\n");
	while(tempX )
	{
		if (x > tempX->x  )
			tempX = tempX->siguiente;
		else if (tempX->x == x)
		{
			tempY = tempX->nodoY;
			while(tempY)
			{
				if ( y > tempY->y)
				{
//					debug->setDebugString(x);
//					debug->setDebugString(",");
//					debug->setDebugString(tempX->x);
//					debug->setDebugString(",");
//					debug->setDebugString(y);
//					debug->setDebugString(",");
//					debug->setDebugString(tempY->y);
//					debug->setDebugString("\n");
//					debug->setDebugString("siguiente Buscar Y0\n");
//					if( tempY->siguiente)
//						debug->setDebugString("siguiente existe");
//					else
//						tempY = NULL;
//						debug->setDebugString("siguiente NO existe");
					tempY = tempY->siguiente;
//					if( tempY)
//						debug->setDebugString("Y existe");
//					else
//						debug->setDebugString("Y NO existe");

//					return NULL;
				}
				else if(y == tempY->y)
				{
					nodoUltimoMovimientoX = tempX;
					nodoUltimoMovimientoY = tempY;

//					debug->setDebugString("Se encontro: ");
//					debug->setDebugString(x);
//					debug->setDebugString(",");
//					debug->setDebugString(tempX->x);
//					debug->setDebugString(",");
//					debug->setDebugString(y);
//					debug->setDebugString("-");
//					debug->setDebugString((int)tempY->valor);
//					debug->setDebugString(tempY->y);
//					debug->setDebugString("\n");
					return tempY;
				}
				else
				{
//					debug->setDebugString("siguiente Buscar Y1\n");
					tempY = tempY->siguiente;
//					return NULL;
				}
			}
//			debug->setDebugString("Salio while\n");
			return NULL;
		}
		else
		{
//			debug->setDebugString("siguiente Buscar X\n");
			tempX = tempX->siguiente;
		}
	}
//	debug->setDebugString("Termino\n");
	return NULL;
}
//char Lista::obtener() {
//	return this->valor;
//}

//void Lista::insertar(int x, int y) {
//	this->x = x;
//	this->y = y;
//}
