#ifndef MAINPROJECT_H
#define MAINPROJECT_H
#include <QtGlobal>
#include <QDebug>
#include <QCoreApplication>
#include <QPluginLoader>
#include <QDir>

#include "interface.h"
#include "sender.h"


class MainProject : public QObject
{
    Q_OBJECT
public:
    explicit MainProject();
    void searchPlugin();
    void usePlugin();
    Interface *plugin = nullptr;
    Sender *m_sender = nullptr;
signals:
    void test(float data);
private:

};

#endif // MAINPROJECT_H
