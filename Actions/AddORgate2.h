#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\OR2.h"

class ApplicationManager;

class AddORgate2 : public AddGate<OR2>
{
public:
	AddORgate2(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
