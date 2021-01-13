#pragma once
#include <fstream>
#include <string>
#include "./action.h"
#include "../Defs.H"
using namespace std;

class ApplicationManager;

class Load : public Action
{
private:
ifstream in;

public:
	Load(ApplicationManager* pApp);
	~Load();

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();

};
struct ConnectionData
{
	int id, dest, source, pin, x1, y1, x2, y2;
	std::string label;
};
