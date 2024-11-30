#pragma once
#include <vector>


class Classifier
{   

private:
    std::vector<std::vector<double>> m_dataset;

public:
    Classifier(/* args */);
    ~Classifier();

    void train(const std::vector<std::vector<double>> &trainingSet);
    double test(std::vector<double> unknown);

    double euclideanDistance(const std::vector<double> &v1,
                             const std::vector<double> &v2);
    void showTraining() const;

};

