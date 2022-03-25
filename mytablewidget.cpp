#include "mytablewidget.h"

MyTableWidget::MyTableWidget(QWidget* parent) : QTableWidget(parent) {
    mine_pic = QIcon(QPixmap(":/icon/mine.png").scaled(30, 30));
    ques_pic = QIcon(QPixmap(":/icon/ques.jpg").scaled(30, 30));
    flag_pic = QIcon(QPixmap(":/icon/flag.png").scaled(30, 30));
    setFont(QFont("Microsoft YaHei", 12));
}

MyTableWidget::~MyTableWidget() {}

void MyTableWidget::mousePressEvent(QMouseEvent* event) {
    setCurrentIndex(QModelIndex());
    QTableWidget::mousePressEvent(event);
    QModelIndex index = currentIndex();
    if (index.row() < 0 || index.column() < 0) {
        return;
    }
    if (event->button() == Qt::LeftButton) {
//        qDebug() << "left: " << index.row() << " " << index.column() << endl;
        emit mouseEvent(index.row(), index.column(), Command::LeftSignalClick);
    } else if (event->button() == Qt::RightButton) {
//        qDebug() << "right: " << index.row() << " " << index.column() << endl;
        emit mouseEvent(index.row(), index.column(), Command::RightSignalClick);
    }
//    qDebug() << index.row() << " " << index.column() << endl;
}

void MyTableWidget::mouseDoubleClickEvent(QMouseEvent* event) {
    setCurrentIndex(QModelIndex());
    QTableWidget::mousePressEvent(event);
    QModelIndex index = currentIndex();
    if (index.row() < 0 || index.column() < 0) {
        return;
    }
    if (event->button() == Qt::LeftButton) {
        emit mouseEvent(index.row(), index.column(), Command::LeftDoubleClickNum);
    }
}

void MyTableWidget::setMineStyle(int x, int y, int value) {
//    qDebug() << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << ": single clicked " << x << " " << y << endl;
    QTableWidgetItem* item = new QTableWidgetItem();
    if (item == nullptr) {
//        qDebug() << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << "nullptr item " << endl;
        return;
    }
    if (value == 100) {
        QPushButton button;
        item->setIcon(button.icon());
    } else if (value == -1) {
        item->setIcon(mine_pic);
    } else if (value == -2) {
        item->setIcon(flag_pic);
    } else if (value == -3) {
        item->setIcon(ques_pic);
    } else if (value == 0) {
        item->setBackground(QBrush(Qt::white));
    } else {
        item->setBackground(QBrush(Qt::gray));
        //        setStyleSheet("background-color: rgb(192,192,192)");
        switch (value) {
            case 1: item->setTextColor(QColor(176, 23, 31)); break;
            case 2: item->setTextColor(QColor(0, 0, 255)); break;
            case 3: item->setTextColor(QColor(255, 0, 0)); break;
            case 4: item->setTextColor(QColor(128, 42, 42)); break;
            case 5: item->setTextColor(QColor(163, 148, 128)); break;
            case 6: item->setTextColor(QColor(0, 0, 0)); break;
            case 7: item->setTextColor(QColor(61, 145, 64)); break;
            case 8: item->setTextColor(QColor(160, 32, 240)); break;
            default: break;
        }
        item->setText(QString::number(value));
    }
    setItem(x, y, item);
//    qDebug() << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << ": single clicked " << x << " " << y << endl;
}
