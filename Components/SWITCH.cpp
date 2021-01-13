#include "./SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo &r_GfxInfo) : outPin(5), Component(r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->setLabel("SWITCH");
}

void SWITCH::Operate()
{
	this->outPin.setStatus(this->status);
}

// Function Draw
// Draws 2-input AND gate
void SWITCH::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCH(m_GfxInfo, this->getSelected(), this->status == STATUS::HIGH);
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

SWITCH *SWITCH::clone()
{
	return new SWITCH(this->m_GfxInfo);
}

InputPin *SWITCH::getInputPin(int n)
{
	return NULL;
}
OutputPin *SWITCH::getOutputPin()
{
	return &(this->outPin);
}

void SWITCH::Save(ofstream &file)
{
	file << ActionType::ADD_Switch
		 << "\t"
		 << this->getComponentId()
		 << "\t"
		 << this->getLabel()
		 << "\t"
		 << this->getGraphicsInfo().x1
		 << "\t"
		 << this->getGraphicsInfo().y1
		 << endl;
	this->getOutputPin()->getConnections()->forEach([&](Connection *conn) {
		conn->Save(file, this->getComponentId());
	});
}

void SWITCH::toggleSwitch()
{
	if (this->status == STATUS::LOW) {
		this->status = STATUS::HIGH;
	} else {
		this->status = STATUS::LOW;
	}
	this->Operate();
}