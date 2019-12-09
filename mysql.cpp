#include "mysql.h"

Mysql& Mysql::getInstance()
{
    static Mysql instance;

    return instance;
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

QVector<QString> Mysql::database()
{
    QString databaseSql = "show databases;";

    QSqlQuery query;
    query.exec(databaseSql);

    QVector<QString> databases;
    while (query.next()) {
        databases.append(query.value(0).toString());
    }

    return databases;
}

QVector<QString> Mysql::table(QString database)
{
    QString databaseSql = "use "+database+";";

    QSqlQuery query;
    query.exec(databaseSql);

    QString tableSql = "show tables;";
    query.exec(tableSql);

    QVector<QString> tables;
    while (query.next()) {
        tables.append(query.value(0).toString());
    }

    return tables;
}

QString Mysql::connectError()
{
    return dbHandle.lastError().text();
}
