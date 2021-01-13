#pragma once
class Connection;
class Gate;
class InputPin;
class OutputPin;
#include "./Component.h"
#include "./Connection.h"
//#include "./InputPin.h"
//#include "./OutputPin.h"


class SWITCH : public Component
{
private:
	OutputPin outPin;

public:
	SWITCH(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();			 //Calculates the output of the AND gate
	virtual void Draw(Output *pOut); //Draws 2-input gate

	virtual int GetOutPinStatus();		  //returns status of outputpin if SWITCH, return -1
	virtual int GetInputPinStatus(int n); //returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s); //set status of Inputpin # n, to be used by connection class.
	virtual SWITCH *clone();

	virtual InputPin *getInputPin(int n);
	virtual OutputPin *getOutputPin();
	virtual void SWITCH::Save(ofstream &file);
};