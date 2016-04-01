#include "sql_database.h"
#include "global.h"

/*
 *SQL settings
 *constructor
 *create QSettings varible, set the ini file name and path
 */
SQL_settings::SQL_settings()
{
	SQL_set = new QSettings("SQL_settings.ini", QSettings::IniFormat);
}

/*
 *SQL settings
 *destructor
 */
SQL_settings::~SQL_settings()
{
	delete SQL_set;
	SQL_set = NULL;
}

/*
 *Gets host name
 *returns hostname from global variable
 */
std::string SQL_settings::get_host_name()
{
	return host_name;
}

/*
 *Get user name
 *return user name from global variable
 */
std::string SQL_settings::get_user_name()
{
	return user_name;
}

/*
 *Get password
 *return password from global variable
 */
std::string SQL_settings::get_password()
{
	return password;
}

/*
 *Get schema
 *return schema from global variable
 */
std::string SQL_settings::get_schema()
{
	return schema;
}

/*
 *Get table
 *return table from global variable
 */
std::string SQL_settings::get_table()
{
	return table;
}

/*
 *Set hostname
 *set hostname into global variable
 */
void SQL_settings::set_hostname(std::string in_hostname)
{
	host_name.clear();
	host_name.append(in_hostname);
}

/*
 *Set username
 *set username into global variable
 */
void SQL_settings::set_username(std::string in_username)
{
	user_name.clear();
	user_name.append(in_username);
}

/*
 *Set password
 *set password into global variable
 */
void SQL_settings::set_password(std::string in_password)
{
	password.clear();
	password.append(in_password);
}

/*
 *Set schema
 *set schema into global variable
 */
void SQL_settings::set_schema(std::string in_schema)
{
	schema.clear();
	schema.append(in_schema);
}

/*
 *Set table
 *set table into global variable
 */
void SQL_settings::set_table(std::string in_table)
{
	table.clear();
	table.append(in_table);
}

/*
 *Read settings
 *read settings from ini file
 */
int SQL_settings::read_settings()
{
	host_name.clear();
	user_name.clear();
	password.clear();
	schema.clear();
	table.clear();

	SQL_set->beginGroup("SQL_settings");

	if (SQL_set->contains("host_name") == true)
		host_name.append(SQL_set->value("host_name").toString().toStdString());
	else
		return SQL_READ_INI_FILE_ERROR;

	if (SQL_set->contains("user_name") == true)
		user_name.append(SQL_set->value("user_name").toString().toStdString());
	else
		return SQL_READ_INI_FILE_ERROR;

	if (SQL_set->contains("password") == true)
		password.append(SQL_set->value("password").toString().toStdString());
	else
		return SQL_READ_INI_FILE_ERROR;

	if (SQL_set->contains("schema") == true)
		schema.append(SQL_set->value("schema").toString().toStdString());
	else
		return SQL_READ_INI_FILE_ERROR;

	if (SQL_set->contains("table") == true)
		table.append(SQL_set->value("table").toString().toStdString());
	else
		return SQL_READ_INI_FILE_ERROR;

	SQL_set->endGroup();
	return SQL_OK;
}

/*
 *Write settings
 *write settings into ini file
 */
int SQL_settings::write_settings()
{
	SQL_set->beginGroup("SQL_settings");

	if (SQL_set->contains("host_name") == true){
		SQL_set->setValue("host_name", host_name.c_str());
	}
	else
		return SQL_WRITE_INI_FILE_ERROR;

	if (SQL_set->contains("user_name") == true){
		SQL_set->setValue("user_name", user_name.c_str());
	}
	else
		return SQL_WRITE_INI_FILE_ERROR;

	if (SQL_set->contains("password") == true){
		SQL_set->setValue("password", password.c_str());
	}
	else
		return SQL_WRITE_INI_FILE_ERROR;

	if (SQL_set->contains("schema") == true){
		SQL_set->setValue("schema", schema.c_str());
	}
	else
		return SQL_WRITE_INI_FILE_ERROR;

	if (SQL_set->contains("table") == true){
		SQL_set->setValue("table", table.c_str());
	}
	else
		return SQL_WRITE_INI_FILE_ERROR;
}

