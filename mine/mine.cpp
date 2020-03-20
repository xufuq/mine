#include "mine.h"

Mine::Mine(QWidget *parent) : QWidget(parent)
{
    srand((unsigned)time(NULL));
    one_box=new MyPushbutton();
    put_out=new QGridLayout(this);
    //设置间距为零
    time_count=0;
    flag_count=0;
    show_box=0;
    put_out->setContentsMargins(0,0,0,0);
    for(int i=0;i<576;i++)
        all_mine.push_back(new MyPushbutton());
    for(int i=1;i<17;i++)
    {
        for(int j=1;j<31;j++)
            put_out->addWidget(all_mine[32*i+j],i-1,j-1);
    }
    put_out->setSpacing(0);
    put_out->setMargin(0);

    QSet<int> my_set;
    QVector<int> prepare(576);
    int count=0;
    while(count<99)
    {
        int randVal=my_rand();
        if(my_set.find(randVal)==my_set.end())
        {
            my_set.insert(randVal);
            int y=randVal/30;
            int x=randVal%30;
            prepare[32*(y+1)+x+1]=-1;
            count++;
            qDebug() << randVal<<"  "<<count;
        }
    }
    for(int i=1;i<17;i++)
    {
        for(int j=1;j<31;j++)
        {
            if(prepare[32*i+j]!=-1)
            {
                for(int m=-1;m<2;m++)
                {
                    for(int n=-1;n<2;n++)
                        if(prepare[32*(i+m)+j+n]==-1)
                            prepare[32*i+j]++;
                }
            }
        }
    }
    for(int i=1;i<17;i++)
    {
        for(int j=1;j<31;j++)
        {
            all_mine[32*i+j]->set_flag(prepare[32*i+j],i,j,32*i+j);
            connect(all_mine[32*i+j]->My_Emit,SIGNAL(SendData(int,int,int)),this,SLOT(auto_click(int,int,int)));
        }
    }
    time1=new QTimer(this);
    time1->start(100);
    connect(time1,&QTimer::timeout,this,&time_out);
}

int Mine::my_rand()
{
    int num=rand()%480;
    return num;
}

void Mine::auto_click(int y,int x,int count)
{
    click_event(y,x,count);
    for(auto c:need_click)
    {
            all_mine[c]->click_mine();
    }

    int Rem_0count=0,need_0count=0;

    do
    {
        QVector<int> Rem_vec=need_click;
        need_click.clear();
        Rem_0count=need_0count;
        for(auto again_mine:Rem_vec)
            click_event(all_mine[again_mine]->MyPos[0],all_mine[again_mine]->MyPos[1],again_mine);
        for(auto c:need_click)
        {
            if(all_mine[c]->if_equal()==0)
            {
                for(int i=-1;i<2;i++)
                {
                    for(int j=-1;j<2;j++)
                    {
                        all_mine[(all_mine[c]->MyPos[0]+i)*32+all_mine[c]->MyPos[1]+j]->click_mine();
                    }
                }
                //all_mine[c]->click_mine();
                need_0count++;
            }
            else
                all_mine[c]->click_mine();
        }
    }
    while(Rem_0count!=need_0count);

    need_click.clear();
}
void Mine::click_event(int y,int x,int count)
{
    int m=0,n=0;
    //第二象限
    if(full_check(all_mine[count])||all_mine[count]->if_equal()==0)
    {
        for(m=0;m>-16;m--)
        {
            for(n=0;n>-30;n--)
            {
                if((y+m)>0&&(x+n)>0)
                {
                    now_pos=32*(y+m)+x+n;
                    if(now_pos!=count)//如果不是当前点就继续
                    {
                        int flag=all_mine[now_pos]->if_equal();
                        if(flag==0)
                            need_click.push_back(now_pos);
                         else if(flag==-1)
                            break;
                         else if(flag==-2)
                            break;
                        else
                        {
                           need_click.push_back(now_pos);
                           break;
                        }
                    }
                }
                else
                    break;
            }
            if(n==0)
                break;
        }
        //第三象限
        for(m=1;m<16;m++)
        {
            for(n=0;n>-30;n--)
            {
                if((y+m)<17&&(x+n)>0)
                {
                    now_pos=32*(y+m)+x+n;
                    if(now_pos!=count)//如果不是当前点就继续
                    {
                        int flag=all_mine[now_pos]->if_equal();
                        if(flag==0)
                            need_click.push_back(now_pos);
                         else if(flag==-1)
                            break;
                         else if(flag==-2)
                            break;
                        else
                        {
                           need_click.push_back(now_pos);
                           break;
                        }
                    }
                }
                else
                    break;

            }
            if(n==0)
                break;
        }
        //第四象限
        for(m=0;m<16;m++)
        {
            for(n=1;n<30;n++)
            {
                if((y+m)<17&&(x+n)<31)
                {
                    now_pos=32*(y+m)+x+n;
                    if(now_pos!=count)//如果不是当前点就继续
                    {
                        int flag=all_mine[now_pos]->if_equal();
                        if(flag==0)
                            need_click.push_back(now_pos);
                         else if(flag==-1)
                            break;
                         else if(flag==-2)
                            break;
                        else
                        {
                           need_click.push_back(now_pos);
                           break;
                        }
                    }
                }
                else
                    break;
            }
            if(n==1)
                break;
        }
        //第三象限
        for(m=1;m<16;m++)
        {
            for(n=1;n<30;n++)
            {
                if((y+m)<17&&(x+n)<31)
                {
                    now_pos=32*(y+m)+x+n;
                    if(now_pos!=count)//如果不是当前点就继续
                    {
                        int flag=all_mine[now_pos]->if_equal();
                        if(flag==0)
                            need_click.push_back(now_pos);
                         else if(flag==-1)
                            break;
                         else if(flag==-2)
                            break;
                         else
                         {
                            need_click.push_back(now_pos);
                            break;
                          }
                    }
                }
                else
                    break;

            }
            if(n==1)
                break;
        }
    }
}

int Mine::full_check(MyPushbutton *Item)
{
    int num=0;
    int check_right=0;
    for(int i=-1;i<2;i++)
    {
        for(int j=-1;j<2;j++)
        {
            if(all_mine[(Item->MyPos[0]+i)*32+Item->MyPos[1]+j]->now_flag==-1)//标记为红旗
            {
                if(all_mine[(Item->MyPos[0]+i)*32+Item->MyPos[1]+j]->real_flag!=-1)//标记为红旗但是不是雷
                    check_right--;
                num++;
            }
        }
    }
    if(num==Item->real_flag)
    {
        if(check_right==0)
            return 1;//为真，可以点开周围
        else
        {
            qDebug()<<" game over";
            return -1;//有选错的红旗，结束游戏
        }
    }
    else
        return 0;//未点完，不能点开，游戏继续
}

void Mine::time_out()
{
    int right_count=0;
    mine_count=0;
    time_count+=0.1;
    flag_count=0;
    for(int i=1;i<17;i++)
    {
        for(int j=1;j<31;j++)
        {
            if(all_mine[32*i+j]->now_flag==all_mine[32*i+j]->real_flag)
            {
                right_count++;
                if(all_mine[32*i+j]->real_flag==-1)
                    mine_count++;
            }
            if(all_mine[32*i+j]->now_flag==-1)
                flag_count++;
        }
    }
    if(right_count==480&&show_box==0)
    {
        QMessageBox::about(this,tr("Succeed"),tr("You have win!\nNew game?"));
        right_count=0;
        show_box=1;
    }
}
