#include "mu_test.h"

#include <iostream>

#include "app_db.hpp"

BEGIN_TEST(device_name_by_id)
	device::AppDB sqlObj;
	sqlObj.MakeDeviceTable();
	std::string result = sqlObj.DeviceName(1000);
	std::string check("temperature_1_a_1");
	ASSERT_EQUAL(result, check);
END_TEST

BEGIN_TEST(device_id_by_name)
	device::AppDB sqlObj;
	sqlObj.MakeDeviceTable();
	std::string name("temperature_1_a_1");
	int result = sqlObj.DeviceID(name);
	ASSERT_EQUAL(result, 1000);
	//std::cout << result << '\n';
END_TEST

BEGIN_TEST(insert_device_name_by_id)
	device::AppDB sqlObj;
	sqlObj.MakeDeviceTable();
	std::string mDevice("motion_1_a_1");
	sqlObj.InsertDevice(mDevice);
	std::string result = sqlObj.DeviceName(1);
	ASSERT_EQUAL(result, mDevice);
END_TEST

BEGIN_TEST(insert_device_id_by_named)
	device::AppDB sqlObj;
	sqlObj.MakeDeviceTable();
	std::string mDevice("motion_1_a_1");
	sqlObj.InsertDevice(mDevice);
	int result = sqlObj.DeviceID(mDevice);
	ASSERT_EQUAL(result, 1);
END_TEST

BEGIN_TEST(insert_3_device_name_by_id)
	device::AppDB sqlObj;
	sqlObj.MakeDeviceTable();
	std::string mDevice("motion_1_a_1");
	std::string bDevice("badge_1_a_1");
	std::string mDevice2("motion_1_a_2");
	sqlObj.InsertDevice(mDevice);
	sqlObj.InsertDevice(bDevice);
	sqlObj.InsertDevice(mDevice2);
	std::string result = sqlObj.DeviceName(3);
	ASSERT_EQUAL(result, mDevice2);
END_TEST

BEGIN_SUITE(sql builder test)
	TEST(device_name_by_id)
	TEST(device_id_by_name)
	TEST(insert_device_name_by_id)
	TEST(insert_device_id_by_named)
	TEST(insert_3_device_name_by_id)
END_SUITE