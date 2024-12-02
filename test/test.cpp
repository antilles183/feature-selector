#include "test_Node.cpp"
#include "test_Evaluator.cpp"
#include "test_PriorityQueue.cpp"
#include "test_Classifier.cpp"
#include "test_Stopwatch.cpp"


int main() {

    InputOutput io;

    //##########################################################################
    
    io.console('#', 80, true);
    std::cout << "\tBEGIN TEST --- NODE \n"; 
    io.console('#', 80, true);
    io.console('\n', 1);

    test_Node();

    io.console('-', 80, true);
    std::cout << "\tEND TEST --- NODE \n"; 
    io.console('-', 80, true);
    io.console('\n', 1);

    //##########################################################################

    io.console('#', 80, true);
    std::cout << "\tBEGIN TEST --- EVALUATOR \n"; 
    io.console('#', 80, true);
    io.console('\n', 1);

    test_Evaluator();

    io.console('-', 80, true);
    std::cout << "\tEND TEST --- EVALUATOR \n"; 
    io.console('-', 80, true);
    io.console('\n', 1);

    //##########################################################################

    io.console('#', 80, true);
    std::cout << "\tBEGIN TEST --- PRIORITY QUEUE \n"; 
    io.console('#', 80, true);
    io.console('\n', 1);

    test_PriorityQueue();

    io.console('-', 80, true);
    std::cout << "\tEND TEST --- PRIORITY QUEUE \n"; 
    io.console('-', 80, true);
    io.console('\n', 1);

    //##########################################################################

    io.console('#', 80, true);
    std::cout << "\tBEGIN TEST --- CLASSIFIER \n"; 
    io.console('#', 80, true);
    io.console('\n', 1);

    test_Classifier();

    io.console('-', 80, true);
    std::cout << "\tEND TEST --- CLASSIFIER \n"; 
    io.console('-', 80, true);
    io.console('\n', 1);

    //##########################################################################

    io.console('#', 80, true);
    std::cout << "\tBEGIN TEST --- STOPWATCH \n"; 
    io.console('#', 80, true);
    io.console('\n', 1);

    test_Stopwatch();

    io.console('-', 80, true);
    std::cout << "\tEND TEST --- STOPWATCH \n"; 
    io.console('-', 80, true);
    io.console('\n', 1);

    //##########################################################################

    return 0;
}