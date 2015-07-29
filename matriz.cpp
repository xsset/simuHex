/*
 * matriz.cpp
 *
 *  Created on: 18/01/2015
 *      Author: xsset
 */

#include "matriz.h"

Matriz::Matriz() {
	// TODO Auto-generated constructor stub
	lista = new Lista();
//	actual = NULL;
//	size = 0;
//	numerosElementos = 0;

	debug = new DebugClass();
	nodoHijoY = NULL;
	nodoPadreX = NULL;
//	Nueva = new Lista();
}

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
	vaciar();
}
//void Matriz::insertarOrdenada(int x, int y, char valor)
//{
//	Lista * temporal = new Lista();
//
//	temporal->x = x;
//	temporal->y = y;
//	temporal->valor = valor;
//
//
//	if(! listaInicio)
//	{
//		listaInicio = temporal;
//
//	}
//	else
//	{
//
//	}
//	numerosElementos++;
//
//
//}
void Matriz::insertar(int x, int y, char valor)
{


	lista-> insertarN(x,y,valor);
	nodoHijoY = this->lista->nodoUltimoMovimientoY;
	nodoPadreX = this->lista->nodoUltimoMovimientoX;
//	numX = listaInicio->numNodoX;
//	numY = listaInicio->numNodoY;
//	numCelulas = numY;
//	if(!nodoActual)
//		debug->setDebugString("NO existe Actual");
//	else
//		debug->setDebugString(" existe Actual");
//	if(!nodoPadre)
//		debug->setDebugString("NO existe Padre");
//	else
//		debug->setDebugString(" existe Padre");

}

//char Matriz::obtener(int x, int y) {
//	return listaInicio->buscar(x,y)->valor;
////	if()
////	return actual->valor;
//}

void Matriz::valores() {
//	return;
	Lista * temporal ;
	temporal = lista;
//
//	debug->setDebugString("valores\n");
//	while(temporal)
//	{
//		debug->setDebugString(temporal->x);
//		debug->setDebugString(",");
//		debug->setDebugString(temporal->y);
//		debug->setDebugString(" valor=");
//		debug->setDebugString((int)temporal->valor);
//		debug->setDebugString("\n");
//		temporal = temporal->siguiente;
//	}
	if (lista == NULL)
	{
		debug->setDebugString("Lista vacia\n");
	}

	//debug->setDebugString("Imprimir Todos\n");
	lista->impimirX();
	//debug->setDebugString("Saliendo Imprimir Todos\n");
//	Nueva->impimirY();
}

void Matriz::leerLinea()
{

}

void Matriz::cargarMalla() {
	char temp[30];
	int valor;
	char  letra;
	char *ptr;
	letra = 'a';
	int x = 0;
	int valX = 0;
	int valY = 0;
	int valEstado = 0;

	do
	{
		fread(&letra,sizeof(char),1,archivoTXT);
		for(x = 0 ; letra != '\n' && !feof(archivoTXT) ; x++)
		{
//			debug->setDebugString((int)letra);
			temp[x] = letra;
			valor = fread(&letra,sizeof(char),1,archivoTXT);

		}
//		fread(&letra,sizeof(char),1,archivoTXT);
//		debug->setDebugString((int)letra);
//		debug->setDebugString("\n");
		temp[x] = '\0';
		if(!feof(archivoTXT))
		{
			ptr = strtok(temp," ");//argumentos: frase, caracter delimitador
			valX = atoi(ptr);
			ptr = strtok(NULL, " ");
			valY = atoi(ptr);
			ptr = strtok(NULL, " ");
			valEstado = atoi(ptr);
			insertar(valX,valY,valEstado);
		}


//		debug->setDebugString("Linea leida\n");
	}while(!feof(archivoTXT));
}

bool Matriz::estaVacia() {
	if(lista->inicioX)
		return false;
	else
	{
//		debug->setDebugString("\tVacio");
//		debug->setDebugString(" X: ");
//		debug->setDebugString(lista->numNodoX);
//		debug->setDebugString(" Y: ");
//		debug->setDebugString(lista->numNodoY);
//		debug->setDebugString("\n");
		return true;
	}
}

