#include "mu_test.h"
#include <iostream>

#include "subscribers_factory.hpp"
#include "sql_builder.hpp"

BEGIN_TEST(sensor_name_by_id)
	device::SqlBuilder sqlObj;
	std::string result = sqlObj.SensorName(10);
	std::string check("Temperature_1_a_1");
	ASSERT_EQUAL(result, check);
END_TEST

BEGIN_TEST(sensor_id_by_name)

END_TEST

BEGIN_SUITE(sql builder test)
	TEST(sensor_name_by_id)
END_SUITE