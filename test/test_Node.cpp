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

    Node n2(-1);
    Node n3(0);
    Node n4(1);
    Node n5(99);

    std::cout << "n2(-1) < n3(0) == " << (n2 < n3) << std::endl;
    std::cout << "n2(-1) > n3(0) == " << (n2 > n3) << std::endl;
    std::cout << "\n";
    std::cout << "n3(0) < n4(1) == " << (n3 < n4) << std::endl;
    std::cout << "n3(0) > n4(1) == " << (n3 > n4) << std::endl;
    std::cout << "\n";
    std::cout << "n4(1) < n5(99) == " << (n4 < n5) << std::endl;
    std::cout << "n4(1) > n5(99) == " << (n4 > n5) << std::endl;
    std::cout << "\n";
    std::cout << "n5(99) < n5(99) == " << (n5 < n5) << std::endl;
    std::cout << "n5(99) > n5(99) == " << (n5 > n5) << std::endl;
    std::cout << "\n";

    std::cout << "n4.accuracy() == " << n4.accuracy() << '\n';
    std::cout << "n5.accuracy() == " << n5.accuracy() << '\n';
    std::cout << "n5 > n4 ? n5 : n4 == " << (n5 > n4 ? n5.accuracy() : n4.accuracy()) << std::endl;
    std::cout << "\n";




    return 0;
}