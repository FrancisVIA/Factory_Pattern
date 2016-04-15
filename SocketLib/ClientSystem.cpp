#include "ClientSystem.h"

ClientSystem& g_ClientSystem()
{
		static ClientSystem clientSystem;
		return clientSystem;
}

ClientSystem::ClientSystem():BaseSystem(),\
sock(-1)
{
		memset(&serverAddr , 0, sizeof(serverAddr));
		SetName("Client");
}

ClientSystem::~ClientSystem()
{

}

void ClientSystem::SetServer(string& IP, int port)
{
		memset(&serverAddr , 0, sizeof(serverAddr));
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(port);
		serverAddr.sin_addr.S_un.S_addr = inet_addr(IP.c_str());
}

bool ClientSystem::CreateConnection()
{
		WORD wVersionRequested;
		WSADATA wsaData;
		int err;
		wVersionRequested = MAKEWORD(2, 2);

		err = WSAStartup(wVersionRequested,&wsaData);

		if (err != 0)
		{
				return false;				
		}

		if (LOBYTE(wsaData.wVersion)!=2||\
			HIBYTE(wsaData.wVersion)!=2)
		{
				return false;
		}

		sock = socket(AF_INET, SOCK_STREAM, 0);

		if (sock == INVALID_SOCKET)
		{
				return false;
		}

		err = connect(sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

		if (err != 0)
		{
				return false;				
		}

		clientThread.SetSocket(sock);
		clientThread.Start();

		return true;
}

bool ClientSystem::TerminateConnection()
{
		int err;

		clientThread.Stop();
		err = shutdown(sock, SD_BOTH);

		if (err != 0)
		{
				return false;				
		}

		return true;
}