#include "./changeSwitch.h"
#include "../ApplicationManager.h"

changeSwitch::changeSwitch(ApplicationManager *pApp) : Action(pApp)
{
}

changeSwitch::~changeSwitch()
{
}

void changeSwitch::ReadActionParameters()
{
}

void changeSwitch::Execute()
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
        if (SWITCH *sw = dynamic_cast<SWITCH *>(collidedComponent))
        {
            sw->toggleSwitch();
        }
    }
}

void changeSwitch::Undo()
{
}

void changeSwitch::Redo()
{
}
