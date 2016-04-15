#include "ServerThread.h"

ServerThread::ServerThread():BaseThread(), sock(-1)
{
		memset(send_buf, 0, 1024);
		memset(recv_buf, 0, 1024);
}

ServerThread::~ServerThread()
{

}

void ServerThread::SetSocket(SOCKET s)
{
		sock = s;
}

void ServerThread::Run()
{
		int err = SOCKET_ERROR-1;
		static int send_count = 1;
		memset(send_buf, 0, strlen(send_buf));
		memset(recv_buf, 0, strlen(recv_buf));
		sprintf(send_buf , "Hello Client! This is Server! The %d time send!", send_count);
		++send_count;
		err = recv(sock, recv_buf ,1024, 0);

		if (err == SOCKET_ERROR)
		{
				return;
		}

		err = send(sock, send_buf, 1024, 0);

		if (err == SOCKET_ERROR)
		{
				return;
		}

}