#include <windows.h>

void domything()
{
	WinExec("cmd.exe", 1);
}

BOOL WINAPI DllMain(HINSTANCE h, DWORD d, LPVOID l)
{
	switch (d)
	{
		case DLL_PROCESS_ATTACH:
			domything();
			break;
		default:
			break;
	};

	return TRUE;
}
