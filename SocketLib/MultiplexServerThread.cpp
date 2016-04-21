#include "MultiplexServerThread.h"

MultiplexServerThread::MultiplexServerThread():
ServerThread()
{
		m_Socket_List.clear();
}

MultiplexServerThread::~MultiplexServerThread()
{
		m_Socket_List.clear();
}

void MultiplexServerThread::PushSocket(SOCKET s)
{
		m_Socket_List.push_back(s);
}

void MultiplexServerThread::Run()
{
		for (int i = 0;i<m_Socket_List.size();++i)
		{
				int err = SOCKET_ERROR-1;
				static int send_count = 1;
				memset(send_buf, 0, strlen(send_buf));
				memset(recv_buf, 0, strlen(recv_buf));
				sprintf(send_buf , "Hello Client! This is Server! The %d time send!", send_count);
				++send_count;
				err = recv(m_Socket_List[i], recv_buf ,1024, 0);

				if (err == SOCKET_ERROR)
				{
						return;
				}

				err = send(m_Socket_List[i], send_buf, 1024, 0);

				if (err == SOCKET_ERROR)
				{
						return;
				}
		}
}
