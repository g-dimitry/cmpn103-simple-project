#include "./NOR2.h"

NOR2::NOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut) : Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("NOR2");
}

void NOR2::Operate()
{
	STATUS status = STATUS::LOW;
	if (!(this->m_InputPins[0].getStatus() == STATUS::HIGH || this->m_InputPins[1].getStatus() == STATUS::HIGH))
	{
		status = STATUS::HIGH;
	}
	this->m_OutputPin.setStatus(status);
}

// Function Draw
// Draws 2-input AND gate
void NOR2::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo, this->getSelected());
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus(); //n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

NOR2* NOR2::clone() {
	return new NOR2(this->m_GfxInfo, 5);
}