NodoY * Matriz::buscar(int x, int y)
{
//	debug->setDebugString("Se buscara");
//	debug->setDebugString(" X: ");
//	debug->setDebugString(x);
//	debug->setDebugString(" Y: ");
//	debug->setDebugString(y);
//	debug->setDebugString("\n");
	nodoHijoY = this->lista->buscar(x,y);
	if( nodoHijoY)
	{
		nodoPadreX = this->lista->nodoUltimoMovimientoX;
		return nodoHijoY;
	}
	else
		nodoPadreX = NULL;
//	Lista * temporal ;
//	temporal = listaInicio;
//	while(temporal)
//	{
//		if(temporal->inicioX->x ==  x )
//		{
////			while()
//
////			debug->setDebugString("encontrado ");
////			debug->setDebugString(x);
////			debug->setDebugString(",");
////			debug->setDebugString(y);
////			debug->setDebugString("\n");
////			actual = temporal;
//			return temporal;
//		}
////		debug->setDebugString(temporal->x);
////		debug->setDebugString("\n");
//		temporal = temporal->siguiente;
//	}
	return NULL;
}

void Matriz::eliminar(NodoX * nodoX,NodoY * nodoY) {
//	char valor;
//	NodoY * nodoanterior;
//	NodoY * nodoTemporal;
//	debug->setDebugString("antes de eliminar\n");
//		if(nodoY && nodoX)
//		{
//			nodoTemporal = nodoY;
////			while( nodo)
//		}
//		if(nodo->siguiente == NULL)
//		{
//			return;
//		}
//		else
//			nodo = nodo->siguiente;
//		nodo->eliminar();
//		size--;
	lista->eliminar(nodoX,nodoY);
//	if(lista->numNodoX == 0)
//		delete lista;
}

void Matriz::eliminar(int x,int y) {
//	char valor;
	NodoX * nodoX;
	NodoY * nodoY;
//	debug->setDebugString("antes de eliminar\n");
//		if(nodoY && nodoX)
//		{
//			nodoTemporal = nodoY;
////			while( nodo)
//		}
//		if(nodo->siguiente == NULL)
//		{
//			return;
//		}
//		else
//			nodo = nodo->siguiente;
//		nodo->eliminar();
//		size--;
	nodoY = lista->buscar(x,y);
	nodoX = lista->nodoUltimoMovimientoX;
	lista->eliminar(nodoX,nodoY);
}


//Lista* Matriz::busquedaOrdenadaParaInsertar(int x, int y)
//{
//	Lista * temporal ;
//	temporal = listaMitad;
//	int numeroSegundaMitad;
//	if(listaMitad->x >= x)
//	{
//		while(temporal)
//		{
//			if(temporal->x == x && temporal->y == y)
//			{
//				return temporal;
//			}
//			else
//			{
//				temporal = temporal->siguiente;
//			}
//		}
//	}
//	else
//	{
//		while(temporal)
//		{
//			if(temporal->x == x && temporal->y == y)
//			{
//				return temporal;
//			}
//			else
//			{
//				temporal = temporal->atras;
//			}
//		}
//	}
//	return NULL;
////		while(temporal)
////		{
////			if(temporal->x == x && temporal->y == y)
////			{
//////				debug->setDebugString("Lo encontre\n");
////				return temporal;
////			}
//////			debug->setDebugString(temporal->x);
//////			debug->setDebugString(",");
//////			debug->setDebugString(temporal->y);
//////			debug->setDebugString(" valor+");
//////			debug->setDebugString((int)temporal->valor);
//////			debug->setDebugString("\n");
////			temporal = temporal->siguiente;
////		}
//	return NULL;
//}

//Lista* Matriz::busquedaOrdenada(int x, int y) {
//	Lista * temporal ;
//	temporal = listaMitad;
//	int numeroSegundaMitad;
//	if(listaMitad->x >= x)
//	{
//		while(temporal)
//		{
//			if(temporal->x == x && temporal->y == y)
//			{
//				return temporal;
//			}
//			else
//			{
//				temporal = temporal->siguiente;
//			}
//		}
//	}
//	else
//	{
//		while(temporal)
//		{
//			if(temporal->x == x && temporal->y == y)
//			{
//				return temporal;
//			}
//			else
//			{
//				temporal = temporal->atras;
//			}
//		}
//	}
//	return NULL;
////		while(temporal)
////		{
////			if(temporal->x == x && temporal->y == y)
////			{
//////				debug->setDebugString("Lo encontre\n");
////				return temporal;
////			}
//////			debug->setDebugString(temporal->x);
//////			debug->setDebugString(",");
//////			debug->setDebugString(temporal->y);
//////			debug->setDebugString(" valor+");
//////			debug->setDebugString((int)temporal->valor);
//////			debug->setDebugString("\n");
////			temporal = temporal->siguiente;
////		}
//	return NULL;
//}

