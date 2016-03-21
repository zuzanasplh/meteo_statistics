/********************************************************************************
** Form generated from reading UI file 'sql_connection_w.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQL_CONNECTION_W_H
#define UI_SQL_CONNECTION_W_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SQL_connection_w
{
public:
    QPushButton *OK_button;
    QPushButton *cancel_button;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *hostname_label;
    QLineEdit *host_name_line;
    QLabel *user_name_label;
    QLineEdit *user_name_line;
    QLabel *password_label;
    QLineEdit *password_line;
    QLabel *schema_label;
    QLabel *table_label;
    QLineEdit *schema_line;
    QLineEdit *table_line;

    void setupUi(QWidget *SQL_connection_w)
    {
        if (SQL_connection_w->objectName().isEmpty())
            SQL_connection_w->setObjectName(QStringLiteral("SQL_connection_w"));
        SQL_connection_w->resize(265, 181);
        OK_button = new QPushButton(SQL_connection_w);
        OK_button->setObjectName(QStringLiteral("OK_button"));
        OK_button->setGeometry(QRect(40, 150, 75, 23));
        cancel_button = new QPushButton(SQL_connection_w);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(160, 150, 75, 23));
        widget = new QWidget(SQL_connection_w);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(38, 12, 191, 126));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        hostname_label = new QLabel(widget);
        hostname_label->setObjectName(QStringLiteral("hostname_label"));

        gridLayout->addWidget(hostname_label, 0, 0, 1, 3);

        host_name_line = new QLineEdit(widget);
        host_name_line->setObjectName(QStringLiteral("host_name_line"));

        gridLayout->addWidget(host_name_line, 0, 3, 1, 1);

        user_name_label = new QLabel(widget);
        user_name_label->setObjectName(QStringLiteral("user_name_label"));

        gridLayout->addWidget(user_name_label, 1, 0, 1, 3);

        user_name_line = new QLineEdit(widget);
        user_name_line->setObjectName(QStringLiteral("user_name_line"));

        gridLayout->addWidget(user_name_line, 1, 3, 1, 1);

        password_label = new QLabel(widget);
        password_label->setObjectName(QStringLiteral("password_label"));

        gridLayout->addWidget(password_label, 2, 0, 1, 3);

        password_line = new QLineEdit(widget);
        password_line->setObjectName(QStringLiteral("password_line"));

        gridLayout->addWidget(password_line, 2, 3, 1, 1);

        schema_label = new QLabel(widget);
        schema_label->setObjectName(QStringLiteral("schema_label"));

        gridLayout->addWidget(schema_label, 3, 0, 1, 2);

        table_label = new QLabel(widget);
        table_label->setObjectName(QStringLiteral("table_label"));

        gridLayout->addWidget(table_label, 4, 0, 1, 1);

        schema_line = new QLineEdit(widget);
        schema_line->setObjectName(QStringLiteral("schema_line"));

        gridLayout->addWidget(schema_line, 3, 3, 1, 1);

        table_line = new QLineEdit(widget);
        table_line->setObjectName(QStringLiteral("table_line"));

        gridLayout->addWidget(table_line, 4, 3, 1, 1);


        retranslateUi(SQL_connection_w);
        QObject::connect(OK_button, SIGNAL(clicked()), SQL_connection_w, SLOT(close()));

        QMetaObject::connectSlotsByName(SQL_connection_w);
    } // setupUi

    void retranslateUi(QWidget *SQL_connection_w)
    {
        SQL_connection_w->setWindowTitle(QApplication::translate("SQL_connection_w", "SQL_connection_w", 0));
        OK_button->setText(QApplication::translate("SQL_connection_w", "OK", 0));
        cancel_button->setText(QApplication::translate("SQL_connection_w", "Cancel", 0));
        hostname_label->setText(QApplication::translate("SQL_connection_w", "host name", 0));
        user_name_label->setText(QApplication::translate("SQL_connection_w", "user name", 0));
        password_label->setText(QApplication::translate("SQL_connection_w", "password", 0));
        schema_label->setText(QApplication::translate("SQL_connection_w", "schema", 0));
        table_label->setText(QApplication::translate("SQL_connection_w", "table", 0));
    } // retranslateUi

};

namespace Ui {
    class SQL_connection_w: public Ui_SQL_connection_w {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQL_CONNECTION_W_H
