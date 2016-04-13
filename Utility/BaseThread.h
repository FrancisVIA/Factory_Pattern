#ifndef BASETHREAD_H
#define BASETHREAD_H
#include "stdafx.h"

class BaseThread
{
public:	
		BaseThread();
		~BaseThread();

		void Start();
		void Stop();
		DWORD GetThreadID();

private:
		static UINT WINAPI ThreadProc(void *);
		virtual void Run() = 0; 

		HANDLE event_handle;
		HANDLE thread_handle;
		UINT thread_ID;
};

#endif