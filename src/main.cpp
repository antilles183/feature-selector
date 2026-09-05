#include "InputOutput.h"
#include "Search.h"
#include "Evaluator.h"
#include "Classifier.h"
#include "Validator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

/*******************************************************************************
- Group: atill006 – Session 22
- DatasetID: 211
- Small Dataset Results:
	- Forward: Feature Subset: {3,5}, Acc: 0.9200
	- Backward: Feature Subset: {2,4,5,7,10} Acc: 0.8200
- Large Dataset Results:
	- Forward: Feature Subset: {1,27}, Acc: 0.955
	- Backward: Feature Subset: {27}, Acc: 0.8470
- Titanic Dataset Results:
	- Forward: Feature Subset: {1,2,6}, Acc: 0.7759
	- Backward: Feature Subset: {1,2,6}, Acc: 0.7815
*******************************************************************************/

/*******************************************************************************
* PROTOTYPES
*******************************************************************************/
int getDataSet(DataSet &dataset);
void normalizeZscore(const DataSet &dataset,
                     DataSet &datasetNormal);
void printDataSet(const DataSet &dataset);



/*******************************************************************************
* MAIN
*******************************************************************************/
int main(int argc, char *argv[]) {
    
    InputOutput io;
    Search search;
    DataSet dataSet;
    DataSet dataSetNormal;
    Validator validator;
    Classifier classifier;
    FeatureSet featureSet;

    int datasetSelectionIndex = getDataSet(dataSet);
    normalizeZscore(dataSet, dataSetNormal);

    // prompt for algorithm
    std::cout << "\nChoose an algorithm:\n";
    std::cout << "\t1. Forward Selection\n";
    std::cout << "\t2. Backward Elimination\n";
    std::cout << "\t3. atill006 Special Algorithm\n\n";
    int algorithm = io.getValidInteger(1, 3, 1);
    std::cout << "\n";

    // run selected algorithm
    io.console('-', 80, true);
    switch (algorithm)
    {
    case 1:
        std::cout << "***RUNNING FORWARD SELECTION***\n";
        io.console('-', 80, true);
        search.forwardSelection(dataSetNormal, validator.evaluate, classifier);
        break;
    
    case 2:
        std::cout << "***RUNNING BACKWARD ELIMINATION***\n";
        io.console('-', 80, true);
        search.backwardElimination(dataSetNormal, validator.evaluate, classifier);
        break;

    case 3:
        std::cout << "***RUNNING ATILL006 SPECIAL ALGORITHM***\n";
        io.console('-', 80, true);
        search.specialAlgorithm(featureSet, Evaluator::random);
        break;

    default:
        std::cout << "ERROR: algorithm not provided\n";
        break;
    }


    return 0;

}



/*******************************************************************************
* HELPERS
*******************************************************************************/

void normalizeZscore(const DataSet &dataset,
                     DataSet &datasetNormal)
{
    // Guard: bad dataset
    if(!dataset.size()) {
        std::cout << "Error: normalize()\n";
        exit(EXIT_FAILURE);
    } 
    
    std::cout << "Normalizing...";

    // get records & features counts
    unsigned records = dataset.size();
    unsigned fields = dataset.at(0).size();

    // allocate for means and standard deviations
    //    idx0 is label and may be worthless, but harmless to have.
    //    may just change this to vectors later and not use heap
    double* mean = new double[fields]();
    double* sigma = new double[fields]();

    // calculate mean
    for (int feature = 0; feature < fields; feature++) {
        for (int record = 0; record < records; record++) {
            mean[feature] += dataset.at(record).at(feature);
        }
    }

    for (int feature = 0; feature < fields; feature++)
        mean[feature] = mean[feature] / records;

    // calculate standard deviation
    for (int feature = 0; feature < fields; feature++) {
        for (int record = 0; record < records; record++) {
            sigma[feature] += std::pow(dataset.at(record).at(feature) - mean[feature], 2);
        }
    }

    for (int feature = 0; feature < fields; feature++)
        sigma[feature] = std::sqrt( sigma[feature] / (records - 1) );

    // build & fill datasetNormal
    //     create record & copy class label unchanged
    std::vector<double> tempVec;
    for (int record = 0; record < records; record++) {
        tempVec.push_back(dataset.at(record).at(0));
        datasetNormal.push_back(tempVec);
        tempVec.clear();
    }

    //     copy normalized features data:    x' = (x - mean) / sigma
    double normalData;
    for (int feature = 1; feature < fields; feature++) {
        for (int record = 0; record < records; record++) {
            normalData = ( dataset.at(record).at(feature) - mean[feature] ) / sigma[feature];
            datasetNormal.at(record).push_back(normalData);
        }
    }

    std::cout << "complete\n\n";

    // OUTPUT: if true, print means and standard deviations to console
    if(false) {
        std::cout << "mu : " << std::setprecision(3);
        std::cout << mean[0] << '\t' << std::setprecision(8);
        for (int feature = 1; feature < fields; feature++) {
            std::cout << std::setw(8) << mean[feature] << '\t';
        }

        std::cout << "\nsig: " << std::setprecision(2);
        std::cout << sigma[0] << '\t' << std::setprecision(8);
        for (int feature = 1; feature < fields; feature++) {
            std::cout << std::setw(8) << sigma[feature] << '\t';
        }
        std::cout << '\n';
    }

    // deallocate
    delete[] mean;
    delete[] sigma;
}



/*******************************************************************************
 * @brief Get the Data Set object
 * 
 * @param dataset 
*******************************************************************************/
int getDataSet(DataSet &dataset)
{
    InputOutput io;
    std::ifstream dataFile;
    std::string files[] = {"small-test-dataset.txt",
                           "large-test-dataset.txt",
                           "titanic-clean.txt"};
    int datasetIndex;

    // prompt for dataset
    std::cout << "Welcome to atill006's Feature Selection Algorithm.\n";
    std::cout << "\nChoose a dataset:\n";
    std::cout << "\t1. small-test-dataset.txt\n";
    std::cout << "\t2. large-test-dataset.txt\n";
    std::cout << "\t3. titanic-clean.txt\n\n";
    datasetIndex = io.getValidInteger(1, 3, 1);
    std::cout << "\n";

    // open & verify file
    dataFile.open(("../data/" + files[datasetIndex-1]));
    if(!dataFile) {
        std::cerr << "Error: File could not be opened." << std::endl;
        exit(EXIT_FAILURE);
    } else {
        std::cout << "Parsing file...";
    }

    // parse data from file
    std::string line;
    std::string data;
    std::vector<double> instance;
    while(std::getline(dataFile, line)) {

        std::stringstream ss(line);
        
        while(ss >> data)
            instance.push_back( std::stod(data));

        dataset.push_back(instance);
        instance.clear();
    }

    dataFile.close();

    std::cout << "complete\n";

    return datasetIndex;

}



void printDataSet(const DataSet &dataset)
{
    //UNTESTED FUNCTION

    // GUARD
    if(!dataset.size() || !dataset.at(0).size())
        return;

    std::cout << std::setprecision(8);
    for(int i = 0; i < dataset.size(); i++) {
        std::cout << i << " : ";
        std::cout << dataset.at(i).at(0) << '\t';
        for(int j = 1; j < dataset.at(i).size(); j++) {
            std::cout << std::setw(8) << dataset.at(i).at(j) << '\t';
        }
        std::cout << '\n';

    }

}