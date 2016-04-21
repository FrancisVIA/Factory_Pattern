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
		void SetGuid();

		char guid_buf[128];
private:
		MSG msg;
		char system_name[256];

};





#endif