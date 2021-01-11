#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class Deselect : public Action
{
private:
public:
	Deselect(ApplicationManager* pApp);
	~Deselect();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
