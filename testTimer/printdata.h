#ifndef PRINTDATA_H
#define PRINTDATA_H
#include <QObject>
#include <QDebug>

class PrintData : public QObject
{
    Q_OBJECT
public slots:
    void print(float data);
};

#endif // PRINTDATA_H
