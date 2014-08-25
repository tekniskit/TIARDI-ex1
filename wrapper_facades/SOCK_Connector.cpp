#include "SOCK_Connector.h"

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

void SOCK_Connector::close()
{
	int iResult = closesocket(socket_);
	if (iResult == SOCKET_ERROR) {
		
		WSACleanup();
	}
	
	isRunning = false;
}

int SOCK_Connector::recive(char* buffer, u_int size)
{
	int iResult = _WINSOCKAPI_::recv(socket_, buffer, size,0);
	if (iResult == SOCKET_ERROR) {
		isRunning = false;
		closesocket(socket_);
		WSACleanup();
		return 0;
	}
	return iResult;
}

int SOCK_Connector::send(char* sendbuf, u_int size)
{
	int iResult = _WINSOCKAPI_::send(socket_, sendbuf, (int)size, 0);
	if (iResult == SOCKET_ERROR) {
		isRunning = false;
		closesocket(socket_);
		WSACleanup();
		return 0;
	}

	return iResult;
}

SOCK_Connector::~SOCK_Connector()
{
	WSACleanup();
}