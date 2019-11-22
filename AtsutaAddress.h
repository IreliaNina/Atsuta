#ifndef _atsutaaddress_h_
#define _atsutaaddress_h_
#include "AtsutaExtensions.h"
class AtsutaAddress {
public:
	SOCKADDR local;
	SOCKADDR remote;
	int32_t localsize;
	int32_t remotesize;
	AtsutaAddress(SOCKADDR*, SOCKADDR*, int32_t, int32_t);
	~AtsutaAddress();
};
#endif