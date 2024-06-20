#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(DataGenerator *dataGenerator, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dataGenerator_(dataGenerator) {
    ui->setupUi(this);
    connect(dataGenerator_, &DataGenerator::dataUpdated, this, &MainWindow::onDataUpdated);

    chart_ = new QChart();
    chartView_ = new QChartView(chart_);

    setChart();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onDataUpdated() {
    qDebug() << "In onDataUpdated: ";

    updateChart();

    chartView_->setRenderHint(QPainter::Antialiasing);
    chartView_->setVisible(true);
    chartView_->repaint();

    setCentralWidget(chartView_);

}

void MainWindow::updateSeries(QSplineSeries &newSplineSeries) {
    for (int i = 0; i < dataGenerator_->getPackegesQuantity().size(); i++) {
        newSplineSeries.append(i, dataGenerator_->getPackegesQuantity().at(i));
    }
    dataGenerator_->printData();
}

void MainWindow::setChart() {
    chart_->legend()->hide();
    chart_->setTheme(QChart::ChartTheme::ChartThemeDark);
    chart_->createDefaultAxes();

    // Создаем вертикальную ось, если она отсутствует
    QValueAxis *verticalAxis = new QValueAxis(chart_);
    verticalAxis->setRange(0, MIN_YLENGHT);
    chart_->addAxis(verticalAxis, Qt::AlignLeft);

    // Создаем горизонтальную ось, если она тоже отсутствует
    QValueAxis *horizontalAxis = new QValueAxis(chart_);
    horizontalAxis->setRange(0, MAX_XLENGHT);
    chart_->addAxis(horizontalAxis, Qt::AlignBottom);

    chart_->axes(Qt::Vertical).first()->setRange(0, MIN_YLENGHT);
    chart_->axes(Qt::Horizontal).first()->setRange(0, MAX_XLENGHT);
    chart_->setVisible(true);
}

void MainWindow::updateChart() {
    chart_->removeAllSeries();
    QSplineSeries *newSplineSeries = new QSplineSeries();
    updateSeries(*newSplineSeries);
    chart_->addSeries(newSplineSeries);
    qDebug() << "Chart size: " << chart_->series().size();
}
