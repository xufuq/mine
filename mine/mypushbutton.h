#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QIcon>
#include <QDebug>
#include <QPixmap>
#include <QString>
#include <QFont>
#include <QMessageBox>
#include "for_emit.h"
class MyPushbutton :public QPushButton
{
    //Q_OBJECT
public:
    MyPushbutton();
    void mousePressEvent(QMouseEvent *event);
    void set_flag(int&, int&, int&,int z);
    void click_mine();
    int  if_equal();
    static int all_use;
    int MyPos[2]={0,0};
    int   now_flag;
    int   real_flag;
    int   count;
    For_Emit *My_Emit;

signals:


public slots:

private:
    int   enter_true;
    int   left_is_use;
    int   right_is_use;

    QIcon mine_pic;
    QIcon ques_pic;
    QIcon flag_pic;
};

#endif // MYPUSHBUTTON_H
