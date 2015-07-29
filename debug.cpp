/*
 * debug.cpp
 *
 *  Created on: 15/01/2015
 *      Author: xsset
 */

#include "debug.h"


// using namespace std;

DebugClass::DebugClass()
{
	activo = false;
}

void DebugClass::setDebugString(int intDebug)
{
	if(activo)
		return;


//	cout << intDebug;
	printf("%i",intDebug);
}

void DebugClass::setDebugString(float floatDebug)
{
	if(activo)
		return;


//	cout << floatDebug;
}

void DebugClass::setDebugString(char charDebug)
{
//	if(activo)
//		return;
	printf("%c",charDebug);

//	int dato = charDebug;
//	cout << charDebug;
}
void DebugClass::setDebugString(const char * charDebug)
{
//	if(activo)
//		return;

	printf("%s",charDebug);
//	int dato = charDebug;
//	cout << charDebug;
}



