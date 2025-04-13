/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit_info;
    QLabel *label_content;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(830, 620);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 181, 31));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        label->setFont(font);
        lineEdit_info = new QLineEdit(centralwidget);
        lineEdit_info->setObjectName("lineEdit_info");
        lineEdit_info->setGeometry(QRect(20, 70, 191, 31));
        label_content = new QLabel(centralwidget);
        label_content->setObjectName("label_content");
        label_content->setGeometry(QRect(20, 480, 791, 121));
        QFont font1;
        font1.setPointSize(13);
        label_content->setFont(font1);
        label_content->setFrameShape(QFrame::Box);
        label_content->setFrameShadow(QFrame::Plain);
        label_content->setWordWrap(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 70, 101, 31));
        QFont font2;
        font2.setPointSize(15);
        pushButton->setFont(font2);
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 110, 791, 321));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 440, 91, 31));
        QFont font3;
        font3.setPointSize(17);
        font3.setBold(true);
        label_2->setFont(font3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\223\210\345\210\251\346\263\242\347\211\271\346\243\200\347\264\242", nullptr));
        label_content->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\345\206\205\345\256\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
