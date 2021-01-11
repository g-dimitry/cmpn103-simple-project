#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class Exit : public Action
{
private:
public:
	Exit(ApplicationManager* pApp);
	~Exit();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
