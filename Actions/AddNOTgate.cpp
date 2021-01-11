#include "AddNOTGate.h"

AddNOTGate::AddNOTGate(ApplicationManager* pApp) : AddGate<NOT>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::NOT_FANOUT, "Not Gate") {}

void AddNOTGate::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawNot(gInfo);
}