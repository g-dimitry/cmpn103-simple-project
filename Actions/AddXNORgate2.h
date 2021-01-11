#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\XNOR2.h"

class ApplicationManager;

class AddXNORgate2 : public AddGate<XNOR2>
{
public:
	AddXNORgate2(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
