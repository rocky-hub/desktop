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

    QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(treeWidget);
    treeWidgetItem->setText(0, "111");

    QTreeWidgetItem *treeWidgetItem1 = new QTreeWidgetItem(treeWidget);
    treeWidgetItem1->setText(0, "222");

    QTreeWidgetItem *treeWidgetItem3 = new QTreeWidgetItem(treeWidgetItem1);
    treeWidgetItem3->setText(0,"222_222");

    Mysql& mysqlHandle = Mysql::getInstance();
    mysqlHandle.databases();

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
