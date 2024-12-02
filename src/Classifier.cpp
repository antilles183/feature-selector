#include "Classifier.h"
#include <iomanip>
#include <iostream>
#include <cfloat>
#include <cmath>



/*******************************************************************************
 * @brief 
 * 
 * @param trainingSet 
*******************************************************************************/
void Classifier::train(const DataSet &trainingSet)
{
    m_stopwatch.start();

    // GUARD: bad dataset
    if (!trainingSet.size()) {
        std::cerr << "\nERROR: Classifier::train()\n";
        exit(EXIT_FAILURE);
    }

    m_dataset = trainingSet;

    m_stopwatch.stop();
    m_trainDuration = m_stopwatch.duration();

}



/*******************************************************************************
 * @brief 
 * 
 * @param unknown 
 * @return double 
*******************************************************************************/
double Classifier::test(const std::vector<double> &unknown)
{
    // GUARDS
    if(!m_dataset.size()) {
        std::cout << "ERROR: test(): No training data\n";
        exit(EXIT_FAILURE);
    }

    if(m_dataset.at(0).size() != unknown.size()) {
        std::cout << "ERROR: test(): size mismatch\n";
        exit(EXIT_FAILURE);
    }

    m_stopwatch.start();
    // std::cout << "testing...";

    // local declarations
    unsigned records = m_dataset.size();
    unsigned features = m_dataset.at(0).size();
    double distance;
    double minDistance = DBL_MAX;
    DataSet nn;
    double prediction;

    // traverse training data keeping track of nearest neighbor
    for (unsigned record = 0; record < records; record++) {

        distance = euclideanDistance( m_dataset.at(record), unknown );

        if (distance < minDistance) {
            nn.clear();
            nn.push_back(m_dataset.at(record));
            minDistance = distance;
        }
        else if (distance == minDistance)
        {
            nn.push_back(m_dataset.at(record));
        }
    }

    // ERROR TEST: no neigbors means somethings wrong 
    if (nn.empty()) {
        std::cout << "ERROR: test(): No nearest neighbor\n";
        exit(EXIT_FAILURE);
    }

    // TODO: ask how to handle equidistance neigbors. Using random selection
    std::vector<double> neighbor = nn.at( rand() % nn.size() );

    // OUTPUT: prints nearest neighbor data to console
    if(false) {
        std::cout << "n-neighbor: " << neighbor.at(0) << '\t';
        for (unsigned feature = 1; feature < features; feature++)
            std::cout << std::setw(8) << neighbor.at(feature) << '\t';
        std::cout << "\n";
    }

    m_stopwatch.stop();
    m_testDuration = m_stopwatch.duration();
    // std::cout << "complete (" << m_stopwatch.getMicroseconds() << " microseconds)\n";

    return neighbor.at(0);
}



/*******************************************************************************
 * @brief 
 * 
 * @param v1 
 * @param v2 
 * @return double 
*******************************************************************************/
double Classifier::euclideanDistance(const std::vector<double> &v1,
                                     const std::vector<double> &v2) const
{
    // GUARD: unequal vector sizes
    if (v1.size() != v2.size()) {
        std::cout << "ERROR: euclideanDistance()";
        exit(EXIT_FAILURE);
    }

    // d = sqrt( (a1-b1)^2 + (a2-b2)^2 + ... )
    double squaredSum{0};
    for (unsigned feature = 1; feature < v1.size(); feature++)
        squaredSum += std::pow( v1.at(feature) - v2.at(feature) , 2);

    return std::sqrt(squaredSum);
}



/*******************************************************************************
 * @brief 
 * 
 * @return int 
*******************************************************************************/
int Classifier::getTrainDuration() const
{
    return std::chrono::duration_cast<std::chrono::microseconds>( m_trainDuration ).count();
}



/*******************************************************************************
 * @brief 
 * 
 * @return int 
*******************************************************************************/
int Classifier::getTestDuration() const
{
    return std::chrono::duration_cast<std::chrono::microseconds>( m_testDuration ).count();
}



/*******************************************************************************
 * @brief 
 * 
*******************************************************************************/
void Classifier::printTrainingData() const 
{
    // GUARD
    if(!m_dataset.size()) {
        std::cout << "ERROR: printTrainingData(): No training data\n";
        exit(EXIT_FAILURE);
    }

    // local declarations
    unsigned records = m_dataset.size();
    unsigned features = m_dataset.at(0).size();

    // output training data
    std::cout << std::setprecision(8);
    for(unsigned record = 0; record < records; record++) {

        std::cout << record << " : ";
        std::cout << m_dataset.at(record).at(0) << '\t';

        for(unsigned feature = 1; feature < features; feature++)
            std::cout << std::setw(8) << m_dataset.at(record).at(feature) << '\t';

        std::cout << '\n';
    }
}
