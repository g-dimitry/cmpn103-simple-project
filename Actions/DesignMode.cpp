#include "./DesignMode.h"
#include "../ApplicationManager.h"


DesignMode::DesignMode(ApplicationManager *pApp) : Action(pApp)
{
  
}

DesignMode::~DesignMode()
{
}


void DesignMode::ReadActionParameters()
{

}


void DesignMode::Execute()
{
    UI.AppMode = MODE::DESIGN;
}


void DesignMode::Undo()
{
}


void DesignMode::Redo()
{
}
