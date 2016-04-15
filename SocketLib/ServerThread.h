#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include "stdafx.h"
#include "..\Utility\BaseThread.h"

class ServerThread:public BaseThread
{
public:
		ServerThread();
		~ServerThread();
		void SetSocket(SOCKET);

private:
		virtual void Run();

		SOCKET sock;
		char send_buf[1024];
		char recv_buf[1024];
};

#endif