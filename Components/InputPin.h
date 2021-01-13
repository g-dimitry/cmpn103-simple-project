#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "./Pin.h"

class Component; //Forward class declaration
class LED;
class InputPin : public Pin //inherited from class Pin
{
	Component *pComp; //Component at which this pin is associated
public:
	InputPin();
	void setComponent(Component *pCmp); //sets the component of this input pin
	Component *getComponent();					//returns the component of this input pin
	int getPinCount();
	virtual void setStatus(STATUS status);
};

#endif