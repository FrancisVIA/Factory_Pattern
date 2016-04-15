#include "stdafx.h"
#include "ClientSystem.h"

#pragma comment(lib, "Ws2_32.lib")

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
		if (!g_ClientSystem().Init())
		{
				return 0;
		}
		std::string IP = "127.0.0.1";
		g_ClientSystem().SetServer(IP, 12345);
		g_ClientSystem().CreateConnection();
		g_ClientSystem().MainLoop();
		g_ClientSystem().TerminateConnection();
	
		return 0;
}