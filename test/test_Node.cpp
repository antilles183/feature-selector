#include "../src/Node.h"
#include "../src/InputOutput.h"


int test_Node() {

    Node n1;

    for(int i = 0; i < 15; i++) {
        n1.insert(i);
    }

    std::cout << "\n";
    std::cout << n1 << std::endl;
    std::cout << "Accuracy: " << n1.accuracy() << "\n";

    std::cout << "\n";

    return 0;
}