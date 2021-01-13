#include "./BUFFER.h"

BUFFER::BUFFER(const GraphicsInfo &r_GfxInfo, int r_FanOut) : Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("BUFFER");
}

BUFFER::BUFFER(const GraphicsInfo &r_GfxInfo, int r_FanOut, int id) : Gate(1, r_FanOut, id)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("BUFFER");
}

void BUFFER::Operate()
{
	STATUS status = STATUS::LOW;
	if (this->m_InputPins[0].getStatus() == STATUS::HIGH)
	{
		status = STATUS::HIGH;
	}
	this->m_OutputPin.setStatus(status);
}

// Function Draw
// Draws 2-input AND gate
void BUFFER::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFFER(m_GfxInfo, this->getSelected());
}

//returns status of outputpin
int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus(); //n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFFER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

BUFFER *BUFFER::clone()
{
	return new BUFFER(this->m_GfxInfo, 5);
}
