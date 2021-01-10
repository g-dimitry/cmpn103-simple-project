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
