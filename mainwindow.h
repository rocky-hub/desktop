#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QFormLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QWidget>
#include <QVBoxLayout>
#include <QSplitter>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include "filesystem.h"
#include "login.h"
#include "mysql.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupUi(QMainWindow *mainWindow);
    void initMenubar(QMainWindow *mainWindow);
    void initToolbar(QMainWindow *mainWindow);
    void initCentralWidget(QMainWindow *mainWindow);
    QWidget *loginLayout();
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QWidget *centralWidget;
    QGroupBox *formGroupBox;
    FileSystem *fileHandle;
    QWidget *loginUi;
    QWidget *home;
    Mysql *mysqlHandle;

signals:

public slots:
    void reloadCentralWidget();
};
#endif // MAINWINDOW_H
