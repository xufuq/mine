#ifndef FOR_EMIT_H
#define FOR_EMIT_H

#include <QObject>

class For_Emit : public QObject
{
    Q_OBJECT
public:
    explicit For_Emit(QObject *parent = nullptr);

signals:
    void SendData(int,int,int);
public slots:
};

#endif // FOR_EMIT_H
