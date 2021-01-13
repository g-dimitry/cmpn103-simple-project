#include "./AddConnection.h"

AddConnection::AddConnection(ApplicationManager *pApp) : Action(pApp)
{
}

AddConnection::~AddConnection()
{
}

void AddConnection::ReadActionParameters()
{
}

void AddConnection::Execute()
{
    this->pManager->GetOutput()->PrintMsg("Please select an output pin");
    int x, y = 0;
    this->pManager->GetInput()->WaitMouseClick(x, y);
    GraphicsInfo srcGInfo;
    srcGInfo.x1 = x;
    srcGInfo.x2 = x;
    srcGInfo.y1 = y;
    srcGInfo.y2 = y;
    Component *SrcComp;
    bool collides = this->pManager->ComponentCollides(srcGInfo, &SrcComp);
    if (!collides)
    {
        return;
    }
    if (dynamic_cast<Connection *>(SrcComp))
    {
        return;
    }
    if (Gate *gate = dynamic_cast<Gate *>(SrcComp))
    {
        if (x < SrcComp->getGraphicsInfo().x2 - 8)
        {
            this->pManager->GetOutput()->PrintMsg("Not an output pin");
            return;
        }
        if (!(y > SrcComp->getGraphicsInfo().y1 + UI.Gate_Height / 2 - 4 && y < SrcComp->getGraphicsInfo().y1 + UI.Gate_Height / 2 + 4))
        {
            this->pManager->GetOutput()->PrintMsg("Not an output pin");
            return;
        }
    }
    else if (SWITCH *sw = dynamic_cast<SWITCH *>(SrcComp))
    {
        if (x < SrcComp->getGraphicsInfo().x2 - 8)
        {
            this->pManager->GetOutput()->PrintMsg("Not an output pin");
            return;
        }
        if (!(y > SrcComp->getGraphicsInfo().y1 + UI.Gate_Height / 2 - 4 && y < SrcComp->getGraphicsInfo().y1 + UI.Gate_Height / 2 + 4))
        {
            this->pManager->GetOutput()->PrintMsg("Not an output pin");
            return;
        }
    }
    else if (LED *led = dynamic_cast<LED *>(SrcComp))
    {
        this->pManager->GetOutput()->PrintMsg("Not an output pin");
        return;
    }
    ////////////////////////////////////////////////////
    this->pManager->GetOutput()->PrintMsg("Please select an input pin");
    this->pManager->GetInput()->WaitMouseClick(x, y);
    GraphicsInfo destGInfo;
    destGInfo.x1 = x;
    destGInfo.x2 = x;
    destGInfo.y1 = y;
    destGInfo.y2 = y;
    Component *DestComponent;
    bool destCollides = this->pManager->ComponentCollides(destGInfo, &DestComponent);
    if (!destCollides)
    {
        this->pManager->GetOutput()->PrintMsg("Not an input pin");
        return;
    }
    if (dynamic_cast<Connection *>(DestComponent))
    {
        this->pManager->GetOutput()->PrintMsg("Not an input pin");
        return;
    }
    int pinCount = 1;
    int pinNumber = -1;
    if (Gate *DestGate = dynamic_cast<Gate *>(DestComponent))
    {
        pinCount = DestGate->getInputsCount();
        if (x > DestGate->getGraphicsInfo().x1 + 8)
        {
            this->pManager->GetOutput()->PrintMsg("Not an input pin");
            return;
        }
        if (pinCount == 1)
        {
            if (y >= DestGate->getGraphicsInfo().y1 + UI.Gate_Height / 2 - 4 && y <= DestGate->getGraphicsInfo().y1 + UI.Gate_Height / 2 + 4)
            {
                pinNumber = 0;
            }
        }
        else if (pinCount == 2)
        {
            if (y >= DestGate->getGraphicsInfo().y1 + 12 && y <= DestGate->getGraphicsInfo().y1 + 20)
            {
                pinNumber = 0;
            }
            if (y >= DestGate->getGraphicsInfo().y1 + 44 && y <= DestGate->getGraphicsInfo().y1 + 52)
            {
                pinNumber = 1;
            }
        }
        else
        {
            if (y >= DestGate->getGraphicsInfo().y1 + 12 && y <= DestGate->getGraphicsInfo().y1 + 20)
            {
                pinNumber = 0;
            }
            if (y >= DestGate->getGraphicsInfo().y1 + 28 && y <= DestGate->getGraphicsInfo().y1 + 36)
            {
                pinNumber = 1;
            }
            if (y >= DestGate->getGraphicsInfo().y1 + 44 && y <= DestGate->getGraphicsInfo().y1 + 52)
            {
                pinNumber = 2;
            }
        }
    }
    else if (SWITCH *sw = dynamic_cast<SWITCH *>(DestComponent))
    {
        this->pManager->GetOutput()->PrintMsg("Not an input pin");
        return;
    }
    else if (LED *led = dynamic_cast<LED *>(DestComponent))
    {
        if (x > led->getGraphicsInfo().x1 + 8)
        {
            this->pManager->GetOutput()->PrintMsg("Not an input pin");
            return;
        }
        if (y < led->getGraphicsInfo().y1 + UI.SWITCH_HEIGHT / 2 - 4 || y > led->getGraphicsInfo().y1 + UI.SWITCH_HEIGHT / 2 + 4)
        {
            this->pManager->GetOutput()->PrintMsg("Not an input pin");
            return;
        }
        pinCount = 1;
        pinNumber = 0;
    }
    if (pinNumber == -1)
    {
        this->pManager->GetOutput()->PrintMsg("Not an input pin");
        return;
    }
    GraphicsInfo gInfo;
    gInfo.x1 = SrcComp->getGraphicsInfo().x2;
    gInfo.y1 = SrcComp->getGraphicsInfo().y1 + (SrcComp->getGraphicsInfo().y2 - SrcComp->getGraphicsInfo().y1) / 2;
    gInfo.x2 = DestComponent->getGraphicsInfo().x1;
    if (pinCount == 1)
    {
        gInfo.y2 = DestComponent->getGraphicsInfo().y1 + (DestComponent->getGraphicsInfo().y2 - DestComponent->getGraphicsInfo().y1) / 2;
    }
    else if (pinCount == 2)
    {
        if (pinNumber == 0)
        {
            gInfo.y2 = DestComponent->getGraphicsInfo().y1 + 16;
        }
        else
        {
            gInfo.y2 = DestComponent->getGraphicsInfo().y2 - 16;
        }
    }
    else
    {
        if (pinNumber == 0)
        {
            gInfo.y2 = DestComponent->getGraphicsInfo().y1 + 16;
        }
        else if (pinNumber == 1)
        {
            gInfo.y2 = DestComponent->getGraphicsInfo().y1 + 32;
        }
        else
        {
            gInfo.y2 = DestComponent->getGraphicsInfo().y2 - 16;
        }
    }
    if (this->pManager->inputPinHasConnection(DestComponent->getInputPin(pinNumber))) {
        this->pManager->GetOutput()->PrintMsg("Input pin has a connection already");
        return;
    }
    auto tmp = DestComponent->getInputPin(pinNumber);
    Connection *conn = new Connection(gInfo, SrcComp->getOutputPin(), DestComponent->getInputPin(pinNumber));
    SrcComp->getOutputPin()->ConnectTo(conn);
    this->pManager->AddComponent(conn);
    this->pManager->GetOutput()->ClearStatusBar();
}

void AddConnection::Undo()
{
}

void AddConnection::Redo()
{
}
