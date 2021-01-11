#pragma once
#include "AddGate.h"
#include "..\Components\OR3.h"

class AddORgate3 : public AddGate<OR3>
{
public:
	AddORgate3(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
