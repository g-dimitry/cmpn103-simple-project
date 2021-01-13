#ifndef _OUTPUTPIN_H
#define _OUTPUTPIN_H

/*class OutputPin 
  ---------------
 An output pin obtains its value as a result of calculating the outputs of
 a component. The output pin propagates its value immediately to the associated connections
*/

#include "./Pin.h"
#include "../Utils/Array/Array.h"

class Connection; //Forward class declartion

class OutputPin : public Pin //inherited from class Pin
{
private:
	Array<Connection *> connections;
	int m_FanOut; //Maximum No. of connections connected to that output pin (depends on the component)
public:
	OutputPin(int r_FanOut);
	bool ConnectTo(Connection *r_Conn); //connect to a new connection
	Array<Connection*>* getConnections();
	void RemoveConnection(Connection* conn);
};

#endif