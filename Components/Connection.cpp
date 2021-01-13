#include "./Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin, InputPin *pDstPin) : Component(r_GfxInfo)

{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	this->setLabel("WIRE");
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin *Connection::getSourcePin()
{
	return SrcPin;
}

void Connection::setDestPin(InputPin *pDstPin)
{
	DstPin = pDstPin;
}

InputPin *Connection::getDestPin()
{
	return DstPin;
}

void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::setPointsVector(vector<AStar::Pair> v)
{
	this->pointsVector = v;
}

void Connection::Draw(Output *pOut)
{
	pOut->DrawConnection(m_GfxInfo, this->pointsVector, this->getSelected());
}

int Connection::GetOutPinStatus() //returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}

int Connection::GetInputPinStatus(int n) //returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus(); //n is ignored as connection has only one input pin (src pin)
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

Connection *Connection::clone()
{
	return NULL;
}
InputPin *Connection::getInputPin(int n)
{
	return NULL;
}
OutputPin *Connection::getOutputPin()
{
	return NULL;
}
bool Connection::Collides(Component *comp)
{
	bool doesCollide = false;
	for (int i = 0; i < this->pointsVector.size() - 1; i++) {
		int x1 = (this->pointsVector[i].second) * UI.GridSize;
		int y1 = (this->pointsVector[i].first) * UI.GridSize - 4;
		int x2 = (this->pointsVector[i + 1].second) * UI.GridSize;
		int y2 = (this->pointsVector[i + 1].first) * UI.GridSize + 4;
		doesCollide = isPointInsideRect(x1, y1, comp->getGraphicsInfo())
		|| isPointInsideRect(x1, y2, comp->getGraphicsInfo())
		|| isPointInsideRect(x2, y1, comp->getGraphicsInfo())
		|| isPointInsideRect(x2, y2, comp->getGraphicsInfo())
		|| isPointInsideRect(comp->getGraphicsInfo().x1, comp->getGraphicsInfo().y1, x1, y1, x2, y2)
		|| isPointInsideRect(comp->getGraphicsInfo().x1, comp->getGraphicsInfo().y2, x1, y1, x2, y2)
		|| isPointInsideRect(comp->getGraphicsInfo().x2, comp->getGraphicsInfo().y1, x1, y1, x2, y2)
		|| isPointInsideRect(comp->getGraphicsInfo().x2, comp->getGraphicsInfo().y2, x1, y1, x2, y2);
		break;
	}
	return doesCollide;
}
bool Connection::Collides(GraphicsInfo gInfo)
{
	bool doesCollide = false;
	for (int i = 0; i < this->pointsVector.size() - 1; i++) {
		int x1 = (this->pointsVector[i].second) * UI.GridSize;
		int y1 = (this->pointsVector[i].first) * UI.GridSize - 4;
		int x2 = (this->pointsVector[i + 1].second) * UI.GridSize;
		int y2 = (this->pointsVector[i + 1].first) * UI.GridSize + 4;
		doesCollide = isPointInsideRect(x1, y1, gInfo)
		|| isPointInsideRect(x1, y2, gInfo)
		|| isPointInsideRect(x2, y1, gInfo)
		|| isPointInsideRect(x2, y2, gInfo)
		|| isPointInsideRect(gInfo.x1, gInfo.y1, x1, y1, x2, y2)
		|| isPointInsideRect(gInfo.x1, gInfo.y2, x1, y1, x2, y2)
		|| isPointInsideRect(gInfo.x2, gInfo.y1, x1, y1, x2, y2)
		|| isPointInsideRect(gInfo.x2, gInfo.y2, x1, y1, x2, y2);
		break;
	}
	return doesCollide;
}

void Connection::Save(ofstream &file, int srcCompId) {
	file << ActionType::ADD_CONNECTION
		<< "\t"
		<< this->getComponentId()
		<< "\t"
		<< this->getLabel()
		<< "\t"
		<< this->getGraphicsInfo().x1
		<< "\t"
		<< this->getGraphicsInfo().y1
		<< "\t"
		<< this->getGraphicsInfo().x2
		<< "\t"
		<< this->getGraphicsInfo().y2
		<< "\t"
		<< srcCompId
		<< "\t"
		<< this->DstPin->getComponent()->getComponentId()
		<< "\t"
		<< this->DstPin->getPinCount()
		<< endl;
}