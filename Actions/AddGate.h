#pragma once
#include <string>
#include "./action.h"
#include "../Components/Gate.h"
#include "../Defs.H"
class ApplicationManager;

class AddGate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;					//Center point of the gate
	int x1, y1, x2, y2; //Two corners of the rectangluar area
	int width, height, fanout;
	std::string gateTitle;
	Gate* gate;
	ActionType actionType;
public:
	AddGate(ApplicationManager* pApp, int width, int height, int fanout, std::string gateTitle, ActionType actionType);
	~AddGate();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
