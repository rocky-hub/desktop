#include "mysql.h"

Mysql::Mysql(QWidget *parent) : QWidget(parent)
{

}


bool Mysql::setConnect(QJsonObject jsonObj)
{
    dbHandle = QSqlDatabase::addDatabase("QMYSQL");
    dbHandle.setHostName(jsonObj.value("host").toString());
    dbHandle.setPort(jsonObj.value("port").toInt());
    dbHandle.setUserName(jsonObj.value("username").toString());
    dbHandle.setPassword(jsonObj.value("password").toString());

    if (!jsonObj.value("database").toString().isEmpty()) {
        dbHandle.setDatabaseName(jsonObj.value("database").toString());
    }

    return dbHandle.open();
}

void Mysql::setDatabase(QString database)
{
    QString databaseSql = "use "+database+";";

    QSqlQuery query;
    query.exec(databaseSql);
}

void Mysql::databases()
{
    qDebug() << dbInstances.isEmpty();

    QString databaseSql = "show databases;";

    QSqlQuery query;
    query.exec(databaseSql);

    while (query.next()) {
        qDebug() << query.value(0).toString();
    }
}

void Mysql::tables()
{
    qDebug() << "show tables";
    QString databaseSql = "use test;";

    QSqlQuery query;
    query.exec(databaseSql);

    QString tableSql = "show tables";
    query.exec(tableSql);

    while (query.next()) {
        qDebug() << query.value(0).toString();
    }
}

QString Mysql::connectError()
{
    return dbHandle.lastError().text();
}
