#include "plugin.h"
QString Plugin::getUpString(QString str)
{
    return str.toUpper();
}
Plugin::Plugin()
{
    m_timer.setInterval(m_msecInterval);
    m_timer.setSingleShot(false);
    QObject::connect(&m_timer, &QTimer::timeout, this, &Plugin::simulValue);
}

void Plugin::start()
{
    m_started = true;
    m_timer.start();
}

void Plugin::stop()
{
    m_timer.stop();
    m_started = false;
}

void Plugin::simulValue()
{
    GenerateSignal();
    emit dataReceived(m_curSimulHeightValue);
}

float Plugin::GenerateSignal() {
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
