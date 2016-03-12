#ifndef _METEO_GRAPH_H_
#define _METEO_GRAPH_H_

#include "qcustomplot.h"
#include "ui_meteo_statistics.h"
#include "global.h"


class plot
{
public:
	void set_name(std::string name);
	void set_graph(QCPGraph *in_graph);
	void set_axis(QCPAxis *in_axis);
	std::string get_name(void);
	QCPGraph* get_graph(void);
	QCPAxis* get_axis(void);
private:
	std::string my_name;
	QCPGraph *my_graph;
	QCPAxis *my_axis;
};


class meteo_graph
{
public:
	void create_graph(Ui::meteo_statisticsClass *ui);
	void draw_graph(int number, QVector<double> time, QVector<double> data);
	void hide_graph(int number);
	void delete_graph(void);
	plot *get_plot(int number);
	QCPAxisRect* get_QCPAxisRect(void);
private:
	plot meteo_plots[21];
	QCPAxisRect *wide_axis_rect;
};

#endif