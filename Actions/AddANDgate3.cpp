#include "AddANDgate3.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp) : AddGate<AND3>(pApp, UI.Gate_Width, UI.Gate_Width, FANOUT::AND3_FANOUT, "3 Input And Gate") {}

void AddANDgate3::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawAND3(gInfo);
}
