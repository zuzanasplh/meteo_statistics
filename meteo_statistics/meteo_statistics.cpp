#include "meteo_statistics.h"
#include "ui_meteo_statistics.h"

SQL_settings my_settings;
/*
 *meteo_statistics constructor
 *create all graph, link signals with functions
 */
meteo_statistics::meteo_statistics(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::meteo_statisticsClass)
{
	ui->setupUi(this);
	my_graphs.create_graph(ui);
	wideAxisRect = new QCPAxisRect(ui->customplot);
	connect(ui->unit_combo, static_cast<void (QComboBox::*)(const QString &)>(&(QComboBox::currentTextChanged)), this, &meteo_statistics::calculate_statistics);
	connect(ui->dateTime_start, &QDateTimeEdit::dateTimeChanged, this, &meteo_statistics::obtain_datetime);
	connect(ui->dateTime_end, &QDateTimeEdit::dateTimeChanged, this, &meteo_statistics::obtain_datetime);
	connect(ui->dateTime_start, &QDateTimeEdit::dateTimeChanged, this, &meteo_statistics::draw_graph);
	connect(ui->dateTime_end, &QDateTimeEdit::dateTimeChanged, this, &meteo_statistics::draw_graph);
	connect(ui->check_InTemp, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_InHR, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH1Temp, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH1HR, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH2Temp, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH2HR, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH3Temp, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH3HR, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH4Temp, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH4HR, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH5Temp, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_CH5HR, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_UV, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_Baro, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_Weather, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_Wchill, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_Wgust, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_Wspeed, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_Wdir, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->check_RainCount, &QCheckBox::clicked, this, &meteo_statistics::draw_graph);
	connect(ui->import_data_act, &QAction::triggered, this, &meteo_statistics::import_data);
	connect(ui->SQL_con_act, &QAction::triggered, this, &meteo_statistics::SQL_set_connection);
	
}

/*
 *meteo_statistics destructor
 */
meteo_statistics::~meteo_statistics()
{
	delete wideAxisRect;
	delete ui;
}


void meteo_statistics::import_data()
{
	import_window.show();
}

void meteo_statistics::SQL_set_connection()
{
	sql_connection_window.set_hostname(my_settings.get_host_name());
	sql_connection_window.set_username(my_settings.get_user_name());
	sql_connection_window.set_password(my_settings.get_password());
	sql_connection_window.set_schema(my_settings.get_schema());
	sql_connection_window.set_table(my_settings.get_table());

	sql_connection_window.show();
}
/*
 *on_unit_combo_currentIndexChanged
 *call this function when user select measured unit
 *obtain data from SQL database and calculete basic statistics
 */
int meteo_statistics::on_unit_combo_currentIndexChanged()
{
	int error;
	error = calculate_statistics();
	if (error != SQL_OK)
		return error;
	else
		return SQL_OK;
}

/*
 *Obtain datetime
 *obtain datetime values from SQL database which are between the range
 */
int meteo_statistics::obtain_datetime()
{
	int error;
	QDateTime qt_datetime;
	QString qstr_datetime;

	qt_datetime = ui->dateTime_start->dateTime();
	qstr_datetime = qt_datetime.toString("yyyy-MM-dd hh:mm:ss");
	str_startDT = qstr_datetime.toLocal8Bit().constData();

	qt_datetime = ui->dateTime_end->dateTime();
	qstr_datetime = qt_datetime.toString("yyyy-MM-dd hh:mm:ss");
	str_endDT = qstr_datetime.toLocal8Bit().constData();
	my_meteo_database.SQL_connect();
	error = my_meteo_database.get_string_values("datum_zapisu", str_startDT, str_endDT, &datetime);
	if (error != SQL_OK)
		return error;
	error = my_meteo_database.SQL_disconnect();
	if (error != SQL_OK)
		return error;
	error = calculate_statistics();
	if (error != SQL_OK)
		return error;
}

/*
 *Check boxes
 *check which boxes - units are checked
 */
