#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DataGenerator datagenerator;
    GeneratorThread generatorThread(&datagenerator);
    generatorThread.start();

    MainWindow w(&datagenerator);
    w.show();
    return a.exec();
}
