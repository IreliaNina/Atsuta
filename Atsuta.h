#ifndef _atsuta_h_
#define _atsuta_h_
#include "AtsutaSocket.h" 

class Atsuta : public VirtualAtsuta
{
private:
	HANDLE completionport;
	std::set<std::shared_ptr<VirtualSocket>> handles;
public: 
	Atsuta();
	~Atsuta();
	void run();
	bool atsutaconnect(const std::string&, const std::string&,AtsutaOpenCallbackType);
	bool atsutaconnect(std::string&&, std::string&&,AtsutaOpenCallbackType);
	bool atsutalisten(const std::string&, const std::string&, AtsutaOpenCallbackType, AtsutaCloseCallbackType);
	bool atsutalisten(std::string&&, std::string&&, AtsutaOpenCallbackType, AtsutaCloseCallbackType);
protected:

private:
	void atsutaaccept(AtsutaOverlapped*);
	bool atsutaaccept(std::shared_ptr<AtsutaSocket> , const std::string& , const std::string& , AtsutaOpenCallbackType,AtsutaCloseCallbackType);
	std::unique_ptr<AtsutaAcceptEx> getacceptex(SOCKET);
	std::unique_ptr<AtsutaGetAcceptExSockaddrs> getacceptexsockaddr(SOCKET);
	std::shared_ptr<AtsutaSocket> createsocket(const std::string&, const std::string&);
	void AssociatePort(VirtualSocket* key);
	void atsutaremove(std::shared_ptr<VirtualSocket>);
	friend class VirtualSocket;
	void post(const std::shared_ptr<AtsutaOverlapped>&);
};
#endif;

