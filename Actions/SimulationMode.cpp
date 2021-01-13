#include "./SimulationMode.h"
#include "../ApplicationManager.h"
#include "../Utils/Array/Array.h";
#include "../Components/Component.h"

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
    Array<Component*> arr = this->pManager->getCompList()->clone();
    arr.filter([=](Component* comp) {
        if (dynamic_cast<SWITCH*>(comp)) {
            return true;
        }
        return false;
    });
    arr.forEach([&](Component* comp) {
        comp->Operate();
    });
}


void SimulationMode::Undo()
{
}


void SimulationMode::Redo()
{
}
