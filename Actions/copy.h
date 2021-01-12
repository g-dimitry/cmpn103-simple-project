#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class Copy : public Action
{
private:
public:
	Copy(ApplicationManager* pApp);
	~Copy();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
