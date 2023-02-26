#ifndef SQL_BUILDER_HPP
#define SQL_BUILDER_HPP

#include <string>
#include <sqlite3.h>

namespace device {

class AppDB {
public:
	explicit AppDB();

	void MakeDeviceTable();
	void InsertDevice(const std::string &a_name);
	
	size_t SizeDB() const;
	std::string DeviceName(int a_id) const;
	int DeviceID(const std::string &a_name) const;

private:
	size_t m_size;
};

} //device

#endif //SQL_BUILDER_HPP