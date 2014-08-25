#pragma once 
#include <Windows.h>
#include "SOCK_Connector.h"

class INET_Addr {
public:
	INET_Addr(u_short port, u_long addr);
		
private:
	sockaddr_in addr_;
	
	friend bool SOCK_Connector::connect(INET_Addr addr);
};