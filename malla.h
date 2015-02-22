//
//  malla.h
//  wxhello01
//
//  Created by Julio Cesar Cabrera on 13/01/14.
//  Copyright (c) 2014 Julio Cesar Cabrera. All rights reserved.
//

#ifndef __wxhello01__malla__

#define __wxhello01__malla__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#endif /* defined(__wxhello01__malla__) */
#include "utileria.h"
#include "debug.h"
#include "hexagono.h"
#include "cursor.h"
#include "matriz.h"

#include <wx/dcbuffer.h>
#include <wx/pen.h>

#define PORCENTAJE 1

#ifndef _MALLA_
#define _MALLA_




class Malla
{
	public:
		Malla( Cursor * puntero);
//		void hex(double initX, double initY,float largo,wxPen color ,bool relleno,wxBufferedPaintDC& dc );
//		void paint(int largo,int ventanaAlto,int ventanaAncho,wxPen * color,int viewHexagonoX,int viewHexagonoY,NodoMov  * array,int mouseX,int mouseY,wxBufferedPaintDC& dc);
//		int getHexX(int i,int largo);
//		int getHexY(int i,int j,int viewHexagonoX,int largo);
//		bool inside(int initX ,int initY,int largo,int mouseX,int mouseY);
//		wxPen convertir(char color);
		void clickCoordenadas(int x,int y,char color);
		void paint(int ventanaLargo, int ventanaAncho,bool lineas,int largoLado,int zoom,wxColour colorMargenes ,wxBufferedPaintDC& dc );

		int coordenadasMatrizX();
		int coordenadasMatrizY();
		int coordenadaVirtualX(int x);
		int coordenadaVirtualY(int x,int y);
//		void setNumeHexagonalX(int numHexagonalX);
//		void setNumeHexagonalY(int numHexagonalY);
		void evolucionar();
		void calculaVecindad(int x, int y , int valor,Matriz * matriz, Matriz * matrizTemporal,Matriz * vecinos);
		void aleatorio();
		void aleatorio(int x, int y);
		void busquedaTodosVecinos(int x,int y,Matriz * matriz,Matriz * vecinos,Matriz * leidos);
		void busquedaVecinos(Matriz * matriz,Matriz * vecinos,int x, int y);
		void eliminarBlancos(Matriz * matriz);
		void buscarVecinosMouse();
		void moverHexagonos(char Direccion,int posiciones,Matriz * temp,Matriz * nueva);
		void limpiarBanderasVecinos();
		void moverHexagonoHacia(Cursor * cursor, Matriz* vieja, Matriz * nueva);
		void imprimirBanderas();
		void insertarMover();
		void copiarMatriz();
		void eliminarMatriz();
		void clickIzquierdo();
		void accionMalla(char accion);
		void calcularPorcentaje();
		void limitesPantalla();
//		void cli
//		void moverHexagonos(char Direccion,int posiciones,Matriz * temp);
//		void mover

		bool lineas;
		Matriz * matriz;
		Matriz * mVecinos;
		Matriz * mLeidos;
		Matriz * mCopiar;
		Matriz * mEliminar;
		Matriz * mMover;
		Matriz * mTemporal;
		wxColour colorLineas;
		wxColour colorRelleno;
		Hexagono *hexagono;
		NodoY * actual;

//	private:
		DebugClass * debug;
		Cursor * cursor;
		Cursor * cursorCelulas;
		Cursor * cursorAnteriorCelulas;
		Cursor * cursorPorcentaje;
		Punto * PuntoInicial;
		int numHexagonalX;
		int numHexagonalY;
		char Zoom;
		int largo;

		int viewInicialX;
		int viewInicialY;
		int viewFinalX;
		int viewFinalY;
		int evoluciones;
		bool vecinosPersistentes;
		bool vecinos;
		bool mover;
		bool copiar;
		bool eliminar;
};

//void hex(double initX, double initY,float largo,wxPen color ,bool relleno,wxBufferedPaintDC &dc );
//int getHexX(int i,int largo);
//int getHexY(int i,int j,int viewHexagonoX,int largo);
//bool inside(int initX ,int initY,int largo,int mouseX,int mouseY);
//void malla(int largo,int ventanaAlto,int ventanaAncho,wxPen * color,int viewHexagonoX,int viewHexagonoY,NodoMov  * array,int mouseX,int mouseY,wxBufferedPaintDC& dc);
//wxPen convertir(char);

#endif
