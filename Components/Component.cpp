#include "./Component.h"

int Component::ComponentCount = 0;

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	id = Component::ComponentCount;
	Component::ComponentCount++;
}

int Component::getComponentId()
{
	return this->id;
}

Component::Component(int id, const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	this->id = id;
	if (id > Component::ComponentCount)
	{
		Component::ComponentCount = id;
	}
}

Component::Component(int id)
{
	this->id = id;
	if (id > Component::ComponentCount)
	{
		Component::ComponentCount = id;
	}
}

Component::Component()
{
	id = Component::ComponentCount;
	Component::ComponentCount++;
}

Component::~Component()
{
}

bool Component::isPointInsideRect(int x, int y, GraphicsInfo g)
{
	if (x >= g.x1 && x <= g.x2 && y >= g.y1 && y <= g.y2)
	{
		return true;
	}
	return false;
}

bool Component::isPointInsideRect(int x, int y, int x1, int y1, int x2, int y2)
{
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
	{
		return true;
	}
	return false;
}

bool Component::Collides(Component *comp)
{
	return isPointInsideRect(this->m_GfxInfo.x1, this->m_GfxInfo.y1, comp->m_GfxInfo) || isPointInsideRect(this->m_GfxInfo.x1, this->m_GfxInfo.y2, comp->m_GfxInfo) || isPointInsideRect(this->m_GfxInfo.x2, this->m_GfxInfo.y1, comp->m_GfxInfo) || isPointInsideRect(this->m_GfxInfo.x2, this->m_GfxInfo.y2, comp->m_GfxInfo) || isPointInsideRect(comp->m_GfxInfo.x1, comp->m_GfxInfo.y1, this->m_GfxInfo.x1, this->m_GfxInfo.y1, this->m_GfxInfo.x2, this->m_GfxInfo.y2) || isPointInsideRect(comp->m_GfxInfo.x1, comp->m_GfxInfo.y2, this->m_GfxInfo.x1, this->m_GfxInfo.y1, this->m_GfxInfo.x2, this->m_GfxInfo.y2) || isPointInsideRect(comp->m_GfxInfo.x2, comp->m_GfxInfo.y1, this->m_GfxInfo.x1, this->m_GfxInfo.y1, this->m_GfxInfo.x2, this->m_GfxInfo.y2) || isPointInsideRect(comp->m_GfxInfo.x2, comp->m_GfxInfo.y2, this->m_GfxInfo.x1, this->m_GfxInfo.y1, this->m_GfxInfo.x2, this->m_GfxInfo.y2);
}

bool Component::Collides(GraphicsInfo gInfo)
{
	return isPointInsideRect(this->m_GfxInfo.x1, this->m_GfxInfo.y1, gInfo) || isPointInsideRect(this->m_GfxInfo.x1, this->m_GfxInfo.y2, gInfo) || isPointInsideRect(this->m_GfxInfo.x2, this->m_GfxInfo.y1, gInfo) || isPointInsideRect(this->m_GfxInfo.x2, this->m_GfxInfo.y2, gInfo) || isPointInsideRect(gInfo.x1, gInfo.y1, this->m_GfxInfo.x1, this->m_GfxInfo.y1, this->m_GfxInfo.x2, this->m_GfxInfo.y2) || isPointInsideRect(gInfo.x1, gInfo.y2, this->m_GfxInfo.x1, this->m_GfxInfo.y1, this->m_GfxInfo.x2, this->m_GfxInfo.y2) || isPointInsideRect(gInfo.x2, gInfo.y1, this->m_GfxInfo.x1, this->m_GfxInfo.y1, this->m_GfxInfo.x2, this->m_GfxInfo.y2) || isPointInsideRect(gInfo.x2, gInfo.y2, this->m_GfxInfo.x1, this->m_GfxInfo.y1, this->m_GfxInfo.x2, this->m_GfxInfo.y2);
}

void Component::toggleSelect()
{
	this->selected = !this->selected;
}

bool Component::getSelected()
{
	return this->selected;
}

void Component::setSelected(bool selectedValue)
{
	this->selected = selectedValue;
}

GraphicsInfo Component::getGraphicsInfo()
{
	return this->m_GfxInfo;
}
void Component::setGraphicsInfo(GraphicsInfo gInfo)
{
	this->m_GfxInfo = gInfo;
}

string Component::getLabel()
{
	return this->m_Label;
}

void Component::setLabel(string label)
{
	this->m_Label = label;
}
