#ifndef _atsutasocket_h_
#define _atsutasocket_h_

#include "AtsutaOverlapped.h"

class AtsutaSocket : public VirtualSocket
{
public:
	
private:
	ADDRINFO* destination;
	SOCKET connection;
	std::shared_ptr<AtsutaOverlapped> ovlread;
	std::shared_ptr<AtsutaOverlapped> ovlwrite;
	std::shared_ptr<AtsutaOverlapped> ovlaccept;
	AtsutaHandle handle;
	std::shared_ptr<AtsutaAddress> address;
	VirtualAtsuta& ref;
	std::string host;
	std::string port;
	bool pendingread;
	bool pendingwrite;
public:
	
	AtsutaSocket(VirtualAtsuta&);
	bool makesocket(const std::string&, const std::string&);
	const SOCKET& getsocket();
	AtsutaHandle& gethandle();
	ADDRINFO* getinfo();
	void makeaddress(SOCKADDR*, SOCKADDR*, int32_t , int32_t);
	const std::shared_ptr<AtsutaAddress>& getaddressinformation();
	void atsutaread(uint64_t);
	void atsutawrite(std::unique_ptr<char[]>, uint64_t);
	void atsutaaccept();
	AtsutaSocket* self() { return this; }
	const std::shared_ptr<AtsutaOverlapped>& getacceptovl(uint64_t);
	const std::shared_ptr<AtsutaOverlapped>& getacceptovl();
	SOCKET makenewsocket();
	~AtsutaSocket();
	const std::string& gethost();
	const std::string& getport();
	void atsutaclose(VirtualSocket&);
	void setpendingread(bool pending);
	void setpendingwrite(bool pending);
};
#endif

