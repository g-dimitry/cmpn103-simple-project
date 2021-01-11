#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\AND3.h"

template class AddGate<AND3>;

class AddANDgate3 : public AddGate<AND3>
{
public:
	AddANDgate3(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
