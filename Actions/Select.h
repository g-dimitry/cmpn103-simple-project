#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class Select : public Action
{
private:
public:
	Select(ApplicationManager* pApp);
	~Select();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
