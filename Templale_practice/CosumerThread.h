#ifndef  COSUMERTHREAD_H
#define  COSUMERTHREAD_H

#include "BaseThread.h"
#include "AsyncQueue.h"

class CosumerThread:public BaseThread
{
public:
		CosumerThread();
		~CosumerThread();
		void  SetGetter(AsyncQueue<int>*);
		bool  Get(int &);

private:
		virtual void Run();

		AsyncQueue<int> * pQueue;
};



# endif