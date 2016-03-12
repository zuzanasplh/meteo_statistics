#include "meteo_graph.h"

std::string color[20];

/*
 *Set plot name
 */
void plot::set_name(std::string name)
{
	my_name = name;
}

/*
 *Set graph
 */
void plot::set_graph(QCPGraph *in_graph)
{
	my_graph = in_graph;
}

/*
 *Set axis
 */
void plot::set_axis(QCPAxis *in_axis)
{
	my_axis = in_axis;
}

/*
 *Get plot name
 */
std::string plot::get_name(void)
{
	return my_name;
}

/*
 *Get graph
 */
QCPGraph* plot::get_graph(void)
{
	return my_graph;
}

/*
 *Get axis
 */
QCPAxis* plot::get_axis(void)
{
	return my_axis;
}


/*
 *Create graph with axis and set name,
 *set date and time format, tick count, label type, pen color, label color, tick label color
 *hide all axis and all graphs
 */
void meteo_graph::create_graph(Ui::meteo_statisticsClass *ui)
{
	ui->customplot->plotLayout()->clear();

	wide_axis_rect = new QCPAxisRect(ui->customplot);


	for (int i = 0; i < 21; i++){
		meteo_plots[i].set_name(unit_to_string((unit)i));
		meteo_plots[i].set_axis(new QCPAxis(wide_axis_rect, QCPAxis::atLeft));
		wide_axis_rect->addAxis(QCPAxis::atLeft, meteo_plots[i].get_axis());
	}

	ui->customplot->plotLayout()->addElement(0, 0, wide_axis_rect);

	wide_axis_rect->axis(QCPAxis::atBottom)->setTickLabelType(QCPAxis::ltDateTime);
	wide_axis_rect->axis(QCPAxis::atBottom)->setDateTimeFormat("dd-MM-yy\nHH:MM");
	wide_axis_rect->axis(QCPAxis::atBottom)->setAutoTickCount(20);
	wide_axis_rect->setupFullAxesBox(true);
	for (int i = 0; i < 21; i++){
		meteo_plots[i].set_graph(ui->customplot->addGraph(wide_axis_rect->axis(QCPAxis::atBottom), meteo_plots[i].get_axis()));
		meteo_plots[i].get_graph()->setPen(QPen(QColor(unit_color[i][0], unit_color[i][1], unit_color[i][2])));
		meteo_plots[i].get_axis()->setLabelColor(QColor(unit_color[i][0], unit_color[i][1], unit_color[i][2]));
		meteo_plots[i].get_axis()->setLabel(label_to_string((unit)i));
		meteo_plots[i].get_axis()->setTickLabelColor(QColor(unit_color[i][0], unit_color[i][1], unit_color[i][2]));
	}

	wide_axis_rect->axis(QCPAxis::atLeft, 0)->setVisible(false);

	for (int i = 0; i < 21; i++){
		meteo_plots[i].get_graph()->setVisible(false);
		meteo_plots[i].get_axis()->setVisible(false);
	}
}

/*
 *Draw graph
 *clear old data, load new data from sql database, set visible axis and graph
 */
void meteo_graph::draw_graph(int number, QVector<double> time, QVector<double> data)
{
	int i;
	
	meteo_plots[number].get_graph()->clearData();
	meteo_plots[number].get_graph()->setData(time, data);
	meteo_plots[number].get_graph()->rescaleAxes();
	meteo_plots[number].get_axis()->setVisible(true);
	meteo_plots[number].get_graph()->setVisible(true);
	
}

/*
 *Hide graph
 *hide graph with axis
 */
void meteo_graph::hide_graph(int number)
{
	meteo_plots[number].get_graph()->setVisible(false);
	meteo_plots[number].get_axis()->setVisible(false);
}

/*
 *Delete graph
 */
void meteo_graph::delete_graph(void)
{
	for (int i = 0; i < 21; i++){
		delete meteo_plots[i].get_axis();
		meteo_plots[i].set_axis(NULL);
	}
}

/*
 *Get plot
 */
plot *meteo_graph::get_plot(int number)
{
	return &meteo_plots[number];
}

/*
 *Get QCPAxisRect
 */
QCPAxisRect* meteo_graph::get_QCPAxisRect(void)
{
	return wide_axis_rect;
}