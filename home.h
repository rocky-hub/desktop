#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QTextEdit>
#include <QSplitter>
#include "mysql.h"
#include <QDebug>
#include <QStringList>
#include <QList>
#include <QHeaderView>
#include <QVector>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QListWidget>
#include <QListWidgetItem>

class Home : public QWidget
{
    Q_OBJECT
public:
    explicit Home(QWidget *parent = nullptr);
    QWidget *centralWidget();
    QWidget *leftWidget();
    QWidget *rightWidget();
    QWidget *rightTopWidget();
    QWidget *rightButtomWidget();
    QWidget *tableWidget();
    QWidget *commandWidget();
    QWidget *mainWindow;
signals:

public slots:
    void tableSingleClicked(QListWidgetItem *item);
};

#endif // HOME_H
