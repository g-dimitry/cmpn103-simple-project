#pragma once
#include <string>
#include "action.h"
#include "../Defs.H";

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
	AddGate(ApplicationManager* pApp, int width, int height, int fanout, std::string gateTitle): Action(pApp) {
		this->width = width;
		this->height = height;
		this->fanout = fanout;
		this->gateTitle = gateTitle;
	}
	~AddGate() {
		delete this->gate;
	}

	void virtual Draw(GraphicsInfo g) = 0;

	void ReadActionParameters()
	{
		//Get a Pointer to the Input / Output Interfaces
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();

		bool shouldEndDrag = false;
		do {
			buttonstate state = pIn->GetMousePosition(Cx, Cy);
			pOut->StartBuffer();

			this->pManager->UpdateInterface();

			int Len = this->width;
			int Wdth = this->height;
			GraphicsInfo GInfo;
			GInfo.x1 = Cx - Len / 2;
			GInfo.x2 = Cx + Len / 2;
			GInfo.y1 = Cy - Wdth / 2;
			GInfo.y2 = Cy + Wdth / 2;

			Component* tmp = new GateType(GInfo, 5);
			bool ComponentCollides = this->pManager->ComponentCollides(tmp);
			if (ComponentCollides) {
				pOut->DrawErrorRectangle(GInfo);
			}
			else {
				this->Draw(GInfo);
			}

			pOut->CreateDesignToolBar();
			pOut->CreateSimulationToolBar();
			pOut->CreateStatusBar();
			pOut->PrintMsg(this->gateTitle + ": Click to add the gate");

			pOut->EndBuffer();

			if (state == BUTTON_DOWN) {
				if (!ComponentCollides) {
					shouldEndDrag = true;
				}
			}
		} while (!shouldEndDrag);
		pOut->ClearStatusBar();
	}

	void Execute()
	{
		ReadActionParameters();

		//Calculate the rectangle Corners
		int Len = this->width;
		int Wdth = this->height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		GateType* pA = new GateType(GInfo, this->fanout);
		this->gate = pA;
		pManager->AddComponent(pA);
	}

	void Undo()
	{
		this->pManager->RemoveComponent(this->gate->getComponentId());
	}

	void Redo()
	{
		this->pManager->AddComponent(this->gate);
	}
};
