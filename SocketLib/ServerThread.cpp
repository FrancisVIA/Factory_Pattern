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
		int err;
		strcpy(send_buf , "Hello Client! This is Server!");

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