void meteo_statistics::checkboxes()
{
	if (ui->check_InTemp->isChecked())
		units[InTemp] = true;
	else
		units[InTemp] = false;

	if (ui->check_CH1Temp->isChecked())
		units[CH1Temp] = true;
	else
		units[CH1Temp] = false;

	if (ui->check_CH2Temp->isChecked())
		units[CH2Temp] = true;
	else
		units[CH2Temp] = false;

	if (ui->check_CH3Temp->isChecked())
		units[CH3Temp] = true;
	else
		units[CH3Temp] = false;

	if (ui->check_CH4Temp->isChecked())
		units[CH4Temp] = true;
	else
		units[CH4Temp] = false;

	if (ui->check_CH5Temp->isChecked())
		units[CH5Temp] = true;
	else
		units[CH5Temp] = false;

	if (ui->check_InHR->isChecked())
		units[InHR] = true;
	else
		units[InHR] = false;

	if (ui->check_CH1HR->isChecked())
		units[CH1HR] = true;
	else
		units[CH1HR] = false;

	if (ui->check_CH2HR->isChecked())
		units[CH2HR] = true;
	else
		units[CH2HR] = false;

	if (ui->check_CH3HR->isChecked())
		units[CH3HR] = true;
	else
		units[CH3HR] = false;

	if (ui->check_CH4HR->isChecked())
		units[CH4HR] = true;
	else
		units[CH4HR] = false;

	if (ui->check_CH5HR->isChecked())
		units[CH5HR] = true;
	else
		units[CH5HR] = false;

	if (ui->check_UV->isChecked())
		units[UV] = true;
	else
		units[UV] = false;

	if (ui->check_Baro->isChecked())
		units[Baro] = true;
	else
		units[Baro] = false;

	if (ui->check_Weather->isChecked())
		units[Weather] = true;
	else
		units[Weather] = false;

	if (ui->check_RainCount->isChecked())
		units[RainCount] = true;
	else
		units[RainCount] = false;

	if (ui->check_Wchill->isChecked())
		units[Wchill] = true;
	else
		units[Wchill] = false;

	if (ui->check_Wgust->isChecked())
		units[Wgust] = true;
	else
		units[Wgust] = false;

	if (ui->check_Wspeed->isChecked())
		units[Wspeed] = true;
	else
		units[Wspeed] = false;

	if (ui->check_Wdir->isChecked())
		units[Wdir] = true;
	else
		units[Wdir] = false;


}

/*
 *Draw graph
 *Based on checked boxes and selected datetime range the function
 *obtain data from SQL database and draw this data to graph
 */
int meteo_statistics::draw_graph()
{
	int i, j, error;
	double a, b;
	QVector<double> date, meas_values;
	std::vector<double> data_temp;

	checkboxes();
	date = time_to_double();

	for (i = 0; i < 21; i++){
		data_temp.clear();
		meas_values.clear();

		if (units[i]){
			unit_to_string((unit)i);
			error = my_meteo_database.SQL_connect();
			if (error != SQL_OK)
				return error;
			error = my_meteo_database.get_double_values(unit_to_string((unit)i), str_startDT, str_endDT, &data_temp);
			if (error != SQL_OK)
				return error;
			error = my_meteo_database.SQL_disconnect();
			if (error != SQL_OK)
				return error;
			meas_values = data_correction(unit_to_string((unit)i), data_temp);
			my_graphs.draw_graph(i, date, meas_values);
			ui->customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
		}
		else{
			my_graphs.hide_graph(i);
		}
	}
	ui->customplot->replot();	
	return SQL_OK;
}

/*
 *Check meas units
 *Check which measured units are accessible from SQL database
 */
