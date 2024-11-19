#include "Search.h"


Search::Search(/* args */)
{
}

Search::~Search()
{
}



Node Search::forwardSelection(std::set<int> featureSet,
                              double (*eval)(const Node& node))
{

    std::cout << "forwardSelection()\n";

    // start with starting Node
    // traverse featureSet
        // copy startNode  
        // add feature to it
        // eval accuracy
        // add to vector of child nodes


    // RECURSIVE???

    Node node(featureSet);

    std::cout << "Node: " << node << "\n\n";

    std::set<int>::iterator it = featureSet.begin();

    while(it != featureSet.end()){
        std::cout << *it++ << " ==> " << eval(node) << "\n";
    }

    std::cout << "\n";

    return Node(featureSet);

}