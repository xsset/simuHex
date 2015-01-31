/*
 * Punto.cpp
 *
 *  Created on: 16/01/2015
 *      Author: xsset
 */

#include "punto.h"

Punto::Punto() {
	// TODO Auto-generated constructor stub
	this->x = 0;
	this->y = 0;
}
Punto::Punto(int x, int y) {
	// TODO Auto-generated constructor stub
	this->x = x;
	this->y = y;
}
Punto::~Punto() {
	// TODO Auto-generated destructor stub
}

void Punto::setX(int x)
{
	this->x = x;
}
int Punto::getX()
{
	return this->x;
}
void Punto::setY(int y)
{
	this->y = y;
}
int Punto::getY()
{
	return this->y;
}

