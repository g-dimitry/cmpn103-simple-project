#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "../Defs.h"
#include "../GUI/Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
	int id;
	static int ComponentCount;
	bool selected = false;
protected:
	GraphicsInfo m_GfxInfo; //The parameters required to draw a component
public:
	static int getComponentCount()
	{
		return Component::ComponentCount;
	}
	bool getSelected();
	void setSelected(bool selectedValue);
	void toggleSelect();
	int getComponentId();
	Component(const GraphicsInfo &r_GfxInfo);
	Component(int id, const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;					 //Calculates the output according to the inputs
	virtual void Draw(Output *pOut) = 0; //for each component to Draw itself

	virtual int GetOutPinStatus() = 0;				//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) = 0; //returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s) = 0; //set status of Inputpin # n, to be used by connection class.

	Component();
	Component(int id);

	//Destructor must be virtual
	virtual ~Component();

	bool Collides(Component* comp);
	bool Collides(GraphicsInfo gInfo);
};

#endif
