#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\XOR3.h"

class AddXORgate3 : public AddGate<XOR3>
{
public:
	AddXORgate3(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
