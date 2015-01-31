/*
 * nodoY.cpp
 *
 *  Created on: 23/01/2015
 *      Author: xsset
 */

#include "nodoY.h"

NodoY::NodoY() {
	// TODO Auto-generated constructor stub
	y = 0;
	siguiente = NULL;
	valor = -1;
}

NodoY::NodoY(int y) {
	this->y =  y;
	siguiente = NULL;
	valor = -1;
}

NodoY::~NodoY() {
	// TODO Auto-generated destructor stub
}

