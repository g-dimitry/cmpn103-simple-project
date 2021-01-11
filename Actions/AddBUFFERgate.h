#pragma once
#include "AddGate.h"
#include "..\Components\BUFFER.h"

class AddBUFFERgate : public AddGate<BUFFER>
{
public:
	AddBUFFERgate(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
