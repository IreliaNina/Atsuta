#ifndef _atsutaextensions_h_
#define _atsutaextensions_h_
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WS2tcpip.h>
#include <MSWSock.h>
#include <string>
#include <memory>
#include <functional>
#include <vector>
#include <set>
#include <WinInet.h>
#include <tuple>
#pragma comment(lib,"Mswsock.lib")
#pragma comment(lib,"WS2_32")
class AtsutaAcceptEx {
public:
	LPFN_ACCEPTEX accx;
	AtsutaAcceptEx(SOCKET s);

	~AtsutaAcceptEx() {
		accx = nullptr;
	}
};
class AtsutaGetAcceptExSockaddrs{
public:
	LPFN_GETACCEPTEXSOCKADDRS gaccxs;
	AtsutaGetAcceptExSockaddrs(SOCKET s);

	~AtsutaGetAcceptExSockaddrs() {
		gaccxs = nullptr;
	}
};
#endif
