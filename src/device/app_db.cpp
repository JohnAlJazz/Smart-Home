#include <iostream>

#include "app_db.hpp"
#include "abstract_exeption.hpp"

namespace device {

AppDB::AppDB()
: m_size(0)
{}

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

void AppDB::MakeDeviceTable()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	//const char* data = "Callback function called";

	/* Open database */
	remove("devices.db");
	rc = sqlite3_open("devices.db", &db);
   
	if( rc ) {
		fprintf(stderr, "MakeDeviceTable - Can't open database: %s\n", sqlite3_errmsg(db));
		return;
	}
	/* Create SQL statement */
	sql = "CREATE TABLE DEVICES("  \
		"ID INT PRIMARY KEY		NOT NULL," \
		"NAME      TEXT KEY		NOT NULL);";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	
	sqlite3_close(db);
}

void AppDB::InsertDevice(const std::string &a_name)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("devices.db", &db);
	if(rc) {
		fprintf(stderr, "MakeDeviceTable - Can't open database: %s\n", sqlite3_errmsg(db));
		return;
	}

	size_t ID = m_size + 1;
	std::string quary{"INSERT INTO DEVICES (ID,NAME) VALUES ("};
	quary += std::to_string(ID) + ", '" + a_name + "');";
	const char *chQuary = quary.c_str();

	rc = sqlite3_exec(db, chQuary, callback, 0, &zErrMsg);
	if(rc != SQLITE_OK){
	   fprintf(stderr, "SQL error: %s\n", zErrMsg);
	   sqlite3_free(zErrMsg);
	}
	else {
		++m_size;
	}

	sqlite3_close(db);
}

size_t AppDB::SizeDB() const
{
	return m_size;
}

std::string AppDB::DeviceName(int a_id) const
{
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int rc;

	rc = sqlite3_open("devices.db", &db);
	if(rc) {
		fprintf(stderr, "DeviceName - Can't open database: %s\n", sqlite3_errmsg(db)); //- throw
		return(0);
	}

	std::string quary{"SELECT * from DEVICES where ID = "};
	quary += std::to_string(a_id);
	const char *chQuary = quary.c_str();
	sqlite3_prepare_v2(db, chQuary, -1, &stmt, 0);
	std::string result;
	while (sqlite3_step(stmt) != SQLITE_DONE) {
		result = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
	}

	sqlite3_close(db);
	return result;
}

int AppDB::DeviceID(const std::string &a_name) const
{
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int rc;

	rc = sqlite3_open("../server_app/devices.db", &db);
	if( rc ) {
		fprintf(stderr, "DeviceID - Can't open database: %s\n", sqlite3_errmsg(db)); //- throw
		return(0);
	}

	std::string quary{"SELECT * from DEVICES where NAME = '"};
	quary += a_name + "'";
	const char *chQuary = quary.c_str();
	sqlite3_prepare_v2(db, chQuary, -1, &stmt, 0);
	int result;
	while (sqlite3_step(stmt) != SQLITE_DONE) {
		result = sqlite3_column_int(stmt, 0);
		break;
	}

	sqlite3_close(db);

	return result; 
}

}	//device