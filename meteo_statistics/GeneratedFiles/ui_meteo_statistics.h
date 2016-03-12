/********************************************************************************
** Form generated from reading UI file 'meteo_statistics.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METEO_STATISTICS_H
#define UI_METEO_STATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_meteo_statisticsClass
{
public:
    QWidget *centralWidget;
    QPushButton *openpath_button;
    QTextEdit *path_text;
    QPushButton *importdata_button;
    QGroupBox *statistics_box;
    QCheckBox *check_InTemp;
    QCheckBox *check_InHR;
    QCheckBox *check_CH1Temp;
    QCheckBox *check_CH1HR;
    QCheckBox *check_CH2Temp;
    QCheckBox *check_CH2HR;
    QCheckBox *check_CH3Temp;
    QCheckBox *check_CH3HR;
    QCheckBox *check_CH4Temp;
    QCheckBox *check_CH4HR;
    QCheckBox *check_CH5Temp;
    QCheckBox *check_CH5HR;
    QCheckBox *check_UV;
    QCheckBox *check_Baro;
    QCheckBox *check_Weather;
    QCheckBox *check_Wchill;
    QCheckBox *check_Wgust;
    QCheckBox *check_Wdir;
    QCheckBox *check_RainCount;
    QCheckBox *check_Wspeed;
    QProgressBar *progress_import;
    QDateTimeEdit *dateTime_start;
    QDateTimeEdit *dateTime_end;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_MIN;
    QLineEdit *line_min;
    QLabel *label_MAX;
    QLineEdit *line_max;
    QLabel *label_AVG;
    QLineEdit *line_avg;
    QComboBox *unit_combo;
    QCustomPlot *customplot;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *meteo_statisticsClass)
    {
        if (meteo_statisticsClass->objectName().isEmpty())
            meteo_statisticsClass->setObjectName(QStringLiteral("meteo_statisticsClass"));
        meteo_statisticsClass->resize(1211, 504);
        centralWidget = new QWidget(meteo_statisticsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openpath_button = new QPushButton(centralWidget);
        openpath_button->setObjectName(QStringLiteral("openpath_button"));
        openpath_button->setGeometry(QRect(260, 20, 21, 21));
        QIcon icon;
        icon.addFile(QStringLiteral("folder_open.png"), QSize(), QIcon::Normal, QIcon::On);
        openpath_button->setIcon(icon);
        path_text = new QTextEdit(centralWidget);
        path_text->setObjectName(QStringLiteral("path_text"));
        path_text->setEnabled(true);
        path_text->setGeometry(QRect(10, 20, 241, 51));
        path_text->setReadOnly(true);
        importdata_button = new QPushButton(centralWidget);
        importdata_button->setObjectName(QStringLiteral("importdata_button"));
        importdata_button->setGeometry(QRect(10, 80, 75, 23));
        statistics_box = new QGroupBox(centralWidget);
        statistics_box->setObjectName(QStringLiteral("statistics_box"));
        statistics_box->setGeometry(QRect(480, 20, 451, 150));
        check_InTemp = new QCheckBox(statistics_box);
        check_InTemp->setObjectName(QStringLiteral("check_InTemp"));
        check_InTemp->setGeometry(QRect(0, 20, 141, 17));
        check_InHR = new QCheckBox(statistics_box);
        check_InHR->setObjectName(QStringLiteral("check_InHR"));
        check_InHR->setGeometry(QRect(140, 20, 101, 17));
        check_CH1Temp = new QCheckBox(statistics_box);
        check_CH1Temp->setObjectName(QStringLiteral("check_CH1Temp"));
        check_CH1Temp->setGeometry(QRect(0, 40, 111, 17));
        check_CH1HR = new QCheckBox(statistics_box);
        check_CH1HR->setObjectName(QStringLiteral("check_CH1HR"));
        check_CH1HR->setGeometry(QRect(140, 40, 110, 17));
        check_CH2Temp = new QCheckBox(statistics_box);
        check_CH2Temp->setObjectName(QStringLiteral("check_CH2Temp"));
        check_CH2Temp->setGeometry(QRect(0, 60, 112, 17));
        check_CH2HR = new QCheckBox(statistics_box);
        check_CH2HR->setObjectName(QStringLiteral("check_CH2HR"));
        check_CH2HR->setGeometry(QRect(140, 60, 110, 17));
        check_CH3Temp = new QCheckBox(statistics_box);
        check_CH3Temp->setObjectName(QStringLiteral("check_CH3Temp"));
        check_CH3Temp->setGeometry(QRect(0, 80, 112, 17));
        check_CH3HR = new QCheckBox(statistics_box);
        check_CH3HR->setObjectName(QStringLiteral("check_CH3HR"));
        check_CH3HR->setGeometry(QRect(140, 80, 110, 17));
        check_CH4Temp = new QCheckBox(statistics_box);
        check_CH4Temp->setObjectName(QStringLiteral("check_CH4Temp"));
        check_CH4Temp->setGeometry(QRect(0, 100, 112, 17));
        check_CH4HR = new QCheckBox(statistics_box);
        check_CH4HR->setObjectName(QStringLiteral("check_CH4HR"));
        check_CH4HR->setGeometry(QRect(140, 100, 110, 17));
        check_CH5Temp = new QCheckBox(statistics_box);
        check_CH5Temp->setObjectName(QStringLiteral("check_CH5Temp"));
        check_CH5Temp->setGeometry(QRect(0, 120, 112, 17));
        check_CH5HR = new QCheckBox(statistics_box);
        check_CH5HR->setObjectName(QStringLiteral("check_CH5HR"));
        check_CH5HR->setGeometry(QRect(140, 120, 110, 17));
        check_UV = new QCheckBox(statistics_box);
        check_UV->setObjectName(QStringLiteral("check_UV"));
        check_UV->setGeometry(QRect(280, 20, 80, 17));
        check_Baro = new QCheckBox(statistics_box);
        check_Baro->setObjectName(QStringLiteral("check_Baro"));
        check_Baro->setGeometry(QRect(280, 40, 80, 17));
        check_Weather = new QCheckBox(statistics_box);
        check_Weather->setObjectName(QStringLiteral("check_Weather"));
        check_Weather->setGeometry(QRect(280, 60, 80, 17));
        check_Wchill = new QCheckBox(statistics_box);
        check_Wchill->setObjectName(QStringLiteral("check_Wchill"));
        check_Wchill->setGeometry(QRect(360, 20, 100, 17));
        check_Wgust = new QCheckBox(statistics_box);
        check_Wgust->setObjectName(QStringLiteral("check_Wgust"));
        check_Wgust->setGeometry(QRect(360, 40, 100, 17));
        check_Wdir = new QCheckBox(statistics_box);
        check_Wdir->setObjectName(QStringLiteral("check_Wdir"));
        check_Wdir->setGeometry(QRect(360, 80, 100, 17));
        check_RainCount = new QCheckBox(statistics_box);
        check_RainCount->setObjectName(QStringLiteral("check_RainCount"));
        check_RainCount->setGeometry(QRect(280, 80, 80, 17));
        check_Wspeed = new QCheckBox(statistics_box);
        check_Wspeed->setObjectName(QStringLiteral("check_Wspeed"));
        check_Wspeed->setGeometry(QRect(360, 60, 82, 17));
        progress_import = new QProgressBar(centralWidget);
        progress_import->setObjectName(QStringLiteral("progress_import"));
        progress_import->setEnabled(false);
        progress_import->setGeometry(QRect(100, 80, 121, 23));
        progress_import->setValue(0);
        dateTime_start = new QDateTimeEdit(centralWidget);
        dateTime_start->setObjectName(QStringLiteral("dateTime_start"));
        dateTime_start->setGeometry(QRect(10, 130, 111, 22));
        dateTime_start->setWrapping(false);
        dateTime_start->setCalendarPopup(true);
        dateTime_end = new QDateTimeEdit(centralWidget);
        dateTime_end->setObjectName(QStringLiteral("dateTime_end"));
        dateTime_end->setGeometry(QRect(140, 130, 111, 22));
        dateTime_end->setWrapping(false);
        dateTime_end->setCalendarPopup(true);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(280, 20, 181, 141));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 60, 162, 74));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_MIN = new QLabel(layoutWidget);
        label_MIN->setObjectName(QStringLiteral("label_MIN"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_MIN);

        line_min = new QLineEdit(layoutWidget);
        line_min->setObjectName(QStringLiteral("line_min"));

        formLayout->setWidget(0, QFormLayout::FieldRole, line_min);

        label_MAX = new QLabel(layoutWidget);
        label_MAX->setObjectName(QStringLiteral("label_MAX"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_MAX);

        line_max = new QLineEdit(layoutWidget);
        line_max->setObjectName(QStringLiteral("line_max"));

        formLayout->setWidget(1, QFormLayout::FieldRole, line_max);

        label_AVG = new QLabel(layoutWidget);
        label_AVG->setObjectName(QStringLiteral("label_AVG"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_AVG);

        line_avg = new QLineEdit(layoutWidget);
        line_avg->setObjectName(QStringLiteral("line_avg"));

        formLayout->setWidget(2, QFormLayout::FieldRole, line_avg);

        unit_combo = new QComboBox(groupBox);
        unit_combo->setObjectName(QStringLiteral("unit_combo"));
        unit_combo->setGeometry(QRect(10, 30, 161, 22));
        customplot = new QCustomPlot(centralWidget);
        customplot->setObjectName(QStringLiteral("customplot"));
        customplot->setGeometry(QRect(10, 170, 1191, 281));
        meteo_statisticsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(meteo_statisticsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1211, 21));
        meteo_statisticsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(meteo_statisticsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        meteo_statisticsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(meteo_statisticsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        meteo_statisticsClass->setStatusBar(statusBar);

        retranslateUi(meteo_statisticsClass);

        QMetaObject::connectSlotsByName(meteo_statisticsClass);
    } // setupUi

    void retranslateUi(QMainWindow *meteo_statisticsClass)
    {
        meteo_statisticsClass->setWindowTitle(QApplication::translate("meteo_statisticsClass", "meteo_statistics", 0));
        openpath_button->setText(QString());
        importdata_button->setText(QApplication::translate("meteo_statisticsClass", "Import data", 0));
        statistics_box->setTitle(QApplication::translate("meteo_statisticsClass", "Measured units", 0));
        check_InTemp->setText(QApplication::translate("meteo_statisticsClass", "Indoor Temperature", 0));
        check_InHR->setText(QApplication::translate("meteo_statisticsClass", "Indoor Humidity", 0));
        check_CH1Temp->setText(QApplication::translate("meteo_statisticsClass", "CH1 Temperature", 0));
        check_CH1HR->setText(QApplication::translate("meteo_statisticsClass", "CH1 Humidity", 0));
        check_CH2Temp->setText(QApplication::translate("meteo_statisticsClass", "CH2 Temperature", 0));
        check_CH2HR->setText(QApplication::translate("meteo_statisticsClass", "CH2 Humidity", 0));
        check_CH3Temp->setText(QApplication::translate("meteo_statisticsClass", "CH3 Temperature", 0));
        check_CH3HR->setText(QApplication::translate("meteo_statisticsClass", "CH3 Humidity", 0));
        check_CH4Temp->setText(QApplication::translate("meteo_statisticsClass", "CH4 Temperature", 0));
        check_CH4HR->setText(QApplication::translate("meteo_statisticsClass", "CH4 Humidity", 0));
        check_CH5Temp->setText(QApplication::translate("meteo_statisticsClass", "CH5 Temperature", 0));
        check_CH5HR->setText(QApplication::translate("meteo_statisticsClass", "CH5 Humidity", 0));
        check_UV->setText(QApplication::translate("meteo_statisticsClass", "UV", 0));
        check_Baro->setText(QApplication::translate("meteo_statisticsClass", "Presurre", 0));
        check_Weather->setText(QApplication::translate("meteo_statisticsClass", "Weather", 0));
        check_Wchill->setText(QApplication::translate("meteo_statisticsClass", "Wind Chill", 0));
        check_Wgust->setText(QApplication::translate("meteo_statisticsClass", "Wind Gust", 0));
        check_Wdir->setText(QApplication::translate("meteo_statisticsClass", "Wind Directon", 0));
        check_RainCount->setText(QApplication::translate("meteo_statisticsClass", "Rain Count", 0));
        check_Wspeed->setText(QApplication::translate("meteo_statisticsClass", "Wind Speed", 0));
        groupBox->setTitle(QApplication::translate("meteo_statisticsClass", "Statistics", 0));
        label_MIN->setText(QApplication::translate("meteo_statisticsClass", "MIN", 0));
        label_MAX->setText(QApplication::translate("meteo_statisticsClass", "MAX", 0));
        label_AVG->setText(QApplication::translate("meteo_statisticsClass", "AVG", 0));
    } // retranslateUi

};

namespace Ui {
    class meteo_statisticsClass: public Ui_meteo_statisticsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METEO_STATISTICS_H
