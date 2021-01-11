#include "AddORgate3.h"

AddORgate3::AddORgate3(ApplicationManager* pApp) : AddGate<OR3>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::OR3_FANOUT, "3 Input Or Gate") {}

void AddORgate3::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawOR3(gInfo);
}