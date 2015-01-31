/*
 * debug.cpp
 *
 *  Created on: 15/01/2015
 *      Author: xsset
 */

#include "debug.h"


 using namespace std;

DebugClass::DebugClass()
{
	activo = false;
}

void DebugClass::setDebugString(std::string srtingDebug)
{
	if(activo)
		return;
	debugString = srtingDebug;

	cout << srtingDebug;
}

void DebugClass::setDebugString(int intDebug)
{
	if(activo)
		return;

	debugString =wxString::Format(wxT("%i"),intDebug);

	cout << intDebug;
}

void DebugClass::setDebugString(float floatDebug)
{
	if(activo)
		return;

	debugString =wxString::Format(wxT("%f"),floatDebug);

	cout << floatDebug;
}

void DebugClass::setDebugString(char charDebug)
{
	if(activo)
		return;

//	debugString =wxString::Format(wxT("%f"),floatDebug);
//	int dato = charDebug;
	cout << charDebug;
}
void DebugClass::setDebugString(char * charDebug)
{
	if(activo)
		return;

//	debugString =wxString::Format(wxT("%f"),floatDebug);
//	int dato = charDebug;
	cout << charDebug;
}

std::string DebugClass::getDebugString()
{
	return debugString;
}


