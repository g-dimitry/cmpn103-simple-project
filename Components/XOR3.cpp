#include "./XOR3.h"

XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut) : Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("XOR3");
}

XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut, int id) : Gate(3, r_FanOut, id)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("XOR3");
}

void XOR3::Operate()
{
	STATUS status = STATUS::LOW;
	if (
		(this->m_InputPins[0].getStatus() == STATUS::HIGH || this->m_InputPins[1].getStatus() == STATUS::HIGH || this->m_InputPins[2].getStatus() == STATUS::HIGH)
		&& (this->m_InputPins[0].getStatus() != STATUS::HIGH || this->m_InputPins[1].getStatus() != STATUS::HIGH || this->m_InputPins[2].getStatus() == STATUS::HIGH)
		&& (this->m_InputPins[0].getStatus() != STATUS::HIGH || this->m_InputPins[1].getStatus() == STATUS::HIGH || this->m_InputPins[2].getStatus() != STATUS::HIGH)
		&& (this->m_InputPins[0].getStatus() == STATUS::HIGH || this->m_InputPins[1].getStatus() != STATUS::HIGH || this->m_InputPins[2].getStatus() != STATUS::HIGH)
	)
	{
		status = STATUS::HIGH;
	}
	this->m_OutputPin.setStatus(status);
}

// Function Draw
// Draws 2-input AND gate
void XOR3::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo, this->getSelected());
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus(); //n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

XOR3* XOR3::clone() {
	return new XOR3(this->m_GfxInfo, 5);
}

