#include "./LED.h"

LED::LED(const GraphicsInfo &r_GfxInfo) : Component(r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("LED");
	this->inputPin.setComponent(this); 
}

LED::LED(const GraphicsInfo &r_GfxInfo, int id) : Component(id, r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("LED");
	this->inputPin.setComponent(this); 
}

void LED::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}

// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawLED(m_GfxInfo, this->getSelected(), this->inputPin.getStatus() == STATUS::HIGH);
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return 0;
}

//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return 0; //n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
}

LED *LED::clone()
{
	return new LED(this->m_GfxInfo);
}

InputPin *LED::getInputPin(int n)
{
	return &(this->inputPin);
}
OutputPin *LED::getOutputPin()
{
	return NULL;
}

void LED::Save(ofstream &file)
{
	file << ActionType::ADD_LED
		 << "\t"
		 << this->getComponentId()
		 << "\t"
		 << this->getLabel()
		 << "\t"
		 << this->getGraphicsInfo().x1
		 << "\t"
		 << this->getGraphicsInfo().y1
		 << endl;
}