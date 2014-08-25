#include "SOCK_Connector.h"
#include "stdafx.h"

SOCK_Connector::SOCK_Connector()
{
	//----------------------
	// Initialize Winsock
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != NO_ERROR) {
		isRunning = false; 
	}

	socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (socket_ == INVALID_SOCKET) {
		isRunning = false;
		WSACleanup();
	}
}

bool SOCK_Connector::connect(INET_Addr addr)
{

	//----------------------
	// Connect to server.
	int iResult = _WINSOCKAPI_::connect(socket_, (SOCKADDR *)& addr.addr_, sizeof(addr.addr_));

	if (iResult == SOCKET_ERROR) {
		
		iResult = closesocket(socket_);
		if (iResult == SOCKET_ERROR)
			isRunning = false; 
		WSACleanup();
		return false;
	}

	return true; 
}