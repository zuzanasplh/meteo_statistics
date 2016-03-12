#ifndef meteo_statistics_H
#define meteo_statistics_H

#include <QtWidgets/QMainWindow>
#include "ui_meteo_statistics.h"
#include "sql_database.h"
#include "meteo_graph.h"
#include "qcustomplot.h"
#include "global.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qdatetime.h>
#include <vector>
#include <string>

const std::string host_name = "tcp://127.0.0.1:3306";
const std::string user_name = "SQL_francescoh";
const std::string password = "elixir";
const std::string schema = "test";
const std::string table = "meteo";

class meteo_statistics : public QMainWindow
{
	Q_OBJECT

public:
	meteo_statistics(QWidget *parent = 0);
	~meteo_statistics();
	int check_meas_units();
	public slots:
	int calculate_statistics();
	private slots:
	void on_openpath_button_clicked();
	int on_importdata_button_clicked();
	int on_unit_combo_currentIndexChanged();

private:
	int obtain_datetime();
	int draw_graph();
	void checkboxes();
	QVector<double> time_to_double();
	QVector<double> data_correction(std::string, std::vector<double>);
	Ui::meteo_statisticsClass *ui;
	meteo_graph my_graphs;
	QString filename;
	SQL_database my_meteo_database;
	std::vector<std::string> datetime;
	std::string str_startDT, str_endDT;
	QCPAxisRect *wideAxisRect;
	bool units[21];
};



#endif // meteo_statistics_H
