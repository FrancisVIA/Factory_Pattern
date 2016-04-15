#include "stdafx.h"
#include "ServerSystem.h"

#pragma comment(lib, "Ws2_32.lib")

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
		if (!g_ServerSystem().Init())
		{
				return 0;
		}
		g_ServerSystem().SetServer(12345);
		g_ServerSystem().CreateConnection();
		g_ServerSystem().MainLoop();
		return 0;
}