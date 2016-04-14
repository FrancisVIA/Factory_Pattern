#include "BaseThread.h"
#include <process.h>

BaseThread::BaseThread()
{
		event_handle = NULL;
		thread_handle = NULL;
		thread_ID = 0;
};

BaseThread::~BaseThread()
{
		event_handle = NULL;
		thread_handle = NULL;
};

void BaseThread::Start()
{
		event_handle = CreateEvent(NULL, TRUE, FALSE, NULL);
		if (event_handle)
		{
				thread_handle = (HANDLE)_beginthreadex(NULL, 0 , ThreadProc, this, 0 , &thread_ID);
		}
}

void BaseThread::Stop()
{
		SetEvent(event_handle);
		CloseHandle(event_handle);
		event_handle = NULL;
		Sleep(10);
		CloseHandle(thread_handle);
		thread_ID = 0;
}

DWORD BaseThread::GetThreadID()
{
		return GetThreadId(thread_handle);
}

UINT WINAPI BaseThread::ThreadProc(void *ptr)
{
		BaseThread* pThis = (BaseThread *)ptr;
		int ret = -1;
		while(ret != WAIT_OBJECT_0)
		{
				pThis->Run();
				ret = WaitForSingleObject(pThis->event_handle, 0);
		}

		return 0;
}


