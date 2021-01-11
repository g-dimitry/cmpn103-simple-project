#pragma once
class ApplicationManager;
#include "Defs.h"
#include "Components\Component.h"
#include "./Utils/Array/Array.h"
#include "./Actions/Action.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum
	{
		MaxCompCount = 200,
		MaxActions = 200,
	}; //Max no of Components

private:
	Array<Component*> CompList; //List of all Components (Array of pointers)
	Array<Action*> ActionStack;
	int currentStackPosition;

	Output *OutputInterface; //pointer to the Output Clase Interface
	Input *InputInterface;	 //pointer to the Input Clase Interface

public:
public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface(); //Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output *GetOutput();
	Input *GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component *pComp);
	void RemoveComponent(int ID);
	void RemoveComponents(Array<int> arr);

	bool GetComponentByID(int ID, Component* out);
	bool ComponentCollides(Component* comp);

	//destructor
	~ApplicationManager();
}; 

#include "Actions/AddGate.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddBUFFERgate.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddORgate3.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXORgate3.h"