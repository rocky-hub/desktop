#include "home.h"

Home::Home(QWidget *parent) : QWidget(parent)
{

}

QWidget *Home::centralWidget()
{
    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->setFrameStyle(QFrame::NoFrame);
    mainSplitter->setHandleWidth(3);
    mainSplitter->setChildrenCollapsible(false);
    mainSplitter->addWidget(this->leftWidget());

    QSplitter *rightSplitter = new QSplitter(Qt::Vertical, mainSplitter);

    rightSplitter->addWidget(this->rightTopWidget());
    rightSplitter->addWidget(this->rightButtomWidget());

    mainSplitter->addWidget(rightSplitter);

    return mainSplitter;
}

QWidget *Home::leftWidget()
{
    Mysql& mysqlHandle = Mysql::getInstance();
    QVector<QString> databases = mysqlHandle.database();

    QListWidget *listWidget = new QListWidget();
    listWidget->setMaximumWidth(270);
    listWidget->setMidLineWidth(170);

    QVector<QString> tables = mysqlHandle.table(mysqlHandle.currentDatabase);
    if (!mysqlHandle.currentDatabase.isEmpty()) {
        for (int j = 0; j < tables.size(); ++j) {
            listWidget->addItem(new QListWidgetItem(QIcon(":/resource/images/table-small-square.png"), tables[j]));
        }
    }

    return listWidget;
}

QWidget *Home::rightWidget()
{
    QWidget *obj = new QWidget();

    return obj;
}

QWidget *Home::rightTopWidget()
{
    QTextEdit *rightTopWidget = new QTextEdit("top right widget");

    return rightTopWidget;

}

QWidget *Home::rightButtomWidget()
{
    QTableWidget *tableWidget = new QTableWidget(10, 5);
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->setItem(0,0,new QTableWidgetItem("Jan"));
    tableWidget->setItem(1,0,new QTableWidgetItem("Feb"));
    tableWidget->setItem(2,0,new QTableWidgetItem("Mar"));

    return tableWidget;
}

QWidget *Home::tableWidget()
{
    QWidget *obj = new QWidget();

    return obj;
}

QWidget *Home::commandWidget()
{
    QWidget *obj = new QWidget();

    return obj;
}
