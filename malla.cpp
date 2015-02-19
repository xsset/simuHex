//
//  hexagono.c
//  wxhello01
//
//  Created by Julio Cesar Cabrera on 13/01/14.
//  Copyright (c) 2014 Julio Cesar Cabrera. All rights reserved.
//


#include "malla.h"





//MyFrame::MyFrame(const wxString& title)
Malla::Malla(Cursor * cursor)
{
	this->debug= new DebugClass();
	this->cursor = cursor;
	this->Zoom = 1;
	this->largo = 1;
	hexagono = new Hexagono(0,0,1,Zoom);
	lineas = true;
	numHexagonalX = 0;
	numHexagonalY = 0;
	matriz = new Matriz();
	colorRelleno = (*wxGREEN);
	colorLineas = (*wxGREEN);
	viewInicialX = 0;
	viewInicialY = 0;
	viewFinalX = 0;
	viewFinalY = 0;
	PuntoInicial = new Punto();
	evoluciones = 0;
	vecinos = false;
	mVecinos = new Matriz();
	mLeidos = new Matriz();
}
void Malla::paint(int ventanaLargo, int ventanaAncho,bool lineas,int largoLado,int zoom,wxColour colorMargenes ,wxBufferedPaintDC& dc )
{
	this->Zoom = zoom;
	this->lineas = lineas;
	this->colorLineas = colorMargenes;
	hexagono->setZoom(zoom);
//	hexagono->seleccionar = false;
	numHexagonalX =ventanaLargo/((HEXAGONO04X-HEXAGONO02X)*largoLado*zoom);
	numHexagonalY =ventanaAncho/(HEXAGONO03Y*largoLado*zoom);

	viewFinalX = viewInicialX + numHexagonalX;
	viewFinalY =  viewInicialY + numHexagonalY;
//	debug->setDebugString("Coordenadas\n");
//	debug->setDebugString("Inicial X: ");
//	debug->setDebugString(viewInicialX);
//	debug->setDebugString(" Inicial Y: ");
//	debug->setDebugString(viewInicialY);
//	debug->setDebugString(" Final X: ");
//	debug->setDebugString(" NumHexagonal  X: ");
//	debug->setDebugString(numHexagonalX);
//	debug->setDebugString(" NumHexagonal Y: ");
//	debug->setDebugString(numHexagonalY);
//	debug->setDebugString(" Final X: ");
//	debug->setDebugString(viewFinalX);
//	debug->setDebugString(" Final Y: ");
//	debug->setDebugString(viewFinalY);
//	debug->setDebugString("\n");

	largo = largoLado;
	this->Zoom = zoom;


	for(int x = viewInicialX; x < viewFinalX ; x++)
	{
		for(int y = viewInicialY; y < viewFinalY ; y++)
		{
//			PuntoInicial->y =
			if(x %2)
			{
				PuntoInicial->x = (x-viewInicialX)*(HEXAGONO04X-HEXAGONO02X)*largoLado*zoom;
				PuntoInicial->y = y*HEXAGONO03Y*largoLado*zoom + HEXAGONO01Y*largoLado*zoom;
//				wxPen pen(*wxBLUE, 1);
//				dc.SetPen(pen);
			}
			else
			{
				PuntoInicial->x = (x-viewInicialX)*(HEXAGONO04X-HEXAGONO02X )*largoLado*zoom;
				PuntoInicial->y = y*HEXAGONO03Y	*largoLado*zoom;
//				wxPen pen(*wxYELLOW, 1);
//				dc.SetPen(pen);
//				hexagono->calcularPuntos(,);
			}
//			debug->setDebugString("Nueva CoorX ");
//			debug->setDebugString(PuntoInicial->x -coordenadaVirtualX(viewInicialX));
//			debug->setDebugString("\n");
			hexagono->calcularPuntos(PuntoInicial->x,PuntoInicial->y);
			matriz->buscar(x,y);
//			return;
			if(matriz->nodoHijoY)
			{
				this->colorRelleno = hexagono->convertirColor(matriz->nodoHijoY->valor);
				hexagono->relleno = true;
				hexagono->estado = matriz->nodoHijoY->valor;
			}
			else
			{
				hexagono->relleno = false;
			}

			if (hexagono->adentro(cursor))
			{
//				hexagono->setRelleno(false);
				hexagono->seleccionar = true;
//				debug->setDebugString(cursor->color +48);
//				this->colorRelleno = hexagono->convertir(cursor->color);
				this->colorLineas =  hexagono->convertirColor(cursor->color);
//				hexagono->relleno = true;
//				hexagono->paint(colorMargenes, dc);
//				hexagono->paintCoordenadas(dc);

			}
			else
			{
				this->colorLineas = colorMargenes;
			}
			if(vecinos)
			{

			//					debug->setDebugString("Vecino Entrar\n");
			//					debug->setDebugString(coordenadaVirtualX(cursor->x));
			//					debug->setDebugString(" ");
			//					debug->setDebugString(coordenadaVirtualY(cursor->x,cursor->y));
			//					debug->setDebugString("\n");
			//					busquedaTodosVecinos(coordenadaVirtualX(cursor->x),coordenadaVirtualY(cursor->x,cursor->y), matriz,mVecinos,mLeidos);
			//					this->colorLineas =  hexagono->convertirColor(COLORSELECCION);
			//					hexagono->seleccionar = true;
			//					debug->setDebugString("Listar Vecinos\n");
			//					mVecinos->valores();
			//					debug->setDebugString("Fin de la lista Vecinos\n");
			//					mVecinos->vaciar();
								if( matriz->buscar(coordenadaVirtualX(cursor->x),coordenadaVirtualY(cursor->x,cursor->y)))
								{
									if( matriz->buscar(coordenadaVirtualX(cursor->x),coordenadaVirtualY(cursor->x,cursor->y))->valor == BLANCO )
									{
										mLeidos->vaciar();
									}
									else
									{
//										debug->setDebugString("Vecino Entrar\n");
//										debug->setDebugString(coordenadaVirtualX(cursor->x));
//										debug->setDebugString(" ");
//										debug->setDebugString(coordenadaVirtualY(cursor->x,cursor->y));
//										debug->setDebugString("\n");
										if(mLeidos->estaVacia())
										{
											busquedaTodosVecinos(coordenadaVirtualX(cursor->x),coordenadaVirtualY(cursor->x,cursor->y), matriz,mVecinos,mLeidos);
										}
										else if(mLeidos->buscar(x,y))
										{
											if(mLeidos->buscar(x,y)->valor != BLANCO)
											{
												this->colorLineas =  hexagono->convertirColor(COLORSELECCION);
												hexagono->seleccionar = true;
												//					debug->setDebugString("Listar Vecinos\n");
												//					mVecinos->valores();
												//					debug->setDebugString("Fin de la lista Vecinos\n");
												//					mVecinos->vaciar();

												this->colorRelleno = hexagono->convertirColor(COLORSELECCION);
												hexagono->setRelleno(TRUE);
											}
										}
									}
								}
								else
								{
									mLeidos->vaciar();
								}
								//					paint(int ventanaLargo, int ventanaAncho,bool lineas,int largoLado,int zoom,wxColour colorMargenes ,wxBufferedPaintDC& dc )

			}
			else
			{
			}

//			debug->setDebugString(hexagono->estado);
			hexagono->paint(lineas,this->colorRelleno,colorLineas, dc);
			hexagono->setRelleno(false);
			hexagono->seleccionar = false;
//			hexagono->paintCoordenadas(dc);

		}
	}
}
void Malla::clickCoordenadas(int x,int y,char color)
{

	int inicioHexagonoX;
	int inicioHexagonoY;

	inicioHexagonoX = coordenadaVirtualX(x);
	inicioHexagonoY = coordenadaVirtualY(x,y);

//	matriz->escribirArchivo(x,y,color);

//	Lista * list = new Lista();
//	NodoX * nodX;
//	nodX = list->insertarX(10);
//	list->insertarY(2,nodX,color);
//	list->insertarY(4,nodX,color);
//	list->insertarY(6,nodX,color);
//	list->insertarY(-1,nodX,color);
//	list->insertarY(3,nodX,color);
//	list->insertarY(3,nodX,color);
//	list->insertarY(10,nodX,color);
////
////
//	list->impimirX();
//	list->impimirY(nodX);

//	debug->setDebugString("CLICKCOORDENADAS ");
//	debug->setDebugString(inicioHexagonoX);
//	debug->setDebugString(",");
//	debug->setDebugString(inicioHexagonoY);
//	debug->setDebugString(" ");
//	debug->setDebugString(color);
//	debug->setDebugString("\n");


//
//	debug->setDebugString("coor ");
//	debug->setDebugString(x);
//	debug->setDebugString(",");
//	debug->setDebugString(y);
//	debug->setDebugString("\n");
//
//	debug->setDebugString("zoom ");
//	debug->setDebugString(Zoom);
//	debug->setDebugString(",");
//	debug->setDebugString(largo);
//	debug->setDebugString("\n");

//	if(matriz)
//		debug->setDebugString("existe \n ");
	NodoY * nodo = matriz->buscar(inicioHexagonoX,inicioHexagonoY);

	if(color == BLANCO )
	{
		if(nodo != NULL)
		{
			debug->setDebugString("es blanco \n");
//			matriz->eliminar(nodo);
		}
	}
	else if(nodo)
	{
		nodo->valor = color;

	}
	else
	{
		matriz->insertar(inicioHexagonoX,inicioHexagonoY,color);
	}


//	debug->setDebugString("salio click\n");

//	matriz->valores();
//	int NumX =((ventanaX)/(hipotenusa*HexX1*3)-1) ;//canvas.width/  (largo*HexX1*3) -1;
//	int NumY = (ventanaY)/ (hipotenusa*HexY1*2.1)-1 ; //canvas.height/ (largo*HexY1*2.5) ;

//	std::string result;
//	result = wxString::Format(wxT("%i %i "),numHexagonalX,numHexagonalY);


//	debug->setDebugString(result);
//	matriz->vaciar();
}

