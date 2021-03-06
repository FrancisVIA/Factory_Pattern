#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include "stdafx.h"
#include "..\Utility\BaseThread.h"

class ClientThread:public BaseThread
{
public:
		ClientThread();
		~ClientThread();
		void SetSocket(SOCKET);
		void SetGuid(char*);

private:
		virtual void Run();

		SOCKET sock;
		char send_buf[1024];
		char recv_buf[1024];
		char guid_buf[128];
};



#endif