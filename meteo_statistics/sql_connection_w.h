#ifndef SQL_CONNECTION_W_H
#define SQL_CONNECTION_W_H

#include <QWidget>
#include "ui_sql_connection_w.h"
#include "global.h"
#include "sql_database.h"

class SQL_connection_w : public QWidget
{
	Q_OBJECT

public:
	SQL_connection_w(QWidget *parent = 0);
	~SQL_connection_w();
	std::string get_hostname();
	std::string get_username();
	std::string get_password();
	std::string get_schema();
	std::string get_table();
	void set_hostname(std::string in_hostname);
	void set_username(std::string in_username);
	void set_password(std::string in_password);
	void set_schema(std::string in_schema);
	void set_table(std::string in_table);

private slots:
	void on_OK_button_clicked();

private:
	Ui::SQL_connection_w *ui;
};

#endif // SQL_CONNECTION_W_H
