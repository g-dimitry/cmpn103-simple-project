#include "AddORgate2.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) : AddGate<OR2>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::OR2_FANOUT, "2 Input Or Gate") {}

void AddORgate2::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawOR2(gInfo);
}