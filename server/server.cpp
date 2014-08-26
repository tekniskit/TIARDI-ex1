// server.cpp : Defines the entry point for the console application.
//
#include <Windows.h>
#include <iostream>
#include "stdafx.h"

#include "INET_Addr.h"
#include "SOCK_Acceptor.h"
#include "SOCK_Stream.h"

int _tmain(int argc, char* argv[])
{	
	long ip = 0x7F000001; // 127.0.0.1
	u_short port = 5500;

	INET_Addr address(port, ip);
	
	// Passive-mode acceptor object.
	SOCK_Acceptor server(address);
	SOCK_Stream stream;

	std::cout << "Listening on localhost:" << port << std::endl;

	// Main server event loop.
	for (;;)
	{
		// Accept a connection from a client.
		server.accept(stream);
	}

	return 0;
}