#include "./Copy.h"
#include "../ApplicationManager.h"


Copy::Copy(ApplicationManager *pApp) : Action(pApp)
{
  
}

Copy::~Copy()
{
}


void Copy::ReadActionParameters()
{

}


void Copy::Execute()
{
    if (this->pManager->getSelectedComponentsCount()) {
        this->pManager->copySelectedComponents();
    }
}


void Copy::Undo()
{
}


void Copy::Redo()
{
}
