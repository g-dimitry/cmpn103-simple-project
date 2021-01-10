#include "Component.h"

int Component::ComponentCount = 0;

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	id = Component::ComponentCount;
	Component::ComponentCount++;
}

int Component::getComponentId() {
	return this->id;
}

Component::Component(int id, const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	this->id = id;
	if (id > Component::ComponentCount) {
		Component::ComponentCount = id;
	}
}

Component::Component(int id)
{
	this->id = id;
	if (id > Component::ComponentCount) {
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

bool isPointInsideRect(int x, int y, GraphicsInfo g) {
	if (x >= g.x1 && x <= g.x2 && y >= g.y1 && y <= g.y2) {
		return true;
	}
	return false;
}

bool Component::Collides(Component* comp) {
	return isPointInsideRect(this->m_GfxInfo.x1, this->m_GfxInfo.y1, comp->m_GfxInfo)
		|| isPointInsideRect(this->m_GfxInfo.x1, this->m_GfxInfo.y2, comp->m_GfxInfo)
		|| isPointInsideRect(this->m_GfxInfo.x2, this->m_GfxInfo.y1, comp->m_GfxInfo)
		|| isPointInsideRect(this->m_GfxInfo.x2, this->m_GfxInfo.y2, comp->m_GfxInfo);
}