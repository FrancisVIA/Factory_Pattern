#ifndef PRODUCERTHREAD_H
#define PRODUCERTHREAD_H

#include "BaseThread.h"
#include "AsyncQueue.h"

class ProduerThread:public BaseThread
{
public:
		ProduerThread();
		~ProduerThread();
		void SetPutter(AsyncQueue<int>*);
		void Put(int);
private:
		virtual void Run();    

	    AsyncQueue<int>* pQueue;
		int count;
};


#endif