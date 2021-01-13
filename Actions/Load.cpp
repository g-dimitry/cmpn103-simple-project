#include "./Load.h"
#include "../ApplicationManager.h"
#include "../Components/Gate.h"
#include "../Components/Connection.h"
#include "../Components/InputPin.h"
#include "../Components/OutputPin.h"

Load::Load(ApplicationManager *pApp) : Action(pApp)
{
}

Load::~Load()
{
}

void Load::ReadActionParameters()
{
}

void Load::Execute()
{
    in.open("circ.txt");
    int compType;
    Array<ConnectionData> connData;
    while (in >> compType, compType != -1)
    {
        if (in.eof())
        {
            break;
        }

        if (compType == ActionType::ADD_CONNECTION)
        {
            ConnectionData conn;
            in >> conn.id;
            in >> conn.label;
            in >> conn.x1 >> conn.y1 >> conn.x2 >> conn.y2;
            in >> conn.source >> conn.dest >> conn.pin;
            connData.push(conn);
        }
        else if (compType >= ADD_Buff && compType <= ADD_XOR_GATE_3)
        {
            int id;
            string label;
            GraphicsInfo gInfo;
            in >> id;
            in >> label;
            in >> gInfo.x1 >> gInfo.y1;
            gInfo.x2 = gInfo.x1 + UI.Gate_Width;
            gInfo.y2 = gInfo.y1 + UI.Gate_Height;
            Gate *a = Gate::gateFactory(id, (ActionType)compType, gInfo, 5);
            a->setLabel(label);
            this->pManager->getCompList()->push(a);
        }
        else if (compType == ADD_Switch)
        {
            int id;
            string label;
            GraphicsInfo gInfo;
            in >> id;
            in >> label;
            in >> gInfo.x1 >> gInfo.y1;
            gInfo.x2 = gInfo.x1 + UI.Gate_Width;
            gInfo.y2 = gInfo.y1 + UI.Gate_Height;
            SWITCH *a = new SWITCH(gInfo, id);
            a->setLabel(label);
            this->pManager->getCompList()->push(a);
        }
        else if (compType == ADD_LED)
        {
            int id;
            string label;
            GraphicsInfo gInfo;
            in >> id;
            in >> label;
            in >> gInfo.x1 >> gInfo.y1;
            gInfo.x2 = gInfo.x1 + UI.Gate_Width;
            gInfo.y2 = gInfo.y1 + UI.Gate_Height;
            LED *a = new LED(gInfo, id);
            a->setLabel(label);
            this->pManager->getCompList()->push(a);
        }
    }
    ApplicationManager *pApp = this->pManager;
    connData.forEach([&](ConnectionData data) {
        GraphicsInfo gInfo;
        gInfo.x1 = data.x1;
        gInfo.x2 = data.x2;
        gInfo.y1 = data.y1;
        gInfo.y2 = data.y2;
        Component *srcComp;
        Component *destComp;
        pApp->GetComponentByID(data.source, &srcComp);
        pApp->GetComponentByID(data.dest, &destComp);
        OutputPin *src = srcComp->getOutputPin();
        InputPin *dest = destComp->getInputPin(data.pin);
        Connection *conn = new Connection(gInfo, src, dest, data.id);
        src->ConnectTo(conn);
        this->pManager->getCompList()->push(conn);
    });
}

void Load::Undo()
{
}

void Load::Redo()
{
}
