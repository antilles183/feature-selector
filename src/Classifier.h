#pragma once
#include <vector>
#include "defs.h"
#include "Stopwatch.h"


class Classifier
{   

private:
    DataSet m_dataset;
    Stopwatch m_stopwatch;
    std::chrono::steady_clock::duration m_trainDuration;
    std::chrono::steady_clock::duration m_testDuration;

public:

    void train(const DataSet &trainingSet);

    double test(const std::vector<double> &unknown);

    double euclideanDistance(const std::vector<double> &v1,
                             const std::vector<double> &v2) const;

    int getTrainDuration() const;
    int getTestDuration() const;
    void printTrainingData() const;

};

