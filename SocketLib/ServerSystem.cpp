#include "ServerSystem.h"

ServerSystem::ServerSystem():\
	listen_sock(-1), accept_sock(-1)
{
		memset(&serverAddr, 0 ,sizeof(serverAddr));
		memset(&clientAddr, 0 ,sizeof(clientAddr));
}

ServerSystem::~ServerSystem()
{

}

void ServerSystem::SetServer(int port)
{
		memset(&serverAddr , 0, sizeof(serverAddr));
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = port;
		serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
}

bool ServerSystem::CreateConnection()
{
		DWORD wVersionRequested;
		WSADATA wsaData;
		int err;
		wVersionRequested = MAKEWORD(2, 2);
		err = WSAStartup(wVersionRequested, &wsaData);

		if (err!=0)
		{
				return false;
		}

		if (LOBYTE(wsaData.wVersion)!=2||\
			HIBYTE(wsaData.wVersion)!=2)
		{
				return false;
		}

		listen_sock = socket(AF_INET, SOCK_STREAM, 0);

		if (listen_sock==INVALID_SOCKET)
		{
				return false;
		}

		err = bind(listen_sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

		if (err!=0)
		{
				return false;
		}

		err = listen(listen_sock , 1);

		if (err!=0)
		{
				return false;
		}

		while (1)
		{
				int len = sizeof(clientAddr);
				accept_sock = accept(listen_sock, (SOCKADDR*)&clientAddr, &len);
				if (accept_sock!= INVALID_SOCKET)
				{
						serverThread.SetSocket(accept_sock);
						serverThread.Start();
						break;
				}
		}

		return true;
}