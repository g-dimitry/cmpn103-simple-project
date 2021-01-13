#pragma once
/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/

#include <fstream>
#include "./InputPin.h"
#include "./OutputPin.h"
#include "./Component.h"
class Connection;

class Gate : public Component
{
protected:
  InputPin *m_InputPins; //Array of input pins of the Gate
  OutputPin m_OutputPin; //The Gate output pin
  int m_Inputs;          //No. of input pins of that Gate.
public:
  Gate(int r_Inputs, int r_FanOut);
  Gate(int r_Inputs, int r_FanOut, int id);
  static Gate* gateFactory(ActionType actionType,GraphicsInfo gInfo, int fanout);
  static Gate* gateFactory(int id, ActionType actionType,GraphicsInfo gInfo, int fanout);
  int getInputsCount();
  virtual InputPin* getInputPin(int n);
	virtual OutputPin* getOutputPin();
  virtual Gate* Load(ActionType actionType, int x1, int x2);
  virtual void Save(ofstream& file);
  static Gate* isGate(Component* comp);
};
