#include "generatorthread.h"

GeneratorThread::GeneratorThread(DataGenerator *dataGenerator)
    : dataGenerator_(dataGenerator) {
}

void GeneratorThread::run() {
    while (true) {
        dataGenerator_->updateLastValue();
        qDebug() << dataGenerator_->getPackegesQuantity().back();
        QThread::sleep(1); // update in 30 seconds
    }
}
