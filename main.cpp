#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
    // 提高应用程序图标的清晰度
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
