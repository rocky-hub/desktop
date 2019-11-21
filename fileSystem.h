#ifndef FILE_H
#define FILE_H

#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonValue>
#include <QMap>

class fileSystem
{
public:
    fileSystem();
    ~fileSystem();

    void openfile(QIODevice::OpenModeFlag mode);
    void readConfig();
    void writeConfig(QJsonObject jsonObj);
    void clear();

    QFile *fileHandle;
};

#endif // FILE_H
