#include "uart.h"

#include <QSerialPortInfo>

uart::uart()
{
     QObject::connect(&m_port, &QSerialPort::readyRead, this, &uart::readData);
}

uart::~uart()
{
    close();
}

bool uart::open(const QString &name, const QVariant &parameter)
{
    m_port.setPortName(name);
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    bool serialFoundAndFree = false;
    foreach (QSerialPortInfo p, ports) {
        if (p.portName() == m_port.portName() && !p.isBusy())
            serialFoundAndFree = true;
    }

    if (!serialFoundAndFree) {
        qDebug() << "Port" << m_port.portName() << "not found or busy";
        return false;
    }
    m_port.setBaudRate(parameter.toInt());

    // Default UART settings
    m_port.setStopBits(QSerialPort::OneStop);
    m_port.setFlowControl(QSerialPort::NoFlowControl);
    m_port.setParity(QSerialPort::NoParity);

    if (!m_port.isOpen() && !m_port.open(QSerialPort::ReadWrite)) {
        qDebug() << m_port.errorString();
        return false;
    }
    else qDebug() << "asdlabs";
    emit connected();
    return true;
}

void uart::setParameter(const QString &key, const QVariant &value)
{
    if (key == QLatin1String("Port"))
        m_port.setPortName(value.toString());
    if (key == QLatin1String("BaudRate"))
        m_port.setBaudRate(value.toInt());
}

void uart::close()
{
    if(m_port.isOpen()) {
        m_port.close();
        emit disconnected();
    }
}

void uart::sendData(const char *data, qint64 length)
{
    if(m_port.isOpen()) {
        m_port.write(data, length);
        m_port.flush();
    }
}

bool uart::isOpened()
{
    return m_port.isOpen();
}

void uart::readData()
{
    qDebug() << m_port.readAll();
    emit dataReceived(m_port.readAll());
}

