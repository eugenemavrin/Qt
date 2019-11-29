#include <QCoreApplication>
#include "mainproject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainProject m;
    m.searchPlugin();
    m.usePlugin();
    return a.exec();
}
