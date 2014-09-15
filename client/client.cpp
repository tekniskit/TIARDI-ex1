// client.cpp : Defines the entry point for the console application.
#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <iostream>
#include <string>
#include "stdafx.h"
#include "SOCK_Connector.h"
#include "SOCK_Stream.h"
#include "INET_Addr.h"

int _tmain(int argc, char* argv[])
{
	long ip = 0x7F000001; // 127.0.0.1
	u_short port = 5500;

	INET_Addr address(port, ip);

	SOCK_Connector client;
	SOCK_Stream stream;

	client.connect(address);
	stream.set_handle(client.getSocket());

	std::cout << "Connected to " << ip << ":" << port << std::endl;

	// Main client event loop.
	for (;;)
	{
		char clientName[7] = "client";
		
		stream.send(clientName, 7, 0);

		std::string response;
		char buffer[10];
		int length;
		
		do {
			length = stream.recv(buffer, 10, 0);
			response.append(buffer, length);
		} while (response.find("\n") == std::string::npos);

		response.erase(response.find("\n"));

		std::cout << response << std::endl;

		Sleep(2000);
	}

	return 0;
}