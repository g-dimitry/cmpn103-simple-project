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
    this->pManager->GetInput()->GetMousePosition(x,y);
    GraphicsInfo gInfo;
    gInfo.x1 = x;
    gInfo.y1 = y;
    gInfo.x2 = x;
    gInfo.y2 = y;
    Component* collidedComponent = NULL;
    bool doesCollide = this->pManager->ComponentCollides(
    	gInfo,
    	&collidedComponent
    );
    if (doesCollide) {
    	collidedComponent->toggleSelect();
        // heree
    } else {
        this->pManager->deselectAll();
    }
}


void Select::Undo()
{
}


void Select::Redo()
{
}
