#pragma once
#include "Node.h"
#include <set>


class Search
{

public:

    Node forwardSelection(std::set<int> featureSet, 
                          double (*eval)(const Node& node));
    
    Node backwardElimination(std::set<int> featureSet,
                             double (*eval)(const Node& node));

    Node specialAlgorithm(std::set<int> featureSet,
                          double (*eval)(const Node& node));

    
    // PRIVATE HELPERS
    Node forwardSelectionEngine(std::set<int>& featureSet,
                                const Node& parent,
                                double (*eval)(const Node& node));

    Node backwardEliminationEngine(std::set<int>& featureSet,
                                   const Node& parent,
                                   double (*eval)(const Node& node));
                          
};


