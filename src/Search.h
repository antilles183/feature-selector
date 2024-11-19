#pragma once
#include "Node.h"
#include <set>


class Search
{

private:
    /* data */

public:
    Search(/* args */);
    ~Search();

    Node forwardSelection(std::set<int> featureSet, 
                          double (*eval)(const Node& node));
    
    Node backwardElimination(std::set<int> featureSet,
                             double (*eval)(const Node& node));

    Node specialAlgorithm(std::set<int> featureSet,
                          double (*eval)(const Node& node));
                          
};


