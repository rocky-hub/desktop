#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1200, 600);
    w.setWindowIcon(QIcon(":/dbresource/database.ico"));
    w.setWindowTitle("rockySQL");
    w.show();
    return a.exec();
}
