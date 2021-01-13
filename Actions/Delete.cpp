#include "./Delete.h"
#include "../ApplicationManager.h"


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
    ApplicationManager* pApp = this->pManager;
    Array<Component*> arr = this->pManager->getCompList()->clone();
    arr.filter([=](Component* comp) {
        return comp->getSelected();
    });
    arr.forEach([&](Component* comp) {
        pApp->RemoveComponent(comp->getComponentId());
    });
}


void Delete::Undo()
{
}


void Delete::Redo()
{
}
