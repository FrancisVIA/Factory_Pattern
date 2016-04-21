#ifndef MULTIPLEXSERVERTHREAD_H
#define MULTIPLEXSERVERTHREAD_H

#include "stdafx.h"
#include "ServerThread.h"
#include <vector>

class MultiplexServerThread:public ServerThread
{
public:
		MultiplexServerThread();
		~MultiplexServerThread();
		void PushSocket(SOCKET);

private:
		virtual void Run();

		std::vector<SOCKET> m_Socket_List;

};




#endif MULTIPLEXSERVERTHREAD_H