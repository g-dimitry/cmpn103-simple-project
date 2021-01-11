#include "./SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo &r_GfxInfo) : Component(r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void SWITCH::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}

// Function Draw
// Draws 2-input AND gate
void SWITCH::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCH(m_GfxInfo);
}

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return 0;
}

//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return 0; //n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
}