int meteo_statistics::check_meas_units()
{
	QMessageBox message;
	QString count_str;
	int count, i, error;
	ui->unit_combo->blockSignals(true);
	ui->dateTime_start->blockSignals(true);
	ui->dateTime_end->blockSignals(true);
	ui->dateTime_end->setDateTime(QDateTime::currentDateTime());
	ui->dateTime_start->setDateTime(QDateTime::currentDateTime());
	error = my_meteo_database.SQL_connect();
	if (error != SQL_OK)
		return error;
	
	error = my_meteo_database.check_column("InTemp", &count);
	if (error != SQL_OK)
		return error;

	count_str.setNum(count);
	if (count > 0){
		ui->check_InTemp->setEnabled(true);
		ui->unit_combo->addItem("InTemp");
	}
	else{
		ui->check_InTemp->setDisabled(true);
	}

	error = my_meteo_database.check_column("InHR", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_InHR->setEnabled(true);
		ui->unit_combo->addItem("InHR");
	}
	else{
		ui->check_InHR->setDisabled(true);
	}

	error =my_meteo_database.check_column("CH1Temp", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH1Temp->setEnabled(true);
		ui->unit_combo->addItem("CH1Temp");
	}
	else{
		ui->check_CH1Temp->setDisabled(true);
	}

	error =my_meteo_database.check_column("CH1HR", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH1HR->setEnabled(true);
		ui->unit_combo->addItem("CH1HR");
	}
	else{
		ui->check_CH1HR->setDisabled(true);
	}

	error =my_meteo_database.check_column("CH2Temp", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH2Temp->setEnabled(true);
		ui->unit_combo->addItem("CH2Temp");
	}
	else{
		ui->check_CH2Temp->setDisabled(true);
	}

	error =my_meteo_database.check_column("CH2HR", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH2HR->setEnabled(true);
		ui->unit_combo->addItem("CH2HR");
	}
	else{
		ui->check_CH2HR->setDisabled(true);
	}

	error = my_meteo_database.check_column("CH3Temp", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH3Temp->setEnabled(true);
		ui->unit_combo->addItem("CH3Temp");
	}
	else{
		ui->check_CH3Temp->setDisabled(true);
	}

	error = my_meteo_database.check_column("CH3HR", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH3HR->setEnabled(true);
		ui->unit_combo->addItem("CH3HR");
	}
	else{
		ui->check_CH3HR->setDisabled(true);
	}

	error = my_meteo_database.check_column("CH4Temp" ,&count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH4Temp->setEnabled(true);
		ui->unit_combo->addItem("CH4Temp");
	}
	else{
		ui->check_CH4Temp->setDisabled(true);
	}

	error = my_meteo_database.check_column("CH4HR", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH4HR->setEnabled(true);
		ui->unit_combo->addItem("CH4HR");
	}
	else{
		ui->check_CH4HR->setDisabled(true);
	}

	error = my_meteo_database.check_column("CH5Temp", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH5Temp->setEnabled(true);
		ui->unit_combo->addItem("CH5Temp");
	}
	else{
		ui->check_CH5Temp->setDisabled(true);
	}

	error = my_meteo_database.check_column("CH5HR", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_CH5HR->setEnabled(true);
		ui->unit_combo->addItem("CH5HR");
	}
	else{
		ui->check_CH5HR->setDisabled(true);
	}

	error = my_meteo_database.check_column("UV", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_UV->setEnabled(true);
		ui->unit_combo->addItem("UV");
	}
	else{
		ui->check_UV->setDisabled(true);
	}

	error = my_meteo_database.check_column("Baro", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_Baro->setEnabled(true);
		ui->unit_combo->addItem("Baro");
	}
	else{
		ui->check_Baro->setDisabled(true);
	}

	error = my_meteo_database.check_column("Weather", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_Weather->setEnabled(true);
	}
	else{
		ui->check_Weather->setDisabled(true);
	}

	error = my_meteo_database.check_column("Wchill", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_Wchill->setEnabled(true);
		ui->unit_combo->addItem("Wchill");
	}
	else{
		ui->check_Wchill->setDisabled(true);
	}

	error = my_meteo_database.check_column("Wgust", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_Wgust->setEnabled(true);
		ui->unit_combo->addItem("Wgust");
	}
	else{
		ui->check_Wgust->setDisabled(true);
	}

	error = my_meteo_database.check_column("Wspeed", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_Wspeed->setEnabled(true);
		ui->unit_combo->addItem("Wspeed");
	}
	else{
		ui->check_Wspeed->setDisabled(true);
	}

	error = my_meteo_database.check_column("Wdir", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_Wdir->setEnabled(true);
		ui->unit_combo->addItem("Wdir");
	}
	else{
		ui->check_Wdir->setDisabled(true);
	}

	error = my_meteo_database.check_column("RainCount", &count);
	if (error != SQL_OK)
		return error;
	count_str.setNum(count);
	if (count > 0){
		ui->check_RainCount->setEnabled(true);
		ui->unit_combo->addItem("RainCount");
	}
	else{
		ui->check_RainCount->setDisabled(true);
	}

	error = my_meteo_database.SQL_disconnect();
	if (error != SQL_OK)
		return error;
	ui->unit_combo->blockSignals(false);
	ui->dateTime_start->blockSignals(false);
	ui->dateTime_end->blockSignals(false);
	ui->unit_combo->setCurrentIndex(0);
	return SQL_OK;
}

