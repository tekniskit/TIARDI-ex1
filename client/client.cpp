// client.cpp : Defines the entry point for the console application.

#include <Windows.h>
#include <iostream>
#include "stdafx.h"

#include "INET_Addr.h"
#include "SOCK_Connector.h"
#include "SOCK_Stream.h"

int _tmain(int argc, char* argv[])
{
	long ip = inet_addr(argv[0]);
	u_short port = atoi(argv[1]);

	INET_Addr address(port, ip);

	SOCK_Connector client(address);
	SOCK_Stream stream;

	std::cout << "Connected to " << ip << ":" << port << std::endl;

	// Main client event loop.
	for (;;)
	{
		stream = client.connect();
	}

	return 0;
}