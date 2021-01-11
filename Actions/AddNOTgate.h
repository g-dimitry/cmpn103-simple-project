#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\NOT.h"

class ApplicationManager;

class AddNOTGate : public AddGate<NOT>
{
public:
	AddNOTGate(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
