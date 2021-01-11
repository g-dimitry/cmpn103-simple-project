#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class Load : public Action
{
private:
public:
	Load(ApplicationManager* pApp);
	~Load();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
