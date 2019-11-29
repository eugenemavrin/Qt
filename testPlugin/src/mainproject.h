#ifndef MAINPROJECT_H
#define MAINPROJECT_H
#include <QtGlobal>
#include <QDebug>
#include <QCoreApplication>
#include <QPluginLoader>
#include <QDir>

#include "interface.h"

class MainProject : public QObject
{
public:
    void searchPlugin();
    void usePlugin();
private:
    Interface *plugin;
};

#endif // MAINPROJECT_H