int meteo_statistics::read_settings()
{
	int error;
	error = my_settings.read_settings();
	if (error != 0){
		QMessageBox message;
		message.setText("error read ini file");
		message.exec();
		return error;
	}
	return error;
}


/*
 *Calculate statistics
 *calculate basic statistics on choosed measuring unit
 *calculate mininum, maximum, average values
 */
int meteo_statistics::calculate_statistics()
{
	QString text, q_min, q_max, q_avg;
	std::string unit;
	float min, max, avg;
	int error; 

	text = ui->unit_combo->currentText();
	unit = text.toLocal8Bit().constData();
	if (!unit.empty()){
		error = my_meteo_database.SQL_connect();
		if (error != SQL_OK)
			return error;
		error = my_meteo_database.min_column(unit, str_startDT, str_endDT, &min);
		if (error != SQL_OK)
			return error;
		error = my_meteo_database.max_column(unit, str_startDT, str_endDT, &max);
		if (error != SQL_OK)
			return error;
		error = my_meteo_database.avg_column(unit, str_startDT, str_endDT, &avg);
		if (error != SQL_OK)
			return error;
		error = my_meteo_database.SQL_disconnect();
		q_min.setNum(min);
		q_max.setNum(max);
		q_avg.setNum(avg);
		ui->line_min->setText(q_min);
		ui->line_max->setText(q_max);
		ui->line_avg->setText(q_avg);
	}

}

/*
 *Time to double
 *converts datetime to double
 */
QVector<double> meteo_statistics::time_to_double()
{
	std::string temp;
	int year, month, day, hour, min, sec;
	QDate temp_date;
	QTime temp_time;
	QDateTime temp_datetime;
	QVector<double> out_datetime;
	int i, j;
	int counter;

	out_datetime.clear();
	for (int i = 0; i < datetime.size(); i++){
		temp = datetime[i];
		year = stoi(temp.substr(0, 4));
		month = stoi(temp.substr(5, 2));
		day = stoi(temp.substr(8, 2));
		hour = stoi(temp.substr(11, 2));
		min = stoi(temp.substr(14, 2));
		sec = stoi(temp.substr(17, 2));

		temp_date.setDate(year, month, day);
		temp_time.setHMS(hour, min, sec);
		temp_datetime.setDate(temp_date);
		temp_datetime.setTime(temp_time);
		out_datetime.push_back(temp_datetime.toMSecsSinceEpoch() / 1000);
	}
	return out_datetime;
}

/*
 *Data correction
 *calculate additions from rain count to show how many mm fells
 *NULL values from SQL database are replaced with -10000
 *this values are filled with the previous value
 */
QVector<double> meteo_statistics::data_correction(std::string unit_name, std::vector<double> data)
{
	int j;
	double a, b;
	QVector<double> meas_values;

	if (!unit_name.compare("RainCount")){
		for (j = 1; j < data.size(); j++){
			a = data.at(j);
			b = data.at(j - 1);
			if ((abs(a - b) >= 9000) || (a - b < 0))
				meas_values.push_back((0));
			else
				meas_values.push_back(a - b);
		}
	}
	else{
		for (j = 0; j < data.size(); j++){
			a = data.at(j);
			if (a == -10000)
				meas_values.push_back(meas_values.back());
			else
				meas_values.push_back(a);
		}
	}
	return meas_values;
}