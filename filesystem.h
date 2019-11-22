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

class FileSystem
{
public:
    FileSystem();
    ~FileSystem();

    void openfile(QIODevice::OpenModeFlag mode);
    QJsonObject readConfig();
    void writeConfig(QJsonObject jsonObj);
    void clear();

    QFile *fileHandle;
};

#endif // FILE_H
