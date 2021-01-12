#include "./Paste.h"
#include "../ApplicationManager.h"


Paste::Paste(ApplicationManager *pApp) : Action(pApp)
{
    Cx = Cy = 0;
}

Paste::~Paste()
{
}


void Paste::ReadActionParameters()
{
   
}


void Paste::Execute()
{
    if (this->pManager->getClipboardCount()) {
        this->pManager->pasteClipboard(Cx, Cy, &(this->comps));
    }
    ApplicationManager* pApp = this->pManager;
    this->comps.forEach([&](Component* comp) {
        pApp->AddComponent(comp->clone());
    });
}


void Paste::Undo()
{
}


void Paste::Redo()
{
}
