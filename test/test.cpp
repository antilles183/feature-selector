#include "test_Node.cpp"
#include "test_Evaluator.cpp"


int main() {

    InputOutput io;

    //##########################################################################
    
    io.console('#', 80, true);
    std::cout << "\tBEGIN TEST --- NODE \n"; 
    io.console('#', 80, true);

    test_Node();

    io.console('-', 80, true);
    std::cout << "\tEND TEST --- NODE \n"; 
    io.console('-', 80, true);
    io.console('\n', 2);

    //##########################################################################

    io.console('#', 80, true);
    std::cout << "\tBEGIN TEST --- EVALUATOR \n"; 
    io.console('#', 80, true);

    test_Evaluator();

    io.console('-', 80, true);
    std::cout << "\tEND TEST --- EVALUATOR \n"; 
    io.console('-', 80, true);
    io.console('\n', 2);

    //##########################################################################

    return 0;
}