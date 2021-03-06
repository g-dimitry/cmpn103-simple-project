#include "./ApplicationManager.h"
#include "./Actions/AddConnection.h"
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
	for (int i = 0; i < CompList.getCount(); i++)
	{
		if (CompList.getData()[i]->getComponentId() == ID)
		{
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
void ApplicationManager::RemoveComponents(Array<int> *arr)
{
	arr->forEach([=](int ID) {
		this->RemoveComponent(ID);
	});
}
////////////////////////////////////////////////////////////////////
bool ApplicationManager::ComponentCollides(Component *comp, Component **collidedComp, bool includeConnections)
{
	Array<Component *> arr = this->CompList.clone();
	arr.filter([=](Component *comp2) {
		if (!includeConnections && dynamic_cast<Connection *>(comp2))
		{
			return false;
		}
		return comp->Collides(comp2);
	});
	if (arr.getCount() > 0)
	{
		if (collidedComp)
		{
			*collidedComp = arr.getData()[0];
		}
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////
bool ApplicationManager::ComponentCollides(GraphicsInfo gInfo, Component **collidedComp, bool includeConnections)
{
	Array<Component *> arr = this->CompList.clone();
	arr.filter([=](Component *comp2) {
		if (!includeConnections && dynamic_cast<Connection *>(comp2))
		{
			return false;
		}
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
	this->GetOutput()->ClearStatusBar();
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
	case ActionType::DEL:
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
	case PASTE:
		pAct = new Paste(this);
		break;
	case ADD_CONNECTION:
		pAct = new AddConnection(this);
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
	this->GetOutput()->ClearDrawingArea();
	int grid[47][82];
	generateGrid(grid);
	CompList.forEach([&](Component *comp) {
		if (Connection *conn = dynamic_cast<Connection *>(comp))
		{
			vector<AStar::Pair> pointsVector;
			conn->setPointsVector(AStar::getShortestPath(grid, make_pair(conn->getGraphicsInfo().y1 / UI.GridSize, conn->getGraphicsInfo().x1 / UI.GridSize), make_pair(conn->getGraphicsInfo().y2 / UI.GridSize, conn->getGraphicsInfo().x2 / UI.GridSize)));
		}
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

///////////////////////////////////////////////////////////////////

int ApplicationManager::getClipboardCount()
{
	return this->Clipboard.getCount();
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

void ApplicationManager::PushToClipboard(Component *comp)
{
	this->Clipboard.push(comp);
}

/////////////////////////////////////////////////////////////////////

void ApplicationManager::copySelectedComponents()
{
	this->Clipboard.filter([=](Component *comp) { return false; });
	this->CompList.forEach([=](Component *comp) {
		if (!dynamic_cast<Connection *>(comp) && comp->getSelected())
		{
			this->PushToClipboard(comp->clone());
		}
	});
}

/////////////////////////////////////////////////////////////////////

void ApplicationManager::cutSelectedComponents()
{
	this->Clipboard.filter([=](Component *comp) { return false; });
	this->CompList.forEach([&](Component *comp) {
		if (!dynamic_cast<Connection *>(comp) && comp->getSelected())
		{
			this->PushToClipboard(comp->clone());
			if (Gate *gate = dynamic_cast<Gate *>(comp))
			{
				auto conns = gate->getOutputPin()->getConnections()->clone();
				int pinCount = gate->getInputsCount();
				for (int i = 0; i < pinCount; i++)
				{
					auto arr = this->getCompList()->clone();
					arr.forEach([&](Component *component) {
						if (Connection *conn = dynamic_cast<Connection *>(component))
						{
							if (conn->getDestPin() == gate->getInputPin(i))
							{
								conns.push(conn);
								conn->getSourcePin()->RemoveConnection(conn);
							}
						}
					});
				}
				auto ids = conns.map<int>([&](Connection *conn) {
					return conn->getComponentId();
				});
				this->RemoveComponents(ids);
			}
			else if (SWITCH *sw = dynamic_cast<SWITCH *>(comp))
			{
				auto conns = sw->getOutputPin()->getConnections()->clone();
				auto ids = conns.map<int>([&](Connection *conn) {
					return conn->getComponentId();
				});
				this->RemoveComponents(ids);
			}
			else if (LED *led = dynamic_cast<LED *>(comp))
			{
				Array<Connection *> conns;
				auto arr = this->getCompList()->clone();
				arr.forEach([&](Component *component) {
					if (Connection *conn = dynamic_cast<Connection *>(component))
					{
						if (conn->getDestPin() == led->getInputPin(0))
						{
							conns.push(conn);
							conn->getSourcePin()->RemoveConnection(conn);
						}
					}
				});
				auto ids = conns.map<int>([&](Connection *conn) {
					return conn->getComponentId();
				});
				this->RemoveComponents(ids);
			}
			this->RemoveComponent(comp->getComponentId());
		}
	});
	// this->CompList.forEach([&](Component *comp) {
	// 	if (!dynamic_cast<Connection *>(comp) && comp->getSelected())
	// 	{
	// 		this->PushToClipboard(comp->clone());
	// 		IDSArray.push(comp->getComponentId());
	// 	}
	// });
	// IDSArray.forEach([=](int ID) {
	// 	this->RemoveComponent(ID);
	// });
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::pasteClipboard(int &x, int &y, Array<Component *> *arr)
{
	int x1 = 9999, x2 = 0, y1 = 99999, y2 = 0; // x1 -> smallest x , x2 -> largest x
	this->Clipboard.forEach([&](Component *comp) {
		GraphicsInfo compInfo = comp->getGraphicsInfo();
		if (compInfo.x1 < x1)
		{
			x1 = compInfo.x1;
		}
		if (compInfo.y1 < y1)
		{
			y1 = compInfo.y1;
		}
		if (compInfo.x2 > x2)
		{
			x2 = compInfo.x2;
		}
		if (compInfo.y2 > y2)
		{
			y2 = compInfo.y2;
		}
	});
	int boundryWidth = x2 - x1;
	int boundryHeight = y2 - y1;
	this->Clipboard.forEach([&](Component *comp) {
		GraphicsInfo compInfo = comp->getGraphicsInfo();
		compInfo.x1 -= x1 + boundryWidth / 2 / UI.GridSize * UI.GridSize;
		compInfo.x2 -= x1 + boundryWidth / 2 / UI.GridSize * UI.GridSize;
		compInfo.y1 -= y1 + boundryHeight / 2 / UI.GridSize * UI.GridSize;
		compInfo.y2 -= y1 + boundryHeight / 2 / UI.GridSize * UI.GridSize;
		comp->setGraphicsInfo(compInfo);
	});

	/////////////////////////////////////////////////////////////////
	Output *pOut = this->GetOutput();
	Input *pIn = this->GetInput();

	bool shouldEndDrag = false;
	do
	{
		int Cx, Cy = 0;

		buttonstate state = pIn->GetMousePosition(Cx, Cy);
		x = Cx;
		y = Cy;
		pOut->StartBuffer();
		// this->GetOutput()->CreateGrid();
		this->UpdateInterface();

		int Len = boundryWidth;
		int Wdth = boundryHeight;
		Cx = min(UI.width, max(0, Cx));
		Cy = min(UI.height, max(0, Cy));
		Cx = min(UI.width - Len / 2, max(Len / 2, roundf((float)Cx / UI.GridSize) * UI.GridSize));
		Cy = min(UI.height - Wdth / 2 - UI.StatusBarHeight, max(Wdth / 2 + UI.ToolBarHeight, roundf((float)Cy / UI.GridSize) * UI.GridSize));

		bool anyComponentCollides = false;
		arr->filter([](Component *comp) { return false; });
		this->Clipboard.forEach([&](Component *comp) {
			Component *tmp = comp->clone();
			GraphicsInfo GInfo;
			GInfo.x1 = Cx + comp->getGraphicsInfo().x1;
			GInfo.x2 = Cx + comp->getGraphicsInfo().x2;
			GInfo.y1 = Cy + comp->getGraphicsInfo().y1;
			GInfo.y2 = Cy + comp->getGraphicsInfo().y2;
			tmp->setGraphicsInfo(GInfo);
			arr->push(tmp);
			bool ComponentCollides = this->ComponentCollides(tmp);
			if (ComponentCollides)
			{
				anyComponentCollides = true;
				pOut->DrawErrorRectangle(GInfo);
			}
			else
			{
				tmp->Draw(this->GetOutput());
				cout << "=====================================" << endl;
				cout << Cx << endl;
				cout << Cy << endl;
				cout << tmp->getGraphicsInfo().x1 << endl;
				cout << tmp->getGraphicsInfo().y1 << endl;
				cout << tmp->getGraphicsInfo().x2 << endl;
				cout << tmp->getGraphicsInfo().y2 << endl;
			}
		});

		pOut->CreateToolBar();
		pOut->CreateDesignToolBar();
		pOut->CreateSimulationToolBar();
		pOut->CreateStatusBar();
		pOut->EndBuffer();

		if (state == BUTTON_DOWN)
		{
			if (!anyComponentCollides)
			{

				shouldEndDrag = true;
			}
		}
	} while (!shouldEndDrag);
	pOut->ClearStatusBar();
	this->GetInput()->FlushMouse();
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

bool ApplicationManager::inputPinHasConnection(InputPin *inputPin)
{
	Array<Component *> arr = this->CompList.clone();
	arr.filter([=](Component *comp) {
		if (Connection *conn = dynamic_cast<Connection *>(comp))
		{
			return conn->getDestPin() == inputPin;
		}
		return false;
	});
	return arr.getCount() != 0;
}

void ApplicationManager::generateGrid(int grid[][82])
{
	for (int i = 0; i < 47; i++)
	{
		for (int j = 0; j < 82; j++)
		{
			grid[i][j] = 1;
		}
	}
	this->CompList.forEach([=](Component *comp) {
		if (dynamic_cast<Connection *>(comp))
		{
			return;
		}
		GraphicsInfo gInfo = comp->getGraphicsInfo();
		int startX = gInfo.x1 / UI.GridSize + 1;
		int endX = gInfo.x1 / UI.GridSize + 5;
		int startY = gInfo.y1 / UI.GridSize + 1;
		int endY = gInfo.y1 / UI.GridSize + 3;
		for (int i = startX; i <= endX; i += 1)
		{
			for (int j = startY; j <= endY; j += 1)
			{
				grid[j][i] = 0;
			}
		}
	});
}
//////////////////////////////////////////////////////////////////////
Array<Component *> *ApplicationManager::getCompList()
{
	return &(this->CompList);
}