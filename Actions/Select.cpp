#include "./Select.h"
#include "../ApplicationManager.h"

Select::Select(ApplicationManager *pApp) : Action(pApp)
{
}

Select::~Select()
{
}

void Select::ReadActionParameters()
{
}

void Select::Execute()
{
    int x, y;
    this->pManager->GetInput()->GetMousePosition(x, y);
    GraphicsInfo gInfo;
    gInfo.x1 = x;
    gInfo.y1 = y;
    gInfo.x2 = x;
    gInfo.y2 = y;
    Component *collidedComponent = NULL;
    bool doesCollide = this->pManager->ComponentCollides(
        gInfo,
        &collidedComponent,
        true);
    if (doesCollide)
    {
        collidedComponent->toggleSelect();
        function<bool(Component*)> filterSelected = [=](Component* comp) {
            return comp->getSelected();
        };
        Array<Component*> comps = this->pManager->getCompList()->clone();
        Array<Component*>* selectedComponents = comps.filter(filterSelected);
        cout << selectedComponents->getCount();
         //Array<Component*>* selectedComponents = this->pManager->getCompList()->clone().filter(filterSelected);
         int compCount = selectedComponents->getCount();
         if (compCount > 0)
         {
             string message = selectedComponents->reduce<string>([&](string acc, Component *comp, int currentIndex, Component **srcArr) {
                 if (currentIndex == compCount - 1)
                 {
                     return acc + comp->getLabel();
                 }
                 return acc + comp->getLabel() + ", ";
             }, "Selected Gates: ");
             this->pManager->GetOutput()->PrintMsg(message);
         }
    }
    else
    {
        this->pManager->GetOutput()->ClearStatusBar();
        this->pManager->deselectAll();
    }
}

void Select::Undo()
{
}

void Select::Redo()
{
}
