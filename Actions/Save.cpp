#include <fstream>
#include "./Save.h"
#include "../ApplicationManager.h"
#include "../Components//Component.h"

Save::Save(ApplicationManager *pApp) : Action(pApp)
{
  
}

Save::~Save()
{
}


void Save::ReadActionParameters()
{

}


void Save::Execute()
{
    out.open("circ.txt", ios::out);
    if (!out.is_open()) {
        this->pManager->GetOutput()->PrintMsg("Could not open file");
        return;
    }
    Array<Component*> arr = this->pManager->getCompList()->clone();
    arr.forEach([=](Component* comp) {
        if (!dynamic_cast<Connection*>(comp)) {
            comp->Save(out);
        }
    });
    out << "-1" << endl;
}


void Save::Undo()
{
}


void Save::Redo()
{
}
