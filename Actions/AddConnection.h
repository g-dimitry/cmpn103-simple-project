#pragma once
#include "./action.h"
#include "../Defs.H"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"
class ApplicationManager;

class AddConnection : public Action
{
private:
public:
	AddConnection(ApplicationManager* pApp);
	~AddConnection();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
