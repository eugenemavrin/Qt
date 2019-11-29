#include "simulator.h"


Simulator::Simulator()
{
    m_timer.setInterval(m_msecInterval);
    m_timer.setSingleShot(false);
    QObject::connect(&m_timer, &QTimer::timeout, this, &Simulator::simulValue);
}

bool Simulator::start()
{
    m_started = true;
    m_timer.start();
    return true;
}

void Simulator::stop()
{
    m_timer.stop();
    m_started = false;
}

void Simulator::simulValue()
{
    GenerateSignal();
    emit dataReceived(m_curSimulHeightValue);
}

float Simulator::GenerateSignal() {
    if (m_up) {
        m_curSimulHeightValue += m_delta;
        if (m_curSimulHeightValue > m_maxSimulHeightValue - m_delta)
            m_up = false;
    } else {
        m_curSimulHeightValue -= m_delta;
        if (m_curSimulHeightValue < m_minSimulHeightValue)
            m_up = true;
    }

    return m_curSimulHeightValue;
}
