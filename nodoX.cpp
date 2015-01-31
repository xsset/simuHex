/*
 * nodo.cpp
 *
 *  Created on: 23/01/2015
 *      Author: xsset
 */

#include "nodoX.h"

NodoX::NodoX() {
	// TODO Auto-generated constructor stub
	x = 0;
	nodoY = NULL;
	siguiente = NULL;

}

NodoX::NodoX(int x) {
	this->x = x;
	nodoY = NULL;
	siguiente = NULL;
}

NodoX::~NodoX() {
	// TODO Auto-generated destructor stub
}