/*
 *SQL connect
 *connect to sql database
 */
int SQL_database::SQL_connect()
{
	try{
		driver = get_driver_instance();
		con = driver->connect(my_settings.get_host_name().c_str(), my_settings.get_user_name().c_str(), 
			my_settings.get_password().c_str());
		con->setSchema(my_settings.get_schema().c_str());
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL connection error");
		message.exec();
		return SQL_CONNECTION_ERROR;
	}
	return SQL_OK;
}

/*
 *SQL disconnect
 *disconnect from SQL database
 */
int SQL_database::SQL_disconnect()
{
	try
	{
		con->close();
		this->driver->threadEnd();
	}
	catch (sql::SQLException &e)
	{
		QMessageBox message;
		message.setText("SQL close connection error");
		message.exec();
		return SQL_CONNECTION_ERROR;
	}
	return SQL_OK;
}

/*
 *Import file
 *open csv file, read by lines and insert new data into SQL database
 */
int SQL_database::import_file(QString filename, QProgressBar* progress_bar)
{
	std::string line, delimiter = ",", partstr;
	int i, nb_lines, actline, error;
	size_t pos = 0;
	std::vector<std::string> data(50);

	try{
		prep_stmt = con->prepareStatement("INSERT INTO meteo(datum_zapisu, InTemp, InHR, CH1Temp, CH1HR, CH2Temp, CH2HR, CH3Temp, CH3HR, CH4Temp, CH4HR, CH5Temp, CH5HR, UV, Baro, Weather, Wchill, Wgust, Wspeed, Wdir, RainCount)"
			"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL insert data error");
		message.exec();
		return SQL_INSERT_DATA_ERROR;
	}

	error = get_nb_lines(filename.toStdString(), &nb_lines);
	if (error != SQL_OK)
		return error;
	std::ifstream fin(filename.toStdString());

	progress_bar->setMaximum(nb_lines);
	progress_bar->setValue(0);
	actline = 0;

	getline(fin, line);
	actline++;
	while (getline(fin, line)){
		i = 0;
		actline++;
		while ((pos = line.find(delimiter)) != std::string::npos){
			partstr.erase();
			partstr.append(line.substr(0, pos));
			data[i].append(partstr.c_str());
			line.erase(0, pos + delimiter.length());
			i++;
		}
		if (add_row(&data) == SQL_OK)
		{
			progress_bar->setValue(actline);
			for (i = 0; i < 50; i++)
				data[i].erase();
		}
		else
			return SQL_INSERT_DATA_ERROR;
	}
	return SQL_OK;
}

/*
 *Add row
 *read line from csv file is compare with SQL data, if these data are new than are inserted into SQL database
 */
int SQL_database::add_row(std::vector<std::string>* data)
{
	sql::SQLString sqldatetime;
	int i, error;
	bool row_exists;
	std::vector<std::string> mdata;
	mdata = *data;
	std::string datetime;
	//sqldatetime = NULL;

	try{
		datetime.clear();
		datetime.append((mdata)[0]);
		datetime.append("-");
		datetime.append((mdata)[2]);
		datetime.append("-");
		datetime.append((mdata)[3]);
		datetime.append(" ");
		datetime.append((mdata)[4]);
		datetime.append(":");
		datetime.append((mdata)[5]);
		datetime.append(":");
		datetime.append("00");
		sqldatetime.append(datetime.c_str());

		error = check_row("datum_zapisu", datetime, &row_exists);
		if (error == SQL_SELECT_ERROR)
			return SQL_SELECT_ERROR;
		if (!row_exists){
			prep_stmt->setDateTime(1, sqldatetime);
			for (i = 6; i < 26; i++){
				if (i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 18 || i == 20 || i == 24)
				{
					if ((mdata)[i].empty()){
						prep_stmt->setNull(i - 4, sql::DataType::TINYINT);
					}
					else{
						prep_stmt->setInt(i - 4, stoi((mdata)[i]));
					}
				}
				else{
					if ((mdata)[i].empty()){
						prep_stmt->setNull(i - 4, sql::DataType::DOUBLE);
					}
					else{
						prep_stmt->setDouble(i - 4, stof((mdata)[i]));
					}
				}
			}
			prep_stmt->execute();
		}
		else
			return SQL_OK;
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL insert data error");
		message.exec();
		return SQL_INSERT_DATA_ERROR;
	}
	return SQL_OK;
}

