#include "CosumerThread.h"

CosumerThread::CosumerThread():BaseThread()
{
		pQueue = NULL;
}

CosumerThread::~CosumerThread()
{
		pQueue = NULL;
}

void CosumerThread::SetGetter(AsyncQueue<int>* p)
{
		pQueue = p;
}

bool CosumerThread::Get(int &val)
{
	    if (pQueue)
	    {
				return pQueue->Get(val);
	    } 
	    else
	    {
				return false;
	    }
}

void CosumerThread::Run()
{
		int val;
		Get(val);
}