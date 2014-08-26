// client.cpp : Defines the entry point for the console application.

#include <Windows.h>
#include <iostream>
#include <string>
#include "stdafx.h"

#include "INET_Addr.h"
#include "SOCK_Connector.h"

int _tmain(int argc, char* argv[])
{
	long ip = 0x7F000001; // 127.0.0.1
	u_short port = 5500;

	INET_Addr address(port, ip);

	SOCK_Connector client();

	client.connect(address);

	std::cout << "Connected to " << ip << ":" << port << std::endl;

	// Main client event loop.
	for (;;)
	{
		std::string clientName = "client";
		client.send(clientName.c_str, clientName.length);

		std::string response;
		client.receive(response.c_str, 50);

		std::cout << response << std::endl;

		Sleep(2000);
	}

	return 0;
}