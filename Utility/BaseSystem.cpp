#include "BaseSystem.h"
#include "objbase.h"

BaseSystem::BaseSystem()
{
		memset(&msg, 0 , sizeof(MSG));
		memset(system_name, 0 ,256);
}

BaseSystem::~BaseSystem()
{
		
}

bool BaseSystem::Init()
{
		char mutex_name[512];
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

void BaseSystem::SetGuid()
{
		GUID guid;
		CoCreateGuid(&guid);
		sprintf(guid_buf,  "{%08X%04-X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",  
			guid.Data1, guid.Data2, guid.Data3,  
			guid.Data4[0], guid.Data4[1],  
			guid.Data4[2], guid.Data4[3],  
			guid.Data4[4], guid.Data4[5],  
			guid.Data4[6], guid.Data4[7]);  
}