/*
 * nodoY.h
 *
 *  Created on: 23/01/2015
 *      Author: xsset
 */

#ifndef NODOY_H_
#define NODOY_H_

#include <cstdlib>

class NodoY {
public:
	NodoY();
	NodoY(int y);
	virtual ~NodoY();

	int y;
	char valor;
	NodoY * siguiente;

};

#endif /* NODOY_H_ */
