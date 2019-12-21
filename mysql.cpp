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

QSqlError Mysql::addConnection(const QString name, const QString driver, const QString host,
                               const QString user, const QString passwd, int port, const QString dbName)
{
    QSqlError error;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver, name);
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    db.setUserName(user);
    db.setPassword(passwd);

    if (!dbName.isNull()) {
        db.setDatabaseName(dbName);
    }

    if (!db.open()) {
        error = db.lastError();
        db = QSqlDatabase();
        QSqlDatabase::removeDatabase(name);
    }

    return error;
}

QSqlDatabase Mysql::currentDatabase() const
{
    return QSqlDatabase::database(activeConnection);
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

QVector<QString> Mysql::column(QString tableName)
{
    QString columnSql = "select COLUMN_NAME from information_schema.COLUMNS where TABLE_SCHEMA = :database: and TABLE_NAME = :tableName:";
    QSqlQuery query;
    query.prepare(columnSql);
    query.bindValue(0, currentDatabase);
    query.bindValue(1, tableName);
    query.exec();

    QVector<QString> columns;
    while (query.next()) {
        columns.append(query.value(0).toString());
    }

    return columns;
}

void Mysql::value()
{
    QString columnSql = "select COLUMN_NAME, DATA_TYPE from information_schema.COLUMNS where TABLE_SCHEMA = :database and TABLE_NAME = :table";

    QSqlQuery query;
    query.prepare(columnSql);
    query.bindValue(":database", currentDatabase);
    query.bindValue(":table", currenctTable);
    query.exec();

    qDebug() << query.lastError();

    QVector<QString> values;

    while (query.next()) {
        QVector<QString> name;
        QVector<QString> type;
        qDebug() << query.value("COLUMN_NAME").toString() << query.value("DATA_TYPE").toString();
    }
}

QString Mysql::connectError()
{
    return dbHandle.lastError().text();
}
