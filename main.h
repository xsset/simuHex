/*
 * main.h
 *
 *  Created on: 22/02/2015
 *      Author: xsset
 */
#include <stdio.h>
#include <string.h>
#include "malla.h"

#ifndef MAIN_H_
#define MAIN_H_
const char * noGUI = "--no_gui";
const char * help = "--help";
const char * file0 = "-a";
const char * file1 = "--archivo";
const char * evoluciones0 = "-e";
const char * evoluciones1 = "--num_evoluciones";
const char * salida0 = "-s";
const char * salida1 = "--salida";

int main(int argc, const char * argv[]);

Malla * malla;

bool archivoCargado;
bool evolucionActiva;
int numEvoluciones;
bool archivoSalida;
const char * nombreArchivoEntrada;
const char * nombreArchivoSalida;

#endif /* MAIN_H_ */
