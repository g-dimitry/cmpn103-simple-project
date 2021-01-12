#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class Cut : public Action
{
private:
public:
	Cut(ApplicationManager* pApp);
	~Cut();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
