#include "../src/Node.h"
#include <queue>


int test_PriorityQueue() {

    int acc;

    std::priority_queue<Node> pq;

    // fill pq
    for(int i = 1; i < 11; i++)
    {
        acc = rand() % 100;
        printf("pushing with acc == %d\n", acc);
        pq.push( Node(acc) );
    }

    // empty pq to console. accuracy() multiplies by 100 (%) so undo for test
    std::cout << "\npq: ";
    for(;!pq.empty(); pq.pop())
        std::cout << pq.top().accuracy() / 100 << ' ';
    std::cout << '\n';

    std::cout << "\n";

    return 0;
}