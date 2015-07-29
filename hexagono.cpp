/*
 * Hexagono.cpp
 *
 *  Created on: 16/01/2015
 *      Author: xsset
 */

#include "hexagono.h"

Hexagono::Hexagono(int x,int y,int largo,int zoom) {
	// TODO Auto-generated constructor stub
	coordenadas = new Punto [6];
	debug = new DebugClass;

	debug->activo = true;
//	coordenadas[0] = new Punto(x,y);
//	coordenadas[0].setX(x);
//	coordenadas[0].setY(y);
	this->largoLado = largo;
	this->zoom = zoom;
	calcularPuntos(x,y);
	estado  = 0;
	seleccionar = false;
//	this->dc = dc;

}


Hexagono::~Hexagono() {
	// TODO Auto-generated destructor stub
}
void Hexagono::calcularPuntos(int origenX,int origenY)
{
	coordenadas[0].setX(origenX + HEXAGONO01X*largoLado*zoom);
	coordenadas[0].setY(origenY + HEXAGONO01Y*largoLado*zoom);

	coordenadas[1].setX(origenX + HEXAGONO02X*largoLado*zoom);
	coordenadas[1].setY(origenY + HEXAGONO02Y*largoLado*zoom);

	coordenadas[2].setX(origenX + HEXAGONO03X*largoLado*zoom);
	coordenadas[2].setY(origenY + HEXAGONO03Y*largoLado*zoom);

	coordenadas[3].setX(origenX + HEXAGONO04X*largoLado*zoom);
	coordenadas[3].setY(origenY + HEXAGONO04Y*largoLado*zoom);

	coordenadas[4].setX(origenX + HEXAGONO05X*largoLado*zoom);
	coordenadas[4].setY(origenY + HEXAGONO05Y*largoLado*zoom);

	coordenadas[5].setX(origenX + HEXAGONO06X*largoLado*zoom);
	coordenadas[5].setY(origenY + HEXAGONO06Y*largoLado*zoom);

	centro = new Punto();

	centro->setX(( coordenadas[3].getX() - coordenadas[0].getX() )/2 +coordenadas[0].getX());
	centro->setY(( coordenadas[1].getY() - coordenadas[4].getY() )/2 + coordenadas[5].getY());
//	debug->setDebugString("(");
//		 debug->setDebugString(centro->x );
//		 debug->setDebugString("-");
//		 debug->setDebugString(centro->y );
//		 debug->setDebugString(")");
//	debug->setDebugString("\n");
}

int Hexagono::getLargoLado()
{
	return largoLado;
}

void Hexagono::setLargoLado(int largoLado)
{
	this->largoLado = largoLado;
}
int Hexagono::getZoom()
{
	return zoom;
}

void Hexagono::setZoom(int zoom)
{
	this->zoom = zoom;
}

