/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <mytablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    MyTableWidget *tableWidget;
    QPushButton *reStart;
    QPushButton *mine_count;
    QPushButton *time;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(949, 579);
        MainWindow->setIconSize(QSize(255, 255));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new MyTableWidget(centralwidget);
        if (tableWidget->columnCount() < 30)
            tableWidget->setColumnCount(30);
        if (tableWidget->rowCount() < 16)
            tableWidget->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 50, 931, 481));
        QFont font;
        font.setPointSize(12);
        tableWidget->setFont(font);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setIconSize(QSize(25, 25));
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setRowCount(16);
        tableWidget->setColumnCount(30);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(30);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        reStart = new QPushButton(centralwidget);
        reStart->setObjectName(QString::fromUtf8("reStart"));
        reStart->setGeometry(QRect(10, 10, 80, 31));
        reStart->setFont(font);
        mine_count = new QPushButton(centralwidget);
        mine_count->setObjectName(QString::fromUtf8("mine_count"));
        mine_count->setGeometry(QRect(110, 10, 80, 31));
        mine_count->setFont(font);
        time = new QPushButton(centralwidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(210, 10, 80, 31));
        time->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 949, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        reStart->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        mine_count->setText(QString());
        time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
