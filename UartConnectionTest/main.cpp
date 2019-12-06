#include "uart.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString name;
    for (auto x : QSerialPortInfo::availablePorts())
        name = x.portName();
    qDebug() << name;
    uart u;
    u.open(name, 9600);
    u.readData();

    return a.exec();
}
