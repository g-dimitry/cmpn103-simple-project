#pragma once
#include "AddGate.h"
#include "../ApplicationManager.h"
#include "..\Components\NAND2.h"

class ApplicationManager;

class AddNANDgate2 : public AddGate<NAND2>
{
public:
	AddNANDgate2(ApplicationManager* pApp);
	void Draw(GraphicsInfo gInfo);
};
