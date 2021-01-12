#include "./ApplicationManager.h"
#include <iostream>

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
bool ApplicationManager::GetComponentByID(int ID, Component **out)
{
	for (int i = 0; i < CompList.getCount(); i++) {
		if (CompList.getData()[i]->getComponentId() == ID) {
			*out = CompList.getData()[i];
			return true;
		}
	}
	return false;
	/*Array<Component *> clone = CompList.clone();

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
	return false;*/
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::RemoveComponent(int ID)
{
	Component *comp;
	if (this->GetComponentByID(ID, &comp))
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
bool ApplicationManager::ComponentCollides(Component *comp, Component** collidedComp)
{
	Array<Component *> arr = this->CompList.clone();
	arr.filter([=](Component *comp2) {
		return comp->Collides(comp2);
	});
	if (arr.getCount() > 0)
	{
		if (collidedComp) {
			*collidedComp = arr.getData()[0];
		}
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////
bool ApplicationManager::ComponentCollides(GraphicsInfo gInfo, Component** collidedComp)
{
	Array<Component *> arr = this->CompList.clone();
	arr.filter([=](Component *comp2) {
		bool collides = comp2->Collides(gInfo);
		return collides;
	});
	if (arr.getCount() > 0)
	{
		this->GetComponentByID(arr.getData()[0]->getComponentId(), collidedComp);
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
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_Buff);
		break;

	case ADD_INV:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_INV);
		break;

	case ADD_AND_GATE_2:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_AND_GATE_2);
		break;

	case ADD_OR_GATE_2:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_OR_GATE_2);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_NAND_GATE_2);
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_NOR_GATE_2);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_XOR_GATE_2);
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_XNOR_GATE_2);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_AND_GATE_3);
		break;

	case ADD_OR_GATE_3:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_OR_GATE_3);
		break;

	case ADD_XOR_GATE_3:
		pAct = new AddGate(this, UI.Gate_Width, UI.Gate_Height, 5, "Gate", ADD_XOR_GATE_3);
		break;
	case ADD_LED:
		pAct = new AddLED(this, UI.LED_WIDTH, UI.LED_HEIGHT, "LED");
		break;
	case ADD_Switch:
		pAct = new AddSWITCH(this, UI.SWITCH_WIDTH, UI.SWITCH_HEIGHT, "Switch");
		break;
	
	case Change_Switch:
		pAct = new changeSwitch(this);
		break;
	case DELETE:
		pAct = new Delete(this);
		break;
	case DSN_TOOL:
		pAct = new Deselect(this);
		break;
	case DSN_MODE:
		pAct = new DesignMode(this);
		break;
	case EDIT_Label:
		pAct = new EditLabel(this);
		break;
	case EXIT:
		pAct = new Exit(this);
		break;
	case LOAD:
		pAct = new Load(this);
		break;
	case SAVE:
		pAct = new Save(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;
	case SIM_MODE:
		pAct = new SimulationMode(this);
		break;
	case COPY:
		pAct = new Copy(this);
		break;
	case CUT:
		pAct = new Cut(this);
		break;
	}


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
	this->GetOutput()->ClearDrawingArea();
	CompList.forEach([=](Component *comp) {
		comp->Draw(OutputInterface);
	});
}

///////////////////////////////////////////////////////////////////

int ApplicationManager::getSelectedComponentsCount()
{
	Array<Component *> arr = this->CompList.clone();
	arr.filter([=](Component *comp2) {
		return comp2->getSelected();
	});

	return arr.getCount();
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::deselectAll()
{
	cout << this->getSelectedComponentsCount();
	this->CompList.forEach([=](Component *comp) {
		comp->setSelected(false);
	});
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::PushToClipboard(Component* comp) {
	this->Clipboard.push(comp);
}

/////////////////////////////////////////////////////////////////////

void ApplicationManager::copySelectedComponents()
{
	this->Clipboard.filter([=] (Component* comp) {return false;});
	this->CompList.forEach([=](Component* comp) {
		if (comp->getSelected()) {
			this->PushToClipboard(comp->clone());
		}
	});
}

/////////////////////////////////////////////////////////////////////

void ApplicationManager::cutSelectedComponents()
{
	this->Clipboard.filter([=] (Component* comp) {return false;});
	this->CompList.forEach([=](Component* comp) {
		if (comp->getSelected()) {
			this->PushToClipboard(comp->clone());
			this->RemoveComponent(comp->getComponentId());
		}
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

