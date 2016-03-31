#include "sql_connection_w.h"

/*
 *SQL connectio w
 *constructor
 */
SQL_connection_w::SQL_connection_w(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::SQL_connection_w)
{
	ui->setupUi(this);
}

/*
 *SQL connection w
 *destructor
 */
SQL_connection_w::~SQL_connection_w()
{

}

/*
 *Gets hostname
 *obtains hostname from window
 */
std::string SQL_connection_w::get_hostname()
{
	return ui->host_name_line->text().toLocal8Bit().constData();
}

/*
 *Gets username
 *obtains username from window
 */
std::string SQL_connection_w::get_username()
{
	return ui->user_name_line->text().toLocal8Bit().constData();
}

/*
 *Gets password
 *obtains password from window
 */
std::string SQL_connection_w::get_password()
{
	return ui->password_line->text().toLocal8Bit().constData();
}

/*
 *Gets schema
 *obtains schema from window
 */
std::string SQL_connection_w::get_schema()
{
	return ui->schema_line->text().toLocal8Bit().constData();
}

/*
 *Gets table
 *obtains table from window
 */
std::string SQL_connection_w::get_table()
{
	return ui->table_line->text().toLocal8Bit().constData();
}

/*
 *Sets hostname
 *sets hostname from global variable
 */
void SQL_connection_w::set_hostname(std::string in_hostname)
{
	if (!in_hostname.empty())
		ui->host_name_line->setText(in_hostname.c_str());
	else
		return;
}

/*
 *Sets username
 *sets username from global variable
 */
void SQL_connection_w::set_username(std::string in_username)
{
	if (!in_username.empty())
		ui->user_name_line->setText(in_username.c_str());
	else
		return;
}

/*
 *Sets password
 *sets password from global variable
 */
void SQL_connection_w::set_password(std::string in_password)
{
	if (!in_password.empty())
		ui->password_line->setText(in_password.c_str());
	else
		return;
}

/*
 *Sets schema
 *sets schema from global variable
 */
void SQL_connection_w::set_schema(std::string in_schema)
{
	if (!in_schema.empty())
		ui->schema_line->setText(in_schema.c_str());
	else
		return;
}

/*
 *Sets table
 *Sets table form ini file
 */
void SQL_connection_w::set_table(std::string in_table)
{
	if (!in_table.empty())
		ui->table_line->setText(in_table.c_str());
	else
		return;
}

/*
 *On OK button clicked
 *reads settings from lines and write into global variable and write into ini file
 */
void SQL_connection_w::on_OK_button_clicked()
{
	int error;
	my_settings.set_hostname(ui->host_name_line->text().toLocal8Bit().constData());
	my_settings.set_username(ui->user_name_line->text().toLocal8Bit().constData());
	my_settings.set_password(ui->password_line->text().toLocal8Bit().constData());
	my_settings.set_schema(ui->schema_line->text().toLocal8Bit().constData());
	my_settings.set_table(ui->table_line->text().toLocal8Bit().constData());
	error = my_settings.write_settings();
}