//void Hexagono::paint(bool lineas,wxColour  colorRelleno,wxColour  colorLineas ,wxBufferedPaintDC& dc)
//{
//	wxPoint puntos[6];
////	this->lineas = lineas;
////	this->colorLineas = &colorLineas;
////	this->seleccionar = seleccionar;
//
//	puntos[0]= wxPoint(coordenadas[0].getX()  , coordenadas[0].getY());
//	puntos[1]= wxPoint(coordenadas[1].getX()  , coordenadas[1].getY());
//	puntos[2]= wxPoint(coordenadas[2].getX()  , coordenadas[2].getY());
//	puntos[3]= wxPoint(coordenadas[3].getX()  , coordenadas[3].getY());
//	puntos[4]= wxPoint(coordenadas[4].getX()  , coordenadas[4].getY());
//	puntos[5]= wxPoint(coordenadas[5].getX()  , coordenadas[5].getY());
//
//
//
//
//	if(relleno)
//	{
//		wxBrush brushHatch(colorRelleno, wxSOLID);
//		dc.SetBrush(brushHatch);
//	}
//	else
//	{
//		wxBrush brushHatch(colorRelleno, wxTRANSPARENT);
//		dc.SetBrush(brushHatch);
//	}
//
//
//	wxPen  temPen = dc.GetPen();
//	if(!lineas)
//	{
//		wxPen * pen = new wxPen(colorLineas,1,wxTRANSPARENT);
//
//		dc.DrawPoint(puntos[0]);
//		dc.DrawPoint(puntos[1]);
//		dc.DrawPoint(puntos[2]);
//		dc.DrawPoint(puntos[3]);
//		dc.DrawPoint(puntos[4]);
//		dc.DrawPoint(puntos[5]);
//
//		if(this->seleccionar)
//			 pen = new wxPen(colorLineas,1,wxSOLID);
////		else
//		dc.SetPen(*pen);
//		dc.DrawPolygon(WXSIZEOF(puntos), puntos);   //(WXSIZEOF(punto)-2, punto, -intlargo, -intlargo);
//
//	}
//	else
//	{
//		wxPen * pen = new wxPen(colorLineas,1,wxSOLID);
//		dc.SetPen(*pen);
//		dc.DrawPolygon(WXSIZEOF(puntos), puntos);
//	}
//	dc.SetPen(temPen);
////	if(this->seleccionar)
////		{
//////		wxPen  temPen = dc.GetPen();
////		dc.SetPen(*pen);
////		dc.DrawPolygon(WXSIZEOF(puntos), puntos);   //(WXSIZEOF(punto)-2, punto, -intlargo, -intlargo);
////		dc.SetPen(temPen);
////		}
//
//
//}
bool Hexagono::adentro(Punto * mouse)
{
//	DebugClass * debug = new DebugClass;
//	Punto * centro ;


	if ( detectarTriangulo(&coordenadas[0],&coordenadas[1],centro,mouse) )
	{
		return true;
	}
	if ( detectarTriangulo(&coordenadas[1],&coordenadas[2],centro,mouse) )
		return true;
	if ( detectarTriangulo(&coordenadas[2],&coordenadas[3],centro,mouse) )
		return true;
	if ( detectarTriangulo(&coordenadas[3],&coordenadas[4],centro,mouse) )
		return true;
	if ( detectarTriangulo(&coordenadas[4],&coordenadas[5],centro,mouse) )
		return true;
	if ( detectarTriangulo(&coordenadas[5],&coordenadas[0],centro,mouse) )
		return true;
//	int	initX2 = ( (initX  - ((largo*VALDIVISION)*HexX1)/(VALDIVISION*VALDIVISION)));
//	int	initY2 = ( (initY  + ((largo*VALDIVISION)*HexY1)/(VALDIVISION*VALDIVISION)) );
//	int valor = (( initX - mouseX) * ( initY2 - mouseY) ) -  (( initY - mouseY) * (initX2 - mouseX) ); //1


//	int valor = (( centroX - punto->getX()) * ( initY2 - punto->getY()) ) -  (( centroY - punto->getY()) * (initX2 - punto->getX()) ); //1
		return false;
}
bool Hexagono::detectarTriangulo(Punto * puntoA,Punto * puntoB,Punto * puntoC,Punto * puntoP)
{

//		if  ( (( ( puntoA->getX() - puntoC->getX()) * ( puntoB->getY() - puntoC->getY()) )
//				-  ((  puntoA->getY()  - puntoC->getY()) * ( puntoB->getX() - puntoC->getX()) )) > 0)
//		{
////				debug->setDebugString(" false \n");
//
//			return false;
//		}

		Punto * pointV00 = resta(puntoC,puntoA);
		Punto * pointV01 = resta(puntoB,puntoA);
		Punto * pointV02 = resta(puntoP,puntoA);

		float dot00 = productoPunto(pointV00,pointV00);
		float dot01 = productoPunto(pointV00,pointV01);
		float dot02 = productoPunto(pointV00,pointV02);
		float dot11 = productoPunto(pointV01,pointV01);
		float dot12 = productoPunto(pointV01,pointV02);

		float invDenom = 1 / ( (dot00 * dot11) - (dot01 * dot01));
		float u = ( (dot11 * dot02) - (dot01 * dot12)) * invDenom;
		float v = ( (dot00 * dot12) - (dot01 * dot02)) * invDenom;
		if( (u > 0) && (v > 0) && (u + v < 1) )
		{
			return true;
		}


		return false;
//		debug->setDebugString(" true \n");
}
void Hexagono::setRelleno(bool relleno)
{
	this->relleno = relleno;
}
bool Hexagono::getRelleno()
{
	return relleno;
}

int Hexagono::productoPunto(Punto * puntoA,Punto * puntoB)
{
	return (puntoA->getX()*puntoB->getX() + puntoA->getY()*puntoB->getY());
}
Punto* Hexagono::resta(Punto * puntoA,Punto * puntoB)
{
	Punto * punto;
	punto = new Punto(puntoA->getX()-puntoB->getX(),puntoA->getY()-puntoB->getY());
	return punto;
}

//void Hexagono::paintCoordenadas(wxBufferedPaintDC& dc)
//{
//	 wxString msg;
//	 dc.SetTextForeground(*wxYELLOW );
//
//	 msg =  wxString::Format(wxT("(%i,%i)"), coordenadas[0].getX(), coordenadas[0].getY());
//	 dc.DrawText(msg,  coordenadas[0].getX(), coordenadas[0].getY());
//
//	 msg =  wxString::Format(wxT("(%i,%i)"), coordenadas[1].getX(), coordenadas[1].getY());
//	 dc.DrawText(msg,  coordenadas[1].getX(), coordenadas[1].getY());
//
//	 msg =  wxString::Format(wxT("(%i,%i)"), coordenadas[2].getX(), coordenadas[2].getY());
//	 dc.DrawText(msg,  coordenadas[2].getX(), coordenadas[2].getY());
//
//	 msg =  wxString::Format(wxT("(%i,%i)"), coordenadas[3].getX(), coordenadas[3].getY());
//	 dc.DrawText(msg,  coordenadas[3].getX(), coordenadas[3].getY());
//
//	 msg =  wxString::Format(wxT("(%i,%i)"), coordenadas[4].getX(), coordenadas[4].getY());
//	 dc.DrawText(msg,  coordenadas[4].getX(), coordenadas[4].getY());
//
//	 msg =  wxString::Format(wxT("(%i,%i)"), coordenadas[5].getX(), coordenadas[5].getY());
//	 dc.DrawText(msg,  coordenadas[5].getX(), coordenadas[5].getY());
//
//	 msg =  wxString::Format(wxT("(%i,%i)"), centro->x, centro->y);
//	 dc.DrawText(msg,  centro->x, centro->y);
//}
//wxColour Hexagono::convertirColor(char color)
//{
//	switch (color) {
//	case BLANCO:
//		return (*wxWHITE);
//		break;
//	case NEGRO:
//		return (*wxBLACK);
//		break;
//	case ROJO:
//		return (*wxRED);
//		break;
//	case COLORSELECCION:
//		return (*wxBLUE);
//		break;
//
//	}
//	return (*wxGREEN);
//}



