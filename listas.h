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
#include "utileria.h"

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
	void insertar(char valor);
	void eliminar(char valor);
	NodoY * buscar(int x, int y);
	NodoX * inicioX;
	NodoX * nodoUltimoMovimientoX;
	NodoY * nodoUltimoMovimientoY;

	DebugClass * debug;

	int numNodoX;
	int numNodoY;
	int nodoRojo;
	int nodoNegro;
	int nodoBlanco;

};

#endif /* LISTAS_H_ */
