#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->reStart->setStyleSheet("color: rgb(255,0,0);background-color: rgb(192,192,192)");
    ui->mine_count->setStyleSheet("color: rgb(255,0,0);background-color: rgb(0,0,0)");
    ui->time->setStyleSheet("color: rgb(255,0,0);background-color: rgb(0,0,0)");
    ui->tableWidget->setStyleSheet("color: rgb(255,0,0);background-color: rgb(192,192,192)");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(time_out()));
    connect(ui->reStart, SIGNAL(clicked(bool)), this, SLOT(Reboot()));
    connect(ui->tableWidget, SIGNAL(mouseEvent(const int, const int, Command)), this,
            SLOT(clickEvent(const int, const int, Command)));
    Init();
    timer->start(1000);
}

void MainWindow::time_out() {
    ui->mine_count->setText(QString::number(mine_count));
    ui->time->setText(QString::number(++time_count));
}

void MainWindow::clickEvent(const int x, const int y, Command cmd) {
    //    qDebug() << __FILE__ <<  " " << __FUNCTION__ << " " <<  __LINE__  << ": " << x << " " << y << endl;
    if (cmd == Command::RightSignalClick) {
        switch (cur_num[x][y]) {
            case 100:
                cur_num[x][y] = -2;
                ui->tableWidget->setMineStyle(x, y, -2);
                --mine_count;
                break;
            case -2:
                cur_num[x][y] = -3;
                ui->tableWidget->setMineStyle(x, y, -3);
                ++mine_count;
                break;
            case -3:
                cur_num[x][y] = 100;
                ui->tableWidget->setMineStyle(x, y, 100);
                break;
            default: break;
        }
    } else if (cmd == Command::LeftSignalClick && cur_num[x][y] == 100) {
        //        qDebug() << __FILE__ <<  " " << __FUNCTION__ << " " <<  __LINE__  << ": single clicked " <<
        //        real_num[x][y] << " " << x << " " << y << endl;
        switch (real_num[x][y]) {
            case -1:
                ui->tableWidget->setMineStyle(x, y, -1);
                cur_num[x][y] = -1;
                ui->tableWidget->setDisabled(true);
                QMessageBox::information(this, QString::fromLocal8Bit("info"), QString::fromLocal8Bit("game over"));
                break;
            case 0:
                ui->tableWidget->setMineStyle(x, y, 0);
                cur_num[x][y] = 0;
                --right_count;

                if (x - 1 >= 0 && y - 1 >= 0) {
                    axis.setX(x - 1);
                    axis.setY(y - 1);
                    mine_que.push_back(axis);
                }
                if (x - 1 >= 0) {
                    axis.setX(x - 1);
                    axis.setY(y);
                    mine_que.push_back(axis);
                }
                if (x - 1 >= 0 && y + 1 < COL) {
                    axis.setX(x - 1);
                    axis.setY(y + 1);
                    mine_que.push_back(axis);
                }
                if (y - 1 >= 0) {
                    axis.setX(x);
                    axis.setY(y - 1);
                    mine_que.push_back(axis);
                }
                if (y + 1 < COL) {
                    axis.setX(x);
                    axis.setY(y + 1);
                    mine_que.push_back(axis);
                }
                if (x + 1 < ROW && y - 1 >= 0) {
                    axis.setX(x + 1);
                    axis.setY(y - 1);
                    mine_que.push_back(axis);
                }
                if (x + 1 < ROW) {
                    axis.setX(x + 1);
                    axis.setY(y);
                    mine_que.push_back(axis);
                }
                if (x + 1 < ROW && y + 1 < COL) {
                    axis.setX(x + 1);
                    axis.setY(y + 1);
                    mine_que.push_back(axis);
                }
                break;
            default:
                --right_count;
                ui->tableWidget->setMineStyle(x, y, real_num[x][y]);
                cur_num[x][y] = real_num[x][y];
                break;
        }
    } else if (cmd == Command::LeftDoubleClickNum && cur_num[x][y] != 100 && cur_num[x][y] > 0) {
        QQueue<QPoint> double_que;
        int cur_mine_count = 0;
        if (x - 1 >= 0 && y - 1 >= 0) {
            axis.setX(x - 1);
            axis.setY(y - 1);
            double_que.push_back(axis);
            if (cur_num[x - 1][y - 1] == -2) {
                ++cur_mine_count;
            }
        }
        if (x - 1 >= 0) {
            axis.setX(x - 1);
            axis.setY(y);
            double_que.push_back(axis);
            if (cur_num[x - 1][y] == -2) {
                ++cur_mine_count;
            }
        }
        if (x - 1 >= 0 && y + 1 < COL) {
            axis.setX(x - 1);
            axis.setY(y + 1);
            double_que.push_back(axis);
            if (cur_num[x - 1][y + 1] == -2) {
                ++cur_mine_count;
            }
        }
        if (y - 1 >= 0) {
            axis.setX(x);
            axis.setY(y - 1);
            double_que.push_back(axis);
            if (cur_num[x][y - 1] == -2) {
                ++cur_mine_count;
            }
        }
        if (y + 1 < COL) {
            axis.setX(x);
            axis.setY(y + 1);
            double_que.push_back(axis);
            if (cur_num[x][y + 1] == -2) {
                ++cur_mine_count;
            }
        }
        if (x + 1 < ROW && y - 1 >= 0) {
            axis.setX(x + 1);
            axis.setY(y - 1);
            double_que.push_back(axis);
            if (cur_num[x + 1][y - 1] == -2) {
                ++cur_mine_count;
            }
        }
        if (x + 1 < ROW) {
            axis.setX(x + 1);
            axis.setY(y);
            double_que.push_back(axis);
            if (cur_num[x + 1][y] == -2) {
                ++cur_mine_count;
            }
        }
        if (x + 1 < ROW && y + 1 < COL) {
            axis.setX(x + 1);
            axis.setY(y + 1);
            double_que.push_back(axis);
            if (cur_num[x + 1][y + 1] == -2) {
                ++cur_mine_count;
            }
        }
        if (cur_mine_count == real_num[x][y]) {
            while (!double_que.empty()) {
                axis = double_que.front();
                double_que.pop_front();
                mine_que.push_back(axis);
            }
        }
    }
    while (!mine_que.empty()) {
        axis = mine_que.front();
        mine_que.pop_front();
        clickEvent(axis.x(), axis.y(), Command::LeftSignalClick);
    }
    if (right_count == 0) {
        // 成功，返回信息
        QMessageBox::information(this, QString::fromLocal8Bit("info"), QString::fromLocal8Bit("succeed"));
    }
}

