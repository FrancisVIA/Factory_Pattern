// Templale_practice.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Templale_practice.h"
#include "Try.h"
#include "CommonFunction.h"
#include "CosumerThread.h"
#include "ProducerThread.h"
#include <boost/bind.hpp>

#pragma comment(lib, "..\\Debug\\Utility.lib")  

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
		float a1 = 0.1;
		float a2 = 0.2;
		float a3 = 0.0;
		float a4 = 0.0;
		float b5 = -1.0;
		float b6 = -1.0;

		TryFactory<float>* p_try_factory1 = new Try_Derive1Factory<float>(a1, a2);
		TryFactory<float>* p_try_factory2 = new Try_Derive2Factory<float>(a1, a2);
		Try<float>* p_try1 = p_try_factory1->CreateTry();
		Try<float>* p_try2 = p_try_factory2->CreateTry();
		a3 = p_try1->Add();
		a4 = p_try2->Add();

		p_try1->SetFunc(boost::bind(Func1,_1,_2), 15, 5);
		p_try2->SetFunc(boost::bind(Func2,_1,_2), 15, 5);
		b5 = p_try1->ExecuteFunc();
		b6 = p_try2->ExecuteFunc();

		AsyncQueue<int> queue_temp;
		CosumerThread  Cosumer;
		ProduerThread   Producer;
		int cosumer_ID =-1;
		int producer_ID =-1;
		Cosumer.SetGetter(&queue_temp);
		Producer.SetPutter(&queue_temp);

		Producer.Start();
		Sleep(5*1000);
		Cosumer.Start();

		cosumer_ID = Cosumer.GetThreadID();
		producer_ID = Producer.GetThreadID();

		Producer.Stop();
		Sleep(5*1000);
		Cosumer.Stop();
}
