#ifndef SERVERSYSTEM_H
#define SERVERSYSTEM_H

#include "stdafx.h"
#include "ServerThread.h"

class ServerSystem
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







#endif