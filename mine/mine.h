#ifndef MINE_H
#define MINE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMouseEvent>
#include <QEvent>
#include <QLabel>
#include <QDebug>
#include <QVector>
#include <time.h>
#include <QSet>
#include <QTimer>
#include <QDialog>
#include <QMessageBox>
#include "mypushbutton.h"

class Mine : public QWidget
{
    Q_OBJECT
public:
    explicit Mine(QWidget *parent = nullptr);
    float time_count;
    int mine_count;
    int flag_count;
    int show_box;
    QVector<MyPushbutton *> all_mine;
signals:

public slots:
    void auto_click(int,int,int);
    void click_event(int ,int ,int);
    int  full_check(MyPushbutton*);
    void time_out();
private:
    QGridLayout *put_out;
    MyPushbutton *one_box;

    QDialog     *click_button;
    int my_rand();
    int now_pos;
    QVector<int> need_click;
    QTimer *time1;
};

#endif // MINE_H
