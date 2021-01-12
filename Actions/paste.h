#pragma once
#include "./action.h"
#include "../Defs.H"
#include "../Utils/Array/Array.h"
class Component;
class ApplicationManager;

class Paste : public Action
{
private:
	int Cx, Cy;
	Array<Component*> comps;
public:
	Paste(ApplicationManager* pApp);
	~Paste();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();
};
