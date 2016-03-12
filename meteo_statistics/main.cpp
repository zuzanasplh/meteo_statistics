#include "meteo_statistics.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	meteo_statistics w;
	w.check_meas_units();
	w.show();
	return a.exec();
}
