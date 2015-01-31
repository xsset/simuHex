/*
 * nodo.h
 *
 *  Created on: 23/01/2015
 *      Author: xsset
 */

#ifndef NODOX_H_
#define NODOX_H_

#include <cstdlib>
#include "nodoY.h"

class NodoX {
public:
	NodoX();
	NodoX(int x);
	virtual ~NodoX();
	int x;
	NodoY * nodoY;
	NodoX * siguiente;

};

#endif /* NODOX_H_ */
