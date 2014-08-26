#pragma once 
#include <winsock.h> 
#include "INET_Addr.h"

class SOCK_Connector{
	
public:

	SOCK_Connector(); 
	~SOCK_Connector();

	// connect to a socket; 
	bool connect(INET_Addr addr);

	//send a message to the connected 
	// return number of byte send. 
	int send(char *buffer, u_int size);

	//revive a message 
	//return the number of bytes recived. 
	int recive(char* buffer, u_int maxSize);

	SOCKET getSocket(); 

	//Close the socket. 
	void close(); 

	bool isRunning = true; 

private:
	SOCKET socket_ = INVALID_SOCKET;
};