int Malla::coordenadasMatrizX() {
//	int inicioHexagonoX;

	return cursor->x/((HEXAGONO04X-HEXAGONO02X)*largo*Zoom) ;
}

int Malla::coordenadasMatrizY() {
//	debug->setDebugString("coor ");
//	debug->setDebugString(x);
//	debug->setDebugString(",");
//	debug->setDebugString(y);
//	debug->setDebugString("\n");
//
//	debug->setDebugString("zoom ");
//	debug->setDebugString(Zoom);
//	debug->setDebugString(",");
//	debug->setDebugString(largo);
//	debug->setDebugString("\n");
//
//	debug->setDebugString("Matriz Y :");

	if((coordenadasMatrizX()) %2)
	{
//		debug->setDebugString(HEXAGONO03Y*largo*Zoom + HEXAGONO01Y*largo*Zoom);
//		debug->setDebugString("-");
//		debug->setDebugString((float)cursor->y/(float)HEXAGONO03Y*(float)largo*(float)Zoom); //+ (float)HEXAGONO01Y*(float)largo*(float)Zoom));
//		debug->setDebugString("\n");
//		debug->setDebugString("\n");
//		hexagono->calcularPuntos(x*(HEXAGONO04X-HEXAGONO02X)*largoLado*zoom ,y*HEXAGONO03Y*largoLado*zoom + HEXAGONO01Y*largoLado*zoom);
		return (cursor->y - (HEXAGONO01Y*largo*Zoom))/(HEXAGONO03Y*largo*Zoom  ) ;
//
	}
	else
	{
//		debug->setDebugString(HEXAGONO03Y*largo*Zoom);
//		debug->setDebugString("-");
//		debug->setDebugString((float)cursor->y/((float)HEXAGONO03Y*(float)largo*(float)Zoom));
//		debug->setDebugString("\n");
//		debug->setDebugString("\n");
//		hexagono->calcularPuntos(x*(HEXAGONO04X-HEXAGONO02X )*largoLado*zoom,y*HEXAGONO03Y*largoLado*zoom);
		return cursor->y/(HEXAGONO03Y*largo*Zoom) ;
	}
//	coor 186,418
//	zoom 7,1
//	Matriz Y :210-1
//
//	coor 186,421
//	zoom 7,1
//	Matriz Y :210-2


}

