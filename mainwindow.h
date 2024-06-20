#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtCharts>

#include "datagenerator.h"
#include "generatorthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    static const int MAX_XLENGHT = 100;
    static const int MIN_YLENGHT = 100;

public:
    MainWindow(DataGenerator *dataGenerator, QWidget *parent = nullptr);
    ~MainWindow();

private:
    void updateSeries(QSplineSeries &newSplineSeries);
    void setChart();
    void updateChart();
    Ui::MainWindow *ui;
    DataGenerator *dataGenerator_;
    QChart *chart_;
    QChartView *chartView_;

private slots:
    void onDataUpdated();
};
#endif // MAINWINDOW_H
