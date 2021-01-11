#pragma once
#include "./action.h"
#include "../Defs.H"
class ApplicationManager;

class SimulationMode : public Action
{
private:
public:
	SimulationMode(ApplicationManager* pApp);
	~SimulationMode();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
