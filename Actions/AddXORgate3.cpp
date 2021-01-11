#include "AddXORgate3.h"

AddXORgate3::AddXORgate3(ApplicationManager* pApp) : AddGate<XOR3>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::XOR3_FANOUT, "3 Input XOr Gate") {}

void AddXORgate3::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawXOR3(gInfo);
}