#include "InputOutput.h"
#include "Search.h"
#include "Evaluator.h"
#include "Validator.h"
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

    // prompt for feature count
    std::cout << "Welcome to atill006's Feature Selection Algorithm.\n\n";
    std::cout << "Please enter the total number of features: ";
    featureCount = io.getValidInteger(1, 100, 4);

    // generate feature set
    for(int i = 1; i < featureCount + 1; i++)
        featureSet.insert(i);

    // prompt for algorithm
    std::cout << "\nChoose an algorithm:\n";
    std::cout << "\t1. Forward Selection\n";
    std::cout << "\t2. Backward Elimination\n";
    std::cout << "\t3. atill006 Special Algorithm\n\n";
    algorithm = io.getValidInteger(1, 3, 1);
    std::cout << "\n";

    // run selected algorithm
    io.console('-', 80, true);
    switch (algorithm)
    {
    case 1:
        std::cout << "***RUNNING FORWARD SELECTION***\n";
        io.console('-', 80, true);
        // search.forwardSelection(featureSet, Evaluator::random);
        search.forwardSelection(featureSet, Validator::random);
        break;
    
    case 2:
        std::cout << "***RUNNING BACKWARD ELIMINATION***\n";
        io.console('-', 80, true);
        search.backwardElimination(featureSet, Evaluator::random);
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
