#ifndef ASYNCQUECE_H
#define ASYNCQUECE_H

#include <queue>

template<typename T>
class AsyncQueue
{
public:		
		AsyncQueue()
		{

		};
		~AsyncQueue()
		{
				
		};
		bool Get(T& t)
		{
				if (!m_queue.empty())
				{
						t = m_queue.front();
						m_queue.pop();
						return true;
				}
				else
				{
						return false;
				}
		};
		void Put(T t)
		{
				m_queue.push(t);
		};

private:
		std::queue<T> m_queue; 	    
};

#endif