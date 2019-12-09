#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QTextEdit>
#include <QSplitter>
#include "mysql.h"
#include <QDebug>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QList>
#include <QHeaderView>
#include <QVector>

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
};

#endif // HOME_H
