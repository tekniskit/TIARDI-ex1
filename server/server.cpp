// server.cpp : Defines the entry point for the console application.
#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <iostream>
#include <string>
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
	
	// Accept a connection from a client.
	server.accept(stream);

	// Main server event loop.
	for (;;)
	{
		char clientName[7];

		stream.recv(clientName, 7, 0);

		std::cout << clientName << " has connected" << std::endl;

		std::string message = "Hello to you, ";
		message.append(clientName);
		message.append("\n");

		stream.send(message.c_str(), message.length(), 0);
	}

	return 0;
}