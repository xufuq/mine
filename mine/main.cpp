#include "mainwindow.h"
#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int e=a.exec();
    if(e==777)
    {
        QProcess::startDetached(a.applicationFilePath(),QStringList());
        qApp->exit();
    }

    return e;
}
