#include "./SimulationMode.h"
#include "../ApplicationManager.h"


SimulationMode::SimulationMode(ApplicationManager *pApp) : Action(pApp)
{
  
}

SimulationMode::~SimulationMode()
{
}


void SimulationMode::ReadActionParameters()
{

}


void SimulationMode::Execute()
{
    UI.AppMode = MODE::SIMULATION;
}


void SimulationMode::Undo()
{
}


void SimulationMode::Redo()
{
}
