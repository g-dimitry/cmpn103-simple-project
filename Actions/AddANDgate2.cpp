#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp) : Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();

	bool shouldEndDrag = false;
	do {
		buttonstate state = pIn->GetMousePosition(Cx, Cy);
		pOut->StartBuffer();

		this->pManager->UpdateInterface();

		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		GraphicsInfo GInfo;
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;

		Component* tmp = new AND2(GInfo, 5);
		bool ComponentCollides = this->pManager->ComponentCollides(tmp);
		if (ComponentCollides) {
		pOut->DrawErrorRectangle(GInfo);
		}
		else {
		pOut->DrawAND2(GInfo);
		}

		pOut->CreateDesignToolBar();
		pOut->CreateSimulationToolBar();
		pOut->CreateStatusBar();
		pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

		pOut->EndBuffer();

		if (state == BUTTON_DOWN) {
			if (!ComponentCollides) {
				shouldEndDrag = true;
			}
		}
	} while (!shouldEndDrag);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	AND2 *pA = new AND2(GInfo, AND2_FANOUT);
	this->gate = pA;
	pManager->AddComponent(pA);
}

void AddANDgate2::Undo()
{
	this->pManager->RemoveComponent(this->gate->getComponentId());
}

void AddANDgate2::Redo()
{
	this->pManager->AddComponent(this->gate);
}
