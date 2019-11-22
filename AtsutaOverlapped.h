#ifndef _atsutaoverlapped_h_
#define _atsutaoverlapped_h_
#include "AtsutaHandle.h"
namespace AtsutaOperation {
	enum Operation {
		kAtsutaNOP = 0,
		kAtsutaAccept,
		kAtsutaRead,
		kAtsutaWrite
	};
};

class AtsutaOverlapped
{
public:
	OVERLAPPED ovl;
	AtsutaOperation::Operation op;
	std::unique_ptr<char[]> data;
	uint64_t length;
	WSABUF buf;
	VirtualSocket& ref;
	AtsutaOverlapped(VirtualSocket&);
	~AtsutaOverlapped();
};
#endif

