#include "AddNANDgate2.h"

AddNANDgate2::AddNANDgate2(ApplicationManager* pApp) : AddGate<NAND2>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::NAND2_FANOUT, "2 Input NAnd Gate") {}

void AddNANDgate2::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawNAND2(gInfo);
}