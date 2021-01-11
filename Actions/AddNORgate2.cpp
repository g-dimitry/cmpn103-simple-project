#include "AddNORgate2.h"

AddNORgate2::AddNORgate2(ApplicationManager* pApp) : AddGate<NOR2>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::NOR2_FANOUT, "2 Input Nor Gate") {}

void AddNORgate2::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawNOR2(gInfo);
}