/*
 *Check column
 *check if the column is exists in SQL database
 */
int SQL_database::check_column(std::string column_name, int* count)
{
	sql::SQLString sql_query;
	try{
		sql_query.append("SELECT COUNT(");
		sql_query.append(column_name.c_str());
		sql_query.append(") FROM ");
		sql_query.append(my_settings.get_table().c_str());
		sql_query.append(";");
		stmt = con->createStatement();
		res = stmt->executeQuery(sql_query);
		while (res->next()){
			*count = res->getInt(1);
		}
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL check_column error");
		message.exec();
		return SQL_CHECK_COLUMN_ERROR;
	}
	return SQL_OK;
}

/*
 *Min column
 *obtain the minimum value from the selected column from SQL database
 */
int SQL_database::min_column(std::string column, std::string start_DT, std::string end_DT, float* min){
	std::string query;
	sql::SQLString sql_query;
	try{
		sql_query.append("SELECT MIN(");
		sql_query.append(column.c_str());
		sql_query.append(") FROM ");
		sql_query.append(my_settings.get_table().c_str());
		sql_query.append(" WHERE datum_zapisu BETWEEN \"");
		sql_query.append(start_DT.c_str());
		sql_query.append("\" AND \"");
		sql_query.append(end_DT.c_str());
		sql_query.append("\";");

		stmt = con->createStatement();
		res = stmt->executeQuery(sql_query);
		while (res->next()){
			*min = res->getDouble(1);
		}
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL select error");
		message.exec();
		return SQL_SELECT_ERROR;
	}
	return SQL_OK;
}

/*
 *Max column
 *obtain the maximum from the selected column from SQL database
 */
int SQL_database::max_column(std::string column, std::string start_DT, std::string end_DT, float* max){
	std::string query;
	sql::SQLString sql_query;
	try{
		sql_query.append("SELECT MAX(");
		sql_query.append(column.c_str());
		sql_query.append(") FROM ");
		sql_query.append(my_settings.get_table().c_str());
		sql_query.append(" WHERE datum_zapisu BETWEEN \"");
		sql_query.append(start_DT.c_str());
		sql_query.append("\" AND \"");
		sql_query.append(end_DT.c_str());
		sql_query.append("\";");

		stmt = con->createStatement();
		res = stmt->executeQuery(sql_query);
		while (res->next()){
			*max = res->getDouble(1);
		}
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL select error");
		message.exec();
		return SQL_SELECT_ERROR;
	}
	return SQL_OK;
}

/*
 *Avg column
 *obtain average value from the selected column from SQL database
 */
int SQL_database::avg_column(std::string column, std::string start_DT, std::string end_DT, float* avg){
	std::string query;
	sql::SQLString sql_query;
	try{
		sql_query.append("SELECT AVG(");
		sql_query.append(column.c_str());
		sql_query.append(") FROM ");
		sql_query.append(my_settings.get_table().c_str());
		sql_query.append(" WHERE datum_zapisu BETWEEN \"");
		sql_query.append(start_DT.c_str());
		sql_query.append("\" AND \"");
		sql_query.append(end_DT.c_str());
		sql_query.append("\";");

		stmt = con->createStatement();
		res = stmt->executeQuery(sql_query);
		while (res->next()){
			*avg = res->getDouble(1);
		}
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL select error");
		message.exec();
		return SQL_SELECT_ERROR;
	}
	return SQL_OK;
}

/*
 *Get double values
 *obtain double values from selected column, selected datetime range from SQL database
 */
