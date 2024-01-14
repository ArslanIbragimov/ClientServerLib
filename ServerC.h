#pragma once

#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

namespace ServerC {
	
	BOOL ErrorCheck(WSADATA wsaData, SOCKET serverSocket, sockaddr_in serverAddr);
	void start(char* IPAddr, unsigned short PORT, WSADATA WSA, SOCKET Socket, sockaddr_in Server);
}