void Matriz::inicio() {
//	actual = listaInicio;
	nodoPadreX = lista->inicioX;
	if(nodoPadreX)
		nodoHijoY = nodoPadreX->nodoY;
	else
	{
		nodoHijoY = NULL;
//		debug->setDebugString("Nodo Padre No existe\n");
	}
}

bool Matriz::siguiente() {
	if (!nodoPadreX)
	{
//		debug->setDebugString("No actual\n");
		nodoHijoY = NULL;
		return false;
	}
	else if( !nodoHijoY)
	{
		nodoPadreX = NULL;
		return false;
	}
	if (!nodoHijoY->siguiente)
	{
		if (!nodoPadreX->siguiente)
//		debug->setDebugString("siguiente NO existe\n");
			nodoHijoY = NULL;
		else
		{
			nodoPadreX = nodoPadreX->siguiente;
			nodoHijoY = nodoPadreX->nodoY;
			return true;
		}
		nodoPadreX = NULL;
		nodoHijoY = NULL;
		return false;
	}
//	debug->setDebugString("siguiente existe \n");
	nodoHijoY = nodoHijoY->siguiente;
	return true;
}

void Matriz::vaciar() {

	inicio();
	while(lista)
	{
		if(lista->inicioX)
		{
			inicio();
			eliminar(nodoPadreX,nodoHijoY);
			//		if(listaInicio->inicioX)
			//			debug->setDebugString/("lista no vacia \n");
			//		listaInicio
		}
		else
		{
			return;
		}
	}
}

void Matriz::escribirArchivo(int x, int y, char valor) {
	fprintf(archivoTXT,"%d %d %d\n",x,y,valor);
}

void Matriz::abrirArchivoEscritura(const char * Archivo ) {
	 string frase= "Texto de extrada";
//	 this->nombreArchivo = nombre;
	 nombreArchivo = Archivo;

	 debug->setDebugString("entro en la escritura\n");


//	ficheroSalida.open(nombre.c_str(), ios::out);
	archivoTXT = fopen(Archivo,"w");
	if(archivoTXT)
	{
		debug->setDebugString("Archivo Abierto\n");
	}
	else
	{
		debug->setDebugString("No se abrio el archivo\n");
	}
//	ficheroSalida << frase;
//	fpr


}
void Matriz::abrirArchivoLectura(const char * Archivo ) {
	 string frase= "Texto de extrada";
//	 this->nombreArchivo = nombre;
	 nombreArchivo = Archivo;

	 debug->setDebugString("entro en la Lectura\n");


//	ficheroSalida.open(nombre.c_str(), ios::out);
	archivoTXT = fopen(Archivo,"r");
	if(archivoTXT)
	{
		debug->setDebugString("Archivo Abierto\n");
	}
	else
	{
		debug->setDebugString("No se abrio el archivo\n");
	}
//	ficheroSalida << frase;
//	fpr


}

void Matriz::cerrarArchivo() {
	fclose(archivoTXT);
}

void Matriz::guardarMalla() {
//	Nodo
	inicio();
//	nodoPadreX;
//	nodoHijoY;
	while(nodoPadreX)
	{
		escribirArchivo(nodoPadreX->x,nodoHijoY->y,nodoHijoY->valor);
		siguiente();
	}

	debug->setDebugString("guardado Terminado\n");
}

void Matriz::copiar(Matriz* matriz) {
//	return;
	if(!estaVacia())
		vaciar();
	if(matriz->estaVacia())
		return;

	matriz->inicio();
	do
	{
		insertar(matriz->nodoPadreX->x,matriz->nodoHijoY->y,matriz->nodoHijoY->valor);
	}
	while(matriz->siguiente());
	valores();
}

void Matriz::insertar(Matriz* matriz) {
	matriz->inicio();
	do{
		this->insertar(matriz->nodoPadreX->x,matriz->nodoHijoY->y,matriz->nodoHijoY->valor);
	}while(matriz->siguiente());
}

void Matriz::eliminar(Matriz* matriz) {
	matriz->inicio();
		do{
			this->eliminar(matriz->nodoPadreX->x,matriz->nodoHijoY->y);
		}while(matriz->siguiente());

}