void Malla::evolucionar() {

	Matriz * matrizTemporal= new Matriz();
	Matriz * matrizVecinos= new Matriz();

	NodoX * nodoPadreTemporal;
	NodoY * nodoHijoTemporal;


	//			NodoY ;
//	char valor;
	matriz->inicio();

	//			matriz->inicio();
	if(! matriz->nodoHijoY)
		debug->setDebugString("No existe Actual\n");


	while (matriz->nodoHijoY)
	{
//		debug->setDebugString("antes de evolucionar nodo\n");
		nodoPadreTemporal = matriz->nodoPadreX;
		nodoHijoTemporal = matriz->nodoHijoY;
		calculaVecindad(matriz->nodoPadreX->x,matriz->nodoHijoY->y,matriz->nodoHijoY->valor,matriz,matrizTemporal,matrizVecinos);
		matriz->nodoPadreX = nodoPadreTemporal;
		matriz->nodoHijoY = nodoHijoTemporal;
		//				if (valor != BLANCO)
		//					matrizTemporal->insertar(matriz->actual->x,matriz->actual->y,valor);
//		debug->setDebugString("Nodo X: ");
//		debug->setDebugString(matriz->nodoPadre->x);
//		debug->setDebugString("Nodo Y: ");
//		debug->setDebugString(matriz->nodoActual->y);
//		debug->setDebugString("\n");
		matriz->siguiente();
	}

	matrizVecinos->inicio();

	while (matrizVecinos->nodoHijoY)
	{
//		debug->setDebugString("NodoVecino X: ");
//		debug->setDebugString(matrizVecinos->nodoPadre->x);
//		debug->setDebugString("NodoVecino Y: ");
//		debug->setDebugString(matrizVecinos->nodoActual->y);
//		debug->setDebugString("NodoVecino Valor: ");
//		debug->setDebugString(matrizVecinos->nodoActual->valor);
//		debug->setDebugString("\n");
		nodoPadreTemporal = matrizVecinos->nodoPadreX;
		nodoHijoTemporal = matrizVecinos->nodoHijoY;
		calculaVecindad(matrizVecinos->nodoPadreX->x,matrizVecinos->nodoHijoY->y,matrizVecinos->nodoHijoY->valor,matriz,matrizTemporal,matrizVecinos);
		matrizVecinos->nodoPadreX = nodoPadreTemporal;
		matrizVecinos->nodoHijoY = nodoHijoTemporal;
		matrizVecinos->siguiente();
	}
//	matrizTemporal->inicio();
//	while (matrizTemporal->nodoActual)
//	{
//		debug->setDebugString("NodoTemporal X: ");
//		debug->setDebugString(matrizTemporal->nodoPadre->x);
//		debug->setDebugString("NodoTemporal Y: ");
//		debug->setDebugString(matrizTemporal->nodoActual->y);
//		debug->setDebugString("NodoVecino Valor: ");
//		debug->setDebugString(matrizTemporal->nodoActual->valor);
//		debug->setDebugString("\n");
//		matrizTemporal->siguiente();
//	}


	//			matriz->vaciar();
	delete matriz;
	matriz = matrizTemporal;
	evoluciones++;

}

