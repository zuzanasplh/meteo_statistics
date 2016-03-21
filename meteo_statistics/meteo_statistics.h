#ifndef meteo_statistics_H
#define meteo_statistics_H

#include <QtWidgets/QMainWindow>
#include "ui_meteo_statistics.h"
#include "sql_database.h"
#include "meteo_graph.h"
#include "qcustomplot.h"
#include "global.h"
#include "import_data_w.h"
#include "sql_connection_w.h"

#include <qmessagebox.h>
#include <qdatetime.h>
#include <vector>
#include <string>



class meteo_statistics : public QMainWindow
{
	Q_OBJECT

public:
	meteo_statistics(QWidget *parent = 0);
	~meteo_statistics();
	int check_meas_units();
	int read_settings();

	public slots:
	int calculate_statistics();

	private slots:
	int on_unit_combo_currentIndexChanged();
	void import_data();
	void SQL_set_connection();

private:
	int obtain_datetime();
	int draw_graph();
	void checkboxes();
	QVector<double> time_to_double();
	QVector<double> data_correction(std::string, std::vector<double>);
	Ui::meteo_statisticsClass *ui;
	meteo_graph my_graphs;
	import_data_w import_window;
	SQL_connection_w sql_connection_window;
	SQL_database my_meteo_database;
	std::vector<std::string> datetime;
	std::string str_startDT, str_endDT;
	QCPAxisRect *wideAxisRect;
	bool units[21];
};



#endif // meteo_statistics_H
