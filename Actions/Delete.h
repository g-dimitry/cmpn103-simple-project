#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class Delete : public Action
{
private:
public:
	Delete(ApplicationManager* pApp);
	~Delete();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
