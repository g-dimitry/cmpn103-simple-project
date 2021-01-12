#include "./cut.h"
#include "../ApplicationManager.h"


Cut::Cut(ApplicationManager *pApp) : Action(pApp)
{
  
}

Cut::~Cut()
{
}


void Cut::ReadActionParameters()
{

}


void Cut::Execute()
{
    if (this->pManager->getSelectedComponentsCount()) {
        this->pManager->cutSelectedComponents();
    }
}


void Cut::Undo()
{
}


void Cut::Redo()
{
}
