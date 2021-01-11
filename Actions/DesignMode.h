#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class DesignMode : public Action
{
private:
public:
	DesignMode(ApplicationManager* pApp);
	~DesignMode();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
