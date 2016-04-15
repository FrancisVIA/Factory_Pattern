#include "ClientThread.h"

ClientThread::ClientThread():BaseThread(), sock(-1)
{
		memset(send_buf, 0, 1024);
		memset(recv_buf, 0, 1024);
}

ClientThread::~ClientThread()
{
	    
}

void ClientThread::SetSocket(SOCKET s)
{
		sock = s;
}

void ClientThread::Run()
{
		int err;
		sprintf(send_buf , "Hello Server! This is Client!");

		err = send(sock, send_buf, 1024, 0);

		if (err == SOCKET_ERROR)
		{
				return;
		}

		err = recv(sock, recv_buf ,1024, 0);

		if (err == SOCKET_ERROR)
		{
				return;
		}

}