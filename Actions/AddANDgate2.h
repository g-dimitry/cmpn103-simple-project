#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\AND2.h"

class AddANDgate2 : public AddGate<AND2>
{
public:
	AddANDgate2(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
