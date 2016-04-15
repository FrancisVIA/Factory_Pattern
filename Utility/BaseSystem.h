#ifndef BASESYSTEM_H
#define BASESYSTEM_H

#include "stdafx.h"
#include <string>

class BaseSystem
{
public:
		BaseSystem();
		~BaseSystem();

		bool Init();
		int MainLoop();
protected:
		void SetName(char* );
private:
		MSG msg;
		char system_name[64];

};





#endif