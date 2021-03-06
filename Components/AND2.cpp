#include "./AND2.h"

AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut) : Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("AND2");
}

AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut, int id) : Gate(2, r_FanOut, id)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("AND2");
}

void AND2::Operate()
{
	STATUS status = STATUS::LOW;
	if (this->m_InputPins[0].getStatus() == STATUS::HIGH && this->m_InputPins[1].getStatus() == STATUS::HIGH) {
		status = STATUS::HIGH;
	}
	this->m_OutputPin.setStatus(status);
}

// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo, this->getSelected());
}

//returns status of outputpin
int AND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus(); //n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

AND2* AND2::clone() {
	return new AND2(this->m_GfxInfo, 5);
}