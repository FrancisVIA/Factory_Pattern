#include "MultiplexServerSystem.h"

MultiplexServerSystem& g_MultiplexServerSystem()
{
		static MultiplexServerSystem serverSystem;
		return serverSystem;
}

MultiplexServerSystem::MultiplexServerSystem():\
ServerSystem()
{
		
}

MultiplexServerSystem::~MultiplexServerSystem()
{
		
}

bool MultiplexServerSystem::ProcessConnection()
{
		while (1)
		{
				sockaddr clientAddr_temp;
				int len = sizeof(sockaddr);
				SOCKET sock_temp = accept(listen_sock, &clientAddr_temp, &len);
				if (sock_temp!=INVALID_SOCKET)
				{
						serverThread.PushSocket(sock_temp);
						serverThread.Start();
				}
				
		}
}