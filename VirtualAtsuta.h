
#ifndef _virtualatsuta_h_
#define _virtualatsuta_h_
#include "VirtualSocket.h"
class VirtualAtsuta {
public:
	virtual void atsutaremove(std::shared_ptr<VirtualSocket>) = 0;
	virtual std::unique_ptr<AtsutaAcceptEx> getacceptex(SOCKET) = 0;
	virtual std::unique_ptr<AtsutaGetAcceptExSockaddrs> getacceptexsockaddr(SOCKET) = 0;
};
#endif