#include "Classifier.h"
#include <iomanip>
#include <iostream>
#include <cfloat>
#include <cmath>


Classifier::Classifier(/* args */)
{
}

Classifier::~Classifier()
{
}


void Classifier::train(const std::vector<std::vector<double>> &trainingSet) 
{
    // GUARD: bad dataset
    if (!trainingSet.size()) {
        std::cerr << "ERROR: Classifier::train()\n";
        exit(EXIT_FAILURE);
    }

    m_dataset.clear();

    unsigned records = trainingSet.size();
    unsigned features = trainingSet.at(0).size();

    for (unsigned record = 0; record < records; record++) {

        m_dataset.push_back(std::vector<double>());
        for (unsigned feature = 0; feature < features; feature++) {
            m_dataset.at(record).push_back(trainingSet.at(record).at(feature));

        }
    }

}


/*******************************************************************************
 * @brief 
 * 
 * @param unknown 
 * @return double 
*******************************************************************************/
double Classifier::test(std::vector<double> unknown)
{
    // test instance parameter has 1 less field than m_dataset because unlabeled

    // GUARD
    if(!m_dataset.size()) {
        std::cout << "ERROR: test(): No training data\n";
        exit(EXIT_FAILURE);
    }

    unsigned records = m_dataset.size();
    unsigned features = m_dataset.at(0).size();
    double distance;
    double minDistance = DBL_MAX;
    std::vector<std::vector<double>> nn;
    double prediction;

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

    // ERROR TEST: no neigbors
    if (nn.empty()) {
        std::cout << "ERROR: test(): No nearest neighbor\n";
        exit(EXIT_FAILURE);
    }

    // TODO: ask how to handle equidistance neigbors. Using random selection
    // prediction = nn.at( rand() % nn.size() ).at(0);
    std::vector<double> neighbor = nn.at( rand() % nn.size() );

    std::cout << "\nn-neighbor: " << neighbor.at(0) << '\t';
    for (unsigned feature = 1; feature < features; feature++)
        std::cout << std::setw(8) << neighbor.at(feature) << '\t';
    std::cout << "\n\n";

    return neighbor.at(0);
}



double Classifier::euclideanDistance(const std::vector<double> &v1,
                                     const std::vector<double> &v2)
{
    // GUARD: unequal vector sizes
    if (v1.size() != v2.size()) {
        std::cout << "ERROR: euclideanDistance()";
        exit(EXIT_FAILURE);
    }

    double squaredSum{0};
    for (unsigned feature = 1; feature < v1.size(); feature++)
        squaredSum += std::pow( v1.at(feature) - v2.at(feature) , 2);

    return std::sqrt(squaredSum);
}




/*******************************************************************************
 * @brief 
 * 
*******************************************************************************/
void Classifier::showTraining() const 
{
    // GUARD
    if(!m_dataset.size()) {
        std::cout << "ERROR: showTraining(): No training data\n";
        exit(EXIT_FAILURE);
    }

    unsigned records = m_dataset.size();
    unsigned features = m_dataset.at(0).size();

    
    std::cout << std::setprecision(8);
    for(unsigned record = 0; record < records; record++) {

        std::cout << record << " : ";
        std::cout << m_dataset.at(record).at(0) << '\t';

        for(unsigned feature = 1; feature < features; feature++) {
            std::cout << std::setw(8) << m_dataset.at(record).at(feature) << '\t';
        }

        std::cout << '\n';

    }
}