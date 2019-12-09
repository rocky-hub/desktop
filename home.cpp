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
    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->header()->setVisible(false);
    treeWidget->setMaximumWidth(250);
    treeWidget->setMinimumWidth(170);

    Mysql& mysqlHandle = Mysql::getInstance();
    QVector<QString> databases = mysqlHandle.database();

    for (int i = 0; i < databases.size(); ++i) {
        QTreeWidgetItem *treeDatabaseItem = new QTreeWidgetItem(treeWidget);
        treeDatabaseItem->setText(0, databases[i]);

        QVector<QString> tables = mysqlHandle.table(databases[i]);
        for (int j = 0; j < tables.size(); ++j) {
            QTreeWidgetItem *treeTableItem = new QTreeWidgetItem(treeDatabaseItem);
            treeTableItem->setText(0, tables[j]);
        }
    }

    return treeWidget;
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
    QTextEdit *rightButtomWidget = new QTextEdit("right bottom widegt");

    return rightButtomWidget;
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