//void Malla::calculaVecindad(Matriz * matrizTemporal) {
//	//calculaVecindad(this->matriz,matrizTemporal,new Matriz(),3);
////	calculaVecindad(this->matriz,matrizTemporal,new Matriz(),3);
//}
void Malla::calculaVecindad(int x, int y , int valor,Matriz * matriz, Matriz * matrizTemporal,Matriz * vecinos)
{

			// console.log("h "+h + " m "+m + " radio " +radio );
//			rondas--;
//			if(rondas< 1)
//				return;

			int numNegro = 0;
			int numRojo = 0;
			int numBlanco = 0;

			int  i = 0;
			int  j = 0;
			char  k = 0;


//			NodoY * actual;
			int coordenadaX;
			int coordenadaY;
			char valorActual ;

//			if(vecinos->listaInicio->inicioX)
//			{
//				vecinos->inicio();
//				actual= vecinos->nodoActual;
//				coordenadaX = vecinos->nodoPadre->x;
//				coordenadaY = vecinos->nodoActual->y;
//				valorActual = vecinos->nodoActual->valor;
//			}
//			else
//			{
//				actual= matriz->nodoActual;
				coordenadaX = x;
				coordenadaY = y;
				valorActual = valor;
//			}
			char valorContar;
			char valorCalculado;
			NodoY * busqueda;

//			debug->setDebugString("antes de calcular la vecindad \n ");
//
//			debug->setDebugString("coordenadas actuales: ");
//			debug->setDebugString(coordenadaX);
//			debug->setDebugString(" - ");
//			debug->setDebugString(coordenadaY);
//			debug->setDebugString(" \n");

//			matriz->valores();

			for(k = 0 ; k < 7 ; k++)
			{
				switch(k)
				{
				case 0: //superior-inferior Derecho
					i = coordenadaX + 1;

					if(coordenadaX%2  )
						j = coordenadaY + 1;
					else
						j = coordenadaY - 1;
					break;
				case 1:  //mitad Izquierda
					i = coordenadaX - 1;
					j = coordenadaY;
					break;
				case 2:   //Superior En medio
					i = coordenadaX;
					j = coordenadaY + 1;
					break;
				case 3:   //Inferior En medio
					i = coordenadaX;
					j = coordenadaY - 1;
					break;
				case 4:   //Superior-Inferior Izquierda
					i = coordenadaX - 1;

					if(coordenadaX%2  )
						j = coordenadaY + 1;
					else
						j = coordenadaY -1;

					break;

				case 5:   //mitad Derecha
					i = coordenadaX + 1;
					j = coordenadaY;
					break;
				default:
					i = coordenadaX;
					j = coordenadaY;
					break;
				}
//				debug->setDebugString("coordenadas evoluciones: ");
//				debug->setDebugString(i);
//				debug->setDebugString(" - ");
//				debug->setDebugString(j);
//				debug->setDebugString(" \n");
				busqueda = matriz->buscar(i,j);//arrayTemporal[i][j];
//				debug->setDebugString(" despues de buscar\n");


				if(!busqueda)
				{
					numBlanco++;
					if(valorActual != BLANCO)
					{
						if(i != coordenadaX || j != coordenadaY)
						{
//							debug->setDebugString(" Antes de insertar vecino\n");
							vecinos->insertar(i,j,BLANCO);

						}
					}
					//	c
				}
				else
				{
//					vecinos->insertar(busqueda->x,busqueda->y,busqueda->valor);

					valorContar = busqueda->valor;

					if(valorContar == BLANCO)
					{
						numBlanco++;
					}

					else if (valorContar == NEGRO)
					{
						numNegro++;
					}
					else
					{
						numRojo++;
					}
				}



			}//fin del for

/*       							 0 1 2 3 4 5 6 7
						             ...............
						          0: 0 1 2 1 2 2 2 2
						          1: 0 2 2 1 2 2 2
						          2: 0 0 2 1 2 2
						     i=2s 3: 0 2 2 1 2
						          4: 0 0 2 1
						          5: 0 0 2
						          6: 0 0
						          7: 0


 */
//				debug->setDebugString("valor: ");
//				debug->setDebugString();
//				debug->setDebugString("\n");

//				debug->setDebugString("suma\n");
//				debug->setDebugString("Negro: ");
//				debug->setDebugString(numNegro);
//				debug->setDebugString(" Rojo: ");
//				debug->setDebugString(numRojo);
//				debug->setDebugString(" Blanco: ");
//				debug->setDebugString(numBlanco);
//				debug->setDebugString("\n");



			if ( numRojo == 2 ) //columna 2
			{
				valorCalculado =  NEGRO;
			}
			else if (numRojo >= 4 )     //columna 4,5,6,7
			{
				valorCalculado =  NEGRO;
			}
			else if (numRojo == 3)   //columna 3
			{
				valorCalculado =  ROJO;
			}
			else if (numRojo == 0) // columna 0
			{
				valorCalculado =  BLANCO;
			}

			else if(numNegro == 0 ) //  columna 1
			{
				valorCalculado =  ROJO;
			}
			else if( numNegro == 3)
			{
				valorCalculado =  NEGRO;
			}
			else if( numNegro == 1 )
			{
				valorCalculado =  NEGRO;
			}
			else
			{
				valorCalculado =  BLANCO;
			}

			if (valorCalculado != BLANCO)
			{

				matrizTemporal->insertar(coordenadaX,coordenadaY,valorCalculado);
			}

//			vecinos->inicio();
//			while(vecinos->nodoActual)
//			{
//				debug->setDebugString("Antes de la recursividad del nodo: ");
//				debug->setDebugString(coordenadaX);
//				debug->setDebugString(",");
//				debug->setDebugString(coordenadaY);
//				debug->setDebugString("\n");
//
//				vecinos->valores();
//				vecinos->inicio();
//				if( vecinos->nodoPadre->x == coordenadaX && vecinos->nodoActual->y == coordenadaY  )
//				{
//
//					debug->setDebugString("se eliminara de vecinos: ");
//					debug->setDebugString(coordenadaX);
//					debug->setDebugString(",");
//					debug->setDebugString(coordenadaY);
//					debug->setDebugString("\n");
//					vecinos->eliminar(vecinos->nodoPadre, vecinos->nodoActual);
//				}
//				calculaVecindad(matriz,matrizTemporal,vecinos,rondas);
//				vecinos->valores();
//				//					if(vecinos->nodoActual)
//				//						debug->setDebugString("Existe nodoActual\n");
//				//					else
//				//						debug->setDebugString("No Existe nodoActual\n");
//
//
//				debug->setDebugString("saliendo de recursividad\n");
//
//			}

//				return valorCalculado;
				//console.log(" numRojo == 2  ");
//			}
//			numBlanco = 0;
//			numNegro = 0;
//			numRojo = 0;
}

