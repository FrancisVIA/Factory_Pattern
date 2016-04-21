#include "stdafx.h"
#include "MultiplexServerSystem.h"

#pragma comment(lib, "Ws2_32.lib")

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	if (!g_MultiplexServerSystem().Init())
	{
		return 0;
	}
	g_MultiplexServerSystem().SetServer(12345,5);
	g_MultiplexServerSystem().CreateConnection();
	g_MultiplexServerSystem().ProcessConnection();
	g_MultiplexServerSystem().MainLoop();
	return 0;
}