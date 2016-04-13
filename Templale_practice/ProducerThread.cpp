#include "ProducerThread.h"

ProduerThread::ProduerThread():BaseThread()
{
		pQueue = NULL;
		count = 0;
}

ProduerThread::~ProduerThread()
{
		pQueue = NULL;
}

void ProduerThread::SetPutter(AsyncQueue<int>* p)
{
		pQueue = p;
}

void ProduerThread::Put(int val)
{
		if (pQueue)
		{
				pQueue->Put(val);
		}
}

void ProduerThread::Run()
{
		Put(++count);
}