#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"

ApplicationManager::ApplicationManager()
{
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component *pComp)
{
	CompList.push(pComp);
}
////////////////////////////////////////////////////////////////////
bool ApplicationManager::GetComponentByID(int ID, Component* out)
{
	Array<Component*> clone = CompList.clone();
	clone.filter([=](Component* comp) {
		if (comp->getComponentId() == ID) {
			return true;
		}
		return false;
		});
	if (clone.getCount() != 0) {
		out = clone.getData()[0];
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::RemoveComponent(int ID)
{
	Component* comp;
	if (this->GetComponentByID(ID, comp)) {
		CompList.filter([=](Component* comp) {
			if (comp->getComponentId() == ID) {
				return false;
			}
			return true;
			});
	}
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::RemoveComponents(Array<int> arr)
{
	arr.forEach([=](int ID) {
		this->RemoveComponent(ID);
		});
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action *pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_CONNECTION:
		//TODO: Create AddConection Action here
		break;

	case EXIT:
		///TODO: create ExitAction here
		break;
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	CompList.forEach([=](Component* comp) {
		comp->Draw(OutputInterface);
		});
}

////////////////////////////////////////////////////////////////////
Input *ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output *ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete OutputInterface;
	delete InputInterface;
}