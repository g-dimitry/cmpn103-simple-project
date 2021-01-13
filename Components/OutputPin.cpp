#include "./OutputPin.h"
#include "./Connection.h"

OutputPin::OutputPin(int r_FanOut)
{																					//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS : r_FanOut; //set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if (connections.getCount() < m_FanOut)
	{
		connections.push(r_Conn);
		return true;
	}

	return false; //can't connect to any more connections
}

void OutputPin::RemoveConnection(Connection* conn) {
	this->connections.filter([&](Connection* connection) {
		return connection->getComponentId() != conn->getComponentId();
	});
}

Array<Connection*>* OutputPin::getConnections() {
	return &(this->connections);
}