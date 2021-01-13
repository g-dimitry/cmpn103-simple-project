#pragma once
#include <fstream>
#include "./action.h"
#include "../Defs.H"
#include "../Utils/Array/Array.h"
#include "../Components/Connection.h"
class ApplicationManager;

class Save : public Action
{
private:
	ofstream out;

public:
	Save(ApplicationManager *pApp);
	~Save();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
