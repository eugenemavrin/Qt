#include "sender.h"

Sender::Sender()
{

}

void Sender::start()
{
    emit dataReceived(182);
}
QString Sender::getUpString(QString x)
{
    return x;
}
