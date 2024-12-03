#include "InputOutput.h"
#include "Evaluator.h"
#include "Classifier.h"
#include "Validator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>



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
    
    DataSet dataset;
    DataSet datasetNormal;
    Validator validator;
    Classifier classifier;
    FeatureSet featureSet;

    int datasetSelectionIndex = getDataSet(dataset);
    normalizeZscore(dataset, datasetNormal);


    // different features for different datasets
    if(datasetSelectionIndex == 1)
        featureSet = {3, 5, 7};
    else if (datasetSelectionIndex == 2)
        featureSet = {1, 15, 27};
    else if (datasetSelectionIndex == 3)
        featureSet = {2, 4, 6};


    double accuracy = validator.evaluate(featureSet, 
                                          datasetNormal, 
                                          classifier);

    std::cout << "accuracy == " << accuracy << "\n";

    // // output normalized dataset to file
    // InputOutput io;
    // io.writeToFile(dataset, "small-test-dataset", ".csv", ',', "../data/");
    // io.writeToFile(datasetNormal, "small-test-dataset-normal-z-score", ".csv", ',', "../data/");

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