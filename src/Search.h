#pragma once
#include "Node.h"
#include "Validator.h"
#include "Classifier.h"
#include <set>


class Search
{

public:

    Node forwardSelection(std::set<int> featureSet, 
                          double (*eval)(const Node& node));

    Node forwardSelection(const DataSet &dataSet, 
                          double (*eval)(const FeatureSet& featureSet, const DataSet& dataSet, Classifier& classifier),
                          Classifier &classifier);
    
    Node backwardElimination(std::set<int> featureSet,
                             double (*eval)(const Node& node));

    Node backwardElimination(const DataSet &dataSet, 
                             double (*eval)(const FeatureSet& featureSet, const DataSet& dataSet, Classifier& classifier),
                             Classifier &classifier);

    Node specialAlgorithm(std::set<int> featureSet,
                          double (*eval)(const Node& node));

    
    // PRIVATE HELPERS
    Node forwardSelectionEngine(std::set<int>& featureSet,
                                const Node& parent,
                                double (*eval)(const Node& node));

    Node forwardSelectionEngine(std::set<int>& featureSet,
                                const Node& parent,
                                double (*eval)(const FeatureSet& featureSet, const DataSet& dataSet, Classifier& classifier),
                                const DataSet &dataSet,
                                Classifier &classifier);

    Node backwardEliminationEngine(std::set<int>& featureSet,
                                   const Node& parent,
                                   double (*eval)(const Node& node));

    Node backwardEliminationEngine(std::set<int>& featureSet,
                                   const Node& parent,
                                   double (*eval)(const FeatureSet& featureSet, const DataSet& dataSet, Classifier& classifier),
                                   const DataSet &dataSet,
                                   Classifier &classifier);
                          
};


