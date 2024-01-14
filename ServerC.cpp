// ServerC.cpp: определяет точку входа для приложения.
//

#include "ServerC.h"



BOOL ServerC::ErrorCheck(WSADATA wsaData, SOCKET serverSocket, sockaddr_in serverAddr) {
    
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Ошибка инициализации Winsock." << std::endl;
        return false;
        
    }
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Ошибка создания сокета." << std::endl;
        WSACleanup();
        
        return false;
    }
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Ошибка привязки сокета." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return false;
    }
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Ошибка прослушивания сокета." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return false;
    }
    
    return true;
}

void ServerC::start(char* IPAddr, unsigned short PORT, WSADATA WSA, SOCKET SocketS, sockaddr_in Server) {
    if (ServerC::ErrorCheck(WSA, SocketS, Server)) {
        std::cout << "Сервер запускается..." << std::endl;
        Server.sin_addr.s_addr = inet_addr(IPAddr);
        Server.sin_port = htons(PORT);
        SOCKET SocketC = accept(SocketS, NULL, NULL);
        if (SocketC == INVALID_SOCKET) {
            std::cerr << "Ошибка приема соединения." << std::endl;
            closesocket(SocketS);
            WSACleanup();   
        }
        else {
            std::cout << "Подключился компьютер" << std::endl;
        }

        closesocket(SocketC);
        closesocket(SocketS);
        WSACleanup();
    }
    else {
        std::cout << "Сервер не запустился(" << std::endl;
    }

}