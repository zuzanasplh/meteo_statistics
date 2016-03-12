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


const std::string columns[] = { "datum_zapisu", "InTemp", "InHR", "CH1Temp", "CH1HR", "CH2Temp", "CH2HR", "CH3Temp", "CH3HR", "CH4Temp", "CH4HR", "CH5Temp", "CH5HR", "UV", "Baro", "Weather", "Wchill", "Wgust", "Wspeed", "Wdir", "RainCount" };

enum SQL_error{
	SQL_OK = 0,
	SQL_CONNECTION_ERROR,
	SQL_CHECK_COLUMN_ERROR,
	SQL_DELETE_TABLE_ERROR,
	SQL_INSERT_DATA_ERROR,
	SQL_SELECT_ERROR,
	SQL_CHECK_FILE_LINES
};

class SQL_database
{
public:
	int delete_table(const std::string table);
	int import_file(QString filename, std::string table, QProgressBar *progress_bar);
	int SQL_connect(std::string host_name, std::string user_name, std::string password, std::string schema);
	int SQL_disconnect(void);
	int check_column(std::string column_name, std::string table, int *count);
	int min_column(std::string column, std::string start_DT, std::string end_DT, std::string table, float *min);
	int max_column(std::string column, std::string start_DT, std::string end_DT, std::string table, float* max);
	int avg_column(std::string column, std::string start_DT, std::string end_DT, std::string table, float* avg);
	int SQL_database::get_double_values(std::string column, std::string start_DT, std::string end_DT, std::string table, std::vector<double>* values);
	int get_int_values(std::string column, std::string start_DT, std::string end_DT, std::string table, std::vector<int>* values);
	int get_string_values(std::string column, std::string start_DT, std::string end_DT, std::string table, std::vector<std::string>* values);
private:
	int add_row(std::string table, std::vector<std::string> *data);
	int check_row(std::string table, std::string column, std::string datetime, bool* exists);
	int get_nb_lines(std::string filename, int* nb);
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep_stmt;
	sql::Statement *stmt;
	sql::ResultSet *res;
};



#endif