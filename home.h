#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "mysql.h"

class Home : public QWidget
{
    Q_OBJECT
public:
    explicit Home(QWidget *parent = nullptr);
    QWidget *setCentralWidget();
    QWidget *setLeftWidget();
    QWidget *setRightWidget();
    QWidget *setTableWidget();
    QWidget *setCommandWidget();
    Mysql *mysqlHandle;
signals:

public slots:
};

#endif // HOME_H
