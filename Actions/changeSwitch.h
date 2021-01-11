#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class changeSwitch : public Action
{
private:
public:
	changeSwitch(ApplicationManager* pApp);
	~changeSwitch();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
