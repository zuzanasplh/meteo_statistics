#ifndef IMPORT_DATA_W_H
#define IMPORT_DATA_W_H

#include <QWidget>
#include "ui_import_data_w.h"
#include "global.h"
#include "sql_database.h"
#include <qfiledialog.h>

class import_data_w : public QWidget, SQL_database
{
	Q_OBJECT

public:
	import_data_w(QWidget *parent = 0);
	~import_data_w();

private slots:
	void on_openpath_button_clicked();
	int on_importdata_button_clicked();

private:
	Ui::import_data_w *ui;
	QString filename;

};

#endif // IMPORT_DATA_W_H
