#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class EditLabel : public Action
{
private:
public:
	EditLabel(ApplicationManager* pApp);
	~EditLabel();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
