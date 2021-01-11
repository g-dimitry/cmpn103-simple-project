#include "AddBUFFERgate.h"

AddBUFFERgate::AddBUFFERgate(ApplicationManager* pApp) : AddGate<BUFFER>(pApp, UI.Gate_Width, UI.Gate_Height, FANOUT::BUFFER_FANOUT, "Buffer Gate") {}

void AddBUFFERgate::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawBUFFER(gInfo);
}