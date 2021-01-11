#pragma once
#include "AddGate.h"
#include "..\Components\NOT.h"

class AddNOTGate : public AddGate<NOT>
{
public:
	AddNOTGate(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
