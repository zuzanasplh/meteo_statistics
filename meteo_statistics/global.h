#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <iostream>
#include <QtWidgets/QMainWindow>
#include "sql_database.h"

//const std::string host_name = "tcp://127.0.0.1:3306";
//const std::string user_name = "SQL_francescoh";
//const std::string password = "elixir";
//const std::string schema = "test";
//const std::string table = "meteo";

enum unit{
	datum_zapisu = 0,
	InTemp,
	InHR,
	CH1Temp,
	CH1HR,
	CH2Temp,
	CH2HR,
	CH3Temp,
	CH3HR,
	CH4Temp,
	CH4HR,
	CH5Temp,
	CH5HR,
	UV,
	Baro,
	Weather,
	Wchill,
	Wgust,
	Wspeed,
	Wdir,
	RainCount
};

std::string unit_to_string(unit);
QString label_to_string(unit);
extern SQL_settings my_settings;

static int unit_color[21][3] = {
	{ 0, 0, 0 }, { 153, 0, 0 }, { 204, 204, 0 }, { 204, 0, 0 }, { 255, 255, 0 }, { 255, 0, 0 }, { 255, 255, 51 }, { 255, 51, 51 }, { 255, 255, 102 }, { 255, 102, 102 }, { 255, 255, 153 }, { 255, 153, 153 }, { 255, 255, 204 },
	    { 0, 255, 0 }, { 50, 205, 50 }, { 0, 0, 255 }, { 25, 25, 112 },
		{ 255, 105, 180 }, { 205, 92, 92 }, { 70, 130, 180 }, { 128, 128, 128 }
};

#endif