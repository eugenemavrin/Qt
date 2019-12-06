#ifndef UART_H
#define UART_H
#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QObject>
class uart : public QObject
{
    Q_OBJECT
public:
   uart();
    ~uart();
    bool open(const QString &name, const QVariant &parameter = QVariant());
    void close();
    bool isOpened();
    void setParameter(const QString &key, const QVariant &value);
    void readData();
    void sendData(const char *data, qint64 length);

signals:
    void dataReceived(const QByteArray &data);
    void connected();
    void disconnected();
private:
    QSerialPort m_port;
};
#endif // UART_H
