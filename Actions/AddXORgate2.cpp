#include "AddXORgate2.h"

AddXORgate2::AddXORgate2(ApplicationManager* pApp) : AddGate<XOR2>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::XOR2_FANOUT, "2 Input XOr Gate") {}

void AddXORgate2::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawXOR2(gInfo);
}