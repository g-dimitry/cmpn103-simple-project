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
#include "../Defs.H";
#include "./Connection.h"

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

Gate::Gate(int r_Inputs, int r_FanOut, int id) : m_OutputPin(r_FanOut), Component(id)
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

Gate *Gate::gateFactory(int id, ActionType actionType, GraphicsInfo gInfo, int fanout = 5)
{
	switch (actionType)
	{
	case ADD_Buff:
		return new BUFFER(gInfo, fanout, id);

	case ADD_INV:
		return new NOT(gInfo, fanout, id);

	case ADD_AND_GATE_2:
		return new AND2(gInfo, fanout, id);

	case ADD_OR_GATE_2:
		return new OR2(gInfo, fanout, id);

	case ADD_NAND_GATE_2:
		return new NAND2(gInfo, fanout, id);

	case ADD_NOR_GATE_2:
		return new NOR2(gInfo, fanout, id);

	case ADD_XOR_GATE_2:
		return new XOR2(gInfo, fanout, id);

	case ADD_XNOR_GATE_2:
		return new XNOR2(gInfo, fanout, id);

	case ADD_AND_GATE_3:
		return new AND3(gInfo, fanout, id);

	case ADD_OR_GATE_3:
		return new OR3(gInfo, fanout, id);

	case ADD_XOR_GATE_3:
		return new XOR3(gInfo, fanout, id);

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

Gate *Gate::Load(ActionType actionType, int x1, int y1)
{
	GraphicsInfo gInfo;
	gInfo.x1 = x1;
	gInfo.y1 = y1;
	gInfo.x2 = x1 + UI.Gate_Width;
	gInfo.y2 = y1 + UI.Gate_Height;
	return gateFactory(actionType, gInfo);
}

void Gate::Save(ofstream &file)
{
	ActionType actionType;
	if (dynamic_cast<BUFFER *>(this))
	{
		actionType = ADD_Buff;
	}
	else if (dynamic_cast<NOT *>(this))
	{
		actionType = ADD_INV;
	}
	else if (dynamic_cast<AND2 *>(this))
	{
		actionType = ADD_AND_GATE_2;
	}
	else if (dynamic_cast<OR2 *>(this))
	{
		actionType = ADD_OR_GATE_2;
	}
	else if (dynamic_cast<NAND2 *>(this))
	{
		actionType = ADD_NAND_GATE_2;
	}
	else if (dynamic_cast<NOR2 *>(this))
	{
		actionType = ADD_NOR_GATE_2;
	}
	else if (dynamic_cast<XOR2 *>(this))
	{
		actionType = ADD_XOR_GATE_2;
	}
	else if (dynamic_cast<XNOR2 *>(this))
	{
		actionType = ADD_XNOR_GATE_2;
	}
	else if (dynamic_cast<AND3 *>(this))
	{
		actionType = ADD_AND_GATE_3;
	}
	else if (dynamic_cast<OR3 *>(this))
	{
		actionType = ADD_OR_GATE_3;
	}
	else if (dynamic_cast<XOR3 *>(this))
	{
		actionType = ADD_XOR_GATE_3;
	}
	file << actionType
		 << "\t"
		 << this->getComponentId()
		 << "\t"
		 << this->getLabel()
		 << "\t"
		 << this->getGraphicsInfo().x1
		 << "\t"
		 << this->getGraphicsInfo().y1
		 << endl;
	this->m_OutputPin.getConnections()->forEach([&](Connection *conn) {
		conn->Save(file, this->getComponentId());
	});
}

Gate *Gate::isGate(Component *comp)
{
	return dynamic_cast<Gate *>(comp);
}
