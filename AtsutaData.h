#ifndef _atsutadata_h_
#define _atsutadata_h_

class AtsutaData {
public:
	std::unique_ptr<char[]> data;
	unsigned long length;
	AtsutaData(std::unique_ptr<char[]> data, ULONG length);
	~AtsutaData();
};
#endif