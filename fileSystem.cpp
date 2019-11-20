#include "fileSystem.h"
#include <QFile>
#include <QFileInfo>

fileSystem::fileSystem()
{
    this->openfile();
    //this->readConfig();
    //this->writeConfig();
}

void fileSystem::readConfig()
{
    QByteArray config = this->fileHandle->readAll();
    this->fileHandle->close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(config, &jsonError));

    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "json error";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    qDebug() << jsonObj.value("host").toString();
}

void fileSystem::writeConfig(QJsonObject jsonObj)
{
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);

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

fileSystem::~fileSystem()
{
    this->fileHandle->close();
}