int SQL_database::get_double_values(std::string column, std::string start_DT, std::string end_DT, std::vector<double>* values)
{
	std::string query;
	sql::SQLString sql_query;
	try{
		sql_query.append("SELECT ");
		sql_query.append(column.c_str());
		sql_query.append(" FROM ");
		sql_query.append(my_settings.get_table().c_str());
		sql_query.append(" WHERE datum_zapisu BETWEEN \"");
		sql_query.append(start_DT.c_str());
		sql_query.append("\" AND \"");
		sql_query.append(end_DT.c_str());
		sql_query.append("\";");

		stmt = con->createStatement();
		res = stmt->executeQuery(sql_query);
		while (res->next()){
			if (res->isNull(1)){
				values->push_back(-10000);
			}
			else{
				values->push_back(res->getDouble(1));
			}
		}

	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL select error");
		message.exec();
		return SQL_SELECT_ERROR;
	}
	return SQL_OK;
}

/*
 *Get int values
 *obtain int values from selected column, selected datetime range from SQL database 
 */
int SQL_database::get_int_values(std::string column, std::string start_DT, std::string end_DT, std::vector<int>* values)
{

	std::string query;
	sql::SQLString sql_query;
	try{
		sql_query.append("SELECT ");
		sql_query.append(column.c_str());
		sql_query.append(" FROM ");
		sql_query.append(my_settings.get_table().c_str());
		sql_query.append(" WHERE datum_zapisu BETWEEN \"");
		sql_query.append(start_DT.c_str());
		sql_query.append("\" AND \"");
		sql_query.append(end_DT.c_str());
		sql_query.append("\";");

		stmt = con->createStatement();
		res = stmt->executeQuery(sql_query);
		while (res->next()){
			if (res->isNull(1)){
				values->push_back(-10000);
			}
			else{
				values->push_back(res->getInt(1));
			}
		}
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL select error");
		message.exec();
		return SQL_SELECT_ERROR;
	}
	return SQL_OK;
}

/*
 *Get string values
 *obtain string values from selected column, selected datetime range from SQL database
 */
int SQL_database::get_string_values(std::string column, std::string start_DT, std::string end_DT, std::vector<std::string>* values)
{
	std::string query;
	sql::SQLString sql_query;

	try{
		sql_query.append("SELECT ");
		sql_query.append(column.c_str());
		sql_query.append(" FROM ");
		sql_query.append(my_settings.get_table().c_str());
		sql_query.append(" WHERE datum_zapisu BETWEEN \"");
		sql_query.append(start_DT.c_str());
		sql_query.append("\" AND \"");
		sql_query.append(end_DT.c_str());
		sql_query.append("\";");

		stmt = con->createStatement();
		res = stmt->executeQuery(sql_query);
		while (res->next()){
			values->push_back(res->getString(1).c_str());
		}
	}

	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL select error");
		message.exec();
		return SQL_SELECT_ERROR;
	}
	return SQL_OK;
}

/*
 *Check row
 *check if the data are exists in SQL database, to avoid duplicate datas
 */
int SQL_database::check_row(std::string column, std::string datetime, bool* exists)
{
	int result;
	*exists = false;
	std::string str_query;
	str_query.clear();
	sql::SQLString sql_query;
	try{
		sql_query.append("SELECT EXISTS(SELECT * FROM ");
		sql_query.append(my_settings.get_table().c_str());
		sql_query.append(" WHERE ");
		sql_query.append(column.c_str());
		sql_query.append(" = \"");
		sql_query.append(datetime.c_str());
		sql_query.append("\");");

		//SELECT EXISTS(SELECT * FROM meteo WHERE datum_zapisu = "2015-06-27 04:48:00");

		stmt = con->createStatement();
		res = stmt->executeQuery(sql_query);
		while (res->next()){
			result = res->getInt(1);
		}
		if (result == 1){
			*exists = true;
		}
		else{
			*exists = false;
		}
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL select error");
		message.exec();
		return SQL_SELECT_ERROR;
	}
	return SQL_OK;
}

/*Get nb lines
 *obtain how many lines contains the specified file
 */
int SQL_database::get_nb_lines(std::string filename, int* nb)
{
	char c;
	int i;

	try{
		*nb = 0;
		i = 0;
		std::ifstream fin(filename);
		while (fin.get(c)){
			if (c == '\n')
				++i;
		}
		fin.close();
		*nb = i;
	}
	catch (sql::SQLException &e){
		QMessageBox message;
		message.setText("SQL check file lines error");
		message.exec();
		return SQL_CHECK_FILE_LINES;
	}
	return SQL_OK;
}
