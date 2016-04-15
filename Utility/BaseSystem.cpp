#include "BaseSystem.h"

BaseSystem::BaseSystem()
{
		memset(&msg, 0 , sizeof(MSG));
		memset(system_name, 0 ,64);
}

BaseSystem::~BaseSystem()
{
		
}

bool BaseSystem::Init()
{
		char mutex_name[128];
		sprintf(mutex_name, "Global\\%s", system_name);
		int len = strlen(mutex_name)+1;
		wchar_t* output = (wchar_t*)malloc(len*sizeof(wchar_t));
		mbstowcs(output, mutex_name, len);
		HANDLE hmutex = CreateMutex(NULL, FALSE, output);
		if (hmutex==INVALID_HANDLE_VALUE||\
			GetLastError()==ERROR_ALREADY_EXISTS)
		{
				return false;
		}

		return true;
}

int BaseSystem::MainLoop()
{		
		while(GetMessage(&msg, NULL, 0, 0))
		{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
		}

		return 0;
}

void BaseSystem::SetName(char* input)
{
		if (!input)
		{
				return;
		}
		memset(system_name, 0 ,strlen(system_name));
		strcpy(system_name, input);
}