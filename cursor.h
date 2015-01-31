/*
 * cursor.h
 *
 *  Created on: 16/01/2015
 *      Author: xsset
 */

#include "punto.h"
#ifndef CURSOR_H_
#define CURSOR_H_

class Cursor : public Punto
{
public:
	Cursor();
	virtual ~Cursor();
	char getColor();
	void setColor(char color);
	bool isPintar();
	void setPintar(bool pintar);

	char color;
	bool pintar;


};

#endif /* CURSOR_H_ */
