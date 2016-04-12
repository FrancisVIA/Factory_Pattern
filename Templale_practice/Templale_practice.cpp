// Templale_practice.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Templale_practice.h"
#include "Try.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
		float a1=0.1;
		float a2=0.2;
		float a3;
		float a4;

		TryFactory<float>* p_try_factory1 = new Try_Derive1Factory<float>(a1, a2);
		TryFactory<float>* p_try_factory2 = new Try_Derive2Factory<float>(a1, a2);
		Try<float>* p_try1 = p_try_factory1->CreateTry();
		Try<float>* p_try2 = p_try_factory2->CreateTry();
		a3 = p_try1->Add();
		a4 = p_try2->Add();
}
