#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QObject>
#include <QRandomGenerator>
#include <QList>
#include <QDebug>
#include <iostream>

class DataGenerator : public QObject {
    Q_OBJECT

    const static int MAX_VALUE = 10;
    const static int MIN_VALUE = 0;
    const static int EMPTY_SIZE = 0;
    const static int MAX_CONTAINER_SIZE = 10; // количество отрезков на графике (10 делений)

public:
    DataGenerator();
    static int generateRandomValue();
    void fillContainerWithData();
    void updateLastValue();
    const QList<int> &getPackegesQuantity() const;
    void printData();

signals:
    void dataUpdated();

private:
    int currentQuantity_ = EMPTY_SIZE;
    QList<int> packegesQuantity_;
};

#endif // DATAGENERATOR_H
