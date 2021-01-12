#include "./Gate.h"

#include "./AND2.h"
#include "./AND3.h"
#include "./BUFFER.h"
#include "./NAND2.h"
#include "./NOR2.h"
#include "./NOT.h"
#include "./OR2.h"
#include "./OR3.h"
#include "./XNOR2.h"
#include "./XOR2.h"
#include "./XOR3.h"
//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut) : m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs; //set no. of inputs of that gate

	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

Gate *Gate::gateFactory(ActionType actionType, GraphicsInfo gInfo, int fanout = 5)
{
	switch (actionType)
	{
	case ADD_Buff:
		return new BUFFER(gInfo, fanout);

	case ADD_INV:
		return new NOT(gInfo, fanout);

	case ADD_AND_GATE_2:
		return new AND2(gInfo, fanout);

	case ADD_OR_GATE_2:
		return new OR2(gInfo, fanout);

	case ADD_NAND_GATE_2:
		return new NAND2(gInfo, fanout);

	case ADD_NOR_GATE_2:
		return new NOR2(gInfo, fanout);

	case ADD_XOR_GATE_2:
		return new XOR2(gInfo, fanout);

	case ADD_XNOR_GATE_2:
		return new XNOR2(gInfo, fanout);

	case ADD_AND_GATE_3:
		return new AND3(gInfo, fanout);

	case ADD_OR_GATE_3:
		return new OR3(gInfo, fanout);

	case ADD_XOR_GATE_3:
		return new XOR3(gInfo, fanout);

	default:
		return NULL;
	}
}

int Gate::getInputsCount()
{
	return this->m_Inputs;
}

InputPin *Gate::getInputPin(int n)
{
	return &(this->m_InputPins[n]);
}
OutputPin *Gate::getOutputPin()
{
	return &(this->m_OutputPin);
}