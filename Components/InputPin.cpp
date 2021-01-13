#include "./InputPin.h"
#include "./Gate.h"
#include "./LED.h"
InputPin::InputPin()
{
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component *InputPin::getComponent()
{
	return pComp;
}

int InputPin::getPinCount()
{
	int pinIndex;
	if (Gate *gate = Gate::isGate(this->pComp))
	{
		int pinCount = gate->getInputsCount();
		for (int i = 0; i < pinCount; i++)
		{
			if (gate->getInputPin(i) == this)
			{
				pinIndex = i;
				break;
			}
		}
	}
	else if (LED *led = dynamic_cast<LED *>(this->pComp))
	{
		pinIndex = 0;
	}
	return pinIndex;
}

void InputPin::setStatus(STATUS status)
{
	this->m_Status = status;
	this->pComp->Operate();
}
