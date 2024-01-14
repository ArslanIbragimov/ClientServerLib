#include "main.h"

int main() {
	std::setlocale(LOCALE_ALL, "ru");
	WSAData wsadata{};
	SOCKET socket(socket(AF_INET, SOCK_STREAM, 0));
	sockaddr_in server{};
	server.sin_family = AF_INET;
	ServerC::start("192.168.1.4", 1152, wsadata, socket, server);

	return 0;
}