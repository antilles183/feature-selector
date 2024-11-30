#include "../src/Classifier.h"
#include <iostream>
#include <iomanip>

int test_Classifier() {

    Classifier classifier;
    std::vector<std::vector<double>> trainingSet;
    srand(66);

    unsigned records = 10;
    unsigned features = 4;

    // build training data
    for(unsigned record = 0; record < records; record++) {
        trainingSet.push_back(std::vector<double>());
        trainingSet.at(record).push_back(static_cast<double>(rand() % 2));
        for (unsigned feature = 1; feature < features; feature++)
            trainingSet.at(record).push_back(static_cast<double>(rand() % 16000 * 0.001));
    }


    // train
    classifier.train(trainingSet);



    std::vector<double> testInstance1;
    testInstance1.push_back(static_cast<double>(-1));
    for (unsigned feature = 1; feature < features; feature++)
        testInstance1.push_back(static_cast<double>(rand() % 16000 * 0.001));


    double predict1 = classifier.test(testInstance1);

    std::cout << "SHOW TRAINING:\n";
    classifier.showTraining();
    
    std::cout << "\ntestInstance1: " << testInstance1.at(0) << '\t';
    for (unsigned feature = 1; feature < features; feature++)
        std::cout << std::setw(8) << testInstance1.at(feature) << '\t';
    std::cout << "\n\tprediction ===> " << predict1 << '\n';



    std::cout << "\n";

    return 0;
}