#ifndef _atsutahandle_h_
#define _atsutahandle_h_


#include "VirtualAtsuta.h"
class AtsutaHandle;
typedef std::function<void(AtsutaHandle&)> AtsutaOpenCallbackType;
typedef std::function<void(AtsutaHandle&)> AtsutaCloseCallbackType;
typedef std::function<void(AtsutaHandle&, std::unique_ptr<char[]> data, uint64_t length)> AtsutaReadCallbackType;
typedef std::function<void(AtsutaHandle&, std::unique_ptr<char[]> data, uint64_t length)> AtsutaWriteCallbackType;
class AtsutaHandle : public std::enable_shared_from_this<AtsutaHandle>
{
private:
	AtsutaOpenCallbackType opencallback;
	AtsutaCloseCallbackType closecallback;
	AtsutaReadCallbackType readcallback;
	AtsutaWriteCallbackType writecallback;
	std::shared_ptr<void> userdata;
	VirtualSocket& ref;
protected:

	
public:
	AtsutaHandle(VirtualSocket&);
	~AtsutaHandle();


	template<typename R = void>
	std::shared_ptr<R> data() const {
		return std::static_pointer_cast<R>(userdata);
	}


	void data(std::shared_ptr<void> udata) {
		userdata = std::move(udata);
	}

	void setopencallback(AtsutaOpenCallbackType);
	void setclosecallback(AtsutaCloseCallbackType);
	const AtsutaOpenCallbackType& getopencallback();
	const AtsutaCloseCallbackType& getclosecallback();


	void setreadcallback(AtsutaReadCallbackType);
	void setwritecallback(AtsutaWriteCallbackType);
	const AtsutaReadCallbackType& getreadcallback();
	const AtsutaWriteCallbackType& getwritecallback();
	
	const std::shared_ptr<AtsutaAddress>& getaddressinformation();
	void atsutaread(uint64_t length);
	void atsutawrite(std::unique_ptr<char[]> data, uint64_t length);
	std::unique_ptr<char[]> makeuniquedata(char*, uint64_t);
	void atsutaclose();
};
#endif

