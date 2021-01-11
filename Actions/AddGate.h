#pragma once
#include <string>
#include "action.h"
#include "../Defs.H"
class ApplicationManager;

template <typename GateType>
class AddGate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;					//Center point of the gate
	int x1, y1, x2, y2; //Two corners of the rectangluar area
	int width, height, fanout;
	std::string gateTitle;
	GateType* gate;
public:
	AddGate(ApplicationManager* pApp, int width, int height, int fanout, std::string gateTitle);
	~AddGate();

	void virtual Draw(GraphicsInfo g) = 0;

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
