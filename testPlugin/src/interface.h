#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
class Interface : public QObject
{
    Q_OBJECT
public:
    virtual ~Interface() = default;
    virtual QString getUpString(QString str) = 0;
    virtual void start() = 0;
signals:
    void dataReceived(float data);
};

Q_DECLARE_INTERFACE(Interface, "com.mysoft.Application.interface");
#endif // INTERFACE_H
