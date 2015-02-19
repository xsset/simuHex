/*
 * cursor.cpp
 *
 *  Created on: 16/01/2015
 *      Author: xsset
 */

#include "cursor.h"

Cursor::Cursor() {
	// TODO Auto-generated constructor stub
	pintar = false;
	color = -1;
	setX(-1);
	setY(-1);

}

Cursor::~Cursor() {
	// TODO Auto-generated destructor stub
}

char Cursor::getColor()
 {
	return color;
}

void Cursor::setColor(char color) {
	this->color = color;
}

bool Cursor::isPintar()
{
	return pintar;
}

void Cursor::setPintar(bool pintar) {
	this->pintar = pintar;
}
