#pragma once
#include "AddGate.h"
#include "..\Components\XOR2.h"

class AddXORgate2 : public AddGate<XOR2>
{
public:
	AddXORgate2(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
