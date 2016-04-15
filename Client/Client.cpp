#include "stdafx.h"
#include "ClientSystem.h"

#pragma comment(lib, "Ws2_32.lib")

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
		ClientSystem clientSystem;
		std::string IP = "127.0.0.1";
		clientSystem.SetServer(IP, 100);
		clientSystem.CreateConnection();
		clientSystem.TerminateConnection();
	
		return 0;
}