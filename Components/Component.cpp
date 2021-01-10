#include "Component.h"

Component::ComponentCount = 0;

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	Component::ComponentCount++;
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
	Component::ComponentCount++;
}

Component::~Component()
{
}
