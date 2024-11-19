#include "../src/Evaluator.h"


int test_Evaluator() {

    Node node;

    for(int i = 0; i < 5; i++) {
        std::cout << Evaluator::random(node) << "\n";
    }

    std::cout << "\n";

    for(int i = 0; i < 5; i++) {
        std::cout << Evaluator::random() << "\n";
    }

    std::cout << "\n";

    return 0;
}