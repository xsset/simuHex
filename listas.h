/*
 * listas.h
 *
 *  Created on: Jan 20, 2015
 *      Author: xsset
 */

#ifndef LISTAS_H_
#define LISTAS_H_

#include <cstdlib>
#include "debug.h"
#include "nodoX.h"
#include "nodoY.h"

class Lista {
public:
	Lista();
	 ~Lista();
//	void insertarAdelante(Lista * siguiente);
//	void insertarAtras(Lista * atras);
//	void insertar(int x,int y);
	void insertarN(int x, int y, int valor);
	NodoX * insertarX(int x);
	NodoY * insertarY(int y,NodoX * temp,char valor);
	void impimirX();
	void impimirY(NodoX * temp);
	void eliminar(NodoX * nodoX,NodoY * nodoY);
	void vaciar();
	NodoY * buscar(int x, int y);
	NodoX * inicioX;
	NodoX * nodoUltimoMovimientoX;
	NodoY * nodoUltimoMovimientoY;

	DebugClass * debug;

	int numNodoX;
	int numNodoY;

};

#endif /* LISTAS_H_ */
