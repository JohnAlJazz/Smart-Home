#include "mu_test.h"
#include <vector>
#include <string>

#include "pack_protocol.hpp"
#include "unpack_protocol.hpp"

#include "app_db.hpp"

enum key {
    TEMPRATURE_SENSOR
};

BEGIN_TEST(pack_unpack)
	device::AppDB table;
	table.MakeDeviceTable();
	
	std::string strID  {"temperature_1_a_1"};
	std::string strPayload {"abc"};

	auto vec = device::Pack(strID, strPayload);
	auto result = device::Unpack(vec);

	std::cout << "result = " << result.first << "\n";

	ASSERT_EQUAL(result.first, strID);
	ASSERT_EQUAL(result.second, strPayload);
	ASSERT_PASS();
END_TEST

/* BEGIN_TEST(protocol_temperature)
	std::string str("26");
	auto vec = device::Pack(TEMPRATURE_SENSOR, str);
	auto result = device::Unpack(vec);
	ASSERT_EQUAL(std::get<uint32_t>(result), 0);
	ASSERT_EQUAL(std::get<std::string>(result), str);
END_TEST */

BEGIN_SUITE(protocol test)
	TEST(pack_unpack)
	//TEST(protocol_temperature)
END_SUITE
