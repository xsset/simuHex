/*
 * main.cpp
 *
 *  Created on: 22/02/2015
 *      Author: xsset
 */

//#include "main.h"
#include "main.h"

int main(int argc, const char * argv[])
{
//	char *Temp;
	int i;
	numEvoluciones = 0;
//	double inicio=1;
//	double final=0;
	// TODO Auto-generated constructor stub
//	if (argc<2) {
//		printf("hexagonal [--no-gui]\n");
//		return 0;
//	}
	malla = new Malla();
	if (argc>1) {
		for (i = 1; i  < argc ; i++ )
		{
			
			printf("%i-%i ",i,argc);
			printf("%s \n",argv[i]);
			if( !strcmp ( argv[i],noGUI ))
			{
				printf("no gui\n");
			}
			else if( !strcmp ( argv[i],help ))
			{
				printf("help\n");
			}
			else if( !strcmp ( argv[i],file0 ))
			{
				printf("file0\n");
				printf("%s\n",argv[i+1]);
				nombreArchivoEntrada = argv[i+1];
				malla->matriz->abrirArchivoLectura( argv[i+1] );
				malla->matriz->cargarMalla();
//				malla->matriz->valores();
				i++;

				archivoCargado = true;
			}
			else if( !strcmp ( argv[i],file1 ))
			{
				printf("file1\n");
			}
			else if( !strcmp ( argv[i],evoluciones0 ))
			{
				printf("evolucion0:\n");
//				numEvoluciones = atoi(argv[i+1]);
//				numEvoluciones = 0;
				numEvoluciones =  strtol(argv[i+1], NULL, 10);
				evolucionActiva = true;
//				printf("%s \n",argv[i+1]);
				printf("%i \n",numEvoluciones);
				i++;
			}
			else if( !strcmp ( argv[i],evoluciones1 ))
			{
				printf("evolucion1\n");
			}
			else if( !strcmp ( argv[i],salida0 ))
			{
				printf("salida0\n");
				printf("%s\n",argv[i+1]);

				archivoSalida = true;
				nombreArchivoSalida = argv[i+1];
				i++;
			}
			else if( !strcmp ( argv[i],salida1 ))
			{
				printf("salida1\n");
			}
			else
			{
				printf("error %s\n", argv[i]);
			}
		}
//		if()
		if(evolucionActiva)
		{
			malla->evolucionar(numEvoluciones);
		}
		if(archivoSalida)
		{
			malla->matriz->abrirArchivoEscritura(nombreArchivoSalida);
			malla->matriz->guardarMalla();
		}
		//printf("%s",argv[1]);
//		Temp = (char *)argv[1];
//		do{
//			if( !isdigit( *(Temp++) ) )
//			{
//				//printf("
//				printf(" Numero  no valido\n");
//				return 0;
//			}
//		}while(1);

	}
	return 0;
}


