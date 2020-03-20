#include "mypushbutton.h"
MyPushbutton::MyPushbutton() : QPushButton()
{
    now_flag =100;//100是未确定，-1是红旗，-2是问号
    real_flag=0;  //-1是地雷，0-8是周围地雷数，100是未点开
    left_is_use=1;
    right_is_use=1;
    setFixedSize(30,30);
    My_Emit=new For_Emit();
    mine_pic=QIcon(QPixmap(":/icon/image/mine.png").scaled(this->size()));
    ques_pic=QIcon(QPixmap(":/icon/image/ques.jpg").scaled(30,30));
    flag_pic=QIcon(QPixmap(":/icon/image/flag.png").scaled(30,30));
}

int MyPushbutton::all_use=1;

void MyPushbutton::mousePressEvent(QMouseEvent *event)
{

        if((event->button()==Qt::LeftButton)&&left_is_use&&MyPushbutton::all_use)
        {
            right_is_use=0;
            if(real_flag==-1)
            {
                setIcon(mine_pic);
                MyPushbutton::all_use=0;
                QMessageBox::about(this,tr("Failed"),tr("You have lost!\nTry again."));
            }
            else if(real_flag==0)
            {
                click_mine();
                emit My_Emit->SendData(MyPos[0],MyPos[1],count);
            }
            else if(now_flag==real_flag)
            {
                emit My_Emit->SendData(MyPos[0],MyPos[1],count);
            }
            else
            {
                click_mine();
            }
        }

        if((event->button()==Qt::RightButton)&&right_is_use)
        {
            left_is_use=0;
            if(now_flag==100)
            {
                now_flag=-1;
                setIcon(flag_pic);
            }
            else if(now_flag==-1)
            {
                now_flag=-2;
                setIcon(ques_pic);
            }
            else if(now_flag==-2)
            {
                now_flag=100;
                setIcon(QIcon());
                left_is_use=1;
            }
        }
}

void MyPushbutton::set_flag(int &num,int &y,int &x,int z)
{
    real_flag=num;
    MyPos[0]=y,MyPos[1]=x;
    count=z;
}

//如果返回数据为0则是大扩展，是具体数字则只拓展到第一级，是-1则表示这个点已被点开，没有在操作的必要
int MyPushbutton::if_equal()
{
    if(now_flag==real_flag)//已经点开的不在重复点开
    {
        return -1;
    }
    else if(real_flag==0)//也是0的，继续拓展
    {
        return 0;
    }
    else if((real_flag>0)&&(real_flag<9))//点开当前数字
    {
        return real_flag;
    }
    else
        return -2;
}

void MyPushbutton::click_mine()
{
    if(real_flag==0)
        setStyleSheet("background-color: rgb(255,255,255)");
    else
    {
        setStyleSheet("background-color: rgb(192,192,192)");
        switch (real_flag) {
        case 1:
            setStyleSheet("color: rgb(176,23,31);background-color: rgb(192,192,192)");
            break;
        case 2:
            setStyleSheet("color: rgb(0,0,255);background-color: rgb(192,192,192)");
            break;
        case 3:
            setStyleSheet("color: rgb(255,0,0);background-color: rgb(192,192,192)");
            break;
        case 4:
            setStyleSheet("color: rgb(128,42,42);background-color: rgb(192,192,192)");
            break;
        case 5:
            setStyleSheet("color: rgb(163,148,128);background-color: rgb(192,192,192)");
            break;
        case 6:
            setStyleSheet("color: rgb(0,0,0);background-color: rgb(192,192,192)");
            break;
        case 7:
            setStyleSheet("color: rgb(61,145,64);background-color: rgb(192,192,192)");
            break;
        case 8:
            setStyleSheet("color: rgb(160,32,240);background-color: rgb(192,192,192)");
            break;
        default:
            break;
        }
        setFont(QFont("Microsoft YaHei",12));
        setText(QString::number(real_flag));
    }
    now_flag=real_flag;
}