void Malla::aleatorio() {
//	debug->setDebugString("Aleatorio \n");
	aleatorio(numHexagonalX,numHexagonalY);
//	matriz->valores();
}

int Malla::coordenadaVirtualX(int x) {
	return coordenadasMatrizX() + viewInicialX;
}

int Malla::coordenadaVirtualY(int x, int y) {
	return coordenadasMatrizY() + viewInicialY;
}

void Malla::aleatorio(int x, int y) {

	int varRandom;

	for(int i = 0; i < x ; i++)
	{
		for(int j = 0; j < y ; j++)
		{
			varRandom = rand() % 3;
//			if( varRandom)
				matriz->insertar(i+viewInicialX,j+viewInicialY,varRandom );
//			debug->setDebugString(i);
//			debug->setDebugString(",");
//			debug->setDebugString(j);
//			debug->setDebugString("-");
//			debug->setDebugString(varRandom);
//			debug->setDebugString("\n");
		}
	}
}

void Malla::busquedaTodosVecinos(int x,int y,Matriz* matriz, Matriz* vecinos, Matriz* leidos)
{
	NodoY *nodoY;
	NodoX *nodoX;

//	debug->setDebugString("Buscar ");
//	debug->setDebugString(x);
//	debug->setDebugString(" ");
//	debug->setDebugString(y);
//	debug->setDebugString("\n");

	vecinos->inicio();
	if(vecinos->nodoPadreX)
	{
		if(vecinos->buscar(x,y))
		{
//			debug->setDebugString("\tEliminando nodo de vecinos\n");
			vecinos->eliminarMatriz(x,y);
		}
	}
//	else
//	{
//		debug->setDebugString("\tNo existe nodo Vecinos\n");
//
//	}
	//si ya esta leido el que buscamos ya no continua
	if(leidos->buscar(x,y))
	{
//		debug->setDebugString("Valor ya leido\n");

		vecinos->inicio();
		//
		if(vecinos->nodoPadreX)
		{
//			debug->setDebugString("\t ****Buscar vecinos**** \n ");
			busquedaTodosVecinos(vecinos->nodoPadreX->x,vecinos->nodoHijoY->y,matriz,vecinos,leidos);
		}
//		else
//		{
//			debug->setDebugString("\t ****FIN de los vecinos**** \n ");
//		}

		return;
	}


//	debug->setDebugString("Insertar ");
//	debug->setDebugString(x);
//	debug->setDebugString(" ");
//	debug->setDebugString(y);
//	debug->setDebugString("\n");

	nodoY = matriz->buscar(x,y);
	//se inserta x y y
	if (nodoY)
		leidos->insertar(x,y,nodoY->valor);
	else
		leidos->insertar(x,y,BLANCO);

//	nodoY = NULL;

	//si existe en los vecinos se elimina
//	debug->setDebugString("Inicio imprimir leidos\n");
//	leidos->valores();
//	debug->setDebugString("Fin imprimir leidos\n");
//
//
//	debug->setDebugString("Inicio imprimir Vecinos\n");
//	vecinos->valores();
//	debug->setDebugString("Fin imprimir Vecinos\n");


	//
//	if(!leidos->buscar(x,y))
//	{
		//si existe en la matriz
		nodoY = matriz->buscar(x,y);
		if(nodoY)
		{
			nodoX = matriz->nodoPadreX;
			//si el nodoY es blanco no se busca los vecinos
			if(nodoY->valor!=BLANCO)
			{
//				for(int x = 6 ; x > 0; x--)
//				{
//					leidos->insertar(nodoX->x,nodoY->y,COLORSELECCION);
//					leidos->valores();
//				debug->setDebugString("\t Buscar vecinos \n ");
				busquedaVecinos(matriz,vecinos,x,y);
//					vecinos->valores();
//				}
			}
//			else
//			{
//				debug->setDebugString("\t El nodo es blanco \n ");
//			}
//	leidos->inicio();
//			vecinos->inicio();
//			if(vecinos->nodoPadreX)
//				busquedaTodosVecinos(vecinos->nodoPadreX->x,vecinos->nodoHijoY->y,matriz,vecinos,leidos);
		}
//	}

	//
//	if(vecinos->buscar(x,y))
//	{
////		vecinos->eliminarMatriz(x,y);
//		vecinos->inicio();
//		if(vecinos->nodoPadreX)
//			busquedaTodosVecinos(vecinos->nodoPadreX->x,vecinos->nodoHijoY->y,matriz,vecinos,leidos);
//	}
//			{
//			}
//	}while();
		vecinos->inicio();
		//
		if(vecinos->nodoPadreX)
		{
//			debug->setDebugString("\t ****Buscar vecinos 2**** \n ");
			busquedaTodosVecinos(vecinos->nodoPadreX->x,vecinos->nodoHijoY->y,matriz,vecinos,leidos);
		}
//		else
//		{
//			debug->setDebugString("\t ****FIN de los vecinos 2**** \n ");
//		}

}

