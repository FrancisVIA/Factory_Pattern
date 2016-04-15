#ifndef CLIENTSYSTEM_H
#define CLIENTSYSTEM_H

#include "stdafx.h"
#include <string>
#include "ClientThread.h"
#include "..\Utility\BaseSystem.h"

using namespace std;

class ClientSystem:public BaseSystem
{
public:
		ClientSystem();
		~ClientSystem();

		void SetServer(string& IP, int port);
		bool CreateConnection();
		bool TerminateConnection();

private:
		SOCKET sock;
		struct sockaddr_in serverAddr;
		ClientThread clientThread;
	   
};

ClientSystem& g_ClientSystem();

#endif