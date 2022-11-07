#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("TarasGit");
    QCoreApplication::setApplicationName("Qt Conan Printer");
    MainWindow w;
    w.show();
    return a.exec();
}
