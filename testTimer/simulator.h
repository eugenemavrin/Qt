#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <QObject>
#include <QTimer>
#include <QDebug>

class Simulator : public QObject
{
    Q_OBJECT
public:
    explicit Simulator();

    bool start();
    void stop();

signals:
    void dataReceived(float data);

public slots:
    void simulValue();

private:
    bool m_started;

    QTimer m_timer;
    int m_msecInterval = 100;

    float GenerateSignal();
    float m_minSimulHeightValue = 1;
    float m_maxSimulHeightValue = 3;
    float m_delta = 0.1f;
    float m_curSimulHeightValue = 2;
    bool m_up = true;
};

#endif // SIMULATOR_H


