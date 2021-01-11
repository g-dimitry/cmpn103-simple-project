#pragma once
#include <string>
#include "./action.h"
#include "../Components/SWITCH.h"
#include "../Defs.H"
class ApplicationManager;

class AddSWITCH : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;					//Center point of the gate
	int x1, y1, x2, y2; //Two corners of the rectangluar area
	int width, height, fanout;
	std::string gateTitle;
	Component* gate;
	ActionType actionType;
public:
	AddSWITCH(ApplicationManager* pApp, int width, int height, std::string gateTitle);
	~AddSWITCH();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
