#include "simulator.h"
#include "printdata.h"
#include <QObject>
#include <QCoreApplication>

#include <signal.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Simulator s;
    PrintData p;
    s.start();
    QObject::connect(&s, &Simulator::dataReceived, &p, &PrintData::print);
    return a.exec();
}
