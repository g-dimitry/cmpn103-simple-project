#include "./EditLabel.h"
#include "../ApplicationManager.h"

EditLabel::EditLabel(ApplicationManager *pApp) : Action(pApp)
{
}

EditLabel::~EditLabel()
{
}

void EditLabel::ReadActionParameters()
{
}

void EditLabel::Execute()
{
    function<bool(Component *)> filterSelected = [=](Component *comp) {
        return comp->getSelected();
    };
    Array<Component *> comps = this->pManager->getCompList()->clone();
    Array<Component *> *selectedComponents = comps.filter(filterSelected);
    int compCount = selectedComponents->getCount();
    if (compCount > 1)
    {
        this->pManager->GetOutput()->PrintMsg("Please select only one component to edit");
        return;
    }
    else if (compCount == 0)
    {
        this->pManager->GetOutput()->PrintMsg("Nothing is selected");
        return;
    }
    string str = this->pManager->GetInput()->GetSrting(this->pManager->GetOutput(), selectedComponents->getData()[0]->getLabel());
    if (str.length())
    {
        selectedComponents->getData()[0]->setLabel(str);
    }
}

void EditLabel::Undo()
{
}

void EditLabel::Redo()
{
}
