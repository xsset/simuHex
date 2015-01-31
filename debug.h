/*
 * debug.h
 *
 *  Created on: 15/01/2015
 *      Author: xsset
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <wx/dcbuffer.h>
#include <wx/pen.h>
#ifndef DEBUG_H_
#define DEBUG_H_

class DebugClass {
public:
	DebugClass();
	void setDebugString(std::string);
	void setDebugString(int intDebug);
	void setDebugString(float floatDebug);
	void setDebugString(char charDebug);
	void setDebugString(char * charDebug);

	std::string getDebugString();
	bool activo;
private:
	std::string debugString;
//	istring data = NULL;
};

#endif /* DEBUG_H_ */
