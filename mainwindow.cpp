#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(DataGenerator *dataGenerator, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dataGenerator_(dataGenerator) {
    ui->setupUi(this);
    connect(dataGenerator_, &DataGenerator::dataUpdated, this, &MainWindow::onDataUpdated);

    chart_ = new QChart();

    QSplineSeries *newSplineSeries = new QSplineSeries();
    updateSeries(*newSplineSeries);

    setChart(newSplineSeries);

    QChartView *chartView = new QChartView(chart_);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);

    setCentralWidget(chartView);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onDataUpdated() {
    qDebug() << "In onDataUpdated: ";
    updateChart();
}

void MainWindow::updateSeries(QSplineSeries &newSplineSeries) {
    for (int i = 0; i < dataGenerator_->getPackegesQuantity().size(); i++) {
        newSplineSeries.append(i, dataGenerator_->getPackegesQuantity().at(i));
    }
    dataGenerator_->printData();
}

void MainWindow::setChart(QSplineSeries *newSplineSeries) {
    chart_->setTitle("Трафик пакетов");
    chart_->legend()->hide();
    chart_->addSeries(newSplineSeries);

    chart_->createDefaultAxes();
    chart_->axes(Qt::Vertical).first()->setRange(0, MIN_YLENGHT);
    chart_->axes(Qt::Horizontal).first()->setRange(0, MAX_XLENGHT);
    QValueAxis *axisX = qobject_cast<QValueAxis*>(chart_->axes(Qt::Horizontal).first());
    axisX->setTickCount(11);
    axisX->setLabelFormat("%d");

    chart_->setVisible(true);
}

void MainWindow::updateChart() {
    chart_->removeAllSeries();
    QSplineSeries *newSplineSeries = new QSplineSeries();
    updateSeries(*newSplineSeries);

    setChart(newSplineSeries);

    qDebug() << "Chart size: " << chart_->series().size();
}
