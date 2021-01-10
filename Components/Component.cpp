#include "Component.h"

Component::ComponentCount = 0;

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
}

Component::Component()
{
	Component::ComponentCount++;
}

Component::~Component()
{
}
