#include "mainproject.h"

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
    QString teststring = "asdlabs";
    qDebug() << plugin->getUpString(teststring);
}
