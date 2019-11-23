# Atsuta
Networking Library in IOCP

Example usage:
```cpp
#include <iostream>

#include "Atsuta.h"
#pragma comment(lib,"Atsuta")//Visual Studio directive
void readcb(AtsutaHandle& ref, std::unique_ptr<char[]> data, uint64_t length) {
	std::cout << data.get();
	ref.atsutaread(1024);
	//
}
void writecb(AtsutaHandle& ref , std::unique_ptr<char[]> data, uint64_t length) {

}
void closecb(AtsutaHandle& ref){

}
void readfromgooglecb(AtsutaHandle& ref, std::unique_ptr<char[]> data, uint64_t length) {
	//
	ref.atsutaread(1024);
}
void connectgooglecb(AtsutaHandle& ref) {
	ref.setclosecallback(closecb);
	ref.setwritecallback(writecb);
	ref.setreadcallback(readfromgooglecb);
}
int main()
{
	Atsuta ac;
	ac.atsutalisten("0.0.0.0", "7060", [](AtsutaHandle& ref) {//listen on port 7060
		ref.setwritecallback(writecb);
		ref.setreadcallback(readcb);
		ref.atsutaread(1024);
	},closecb);
	ac.atsutalisten("0.0.0.0", "7070", [](AtsutaHandle& ref) {//listen on port 7070
		ref.setwritecallback(writecb);
		ref.setreadcallback(readfromgooglecb);
		ref.atsutaread(1024);
	}, closecb);
	ac.atsutaconnect("google.com", "443", connectgooglecb);//connect to google as well
	ac.run();
	return 0;
}
