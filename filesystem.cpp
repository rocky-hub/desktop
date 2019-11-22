#include "filesystem.h"
#include <QFile>
#include <QFileInfo>

FileSystem::FileSystem()
{
    //this->readConfig();
    //this->writeConfig();
}

QJsonObject FileSystem::readConfig()
{
    this->openfile(QIODevice::ReadOnly);
    QByteArray config = this->fileHandle->readAll();
    this->fileHandle->close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(config, &jsonError));

    if (jsonError.error != QJsonParseError::NoError) {
        this->clear();
        qDebug() << "json error";
    }

    QJsonObject jsonObj = jsonDoc.object();

    return jsonObj;
}

void FileSystem::writeConfig(QJsonObject jsonObj)
{
    this->openfile(QIODevice::ReadOnly);

    QJsonObject configObj;
    QString name = jsonObj.value("name").toString();

    QByteArray config = this->fileHandle->readAll();
    this->fileHandle->close();

    if (!config.isEmpty()) {
        QJsonParseError jsonError;
        QJsonDocument existJsonDoc(QJsonDocument::fromJson(config, &jsonError));

        if (jsonError.error != QJsonParseError::NoError) {
            qDebug() << "json error";
        } else {
            configObj = existJsonDoc.object();

            if (configObj.contains(name)) {
                configObj.remove(name);
            }
        }
    }

    configObj.insert(name, jsonObj);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(configObj);

    this->openfile(QIODevice::WriteOnly);
    this->fileHandle->write(jsonDoc.toJson());
    this->fileHandle->close();
    this->fileHandle->destroyed();
}

void FileSystem::openfile(QIODevice::OpenModeFlag mode = QIODevice::ReadWrite)
{
    this->fileHandle = new QFile("config.json");
    if (!this->fileHandle->open(mode)) {
        qDebug() << "file open error";
        return;
    }
}

void FileSystem::clear()
{
    this->fileHandle = new QFile("config.json");
    this->fileHandle->open(QIODevice:: WriteOnly | QIODevice::Truncate);
    this->fileHandle->close();
}

FileSystem::~FileSystem()
{
    this->fileHandle->close();
}
