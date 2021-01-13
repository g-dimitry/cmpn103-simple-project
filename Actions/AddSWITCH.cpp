#include "./AddSWITCH.h"
#include "../ApplicationManager.h"


AddSWITCH::AddSWITCH(ApplicationManager *pApp, int width, int height, std::string gateTitle) : Action(pApp)
{
    this->width = width;
    this->height = height;
    this->gateTitle = gateTitle;
}

AddSWITCH::~AddSWITCH()
{
    delete this->gate;
}


void AddSWITCH::ReadActionParameters()
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

        Component *tmp = new SWITCH(GInfo);
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
}


void AddSWITCH::Execute()
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
    Component* pA = new SWITCH(GInfo);
    this->gate = pA;
    pManager->AddComponent(pA);
}


void AddSWITCH::Undo()
{
    this->pManager->RemoveComponent(this->gate->getComponentId());
}


void AddSWITCH::Redo()
{
    this->pManager->AddComponent(this->gate);
}
