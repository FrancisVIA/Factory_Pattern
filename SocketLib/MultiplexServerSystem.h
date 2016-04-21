#ifndef MULTIPLEXSERVERSYSTEM_H
#define MULTIPLEXSERVERSYSTEM_H

#include "stdafx.h"
#include "MultiplexServerThread.h"
#include "ServerSystem.h"

class MultiplexServerSystem:public ServerSystem
{
public:
		MultiplexServerSystem();
		~MultiplexServerSystem();

		virtual bool ProcessConnection();
private:
		MultiplexServerThread serverThread;

};

MultiplexServerSystem& g_MultiplexServerSystem();

#endif