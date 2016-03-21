/********************************************************************************
** Form generated from reading UI file 'import_data_w.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORT_DATA_W_H
#define UI_IMPORT_DATA_W_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_import_data_w
{
public:
    QTextEdit *path_text;
    QPushButton *importdata_button;
    QPushButton *openpath_button;
    QProgressBar *progress_import;

    void setupUi(QWidget *import_data_w)
    {
        if (import_data_w->objectName().isEmpty())
            import_data_w->setObjectName(QStringLiteral("import_data_w"));
        import_data_w->resize(400, 300);
        path_text = new QTextEdit(import_data_w);
        path_text->setObjectName(QStringLiteral("path_text"));
        path_text->setEnabled(true);
        path_text->setGeometry(QRect(10, 20, 301, 31));
        path_text->setReadOnly(true);
        importdata_button = new QPushButton(import_data_w);
        importdata_button->setObjectName(QStringLiteral("importdata_button"));
        importdata_button->setGeometry(QRect(10, 60, 75, 23));
        openpath_button = new QPushButton(import_data_w);
        openpath_button->setObjectName(QStringLiteral("openpath_button"));
        openpath_button->setGeometry(QRect(310, 20, 31, 31));
        QIcon icon;
        icon.addFile(QStringLiteral("folder_open.png"), QSize(), QIcon::Normal, QIcon::On);
        openpath_button->setIcon(icon);
        progress_import = new QProgressBar(import_data_w);
        progress_import->setObjectName(QStringLiteral("progress_import"));
        progress_import->setEnabled(false);
        progress_import->setGeometry(QRect(100, 60, 241, 23));
        progress_import->setValue(0);

        retranslateUi(import_data_w);

        QMetaObject::connectSlotsByName(import_data_w);
    } // setupUi

    void retranslateUi(QWidget *import_data_w)
    {
        import_data_w->setWindowTitle(QApplication::translate("import_data_w", "import_data_w", 0));
        importdata_button->setText(QApplication::translate("import_data_w", "Import data", 0));
        openpath_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class import_data_w: public Ui_import_data_w {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORT_DATA_W_H
