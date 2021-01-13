#pragma once
class ApplicationManager;
#include "./Defs.h"
#include "./Components/Component.h"
#include "./Utils/Array/Array.h"
#include "./Actions/Action.h"
#include "./GUI/Output.h"
#include "./GUI/Input.h"
#include "./Actions/AddGate.h"
#include "./Actions/AddLED.h"
#include "./Actions/AddSWITCH.h"

#include "./Actions/changeSwitch.h"
#include "./Actions/Delete.h"
#include "./Actions/Deselect.h"
#include "./Actions/DesignMode.h"
#include "./Actions/EditLabel.h"
#include "./Actions/Exit.h"
#include "./Actions/Load.h"
#include "./Actions/Save.h"
#include "./Actions/Select.h"
#include "./Actions/Copy.h"
#include "./Actions/Cut.h"
#include "./Actions/Paste.h"
#include "./Actions/SimulationMode.h"

#include "./Utils/Astar/Astar.h"

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
	Array<Component*> Clipboard;
	int currentStackPosition;

	Output *OutputInterface; //pointer to the Output Clase Interface
	Input *InputInterface;	 //pointer to the Input Clase Interface

public:
public:
	ApplicationManager(); //constructor
	Array<Component*>* getCompList();

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
	void PushToClipboard(Component* comp);

	bool GetComponentByID(int ID, Component** out);
	bool ComponentCollides(Component* comp, Component** collidedComponent = NULL, bool includeConnections = false);
	bool ComponentCollides(GraphicsInfo gInfo, Component** collidedComponent = NULL, bool includeConnections = false);
	int getSelectedComponentsCount();
	int getClipboardCount();
	void deselectAll();
	void copySelectedComponents();
	void cutSelectedComponents();
	void pasteClipboard(int &Cx, int &Cy, Array<Component*>* arr);
	void generateGrid(int grid[][82]);
	bool inputPinHasConnection(InputPin* inputPin);
	//destructor
	~ApplicationManager();
}; 
