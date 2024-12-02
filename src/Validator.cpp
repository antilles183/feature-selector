#include "Validator.h"
#include <random>
#include <iomanip>



/*******************************************************************************
 * @brief 
 * 
 * @param featureSet 
 * @param dataSet 
 * @param classifier 
 * @return double 
*******************************************************************************/
double Validator::evaluate(const FeatureSet& featureSet,
                           const DataSet& dataSet,
                           Classifier& classifier)
{
    // TODO: Guard against bad feature indices
    // TODO: Guard against empty dataSet
    // TODO: may use a different technique of zeroing out unused features

    Stopwatch stopwatch;
    stopwatch.start();
    std::cout << "evaluate...\n\n";

    // local declarations
    DataSet dataSubset;
    DataSet traingingSet;
    DataSet::const_iterator it;
    std::vector<double> testInstance;
    double correct{0};
    double prediction{-1};

    // build dataSubset
    //  this is dataSet only with featureSet features (dataSet - !featureSet)
    for (unsigned record = 0; record < dataSet.size(); record++)
    {
        // create record and push class label
        dataSubset.push_back(std::vector<double>());
        dataSubset.at(record).push_back( dataSet.at(record).at(0) );

        // push features from featureSet
        for (FeatureSet::iterator fit = featureSet.begin(); fit != featureSet.end(); fit++)
            dataSubset.at(record).push_back( dataSet.at(record).at(*fit) );
    }

    // traverse dataSubset
    for (it = dataSubset.begin(); it != dataSubset.end(); it++)
    {
        // reset
        // TODO: clear() may be unnecessary
        traingingSet.clear();                         // unnecessary?
        testInstance.clear();
        traingingSet = dataSubset;

        // get and remove test instance from training set
        testInstance = *it;
        traingingSet.erase( traingingSet.begin() + (it - dataSubset.begin()) );

        // train, predict, tally for accuracy
        classifier.train(traingingSet);
        prediction = classifier.test(testInstance);

        if ( prediction == (*it).at(0) )
            correct++;

        
        // OUTPUT: trace to console. just printing first & every 10
        int iteration = (it - dataSubset.begin()) + 1;
        if (iteration == 1 || !(iteration % 10)) {
            std::cout << "(" << prediction << " ?= " << (*it).at(0) << ")    ";
            std::cout << "accuracy at " << std::setw(3) << (it - dataSubset.begin()) + 1;
            std::cout << " == " << std::setw(2) << correct << "/" << std::setw(3) << (it - dataSubset.begin()) + 1 ;
            std::cout << " == " << std::setw(8) << correct / ((it - dataSubset.begin()) + 1) << "    ";
            std::cout << "(train " << std::setw(2) << classifier.getTrainDuration() << " microseconds)\t";
            std::cout << "(test "  << std::setw(2) << classifier.getTestDuration()  << " microseconds)";
            std::cout << '\n';
        }
    }

    stopwatch.stop();
    std::cout << "\nevaluate...complete (" << stopwatch.getMicroseconds() << " microseconds)\n\n";

    return correct / dataSet.size();

}



/*******************************************************************************
 * @brief 
 * 
 * @param node 
 * @return double 
*******************************************************************************/
double Validator::random(const Node& node)
{
    // this is a stub. do nothing with node just return random percentage
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    return dis(gen);

}



/*******************************************************************************
 * @brief 
 * 
 * @return double 
*******************************************************************************/
double Validator::random()
{
    Node node;
    return random(node);

}