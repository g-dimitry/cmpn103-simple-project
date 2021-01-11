#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class Save : public Action
{
private:
public:
	Save(ApplicationManager* pApp);
	~Save();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
