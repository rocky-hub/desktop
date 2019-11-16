#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi(QMainWindow *mainWindow)
{
    if (mainWindow->objectName().isEmpty()) {
        mainWindow->setObjectName("main window");
    }

    mainWindow->setWindowIcon(QIcon(":/dbresource/database.ico"));
    mainWindow->setWindowTitle("rockySQL");
    mainWindow->resize(1500, 800);

    this->initMenubar(mainWindow);
    this->initToolbar(mainWindow);
}

void MainWindow::initMenubar(QMainWindow *mainWindow)
{
    menuBar = new QMenuBar(mainWindow);
    menuBar->setObjectName("menuBar");

    QMenu *fileMenu = new QMenu("File");
    QAction *newAction = new QAction("New");
    fileMenu->addAction(newAction);

    QMenu *toolMenu = new QMenu("Tool");

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(toolMenu);
    menuBar->setGeometry(0, 0, this->width(), 50);
    menuBar->setStyleSheet("background-color: #ccc");

    mainWindow->setMenuBar(menuBar);
}

void MainWindow::initToolbar(QMainWindow *mainWindow)
{
    //toolBar = new QToolBar(mainWindow);
}

void MainWindow::initLayout()
{

}

void MainWindow::loginLayout()
{
}



