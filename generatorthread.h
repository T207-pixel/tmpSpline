#ifndef GENERATORTHREAD_H
#define GENERATORTHREAD_H

#include <QThread>
#include <QDebug>
#include "datagenerator.h"

class GeneratorThread : public QThread {
    Q_OBJECT

public:
    GeneratorThread(DataGenerator *dataGenerator);
    void run() override;

private:
    DataGenerator *dataGenerator_;
};

#endif // GENERATORTHREAD_H
