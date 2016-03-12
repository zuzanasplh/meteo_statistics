#include "global.h"

/*
 *Converts measured units to string
 */
std::string unit_to_string(unit u)
{
	switch (u)
	{
	case unit::Baro:
		return "Baro";

	case unit::CH1HR:
		return "CH1HR";

	case unit::CH1Temp:
		return "CH1Temp";

	case unit::CH2HR:
		return "CH2HR";

	case unit::CH2Temp:
		return "CH2Temp";

	case unit::CH3HR:
		return "CH3HR";

	case unit::CH3Temp:
		return "CH3Temp";

	case unit::CH4HR:
		return "CH4HR";

	case unit::CH4Temp:
		return "CH4Temp";

	case unit::CH5HR:
		return "CH5HR";

	case unit::CH5Temp:
		return "CH5Temp";

	case unit::datum_zapisu:
		return "datum_zapisu";

	case unit::InHR:
		return "InHR";

	case unit::InTemp:
		return "InTemp";

	case unit::RainCount:
		return "RainCount";

	case unit::UV:
		return "UV";

	case unit::Wchill:
		return "Wchill";

	case unit::Wdir:
		return "Wdir";

	case unit::Weather:
		return "Weather";

	case unit::Wgust:
		return "Wgust";

	case unit::Wspeed:
		return "Wspeed";

	default:
		return "";
		break;
	}
}

/*
 *Converts graph labels to string
 */
QString label_to_string(unit u)
{
	QChar degree_char(0260);
	QString label;
	switch (u)
	{
	case unit::Baro:
		label.append("Baro hPa");
		return label;

	case unit::CH1HR:
		label.append("CH1HR %");
		return label;

	case unit::CH1Temp:
		label.append("CH1Temp ");
		label.append(degree_char);
		label.append("C");
		return label;

	case unit::CH2HR:
		label.append("CH2HR");
		return label;

	case unit::CH2Temp:
		label.append("CH2Temp ");
		label.append(degree_char);
		label.append("C");
		return label;

	case unit::CH3HR:
		return "CH3HR %";

	case unit::CH3Temp:
		label.append("CH3Temp ");
		label.append(degree_char);
		label.append("C");
		return label;

	case unit::CH4HR:
		label.append("CH4HR %");
		return label;

	case unit::CH4Temp:
		label.append("CH4Temp ");
		label.append(degree_char);
		label.append("C");
		return label;

	case unit::CH5HR:
		label.append("CH5HR %");
		return label;

	case unit::CH5Temp:
		label.append("CH5Temp ");
		label.append(degree_char);
		label.append("C");
		return label;

	case unit::datum_zapisu:
		label.append("datum_zapisu");
		return label;


	case unit::InHR:
		label.append("InHR %");
		return label;

	case unit::InTemp:
		label.append("InTemp ");
		label.append(degree_char);
		label.append("C");
		return label;

	case unit::RainCount:
		label.append("RainCount mm");
		return label;

	case unit::UV:
		label.append("UV");
		return label;

	case unit::Wchill:
		label.append("Wchill m/s");
		return label;

	case unit::Wdir:
		label.append("Wdir");
		return label;

	case unit::Weather:
		label.append("Weather");
		return label;

	case unit::Wgust:
		label.append("Wgust m/s");
		return label;

	case unit::Wspeed:
		label.append("Wspeed m/s");
		return label;

	default:
		return "";
		break;
	}
}