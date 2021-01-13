#include "./AddGate.h"
#include "../ApplicationManager.h"


AddGate::AddGate(ApplicationManager *pApp, int width, int height, int fanout, std::string gateTitle, ActionType actionType) : Action(pApp)
{
    this->width = width;
    this->height = height;
    this->fanout = fanout;
    this->gateTitle = gateTitle;
    this->actionType = actionType;
}

AddGate::~AddGate()
{
    delete this->gate;
}


void AddGate::ReadActionParameters()
{
    //Get a Pointer to the Input / Output Interfaces
    Output *pOut = pManager->GetOutput();
    Input *pIn = pManager->GetInput();

    bool shouldEndDrag = false;
    do
    {
        buttonstate state = pIn->GetMousePosition(Cx, Cy);
        pOut->StartBuffer();
        // this->pManager->GetOutput()->CreateGrid();
        this->pManager->UpdateInterface();

        int Len = this->width;
        int Wdth = this->height;
        Cx = min(UI.width, max(0, Cx));
        Cy = min(UI.height, max(0, Cy));
        Cx = min(UI.width - Len / 2, max(Len / 2, roundf((float)Cx / UI.GridSize) * UI.GridSize));
        Cy = min(UI.height - Wdth / 2 - UI.StatusBarHeight, max(Wdth / 2 + UI.ToolBarHeight, roundf((float)Cy / UI.GridSize) * UI.GridSize));
        GraphicsInfo GInfo;
        GInfo.x1 = Cx - Len / 2;
        GInfo.x2 = Cx + Len / 2;
        GInfo.y1 = Cy - Wdth / 2;
        GInfo.y2 = Cy + Wdth / 2;

        Component *tmp = Gate::gateFactory(this->actionType, GInfo, 5);
        bool ComponentCollides = this->pManager->ComponentCollides(tmp);
        if (ComponentCollides)
        {
            pOut->DrawErrorRectangle(GInfo);
        }
        else
        {
            tmp->Draw(this->pManager->GetOutput());
        }

        pOut->CreateToolBar();
        pOut->CreateDesignToolBar();
        pOut->CreateSimulationToolBar();
        pOut->CreateStatusBar();
        pOut->PrintMsg(this->gateTitle + ": Click to add the gate");

        pOut->EndBuffer();

        if (state == BUTTON_DOWN)
        {
            if (!ComponentCollides)
            {
                shouldEndDrag = true;
            }
        }
    } while (!shouldEndDrag);
    pOut->ClearStatusBar();
    this->pManager->GetInput()->FlushMouse();
}


void AddGate::Execute()
{
    ReadActionParameters();

    //Calculate the rectangle Corners
    int Len = this->width;
    int Wdth = this->height;

    GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

    GInfo.x1 = Cx - Len / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.y2 = Cy + Wdth / 2;
    Gate* pA = Gate::gateFactory(this->actionType, GInfo, this->fanout);
    this->gate = pA;
    pManager->AddComponent(pA);
}


void AddGate::Undo()
{
    this->pManager->RemoveComponent(this->gate->getComponentId());
}


void AddGate::Redo()
{
    this->pManager->AddComponent(this->gate);
}
