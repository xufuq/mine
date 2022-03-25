#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <mytablewidget.h>

#include <QMainWindow>
#include <QPoint>
#include <QQueue>
#include <QTableWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

#define ROW 16
#define COL 30
#define TOTAL 99

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
  public slots:
    void Reboot();
    void Init();
    void time_out();
    void clickEvent(const int, const int, Command);

  private:
    int my_rand();
    Ui::MainWindow* ui;
    QTimer* timer;
    int cur_num[ROW][COL];
    int real_num[ROW][COL];
    int time_count;
    int mine_count;
    int right_count;
    QQueue<QPoint> mine_que;
    QPoint axis;
};
#endif  // MAINWINDOW_H
