#pragma once
#include "AddGate.h"
#include "..\Components\AND3.h"

class AddANDgate3 : public AddGate<AND3>
{
public:
	AddANDgate3(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
