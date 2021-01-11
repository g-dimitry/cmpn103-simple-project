#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\BUFFER.h"

class ApplicationManager;

class AddBUFFERgate : public AddGate<BUFFER>
{
public:
	AddBUFFERgate(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
