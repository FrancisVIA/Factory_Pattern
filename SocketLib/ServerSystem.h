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

		void SetServer(int port);
		bool CreateConnection();

private:
	   SOCKET listen_sock;
	   SOCKET accept_sock;
	   struct sockaddr_in serverAddr;
	   struct sockaddr_in clientAddr;
	   ServerThread  serverThread;

};


ServerSystem& g_ServerSystem();




#endif