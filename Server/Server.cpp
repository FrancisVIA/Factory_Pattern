#include "stdafx.h"
#include "ServerSystem.h"

#pragma comment(lib, "Ws2_32.lib")

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
		ServerSystem serverSystem;
		serverSystem.SetServer(100);
		serverSystem.CreateConnection();
		while(1);

		return 0;
}