#include "mainproject.h"
MainProject::MainProject() : m_sender(new Sender())
{
}
void MainProject::searchPlugin()
{
    QStringList listFiles;
    QDir dir(QCoreApplication::applicationDirPath() + "/Plugins/");
    qDebug() << QCoreApplication::applicationDirPath();
    if(dir.exists())
              listFiles = dir.entryList(QStringList("*"), QDir::Files);
    else
        qCritical() << "dir Plugins not found";
    for(QString str: listFiles) {
        QPluginLoader loader(dir.absolutePath() + "/" +str);
        QObject *pobj = nullptr;
        pobj = qobject_cast<QObject*>(loader.instance());
        if(!pobj)
            continue;
        plugin = nullptr;
        plugin = qobject_cast<Interface *>(pobj);
        if (plugin) {
            qDebug() << "Plugin is finded!";
            break;
        }
    }
}

void MainProject::usePlugin()
{
    emit test(1101);
    QString teststring = "asdlabs";
    qDebug() << plugin->getUpString(teststring);
    m_sender->start();
    plugin->start();
    QObject::connect(plugin, &Interface::dataReceived, this, &MainProject::test);
}
