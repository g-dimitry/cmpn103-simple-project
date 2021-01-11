#include "ApplicationManager.h"

//class AddANDgate2;
//class AddANDgate3;
//class AddBUFFERgate;
//class AddNANDgate2;
//class AddNORgate2;
//class AddNOTgate;
//class AddORgate2;
//class AddORgate3;
//class AddXNORgate2;
//class AddXORgate2;
//class AddXORgate3;

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
bool ApplicationManager::GetComponentByID(int ID, Component *out)
{
	Array<Component *> clone = CompList.clone();
	clone.filter([=](Component *comp) {
		if (comp->getComponentId() == ID)
		{
			return true;
		}
		return false;
	});
	if (clone.getCount() != 0)
	{
		out = clone.getData()[0];
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::RemoveComponent(int ID)
{
	Component *comp;
	if (this->GetComponentByID(ID, comp))
	{
		CompList.filter([=](Component *comp) {
			if (comp->getComponentId() == ID)
			{
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
bool ApplicationManager::ComponentCollides(Component *comp)
{
	Array<Component *> arr = this->CompList.clone();
	arr.filter([=](Component *comp2) {
		return comp->Collides(comp2);
	});
	if (arr.getCount() > 0)
	{
		return true;
	}
	return false;
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
	case ADD_Buff:
		pAct = new AddBUFFERgate(this);
		break;

	case ADD_INV:
		pAct = new AddNOTGate(this);
		break;

	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;

	case ADD_OR_GATE_3:
		pAct = new AddORgate3(this);
		break;

	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;
	}
	// case ADD_Switch:
	// 	pAct = new AddANDgate2(this);
	// 	break;

	// case ADD_LED:
	// 	pAct = new AddANDgate2(this);
	// 	break;

	// case ADD_CONNECTION:
	// 	pAct = new AddANDgate2(this);
	// 	break;
	// }
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
	CompList.forEach([=](Component *comp) {
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