#ifndef CLIENTSYSTEM_H
#define CLIENTSYSTEM_H

#include "stdafx.h"
#include <string>
#include "ClientThread.h"

using namespace std;

class ClientSystem
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


#endif