void MainWindow::Init() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            real_num[i][j] = 0;
            cur_num[i][j] = 100;
        }
    }

    int count = 0;
    while (count < TOTAL) {
        int randVal = my_rand();
        int x = randVal / 30;
        int y = randVal % 30;
        if (real_num[x][y] == 0) {
            real_num[x][y] = -1;
            count++;
        }
    }
    right_count = ROW * COL - TOTAL;
    mine_count = TOTAL;
    for (int x = 0; x < ROW; ++x) {
        for (int y = 0; y < COL; ++y) {
            if (real_num[x][y] == -1) {
                continue;
                ;
            }
            if (x - 1 >= 0 && y - 1 >= 0 && real_num[x - 1][y - 1] == -1) {
                ++real_num[x][y];
            }
            if (x - 1 >= 0 && real_num[x - 1][y] == -1) {
                ++real_num[x][y];
            }
            if (x - 1 >= 0 && y + 1 < COL && real_num[x - 1][y + 1] == -1) {
                ++real_num[x][y];
            }
            if (y - 1 >= 0 && real_num[x][y - 1] == -1) {
                ++real_num[x][y];
            }
            if (y + 1 < COL && real_num[x][y + 1] == -1) {
                ++real_num[x][y];
            }
            if (x + 1 < ROW && y - 1 >= 0 && real_num[x + 1][y - 1] == -1) {
                ++real_num[x][y];
            }
            if (x + 1 < ROW && real_num[x + 1][y] == -1) {
                ++real_num[x][y];
            }
            if (x + 1 < ROW && y + 1 < COL && real_num[x + 1][y + 1] == -1) {
                ++real_num[x][y];
            }
        }
    }
}

int MainWindow::my_rand() {
    int num = rand() % (ROW * COL);
    return num;
}

void MainWindow::Reboot() {
    ui->tableWidget->clear();
    Init();
    time_count = 0;
    ui->tableWidget->setEnabled(true);
}

MainWindow::~MainWindow() { delete ui; }
