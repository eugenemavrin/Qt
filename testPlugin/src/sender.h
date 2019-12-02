#ifndef SENDER_H
#define SENDER_H
#include "interface.h"

class Sender : public Interface
{
    Q_OBJECT
public:
    explicit Sender();
    QString getUpString(QString str) override;
    void start() override;
};
#endif // SENDER_H
