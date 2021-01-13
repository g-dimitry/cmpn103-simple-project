#include "./Delete.h"
#include "../ApplicationManager.h"
#include "../Components/Gate.h"
#include "../Components/LED.h"
#include "../Components/SWITCH.h"

Delete::Delete(ApplicationManager *pApp) : Action(pApp)
{
}

Delete::~Delete()
{
}

void Delete::ReadActionParameters()
{
}

void Delete::Execute()
{
    ApplicationManager *pApp = this->pManager;
    Array<Component *> arr = this->pManager->getCompList()->clone();
    arr.filter([=](Component *comp) {
        return comp->getSelected();
    });
    arr.forEach([&](Component *comp) {
        if (Gate *gate = dynamic_cast<Gate *>(comp))
        {
            auto conns = gate->getOutputPin()->getConnections()->clone();
            int pinCount = gate->getInputsCount();
            for (int i = 0; i < pinCount; i++)
            {
                auto arr = pApp->getCompList()->clone();
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
            pApp->RemoveComponents(ids);
        }
        else if (SWITCH *sw = dynamic_cast<SWITCH *>(comp))
        {
            auto conns = sw->getOutputPin()->getConnections()->clone();
            auto ids = conns.map<int>([&](Connection *conn) {
                return conn->getComponentId();
            });
            pApp->RemoveComponents(ids);
        }
        else if (LED *led = dynamic_cast<LED *>(comp))
        {
            Array<Connection *> conns;
            auto arr = pApp->getCompList()->clone();
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
            pApp->RemoveComponents(ids);
        }
        pApp->RemoveComponent(comp->getComponentId());
    });
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}
