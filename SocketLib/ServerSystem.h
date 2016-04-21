#ifndef SERVERSYSTEM_H
#define SERVERSYSTEM_H

#include "stdafx.h"
#include "ServerThread.h"
#include "..\Utility\BaseSystem.h"

class ServerSystem:public BaseSystem
{
public:
		ServerSystem();
		~ServerSystem();

		void SetServer(int port, int connection_limit);
		bool CreateConnection();
		virtual bool ProcessConnection();

protected:
	   int connection_limit;
	   SOCKET listen_sock;
	   SOCKET accept_sock;
	   struct sockaddr_in serverAddr;
	   struct sockaddr_in clientAddr;
	   ServerThread  serverThread;

};


ServerSystem& g_ServerSystem();




#endif