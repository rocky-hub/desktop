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

class fileSystem
{
public:
    fileSystem();
    ~fileSystem();

    void openfile();
    void readConfig();
    void writeConfig();

    QFile *fileHandle;
};

#endif // FILE_H
