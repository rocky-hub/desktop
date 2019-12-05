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
    QWidget *leftWidget = new QWidget();
    leftWidget->setMaximumWidth(270);
    leftWidget->setMinimumWidth(150);

    this->mysqlHandle = new Mysql;
    this->mysqlHandle->databases();

    return leftWidget;
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
