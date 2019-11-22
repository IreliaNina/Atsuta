#ifndef _nagoy_hpp_
#define _nagoy_hpp_
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinInet.h>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <tuple>
#pragma comment(lib,"WinInet")


namespace NagoyNS {
	
	class NagoyData {
	public:
		char* data;
		uint64_t length;

		NagoyData();
		~NagoyData();

	};
	class RequestType {
	public:
		virtual std::string getrequesttype() = 0;
	};
	class RequestTypeGet : public RequestType {
		std::string getrequesttype();
	};
	class RequestTypePost : public RequestType {
		std::string getrequesttype();
	};
	class NagoyHandles {
	public:
		void* handle;
		NagoyHandles();
		~NagoyHandles();
		
	};

	class Nagoy {
	private:
		NagoyHandles session;
		NagoyHandles connection;
		NagoyHandles request;
		std::vector<std::tuple<std::string, std::string>> headers;
	public:
		Nagoy();
		void setsession(void* session);
		void setconnection(void* connection);
		void setrequest(void* request);
		const NagoyHandles& getsession();
		const NagoyHandles& getconnection();
		const NagoyHandles& getrequest();
		const std::vector<std::tuple<std::string, std::string>>& getheaders();
		void insertheader(std::string& key, std::string& val);
		~Nagoy();
	};
	typedef std::unique_ptr<Nagoy> NagoyArc;
	typedef std::unique_ptr<NagoyData> NagoyDataArc;
	enum NagoyConnectionPort {
		kInternetPortNoSSL = INTERNET_DEFAULT_HTTP_PORT,
		kInternetPortWithSSL = INTERNET_DEFAULT_HTTPS_PORT,
	};
	enum NagoyServiceType {
		kServiceHTTP = INTERNET_SERVICE_HTTP
	};

	NagoyArc createref();
	bool nagoyconnect(const NagoyArc& ref, std::string&& server, NagoyConnectionPort port, NagoyServiceType type);
	bool nagoyconnect(const NagoyArc& ref, std::string& server, NagoyConnectionPort port, NagoyServiceType type);
	bool nagoyrequest(const NagoyArc& ref, std::string& requestpath, RequestType& type, void* query, uint64_t querysize, bool usingssl);
	bool nagoyrequest(const NagoyArc& ref, std::string&& requestpath, RequestType&& type, void* query, uint64_t querysize, bool usingssl);
	void nagoypushheader(const NagoyArc& ref, std::string& key, std::string& val);
	void nagoypushheader(const NagoyArc& ref, std::string&& key, std::string&& val);
	std::unique_ptr<NagoyData> readresponseheaders(const NagoyArc& ref);
	std::unique_ptr<NagoyData> readrequest(const NagoyArc& ref);
};
#endif