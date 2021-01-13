#pragma once
#include "./action.h"
#include "../Defs.H"
#include "../Components/Component.h"

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
