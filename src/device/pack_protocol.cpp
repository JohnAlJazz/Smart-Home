#include <iostream>

#include "pack_protocol.hpp"
#include "app_db.hpp"

namespace device {

static void FillVector(std::vector<unsigned char>& a_vec, size_t a_size, unsigned char* a_bytesPtr) {

	for(size_t i = 0; i < a_size; ++i) {

		a_vec.push_back(a_bytesPtr[i]);
	}
}

std::vector<unsigned char> Pack(std::string a_id, const std::string& a_payLoad)
{
	//4 bytes for device id + len of msg
	size_t size = sizeof(uint32_t) + a_payLoad.length();
	uint64_t htonSize = static_cast<uint64_t>(size);
	unsigned char* sizeTemp = reinterpret_cast<unsigned char*>(&htonSize);

	std::vector<unsigned char> buffer;

	//first 8 bytes are for the size of the msg	
	FillVector(buffer, sizeof(uint64_t), sizeTemp);

	device::AppDB deviceTable;
	uint32_t tempID = deviceTable.DeviceID(a_id);	
	unsigned char* chTempID = reinterpret_cast<unsigned char*> (&tempID);

	//4 bytes after the first 8, indicate the device id	
	FillVector(buffer, sizeof(uint32_t), chTempID);

	unsigned char * chTemp = reinterpret_cast<unsigned char*>(const_cast<char*>(a_payLoad.c_str()));

	size_t sizeStr = a_payLoad.length();
	
	//the rest is the msg	
	FillVector(buffer, sizeStr, chTemp);
	
	return buffer;
}

} //device