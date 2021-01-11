#include "AddXNORgate2.h"

AddXNORgate2::AddXNORgate2(ApplicationManager* pApp) : AddGate<XNOR2>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::XNOR2_FANOUT, "2 Input XNor Gate") {}

void AddXNORgate2::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawXNOR2(gInfo);
}