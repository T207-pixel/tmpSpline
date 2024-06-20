#include "datagenerator.h"

DataGenerator::DataGenerator() {
    packegesQuantity_.reserve(MAX_CONTAINER_SIZE);
    fillContainerWithData();
}

int DataGenerator::generateRandomValue() {
    return  QRandomGenerator::global()->bounded(MIN_VALUE, MAX_VALUE + 1);
}

void DataGenerator::fillContainerWithData() {
    for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {
        packegesQuantity_.push_back(generateRandomValue());
    }
}

void DataGenerator::updateLastValue() {
    packegesQuantity_.removeFirst();
    packegesQuantity_.push_back(generateRandomValue());
    emit dataUpdated();
}

void DataGenerator::printData() {
    qDebug() << "printData: ";
    for (int i : packegesQuantity_) {
        qDebug() << i << " ";
    }
}

const QList<int> &DataGenerator::getPackegesQuantity() const {
    return packegesQuantity_;
}
