#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QVBoxLayout>
#include "mine.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void Reboot();
    void time_out1();
private:
    Mine    *one_mine;
    QWidget *pWidget;
    QGridLayout *main_layout;
    QVBoxLayout *Out_put;
    QPushButton *Restart;
    QLabel      *last;
    QLabel      *use_time;
    QTimer      *Timer1;
};

#endif // MAINWINDOW_H
