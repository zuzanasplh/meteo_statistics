#include "import_data_w.h"

import_data_w::import_data_w(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::import_data_w)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::Window);
	
}

import_data_w::~import_data_w()
{

}


/*
*on_openpath_button_clicked
*call file dialog window to choice file
*/
void import_data_w::on_openpath_button_clicked()
{
	QFileDialog FDialog(this);
	FDialog.setFileMode(QFileDialog::AnyFile);
	FDialog.setNameFilter(tr("Data(*.csv)"));
	if (FDialog.exec()){
		filename = FDialog.selectedFiles().first();
	}
	ui->path_text->setText(filename);
}

/*
*on_importdata_button_clicked
*import data from csv file to SQL database
*/
int import_data_w::on_importdata_button_clicked()
{
	int error;
	ui->progress_import->setVisible(true);
	error = SQL_connect();
	if (error != SQL_OK)
		return error;
	error = import_file(ui->path_text->toPlainText(), ui->progress_import);
	if (error != SQL_OK)
		return error;
	error = SQL_disconnect();
	if (error != SQL_OK)
		return error;
	return SQL_OK;
}
