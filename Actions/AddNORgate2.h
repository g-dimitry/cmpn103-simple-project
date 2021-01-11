#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\NOR2.h"

class ApplicationManager;

class AddNORgate2 : public AddGate<NOR2>
{
public:
	AddNORgate2(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
