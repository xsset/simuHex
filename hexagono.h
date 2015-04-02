/*
 * Hexagono.h
 *
 *  Created on: 16/01/2015
 *      Author: xsset
 */

#include "punto.h"
#include "utileria.h"
#include "debug.h"
//#include <wx/dcbuffer.h>
//#include <wx/pen.h>

#ifndef HEXAGONO_H_
#define HEXAGONO_H_

class Hexagono {
public:
	Hexagono(int x,int y,int largo,int zoom);
	~Hexagono();
	int getLargoLado();
	void setLargoLado(int largoLado);
//	void paint(bool lineas,wxColour  colorRelleno,wxColour  colorLineas ,wxBufferedPaintDC& dc);
//	void paintCoordenadas(wxBufferedPaintDC& dc);
	void setZoom(int zoom);
	int getZoom();
	void calcularPuntos(int origenX,int origenY);
	bool adentro(Punto * punto);
	bool detectarTriangulo(Punto * puntoA,Punto * puntoB,Punto * puntoC,Punto * puntoP);
	void setRelleno(bool relleno);
	bool getRelleno();
	Punto * resta(Punto * puntoA,Punto * puntoB);
	int productoPunto(Punto * puntoA,Punto * puntoB);
//	wxColour convertirColor(char color);

//	void click(char color);
	Punto * centro;
	bool relleno;
	bool lineas;
	char estado; //color
	char colorLineas;
	bool seleccionar;


//private:

	Punto * coordenadas;
	int largoLado;
	int zoom;

	DebugClass * debug;


//	wxBufferedPaintDC& dc;


};

#endif /* HEXAGONO_H_ */
