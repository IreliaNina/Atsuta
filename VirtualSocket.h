#ifndef _virtualsocket_h_
#define _virtualsocket_h_
#include "AtsutaAddress.h"

class VirtualSocket : public std::enable_shared_from_this<VirtualSocket> {
public:
	virtual const SOCKET& getsocket() = 0;
	virtual const std::shared_ptr<AtsutaAddress>& getaddressinformation() = 0;
	virtual void atsutaread(uint64_t length) = 0;
	virtual void atsutawrite(std::unique_ptr<char[]> data, uint64_t length) = 0;
	virtual VirtualSocket* self() = 0;
	virtual void atsutaclose(VirtualSocket&) = 0;
};
#endif