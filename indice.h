/*
 * indice.h
 *
 *  Created on: 21/01/2015
 *      Author: xsset
 */

#ifndef INDICE_H_
#define INDICE_H_

class Indice {
public:
	Indice();
	virtual ~Indice();
	void insertar(int x,int y,Lista * nodo);
	void eliminar(int x,int y);
	Lista * buscar(int x,int y);
};

#endif /* INDICE_H_ */
