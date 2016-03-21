#ifndef SQL_DATABASE_H
#define	SQL_DATABASE_H
#include <iostream>
#include <vector>
#include <qmessagebox.h>
#include "mysql_connection.h"
#include <sqlstring.h>
#include <string>


#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <boost/shared_ptr.hpp>
#include <fstream>
#include <sstream>
#include <QtWidgets/QProgressBar>
#include <QSettings>

const std::string columns[] = { "datum_zapisu", "InTemp", "InHR", "CH1Temp", "CH1HR", "CH2Temp", "CH2HR", "CH3Temp", "CH3HR", "CH4Temp", "CH4HR", "CH5Temp", "CH5HR", "UV", "Baro", "Weather", "Wchill", "Wgust", "Wspeed", "Wdir", "RainCount" };

enum SQL_error{
	SQL_OK = 0,
	SQL_CONNECTION_ERROR,
	SQL_CHECK_COLUMN_ERROR,
	SQL_DELETE_TABLE_ERROR,
	SQL_INSERT_DATA_ERROR,
	SQL_SELECT_ERROR,
	SQL_CHECK_FILE_LINES,
	SQL_READ_INI_FILE_ERROR,
	SQL_WRITE_INI_FILE_ERROR
};

class SQL_settings
{
public:
	SQL_settings();
	~SQL_settings();
	//void set_parameters(std::string host_name, std::string user_name, std::string password, std::string schema, std::string table);
	std::string get_host_name();
	std::string get_user_name();
	std::string get_password();
	std::string get_schema();
	std::string get_table();
	void set_hostname(std::string in_hostname);
	void set_username(std::string in_username);
	void set_password(std::string in_password);
	void set_schema(std::string in_schema);
	void set_table(std::string in_table);
	int read_settings();
	int write_settings();
private:
	QSettings *SQL_set;
	std::string host_name;
	std::string user_name;
	std::string password;
	std::string schema;
	std::string table;
};

class SQL_database
{
public:
	//void set_connection(std::string in_host_name, std::string in_user_name, std::string in_password, std::string in_schema,
	//	std::string in_table);
	//int delete_table(const std::string table);
	int import_file(QString filename, QProgressBar *progress_bar);
	//int get_all_settings();
	int SQL_connect();
	int SQL_disconnect();
	int check_column(std::string column_name, int *count);
	int min_column(std::string column, std::string start_DT, std::string end_DT, float *min);
	int max_column(std::string column, std::string start_DT, std::string end_DT, float* max);
	int avg_column(std::string column, std::string start_DT, std::string end_DT, float* avg);
	int SQL_database::get_double_values(std::string column, std::string start_DT, std::string end_DT, std::vector<double>* values);
	int get_int_values(std::string column, std::string start_DT, std::string end_DT, std::vector<int>* values);
	int get_string_values(std::string column, std::string start_DT, std::string end_DT, std::vector<std::string>* values);
private:
	int add_row( std::vector<std::string> *data);
	int check_row(std::string column, std::string datetime, bool* exists);
	int get_nb_lines(std::string filename, int* nb);

	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep_stmt;
	sql::Statement *stmt;
	sql::ResultSet *res;
};



#endif