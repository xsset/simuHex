/*
 * matriz.h
 *
 *  Created on: 18/01/2015
 *      Author: xsset
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_
#include <iostream>
#include <cstdio>
#include <cstring>

#include "listas.h"
#include "debug.h"

using namespace std;

class Matriz {
public:
	Matriz();
	virtual ~Matriz();
	void insertar(int x,int y,char valor);
//	void insertarOrdenada(int x,int y,char valor);
//	void obtener(int x, int y);
	void eliminar(NodoX * nodoX,NodoY * nodoY);
	void eliminar(int x,int y);
	void inicio();
	bool siguiente();
	void valores();
	void vaciar();
	void leerLinea();
	void guardarMalla();
	void cargarMalla();
	void escribirArchivo(int x,int y,char valor);
	void abrirArchivoEscritura(char * Archivo);
	void abrirArchivoLectura(char * Archivo);
	void cerrarArchivo();
	bool estaVacia();
	void copiar( Matriz * matriz);
	void insertar(Matriz * matriz);
	void eliminar(Matriz * matriz);
//	void insertarVecinos(Lista * nodo);
	NodoY * buscar(int x, int y);
//	Lista * busquedaOrdenada(int x,int y);
//	Lista * busquedaOrdenadaParaInsertar(int x,int y);


	Lista * lista;
	NodoY * nodoHijoY;
	NodoX * nodoPadreX;
	DebugClass * debug;
	char * nombreArchivo;

//	ofstream ficheroSalida;
//	ifstream ficheroEntrada;

	FILE * archivoTXT;


//	int numCelulas;
//	int numX;
//	int numY;

//	Lista * Nueva;
//	int size;
//	int numerosElementos;



};

#endif /* MATRIZ_H_ */