void Malla::busquedaVecinos(Matriz* matriz,Matriz * vecinos, int coordenadaX, int coordenadaY) {

//	debug->setDebugString("Inicio busquedaVecinos leidos\n");
	int i = 0;
	int j = 0;


	NodoY * nodoY;
	for(int k = 0; k < 6 ; k++)
	{
		switch(k)
		{
		case 0: //superior-inferior Derecho
			i = coordenadaX + 1;

			if(coordenadaX%2  )
				j = coordenadaY + 1;
			else
				j = coordenadaY - 1;
			break;
		case 1:  //mitad Izquierda
			i = coordenadaX - 1;
			j = coordenadaY;
			break;
		case 2:   //Superior En medio
			i = coordenadaX;
			j = coordenadaY + 1;
			break;
		case 3:   //Inferior En medio
			i = coordenadaX;
			j = coordenadaY - 1;
			break;
		case 4:   //Superior-Inferior Izquierda
			i = coordenadaX - 1;

			if(coordenadaX%2  )
				j = coordenadaY + 1;
			else
				j = coordenadaY -1;

			break;

		case 5:   //mitad Derecha
			i = coordenadaX + 1;
			j = coordenadaY;
			break;
			//	default:
			//		i = coordenadaX;
			//		j = coordenadaY;
			//		break;
		}
		nodoY = matriz->buscar(i,j);
		if(nodoY)
			vecinos->insertar(i,j,nodoY->valor);
		else
			vecinos->insertar(i,j,BLANCO);
	}
//	vecinos->valores();
//	debug->setDebugString("Terminando busquedaVecinos leidos\n");
}
