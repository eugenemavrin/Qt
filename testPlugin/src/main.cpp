#include <QCoreApplication>
#include "mainproject.h"
#include "printdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainProject m;
    PrintData p;
    m.searchPlugin();
    QObject::connect(&m, &MainProject::test, &p, &PrintData::print);
    QObject::connect(m.plugin, &Interface::dataReceived, &p, &PrintData::print);
    QObject::connect(m.m_sender, &Sender::dataReceived, &p, &PrintData::print);
    m.usePlugin();
    qDebug() << m.plugin->getUpString("teststring_asdlabs");
    return a.exec();
}
