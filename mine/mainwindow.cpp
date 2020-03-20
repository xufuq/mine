#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    one_mine=new Mine();
    pWidget=new QWidget();
    Restart=new QPushButton();
    Restart->setText("再来一次");
    Restart->setStyleSheet("color: rgb(255,0,0);background-color: rgb(192,192,192)");
    last=new QLabel();
    last->setStyleSheet("color: rgb(255,0,0);background-color: rgb(0,0,0)");
    use_time=new QLabel();
    use_time->setStyleSheet("color: rgb(255,0,0);background-color: rgb(0,0,0)");
    setCentralWidget(pWidget);
    main_layout=new QGridLayout();
    Out_put=new QVBoxLayout();
    main_layout->addWidget(Restart,0,0);
    main_layout->addWidget(last,0,1);
    main_layout->addWidget(use_time,0,2);
    Out_put->addLayout(main_layout);
    Out_put->addWidget(one_mine);
    pWidget->setLayout(Out_put);
    setWindowTitle(tr("Mine"));
    //setFixedSize(840,464);
    Timer1=new QTimer(this);
    Timer1->start(1000);
    connect(Timer1,&QTimer::timeout,this,&time_out1);
    connect(Restart,SIGNAL(clicked(bool)),this,SLOT(Reboot()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::Reboot()
{
    qApp->exit(777);
}

void MainWindow::time_out1()
{
    last->setText(QString::number(99-one_mine->flag_count));
    use_time->setText(QString::number(one_mine->time_count));
}
