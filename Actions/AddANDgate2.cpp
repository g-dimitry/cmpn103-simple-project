#include "AddANDgate2.h"

AddANDgate2::AddANDgate2(ApplicationManager* pApp) : AddGate<AND2>(pApp, UI.AND2_Width, UI.AND2_Height, FANOUT::AND2_FANOUT, "2 Input And Gate") {

}

void AddANDgate2::Draw(GraphicsInfo gInfo) {
	this->pManager->GetOutput()->DrawAND2(gInfo);
}