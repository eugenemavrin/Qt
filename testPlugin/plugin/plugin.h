#ifndef PLUGIN_H
#define PLUGIN_H
#include "interface.h"

class Plugin : public Interface
{
    Q_OBJECT
    Q_INTERFACES(Interface)
    Q_PLUGIN_METADATA(IID "com.mysoft.Application.interface" FILE "interface.json")
public:
    QString getUpString(QString str);
};

#endif // PLUGIN_H
