#include "InputOutput.h"
#include "Search.h"
#include "Evaluator.h"
#include <set>


/*******************************************************************************
* PROTOTYPES
*******************************************************************************/



/*******************************************************************************
* MAIN
*******************************************************************************/
int main(int argc, char *argv[]) {

    InputOutput io;
    Search search;
    
    int featureCount;
    std::set<int> featureSet;
    int algorithm;

    std::cout << "Welcome to atill006's Feature Selection Algorithm.\n\n";
    std::cout << "Please enter the total number of features: ";
    featureCount = io.getValidInteger(1, 100, 4);

    for(int i = 1; i < featureCount + 1; i++)
        featureSet.insert(i);


    std::cout << "\nChoose an algorithm:\n";
    std::cout << "\t1. Forward Selection\n";
    std::cout << "\t2. Backward Elimination\n";
    std::cout << "\t3. atill006 Special Algorithm\n\n";
    algorithm = io.getValidInteger(1, 3, 1);
    std::cout << "\n";


    switch (algorithm)
    {
    case 1:
        std::cout << "RUNNING FORWARD SELECTION\n";
        search.forwardSelection(featureSet, Evaluator::random);
        break;
    
    case 2:
        std::cout << "RUNNING BACKWARD ELIMINATION\n";
        search.backwardElimination(featureSet, Evaluator::random);
        break;

    case 3:
        std::cout << "RUNNING SPECIAL ALGORITHM\n";
        search.specialAlgorithm(featureSet, Evaluator::random);
        break;

    default:
        std::cout << "ERROR: algorithm not provided\n";
        break;
    }

    return 0;

}
