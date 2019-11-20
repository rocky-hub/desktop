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
#include "fileSystem.h"
#include "login.h"

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
    fileSystem *fileHandle;
    QWidget *loginUi;

};
#endif // MAINWINDOW_H
