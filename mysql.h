#ifndef MYSQL_H
#define MYSQL_H

#include <QWidget>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QJsonObject>
#include <QVector>
#include <QDebug>

class Mysql : public QWidget
{
    Q_OBJECT
public:
    explicit Mysql(QWidget *parent = nullptr);
    bool setConnect(QJsonObject jsonObj);
    void setDatabase(QString database);
    void tables();
    QString connectError();

    QSqlDatabase dbHandle;
    QVector<QString> dbInstances;

signals:

public slots:
};

#endif // MYSQL_H
