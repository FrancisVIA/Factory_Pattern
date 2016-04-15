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
		int err = SOCKET_ERROR-1;
		static int send_count = 1;
		memset(send_buf, 0 ,strlen(send_buf));
		memset(recv_buf, 0 ,strlen(recv_buf));
		sprintf(send_buf , "Hello Server! This is Client! The %d time sending!", send_count);
		++send_count;
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