/*
 * debug.h
 *
 *  Created on: 15/01/2015
 *      Author: xsset
 */
#include <stdio.h>

#ifndef DEBUG_H_
#define DEBUG_H_

class DebugClass {
public:
	DebugClass();
	void setDebugString(int intDebug);
	void setDebugString(float floatDebug);
	void setDebugString(char charDebug);
	void setDebugString(const char * charDebug);
	bool activo;
};

#endif /* DEBUG_H_ */
