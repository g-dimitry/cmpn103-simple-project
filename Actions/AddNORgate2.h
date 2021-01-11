#pragma once
#include "AddGate.h"
#include "..\Components\NOR2.h"

class AddNORgate2 : public AddGate<NOR2>
{
public:
	AddNORgate2(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
