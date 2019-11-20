#include "fileSystem.h"
#include <QFile>
#include <QFileInfo>

fileSystem::fileSystem()
{
    //this->readConfig();
    //this->writeConfig();
}

void fileSystem::readConfig()
{
    this->openfile();
    QByteArray config = this->fileHandle->readAll();
    this->fileHandle->close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(config, &jsonError));

    if (jsonError.error != QJsonParseError::NoError) {
        this->clear();
        qDebug() << "json error";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    qDebug() << jsonObj.value("host").toString();
}

void fileSystem::writeConfig(QJsonObject jsonObj)
{
    this->openfile();

    QByteArray config = this->fileHandle->readAll();
    if (!config.isEmpty()) {
        QJsonParseError jsonError;
        QJsonDocument existJsonDoc(QJsonDocument::fromJson(config, &jsonError));

        if (jsonError.error != QJsonParseError::NoError) {
            this->clear();
            qDebug() << "json error";
        } else {
            QJsonObject existJsonObj = existJsonDoc.object();
            qDebug() << existJsonObj << "exist json";
        }
    }

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);

    //qDebug() << jsonDoc.toJson();
    this->fileHandle->write(jsonDoc.toJson());
    this->fileHandle->close();
}

void fileSystem::openfile()
{
    this->fileHandle = new QFile("config.json");
    if (!this->fileHandle->open(QIODevice::ReadWrite)) {
        qDebug() << "file open error";
        return;
    }
}

void fileSystem::clear()
{
    this->fileHandle = new QFile("config.json");
    this->fileHandle->open(QIODevice::ReadWrite | QIODevice::Truncate);
    this->fileHandle->close();
}

fileSystem::~fileSystem()
{
    this->fileHandle->close();
}
