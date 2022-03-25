#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QDebug>
#include <QIcon>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <QTableWidget>

enum Command {
    None,
    LeftSignalClick,
    LeftDoubleClickNum,
    RightSignalClick,
};

class MyTableWidget : public QTableWidget {
    Q_OBJECT
  public:
    MyTableWidget(QWidget* parent = 0);
    ~MyTableWidget();
    void setMineStyle(int, int, int);

  signals:
    void mouseEvent(const int x, const int y, Command);

  protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

  private:
    QIcon mine_pic;
    QIcon ques_pic;
    QIcon flag_pic;
};

#endif  // MYTABLEWIDGET_H
