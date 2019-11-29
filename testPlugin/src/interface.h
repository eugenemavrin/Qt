#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>

class Interface : public QObject
{
public:
    virtual ~Interface() = default;
    virtual QString getUpString(QString str) = 0;
};

Q_DECLARE_INTERFACE(Interface, "com.mysoft.Application.interface");
#endif // INTERFACE_H
