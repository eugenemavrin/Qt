#ifndef PLUGIN_H
#define PLUGIN_H
#include "interface.h"
#include <QTimer>

class Plugin : public Interface
{
    Q_OBJECT
    Q_INTERFACES(Interface)
    Q_PLUGIN_METADATA(IID "com.mysoft.Application.interface" FILE "interface.json")
public:
    QString getUpString(QString str) override;
    explicit Plugin();
    void start() override;
    void stop();

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
