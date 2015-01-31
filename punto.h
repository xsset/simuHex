/*
 * Punto.h
 *
 *  Created on: 16/01/2015
 *      Author: xsset
 */

#ifndef PUNTO_H_
#define PUNTO_H_

class Punto {
public:
	Punto();
	Punto(int x, int y);
	virtual ~Punto();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	int x;
	int y;

};


#endif /* PUNTO_H_ */
